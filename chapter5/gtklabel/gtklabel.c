/*
 *
 * Sample Code for Gtk+ Programming in C, 1st Edition, Prentice Hall
 *
 * Copyright 2000 - 2002 Syd Logan, All Rights Reserved
 *
 * This code is distributed without warranty. You are free to use this
 * code for any purpose, however, if this code is republished or
 * redistributed in its original form, as hardcopy or electronically,
 * then you must include this copyright notice along with the code.
 *
 * Questions or comments regarding this code or any bugs it contains can
 * be directed to the author via e-mail at slogan@cts.com
 *
*/

#include <gtk/gtk.h>
#include <stdio.h>

static GtkWidget *leftButton, *rightButton, *centerButton, *fillButton;
static GtkWidget *trueButton, *falseButton;

static void
QuitCallback(GtkWidget *widget, GtkWidget *dialog_window)
{
	gtk_main_quit();
	exit( 0 );
}

static void
ClickedCallback(GtkWidget *widget, GtkWidget *dialog_window)
{
	GtkWidget *window, *labelFrame, *labelTest, *vbox;

	window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
 	gtk_window_position (GTK_WINDOW (window), GTK_WIN_POS_MOUSE);
 	vbox = gtk_vbox_new (FALSE, 0);
 	gtk_container_add (GTK_CONTAINER (window), vbox);

	labelFrame = gtk_frame_new ("Test Label");
 	gtk_box_pack_start (GTK_BOX (vbox), labelFrame, TRUE, TRUE, 10);
 	labelTest = gtk_label_new ("Line 1\n"
		"This is Line 2\n"
		"And this is Line 3\n"
		"And finally, this is Line 4\n"
	);
  gtk_container_add (GTK_CONTAINER (labelFrame), labelTest);

	if ( GTK_TOGGLE_BUTTON(leftButton)->active == TRUE ) {
		gtk_label_set_justify( GTK_LABEL(labelTest), GTK_JUSTIFY_LEFT );
	} else if ( GTK_TOGGLE_BUTTON(rightButton)->active == TRUE ) {
		gtk_label_set_justify( GTK_LABEL(labelTest), GTK_JUSTIFY_RIGHT );
	} else if ( GTK_TOGGLE_BUTTON(centerButton)->active == TRUE ) {
		gtk_label_set_justify( GTK_LABEL(labelTest), GTK_JUSTIFY_CENTER );
	} else if ( GTK_TOGGLE_BUTTON(fillButton)->active == TRUE ) {
		gtk_label_set_justify( GTK_LABEL(labelTest), GTK_JUSTIFY_FILL );
	}
	if ( GTK_TOGGLE_BUTTON(trueButton)->active == TRUE ) {
		gtk_label_set_line_wrap (GTK_LABEL(labelTest), TRUE ); 
		gtk_label_set_text( GTK_LABEL(labelTest),
		"This is a huge line that I am hoping will line wrap when I set line wrap to on because, well, it is big and it ought to line wrap.");
	} else {
		gtk_label_set_line_wrap (GTK_LABEL(labelTest), FALSE ); 
	}
	gtk_widget_show_all( window );
}

main( int argc, char *argv[] )
{
	GtkWidget *label, *button, *hbox, *dialog_window;

	gtk_init( &argc, &argv );

	dialog_window = gtk_dialog_new();
 	gtk_window_position (GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);

	hbox = gtk_hbox_new (FALSE, 0);
	gtk_container_add (GTK_CONTAINER (GTK_DIALOG (dialog_window)->vbox), hbox);
 	label = gtk_label_new ("Justification: ");
 	gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, FALSE, 0);
 	leftButton = gtk_radio_button_new_with_label (NULL, "Left");
 	gtk_box_pack_start (GTK_BOX (hbox), leftButton, FALSE, FALSE, 0);
 	rightButton = gtk_radio_button_new_with_label (
    gtk_radio_button_group (GTK_RADIO_BUTTON (leftButton)), "Right");
  gtk_box_pack_start (GTK_BOX (hbox), rightButton, FALSE, FALSE, 0);
  centerButton = gtk_radio_button_new_with_label (
    gtk_radio_button_group (GTK_RADIO_BUTTON (rightButton)), "Center");
  gtk_box_pack_start (GTK_BOX (hbox), centerButton, FALSE, FALSE, 0);
  fillButton = gtk_radio_button_new_with_label (
    gtk_radio_button_group (GTK_RADIO_BUTTON (centerButton)), "Fill");
  gtk_box_pack_start (GTK_BOX (hbox), fillButton, FALSE, FALSE, 0);

	hbox = gtk_hbox_new (FALSE, 0);
	gtk_container_add (GTK_CONTAINER (GTK_DIALOG (dialog_window)->vbox), hbox);
 	label = gtk_label_new ("Line Wrap: ");
 	gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, FALSE, 0);
 	trueButton = gtk_radio_button_new_with_label (NULL, "True");
 	gtk_box_pack_start (GTK_BOX (hbox), trueButton, FALSE, FALSE, 0);
 	falseButton = gtk_radio_button_new_with_label (
    gtk_radio_button_group (GTK_RADIO_BUTTON (trueButton)), "False");
 	gtk_box_pack_start (GTK_BOX (hbox), falseButton, FALSE, FALSE, 0);

 	button = gtk_button_new_with_label ("Refresh");
 	GTK_WIDGET_SET_FLAGS (button, GTK_CAN_DEFAULT);
	gtk_window_set_default( GTK_WINDOW( dialog_window ), button );
 	gtk_box_pack_start(GTK_BOX (GTK_DIALOG (dialog_window)->action_area), 
		button, TRUE, TRUE, 0);
 	gtk_signal_connect (GTK_OBJECT (button), "clicked", 
		GTK_SIGNAL_FUNC(ClickedCallback), dialog_window);

 	button = gtk_button_new_with_label ("Quit");
 	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area), 
		button, TRUE, TRUE, 0);
 	gtk_signal_connect (GTK_OBJECT (button), "clicked", 
		GTK_SIGNAL_FUNC(QuitCallback), dialog_window);
 	gtk_widget_show_all (dialog_window);
	gtk_main();
}

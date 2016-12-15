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

static GtkWidget *button;

static void
QuitCallback(GtkWidget *widget, GtkWidget *dialog_window)
{
	gtk_main_quit();
	exit( 0 );
}

void
SetButtonLabel( GtkWidget *button, char *label )
{
	gtk_object_set( GTK_OBJECT( button ), "GtkButton::label", label, NULL );
}

static void
ClickedCallback(GtkWidget *widget, GtkWidget *dialog_window)
{
	static int which = 0;
	static int modCnt = 0;
	static char *labels[] = { "Exit", "Dismiss", "Bye!" };

	modCnt++;
	which++;
	if ( which >= sizeof( labels ) / sizeof(char *) ) 
		which = 0;
	SetButtonLabel( button, labels[which] );	
	if ( modCnt % 3 == 0 )
		gtk_toggle_button_set_mode( GTK_TOGGLE_BUTTON( widget ),
			( modCnt % 2 == 0 ? TRUE : FALSE ) );
}

main( int argc, char *argv[] )
{
	GtkWidget *dialog_window;

	gtk_init( &argc, &argv );

	dialog_window = gtk_dialog_new();
  gtk_window_position (GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);

 	button = gtk_toggle_button_new_with_label ("Refresh");
 	GTK_WIDGET_SET_FLAGS (button, GTK_CAN_DEFAULT);
	gtk_window_set_default( GTK_WINDOW( dialog_window ), button );
 	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area), 
		button, TRUE, TRUE, 0);
 	gtk_signal_connect (GTK_OBJECT (button), "clicked", 
		GTK_SIGNAL_FUNC(ClickedCallback), dialog_window);

 	button = gtk_toggle_button_new_with_label ("Quit");
 	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area), 
		button, TRUE, TRUE, 0);
 	gtk_signal_connect (GTK_OBJECT (button), "clicked", 
		GTK_SIGNAL_FUNC(QuitCallback), dialog_window);
 	gtk_widget_show_all (dialog_window);
	gtk_main();
}

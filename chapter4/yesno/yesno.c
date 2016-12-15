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

/*
 * Simple Yes/No OK/Cancel dialog 
 */

static gboolean result;

static void
OkClickedCallback(GtkWidget *widget, GtkWidget *dialog_window)
{
	result = TRUE;
	gtk_widget_destroy( dialog_window );
	gtk_main_quit();
}

static void
CancelClickedCallback(GtkWidget *widget, GtkWidget *dialog_window)
{
	result = FALSE;
	gtk_widget_destroy( dialog_window );
	gtk_main_quit();
}

gboolean
QuestionBox( GtkWidget *parent, char *message, char *ok_label, 
	char *cancel_label, gboolean okIsDefault )
{
	GtkWidget *label, *button, *dialog_window;

	dialog_window = gtk_dialog_new();
 	gtk_window_position (GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);

 	gtk_signal_connect (GTK_OBJECT (dialog_window), "destroy",
		GTK_SIGNAL_FUNC(gtk_widget_destroyed), &dialog_window);

 	gtk_window_set_title (GTK_WINDOW (dialog_window), "Message");
 	gtk_container_border_width (GTK_CONTAINER (dialog_window), 0);

 	button = gtk_button_new_with_label (ok_label);
 	GTK_WIDGET_SET_FLAGS (button, GTK_CAN_DEFAULT);
	if ( okIsDefault == TRUE )
		gtk_window_set_default( GTK_WINDOW( dialog_window ), button );
 	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area), 
		button, TRUE, TRUE, 0);
  gtk_signal_connect (GTK_OBJECT (button), "clicked", 
		GTK_SIGNAL_FUNC(OkClickedCallback), dialog_window);

 	button = gtk_button_new_with_label (cancel_label);
 	GTK_WIDGET_SET_FLAGS (button, GTK_CAN_DEFAULT);
	if ( okIsDefault == FALSE )
		gtk_window_set_default( GTK_WINDOW( dialog_window ), button );
 	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area), 
		button, TRUE, TRUE, 0);
 	gtk_signal_connect (GTK_OBJECT (button), "clicked", 
		GTK_SIGNAL_FUNC(CancelClickedCallback), dialog_window);

 	label = gtk_label_new (message);
 	gtk_misc_set_padding (GTK_MISC (label), 10, 10);
 	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->vbox), label, 
		TRUE, TRUE, 0);
	if ( parent != (GtkWidget *) NULL )
		gtk_window_set_transient_for( GTK_WINDOW( dialog_window ), 
			GTK_WINDOW( parent ) ); 
	gtk_window_set_modal( GTK_WINDOW( dialog_window ), TRUE );
 	gtk_widget_show_all (dialog_window);
	gtk_main();
	return( result );
}

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

main( int argc, char *argv[] )
{
	GtkWidget *dialog, *label, *button;

	gtk_init( &argc, &argv );
	dialog = gtk_dialog_new();

	gtk_widget_set_usize( dialog, 214, 117 );
	gtk_window_set_policy( GTK_WINDOW( dialog ), FALSE, FALSE, FALSE);

	gtk_window_set_title( GTK_WINDOW( dialog ), "Alert" );

	gtk_container_set_border_width (GTK_CONTAINER (dialog), 0);
	label = gtk_label_new("You have new mail!");
	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog)->vbox), 
    label, TRUE, TRUE, 0);

  button = gtk_button_new_with_label ("OK");
  GTK_WIDGET_SET_FLAGS (button, GTK_CAN_DEFAULT);
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog)->action_area),
    button, FALSE, FALSE, 0);
 	gtk_widget_grab_default (button);
	
	gtk_widget_show_all( dialog );

	gtk_main();
}


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
#include <gdk/gdkkeysyms.h>

static void
ClickedCallback(GtkWidget *widget, GtkWidget *dialog_window)
{
	fprintf( stderr, "In ClickedCallback\n" );
	fflush( stderr );
}

main( int argc, char *argv[] )
{
	GtkWidget *button, *dialog_window;
	GtkAccelGroup *accel_group;

	accel_group = gtk_accel_group_new();

	gtk_init( &argc, &argv );

	dialog_window = gtk_dialog_new();
 	gtk_window_position (GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);

 	button = gtk_button_new_with_label ("Press me!");

	gtk_accel_group_attach(accel_group, GTK_OBJECT(dialog_window));
	gtk_widget_add_accelerator(button, "clicked", accel_group, GDK_F1, 0, 0 );

  GTK_WIDGET_SET_FLAGS (button, GTK_CAN_DEFAULT);
	gtk_window_set_default( GTK_WINDOW( dialog_window ), button );
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area), 
		button, FALSE, FALSE, 0);
  gtk_signal_connect (GTK_OBJECT (button), "clicked", 
		GTK_SIGNAL_FUNC(ClickedCallback), button);

  gtk_widget_show_all (dialog_window);
	gtk_main();
}

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
	GtkWidget *dialog, *label;

	gtk_init( &argc, &argv );
	dialog = gtk_dialog_new();

	label = gtk_label_new("Content Area");
	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog)->vbox), 
    label, FALSE, FALSE, 0);

	label = gtk_label_new("Action Area");
	gtk_box_pack_start (GTK_BOX (GTK_DIALOG(dialog)->action_area),
    label, FALSE, FALSE, 0);
	
	gtk_widget_show_all( dialog );
	gtk_main();
}


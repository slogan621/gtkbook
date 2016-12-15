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
	GtkWidget *colorSel;

	gtk_init( &argc, &argv );

	colorSel = gtk_color_selection_dialog_new("Color Selection");
	gtk_widget_show( colorSel );
	gtk_widget_show( GTK_COLOR_SELECTION_DIALOG(colorSel)->reset_button );
	
	gtk_main();
}


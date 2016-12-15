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
#include <strings.h>
#include <time.h>

int main( int argc, char *argv[] )
{
	GtkWidget *window, *packer, *button, *one, *two, *three;
	GdkColor color;
	GtkStyle *style;
 	GtkPackerOptions options;
 
 	gtk_init (&argc, &argv);
 
 	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 	gtk_signal_connect(GTK_OBJECT(window), "destroy", 
		GTK_SIGNAL_FUNC(gtk_main_quit), "WM destroy");
 	gtk_window_set_title(GTK_WINDOW(window), "Packer");

	style = gtk_style_new();
	color.red = 0x0;
	color.green = 0x0;
	color.blue = 0x0;
	style->bg[GTK_STATE_NORMAL] = color;
	gtk_widget_set_style( window, style );
 
 	packer = gtk_packer_new();
 	options = 0;

 	one = gtk_packer_new();
	gtk_packer_add_defaults( GTK_PACKER( packer ), one,
		GTK_SIDE_TOP, GTK_ANCHOR_CENTER, options );
 	gtk_widget_show( one );

	button = gtk_button_new_with_label( "alpha" );
	gtk_widget_show( button );
	gtk_packer_add_defaults( GTK_PACKER( one ), button,
		GTK_SIDE_LEFT, GTK_ANCHOR_CENTER, options );

	button = gtk_button_new_with_label( "beta" );
	gtk_widget_show( button );
	gtk_packer_add_defaults( GTK_PACKER( one ), button,
		GTK_SIDE_LEFT, GTK_ANCHOR_CENTER, options );

 	two = gtk_packer_new();
	gtk_widget_show( two );
	gtk_packer_add_defaults( GTK_PACKER( one ), two,
		GTK_SIDE_LEFT, GTK_ANCHOR_CENTER, options );

	button = gtk_button_new_with_label( "epsilon" );
	gtk_widget_show( button );
	gtk_packer_add_defaults( GTK_PACKER( two ), button,
		GTK_SIDE_TOP, GTK_ANCHOR_CENTER, options );

	button = gtk_button_new_with_label( "delta" );
	gtk_widget_show( button );
	gtk_packer_add_defaults( GTK_PACKER( two ), button,
		GTK_SIDE_TOP, GTK_ANCHOR_CENTER, options );

 	three = gtk_drawing_area_new();
	gtk_widget_set_usize( three, 100, 50 );
	gtk_packer_add_defaults( GTK_PACKER( packer ), three,
		GTK_SIDE_TOP, GTK_ANCHOR_CENTER, options );
	style = gtk_style_new();
	color.red = 0x8000;
	color.green = 0x8000;
	color.blue = 0x8000;
	style->bg[GTK_STATE_NORMAL] = color;
	gtk_widget_set_style( three, style );
 	gtk_widget_show( three );

 	gtk_widget_show( packer );
 	gtk_container_add( GTK_CONTAINER( window ), packer );

 	gtk_widget_show( window );

 	gtk_main();
 
 	return(0);
}

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
	GtkWidget *window, *packer, *one, *two, *three;
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
 	options = GTK_FILL_X;

 	one = gtk_drawing_area_new();
	gtk_widget_set_usize( one, 100, 50 );
	gtk_packer_add_defaults( GTK_PACKER( packer ), one,
		GTK_SIDE_BOTTOM, GTK_ANCHOR_CENTER, options );
	style = gtk_style_new();
	color.red = 0x8000;
	color.green = 0x8000;
	color.blue = 0x8000;
	style->bg[GTK_STATE_NORMAL] = color;
	gtk_widget_set_style( one, style );
 	gtk_widget_show( one );

 	two = gtk_drawing_area_new();
	gtk_widget_set_usize( two, 40, 40 );
	gtk_packer_add_defaults( GTK_PACKER( packer ), two,
		GTK_SIDE_BOTTOM, GTK_ANCHOR_CENTER, options );
	style = gtk_style_new();
	color.red = 0xffff;
	color.green = 0xffff;
	color.blue = 0xffff;
	style->bg[GTK_STATE_NORMAL] = color;
	gtk_widget_set_style( two, style );
 	gtk_widget_show( two );

 	three = gtk_drawing_area_new();
	gtk_widget_set_usize( three, 20, 20 );
	gtk_packer_add_defaults( GTK_PACKER( packer ), three,
		GTK_SIDE_RIGHT, GTK_ANCHOR_CENTER, options );
	style = gtk_style_new();
	color.red = 0xbfff;
	color.green = 0xbfff;
	color.blue = 0xbfff;
	style->bg[GTK_STATE_NORMAL] = color;
	gtk_widget_set_style( three, style );
 	gtk_widget_show( three );

 	gtk_widget_show(packer);
 	gtk_container_add( GTK_CONTAINER( window ), packer );

 	gtk_widget_show(window);

 	gtk_main();
 
 	return(0);
}

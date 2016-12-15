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
	GtkWidget *window, *parent, *prop, *base, *foo;
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
 
 	parent = gtk_packer_new();
 	gtk_widget_show( parent );

 	options = 0;

 	base = gtk_drawing_area_new();
  gtk_widget_set_usize( base, 120, 20 );
	style = gtk_style_new();
	color.red = 0x8000;
	color.green = 0x8000;
	color.blue = 0x8000;
	style->bg[GTK_STATE_NORMAL] = color;
	gtk_widget_set_style( base, style );
	gtk_packer_add_defaults( GTK_PACKER( parent ), base,
		GTK_SIDE_BOTTOM, GTK_ANCHOR_CENTER, options );

 	gtk_widget_show( base );

 	options = GTK_PACK_EXPAND;

 	prop = gtk_drawing_area_new();
  gtk_widget_set_usize( prop, 20, 80 );
	style = gtk_style_new();
	color.red = 0xffff;
	color.green = 0xffff;
	color.blue = 0xffff;
	style->bg[GTK_STATE_NORMAL] = color;
	gtk_widget_set_style( prop, style );
	gtk_packer_add_defaults( GTK_PACKER( parent ), prop,
		GTK_SIDE_RIGHT, GTK_ANCHOR_SW, options );

 	gtk_widget_show( prop );

 	options = GTK_PACK_EXPAND;

	foo = gtk_button_new_with_label( "Foo" );
	gtk_widget_show( foo );
	gtk_packer_add_defaults( GTK_PACKER( parent ), foo,
		GTK_SIDE_RIGHT, GTK_ANCHOR_NE, options );

 	gtk_widget_show( parent );
 	gtk_container_add( GTK_CONTAINER( window ), parent );

 	gtk_widget_show( window );

 	gtk_main();
 
 	return(0);
}

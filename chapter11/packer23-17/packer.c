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
	GtkWidget *window;
 	GtkWidget *packer;
 	GtkWidget *one, *two, *three, *four, *five;
	GdkColor color;
	GtkStyle *style;
 	GtkPackerOptions options;
 
 	gtk_init (&argc, &argv);
 
 	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 	gtk_signal_connect(GTK_OBJECT(window), "destroy", 
		GTK_SIGNAL_FUNC(gtk_main_quit), "WM destroy");
 	gtk_window_set_title(GTK_WINDOW(window), "Packer");
 
 	packer = gtk_packer_new();
	gtk_packer_set_default_pad( GTK_PACKER( packer ), 20, 0 );
 	options = GTK_FILL_X | GTK_PACK_EXPAND;

 	one = gtk_label_new("one");
	gtk_packer_add_defaults( GTK_PACKER( packer ), one,
		GTK_SIDE_LEFT, GTK_ANCHOR_CENTER, options );
 	gtk_widget_show( one );

 	two = gtk_label_new("two");
	gtk_packer_add_defaults( GTK_PACKER( packer ), two,
		GTK_SIDE_LEFT, GTK_ANCHOR_CENTER, options );
 	gtk_widget_show( two );

 	three = gtk_label_new("three");
	gtk_packer_add_defaults( GTK_PACKER( packer ), three,
		GTK_SIDE_LEFT, GTK_ANCHOR_CENTER, options );
 	gtk_widget_show( three );

 	four = gtk_label_new("four");
	gtk_packer_add_defaults( GTK_PACKER( packer ), four,
		GTK_SIDE_LEFT, GTK_ANCHOR_CENTER, options );
 	gtk_widget_show( four );

 	five = gtk_label_new("five");
	gtk_packer_add_defaults( GTK_PACKER( packer ), five,
		GTK_SIDE_LEFT, GTK_ANCHOR_CENTER, options );
 	gtk_widget_show( five );

 	gtk_widget_show(packer);
 	gtk_container_add( GTK_CONTAINER( window ), packer );

 	gtk_widget_show(window);

 	gtk_main();
 
 	return(0);
}

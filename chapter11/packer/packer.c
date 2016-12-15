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
 	GtkWidget *button;
 	char buf[ 10 ];
 	GtkPackerOptions options;
 	int i, pad_x, pad_y, i_pad_x, i_pad_y, border_width;
 
 	gtk_init (&argc, &argv);
 
 	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 	gtk_signal_connect(GTK_OBJECT(window), "destroy", 
		GTK_SIGNAL_FUNC(gtk_main_quit), "WM destroy");
 	gtk_window_set_title(GTK_WINDOW(window), "Packer");
 	gtk_widget_set_usize(GTK_WIDGET(window), 300, 200);
 
 	packer = gtk_packer_new();
 	options = 0;
 	border_width = 0;
 	pad_x = 0; pad_y = 0; i_pad_x = 5; i_pad_y = 5; 

 	for ( i = 0; i < 4; i++ ) {
		sprintf( buf, "Click me! %d\n", i );
 		button = gtk_button_new_with_label (buf);
		gtk_packer_add( GTK_PACKER( packer ), button,
			GTK_SIDE_TOP, GTK_ANCHOR_EAST, options,
			border_width, pad_x, pad_y, i_pad_x, i_pad_y );
 		gtk_widget_show( button );
 	}

/* options:

    GTK_PACK_EXPAND   = 1 << 0, 
    GTK_FILL_X        = 1 << 1,
    GTK_FILL_Y        = 1 << 2
*/
	
 	gtk_widget_show(packer);
 	gtk_container_add( GTK_CONTAINER( window ), packer );
 	gtk_widget_show(window);
 	gtk_main();
 
 	return(0);
}

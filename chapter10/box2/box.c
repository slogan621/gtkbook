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

// main

int main( int argc, char *argv[] )
{
 	GtkWidget *window, *button[20], *widget, *vbox;
	char buf[ 32 ];
	int i;

 	gtk_init(&argc, &argv);
 
 	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 	gtk_signal_connect(GTK_OBJECT(window), "destroy", 
    GTK_SIGNAL_FUNC (gtk_main_quit), "WM destroy");
	sprintf( buf, "Box" );
 	gtk_window_set_title(GTK_WINDOW(window), buf);
 	gtk_widget_set_usize(GTK_WIDGET(window), 640, 480);

 	vbox = gtk_vbox_new (FALSE, 1);
 	gtk_container_add(GTK_CONTAINER (window), vbox);
 	gtk_widget_show( vbox );

	for ( i = 0; i < 10; i++ ) {
		sprintf( buf, "button %d", i );
		button[ i ] = gtk_button_new_with_label( buf );
 		gtk_box_pack_start(GTK_BOX(vbox), button[i], FALSE, TRUE, 0);
 		gtk_widget_show(button[i]);
	}

	for ( i = 10; i < 20; i++ ) {
		sprintf( buf, "button %d", i );
		button[ i ] = gtk_button_new_with_label( buf );
 		gtk_box_pack_end(GTK_BOX(vbox), button[i], FALSE, TRUE, 0);
 		gtk_widget_show(button[i]);
	}

//	gtk_box_set_child_packing( GTK_BOX( vbox ), button[0], FALSE,
//		TRUE, 0, GTK_PACK_END );
	gtk_box_reorder_child( GTK_BOX( vbox ), button[ 0 ], 9);
	gtk_box_reorder_child( GTK_BOX( vbox ), button[ 19 ], 9);
 	gtk_widget_show(window);
 	gtk_main ();
 
 	return(0);
}



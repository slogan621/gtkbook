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
 	GtkWidget *window, *button[3], *widget, *hbox, *vbox;
	GtkWidget *label, *bbox, *hline, *tvbox;
	gint min_width, min_height;
	gboolean expand, fill;
	guint padding;
	GtkPackType pack_type;

 	gtk_init(&argc, &argv);
 
 	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 	gtk_signal_connect(GTK_OBJECT(window), "destroy", 
    GTK_SIGNAL_FUNC (gtk_main_quit), "WM destroy");
 	gtk_window_set_title(GTK_WINDOW(window), "Confirm Operation");

 	tvbox = gtk_vbox_new( FALSE, 10 );
 	gtk_container_add(GTK_CONTAINER (window), tvbox);
 	gtk_widget_show( tvbox );

	label = gtk_label_new( "Are you sure you want delete this file?" );
 	gtk_box_pack_start(GTK_BOX (tvbox), label, FALSE, FALSE, 10);
 	gtk_widget_show( label );

	hline = gtk_hseparator_new();
 	gtk_container_add(GTK_CONTAINER (tvbox), hline);
 	gtk_widget_show( hline );
  gtk_button_box_get_child_ipadding_default(&min_width, &min_height);
	printf( "ipad_x is %d ipad_y is %d\n", min_width, min_height );

 	hbox = gtk_hbutton_box_new();
 	gtk_container_add(GTK_CONTAINER (tvbox), hbox);
 	gtk_widget_show( hbox );

	button[ 0 ] = gtk_button_new_with_label( "Yes" );
 	gtk_container_add(GTK_CONTAINER (hbox), button[0]);
/*
 	gtk_box_pack_start(GTK_BOX(hbox), button[0], FALSE, TRUE, 0);
*/
 	gtk_widget_show(button[0]);

	button[ 1 ] = gtk_button_new_with_label( "No" );
 	gtk_box_pack_start(GTK_BOX(hbox), button[1], FALSE, TRUE, 0);
 	gtk_widget_show(button[1]);

	button[ 2 ] = gtk_button_new_with_label( "Stop Asking" );
 	gtk_box_pack_start(GTK_BOX(hbox), button[2], FALSE, TRUE, 0);
 	gtk_widget_show(button[2]);

 	gtk_widget_show(window);
 	gtk_main ();
 
 	return(0);
}



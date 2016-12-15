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

int main( int argc, char *argv[] )
{
 	GtkWidget *window, *vbox, *notebook, *label, *tab_label;

 	gtk_init(&argc, &argv);

	// create a window
 
 	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 	gtk_signal_connect(GTK_OBJECT(window), "destroy", 
    GTK_SIGNAL_FUNC (gtk_main_quit), "WM destroy");
 	gtk_window_set_title(GTK_WINDOW(window), "Notebook");
 	gtk_widget_set_usize(GTK_WIDGET(window), 200, 100);

	// create a notebook and add it to the window

	notebook = gtk_notebook_new();
 	gtk_container_add(GTK_CONTAINER (window), notebook);

 	gtk_widget_show( notebook );

	// create the first panel, which consists of an instance of
	// GtkVBox, which in turn manages an instance of GtkLabel

	vbox = gtk_vbox_new( FALSE, 10 );

	gtk_widget_show( vbox );

	label = gtk_label_new( "Panel 1" );
	gtk_widget_show( label );
	tab_label = gtk_label_new( "Panel 1" );
	gtk_widget_show( tab_label );
	gtk_box_pack_start_defaults( GTK_BOX( vbox ), label );

	gtk_notebook_append_page( GTK_NOTEBOOK( notebook ), 
		vbox, tab_label ); 

	// create the second panel

	vbox = gtk_vbox_new( FALSE, 10 );

	gtk_widget_show( vbox );

	label = gtk_label_new( "Panel 2" );
	gtk_widget_show( label );
	tab_label = gtk_label_new( "Panel 2" );
	gtk_widget_show( tab_label );
	gtk_box_pack_start_defaults( GTK_BOX( vbox ), label );

	gtk_notebook_append_page( GTK_NOTEBOOK( notebook ), 
		vbox, tab_label ); 

	// create the final panel

	vbox = gtk_vbox_new( FALSE, 10 );

	gtk_widget_show( vbox );

	label = gtk_label_new( "Panel 3" );
	gtk_widget_show( label );
	tab_label = gtk_label_new( "Panel 3" );
	gtk_widget_show( tab_label );
	gtk_box_pack_start_defaults( GTK_BOX( vbox ), label );

	gtk_notebook_append_page( GTK_NOTEBOOK( notebook ), 
		vbox, tab_label ); 

	// show the main window and call the main loop

 	gtk_widget_show(window);
 	gtk_main ();
 
 	return(0);
}


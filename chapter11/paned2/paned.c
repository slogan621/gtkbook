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

gint
paned_timeout (gpointer data)
{
	static int position = 1;
	static int height = 1;
	GtkPaned *vpaned = GTK_PANED( data );

//	gtk_paned_set_position( vpaned, position );
//	gtk_paned_set_handle_size( vpaned, height );
	gtk_paned_set_gutter_size( vpaned, height );
	position += 5;
	height += 10;
	if ( position > 100 )
		position = -1;	// restore default
	if ( height > 100 )
		height = 1;
}

int main( int argc, char *argv[] )
{
 	GtkWidget *window, *vbox, *vpaned, *label, *tab_label;
	int timer;

 	gtk_init(&argc, &argv);

	// create a window
 
 	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 	gtk_signal_connect(GTK_OBJECT(window), "destroy", 
    		GTK_SIGNAL_FUNC (gtk_main_quit), "WM destroy");
 	gtk_window_set_title(GTK_WINDOW(window), "Paned");
 	gtk_widget_set_usize(GTK_WIDGET(window), 200, 100);

	// create a notebook and add it to the window

	vpaned = gtk_vpaned_new();
 	gtk_container_add(GTK_CONTAINER (window), vpaned);

 	gtk_widget_show( vpaned );

	// create the first panel, which consists of an instance of
	// GtkVBox, which in turn manages an instance of GtkLabel

	vbox = gtk_vbox_new( FALSE, 10 );

	gtk_widget_show( vbox );

	label = gtk_label_new( "Panel 1" );
	gtk_widget_show( label );
	tab_label = gtk_label_new( "Panel 1" );
	gtk_widget_show( tab_label );
	gtk_box_pack_start_defaults( GTK_BOX( vbox ), label );

	gtk_paned_pack1( GTK_PANED( vpaned ), vbox, TRUE, FALSE ); 

	// create the second panel

	vbox = gtk_vbox_new( FALSE, 10 );

	gtk_widget_show( vbox );

	label = gtk_label_new( "Panel 2" );
	gtk_widget_show( label );
	tab_label = gtk_label_new( "Panel 2" );
	gtk_widget_show( tab_label );
	gtk_box_pack_start_defaults( GTK_BOX( vbox ), label );

	gtk_paned_pack2( GTK_PANED( vpaned ), vbox, TRUE, FALSE ); 

	// show the main window and call the main loop

 	gtk_widget_show(window);

	timer = gtk_timeout_add (1000, paned_timeout, vpaned);

 	gtk_main ();
 
 	return(0);
}


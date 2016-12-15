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

static GtkWidget *notebook;

// function to create a new pixmap

static GtkWidget *
new_pixmap (char *file, GdkWindow *window, GdkColor *background)
{
  GdkPixmap *pmap;
  GdkBitmap *mask;
  GtkWidget *wpmap;

  pmap = gdk_pixmap_create_from_xpm(window, &mask, background, file);
  wpmap = gtk_pixmap_new(pmap, mask);
  gtk_pixmap_set_build_insensitive(GTK_PIXMAP(wpmap), 1);
  return( wpmap );
}

// ensure the popup is disabled before exiting main loop to avoid warnings

void
CloseDown( GtkWidget *widget, gpointer unused )
{
	// disable the popup menu

	gtk_notebook_popup_disable( GTK_NOTEBOOK( notebook ) );
	gtk_main_quit();
}

int main( int argc, char *argv[] )
{
 	GtkWidget *tab_label, *pixmap, *window, *hbox, *vbox, 
		*hbox_menu, *label;

 	gtk_init(&argc, &argv);

	// create a window
 
 	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 	gtk_signal_connect(GTK_OBJECT(window), "destroy", 
  	GTK_SIGNAL_FUNC (CloseDown), "WM destroy");
 	gtk_window_set_title(GTK_WINDOW(window), "Notebook");
 	gtk_widget_set_usize(GTK_WIDGET(window), 250, 100);
 	gtk_widget_show(window);

	// create a notebook and add it to the window

	notebook = gtk_notebook_new();
	gtk_notebook_popup_enable( GTK_NOTEBOOK( notebook ) );	
	gtk_notebook_set_tab_border( GTK_NOTEBOOK( notebook ), 2 );
	gtk_notebook_set_homogeneous_tabs( GTK_NOTEBOOK( notebook ), TRUE );
 	gtk_container_add(GTK_CONTAINER (window), notebook);

 	gtk_widget_show( notebook );

	// create first panel. vbox is the panel content

	vbox = gtk_vbox_new( FALSE, 10 );
	gtk_widget_show( vbox );

	// add a label to the vbox, this is what the panel displays, and
	// the user sees

	label = gtk_label_new( "Panel 1" );
	gtk_box_pack_start_defaults( GTK_BOX( vbox ), label );
	gtk_widget_show( label );

	// create the panel tab content, which will be a pixmap and label
	// managed by a horizontal box widget. First create the pixmap.

	pixmap = new_pixmap("test1.xpm", window->window,
    &window->style->bg[GTK_STATE_NORMAL]);
	gtk_widget_show( pixmap );

	// then create the label

	tab_label = gtk_label_new( "Panel 1" );
	gtk_widget_show( tab_label );

	// pack both of these into the horiontal box

	hbox = gtk_hbox_new( FALSE, 10 );
	gtk_box_pack_start_defaults( GTK_BOX( hbox ), pixmap );
	gtk_box_pack_start_defaults( GTK_BOX( hbox ), tab_label );

	// next create the menu item. This also consists of an image and
	// label packed into a horizontal box. We must create new instances
	// of each (the image, the box, and the label) since any given
	// widget can only be managed by one parent

	pixmap = new_pixmap("test1.xpm", window->window,
    &window->style->bg[GTK_STATE_NORMAL]);
	gtk_widget_show( pixmap );

	tab_label = gtk_label_new( "Panel 1" );
	gtk_widget_show( tab_label );

	hbox_menu = gtk_hbox_new( FALSE, 10 );
	gtk_box_pack_start_defaults( GTK_BOX( hbox_menu ), pixmap );
	gtk_box_pack_start_defaults( GTK_BOX( hbox_menu ), tab_label );

	// now that we have the panel content, the tab label, and the
	// popup menu item, call gtk_notebook_append_page_menu() to
	// add all three to the notebook.

	gtk_notebook_append_page_menu( GTK_NOTEBOOK( notebook ), 
		vbox, hbox, hbox_menu ); 

	// repeat the above steps for panels 2 and 3. First, panel 2.

	vbox = gtk_vbox_new( FALSE, 10 );

	gtk_widget_show( vbox );

	label = gtk_label_new( "Panel 2" );
	gtk_box_pack_start_defaults( GTK_BOX( vbox ), label );
	gtk_widget_show( label );

	pixmap = new_pixmap("test2.xpm", window->window,
    &window->style->bg[GTK_STATE_NORMAL]);
	gtk_widget_show( pixmap );

	tab_label = gtk_label_new( "Panel 2" );
	gtk_widget_show( tab_label );

	hbox = gtk_hbox_new( FALSE, 10 );
	gtk_box_pack_start_defaults( GTK_BOX( hbox ), pixmap );
	gtk_box_pack_start_defaults( GTK_BOX( hbox ), tab_label );

	pixmap = new_pixmap("test2.xpm", window->window,
    &window->style->bg[GTK_STATE_NORMAL]);
	gtk_widget_show( pixmap );

	tab_label = gtk_label_new( "Panel 2" );
	gtk_widget_show( tab_label );

	hbox_menu = gtk_hbox_new( FALSE, 10 );
	gtk_box_pack_start_defaults( GTK_BOX( hbox_menu ), pixmap );
	gtk_box_pack_start_defaults( GTK_BOX( hbox_menu ), tab_label );

	gtk_notebook_append_page_menu( GTK_NOTEBOOK( notebook ), 
		vbox, hbox, hbox_menu ); 

	// finally, do panel 3

	vbox = gtk_vbox_new( FALSE, 10 );

	gtk_widget_show( vbox );

	label = gtk_label_new( "Panel 3" );
	gtk_box_pack_start_defaults( GTK_BOX( vbox ), label );
	gtk_widget_show( label );

	pixmap = new_pixmap("test3.xpm", window->window,
    &window->style->bg[GTK_STATE_NORMAL]);
	gtk_widget_show( pixmap );

	tab_label = gtk_label_new( "Panel 3" );
	gtk_widget_show( tab_label );

	hbox = gtk_hbox_new( FALSE, 10 );
	gtk_box_pack_start_defaults( GTK_BOX( hbox ), pixmap );
	gtk_box_pack_start_defaults( GTK_BOX( hbox ), tab_label );

	pixmap = new_pixmap("test3.xpm", window->window,
    &window->style->bg[GTK_STATE_NORMAL]);
	gtk_widget_show( pixmap );

	tab_label = gtk_label_new( "Panel 3" );
	gtk_widget_show( tab_label );

	hbox_menu = gtk_hbox_new( FALSE, 10 );
	gtk_box_pack_start_defaults( GTK_BOX( hbox_menu ), pixmap );
	gtk_box_pack_start_defaults( GTK_BOX( hbox_menu ), tab_label );

	gtk_notebook_append_page_menu( GTK_NOTEBOOK( notebook ), 
		vbox, hbox, hbox_menu ); 

	gtk_notebook_set_tab_label_packing( GTK_NOTEBOOK(notebook), vbox,
		TRUE, FALSE, GTK_PACK_START );

 	gtk_main ();
 
 	return(0);
}


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
#include <stdio.h>

static GtkWidget *list;

static void
QuitCallback(GtkWidget *widget, GtkWidget *dialog_window)
{
	gtk_main_quit();
	exit( 0 );
}

static void
UndoSelectionCallback(GtkWidget *widget, GtkWidget *dialog_window)
{
	gtk_list_undo_selection(GTK_LIST(list));
}

static void
SelectItemCallback(GtkWidget *widget, GtkWidget *dialog_window)
{
	gtk_list_select_item(GTK_LIST(list), 2);
}

static void
UnselectItemCallback(GtkWidget *widget, GtkWidget *dialog_window)
{
	gtk_list_unselect_item(GTK_LIST(list), 2);
}

static GtkWidget*
new_pixmap (char *filename, GdkWindow *window, GdkColor *background)
{
  GtkWidget *wpixmap;
  GdkPixmap *pixmap;
  GdkBitmap *mask;

  pixmap = gdk_pixmap_create_from_xpm(window, &mask, background, filename);
  wpixmap = gtk_pixmap_new (pixmap, mask);

  return wpixmap;
}

main( int argc, char *argv[] )
{
	GtkWidget *button, *hbox, *dialog_window;
	GtkWidget *list_item;
	GtkWidget *box1, *box2, *box3, *label, *pixmap;
  GList *item_list;

	gtk_init( &argc, &argv );

	dialog_window = gtk_dialog_new();
 	gtk_window_position (GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);

	gtk_widget_show( dialog_window );

	hbox = gtk_hbox_new (FALSE, 0);
	gtk_container_add (GTK_CONTAINER (GTK_DIALOG (dialog_window)->vbox), 
		hbox);

  box1 = gtk_hbox_new (FALSE, 0);

	pixmap = new_pixmap ("test.xpm", dialog_window->window, 
    &dialog_window->style->bg[GTK_STATE_NORMAL]);
  gtk_box_pack_start (GTK_BOX (box1), pixmap, TRUE, TRUE, 0);
	pixmap = new_pixmap ("test.xpm", dialog_window->window, 
    &dialog_window->style->bg[GTK_STATE_NORMAL]);
  label = gtk_label_new( "List item 1" );
  gtk_box_pack_start (GTK_BOX (box1), label, TRUE, TRUE, 0);
  box2 = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (box2), pixmap, TRUE, TRUE, 0);
	pixmap = new_pixmap ("test.xpm", dialog_window->window, 
    &dialog_window->style->bg[GTK_STATE_NORMAL]);
  label = gtk_label_new( "List item 2" );
  gtk_box_pack_start (GTK_BOX (box2), label, TRUE, TRUE, 0);
  box3 = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (box3), pixmap, TRUE, TRUE, 0);
	pixmap = new_pixmap ("test.xpm", dialog_window->window, 
    &dialog_window->style->bg[GTK_STATE_NORMAL]);
  label = gtk_label_new( "List item 3" );
  gtk_box_pack_start (GTK_BOX (box3), label, TRUE, TRUE, 0);

 	list = gtk_list_new();
	gtk_list_set_selection_mode(GTK_LIST(list), GTK_SELECTION_SINGLE);
	gtk_list_set_selection_mode(GTK_LIST(list), GTK_SELECTION_BROWSE);
	gtk_list_set_selection_mode(GTK_LIST(list), GTK_SELECTION_MULTIPLE);
	gtk_list_set_selection_mode(GTK_LIST(list), GTK_SELECTION_EXTENDED);
	item_list = NULL;
	list_item = gtk_list_item_new();
	gtk_container_add( GTK_CONTAINER( list_item ), box1 );
 	item_list = g_list_append (item_list, list_item);
	list_item = gtk_list_item_new();
	gtk_container_add( GTK_CONTAINER( list_item ), box2 );
 	item_list = g_list_append (item_list, list_item);
	list_item = gtk_list_item_new();
	gtk_container_add( GTK_CONTAINER( list_item ), box3 );
 	item_list = g_list_append (item_list, list_item);
	list_item = gtk_list_item_new_with_label ("Fred Flintstone");
 	item_list = g_list_append (item_list, list_item);
	list_item = gtk_list_item_new_with_label ("Wilma Flintstone");
 	item_list = g_list_append (item_list, list_item);
	list_item = gtk_list_item_new_with_label ("Barney Rubble");
 	item_list = g_list_append (item_list, list_item);
	list_item = gtk_list_item_new_with_label ("Betty Rubble");
 	item_list = g_list_append (item_list, list_item);
	gtk_list_insert_items( GTK_LIST(list), item_list, 0 );

 	gtk_box_pack_start (GTK_BOX (hbox), list, FALSE, FALSE, 0);

 	button = gtk_button_new_with_label ("Select");
 	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area), 
		button, TRUE, TRUE, 0);
 	gtk_signal_connect (GTK_OBJECT (button), "clicked", 
		GTK_SIGNAL_FUNC(SelectItemCallback), dialog_window);

 	button = gtk_button_new_with_label ("Unselect");
 	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area), 
		button, TRUE, TRUE, 0);
 	gtk_signal_connect (GTK_OBJECT (button), "clicked", 
		GTK_SIGNAL_FUNC(UnselectItemCallback), dialog_window);

 	button = gtk_button_new_with_label ("Undo Selection");
 	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area), 
		button, TRUE, TRUE, 0);
 	gtk_signal_connect (GTK_OBJECT (button), "clicked", 
		GTK_SIGNAL_FUNC(UndoSelectionCallback), dialog_window);

 	button = gtk_button_new_with_label ("Quit");
 	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area), 
		button, TRUE, TRUE, 0);
 	gtk_signal_connect (GTK_OBJECT (button), "clicked", 
		GTK_SIGNAL_FUNC(QuitCallback), dialog_window);
 	gtk_widget_show_all (dialog_window);
	gtk_main();
}

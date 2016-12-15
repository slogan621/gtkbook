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

static GtkWidget*
make_tree (GtkWidget *window)
{
  GtkWidget *list, *node;
  GList *item_list = NULL;

  list = gtk_list_new();
  gtk_widget_show( list );

  node = gtk_list_item_new_with_label("Great White Shark");
  item_list = g_list_append( item_list, node );
  node = gtk_list_item_new_with_label("Blue Banded Goby");
  item_list = g_list_append( item_list, node );
  node = gtk_list_item_new_with_label("Grunion");
  item_list = g_list_append( item_list, node );
  node = gtk_list_item_new_with_label("Stonefish");
  item_list = g_list_append( item_list, node );
  node = gtk_list_item_new_with_label("Leopard Shark");
  item_list = g_list_append( item_list, node );
  node = gtk_list_item_new_with_label("Thornback");
  item_list = g_list_append( item_list, node );
  node = gtk_list_item_new_with_label("Ochre Star");
  item_list = g_list_append( item_list, node );
  node = gtk_list_item_new_with_label("Sea Pen");
  item_list = g_list_append( item_list, node );
  node = gtk_list_item_new_with_label("Pacific Octopus");
  item_list = g_list_append( item_list, node );
  node = gtk_list_item_new_with_label("Sea Wasp");
  item_list = g_list_append( item_list, node );
  node = gtk_list_item_new_with_label("Sea Urchin");
  item_list = g_list_append( item_list, node );
  node = gtk_list_item_new_with_label("Gray Whale");
  item_list = g_list_append( item_list, node );
  node = gtk_list_item_new_with_label("Sea Otter");
  item_list = g_list_append( item_list, node );
  node = gtk_list_item_new_with_label("Bottlenose Dolphin");
  item_list = g_list_append( item_list, node );
  node = gtk_list_item_new_with_label("Killer Whale");
  item_list = g_list_append( item_list, node );
  gtk_list_insert_items( GTK_LIST( list ), item_list, 0 );
  
  return list;
}
  
main( argc, argv )
int argc;
char *argv[];
{
  GtkWidget *window, *tree, *vbox;
  
  gtk_init( &argc, &argv );
  
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_show( window );
  gtk_window_position(GTK_WINDOW (window), GTK_WIN_POS_CENTER);
  
  gtk_signal_connect(GTK_OBJECT (window), "destroy",
    GTK_SIGNAL_FUNC(gtk_widget_destroy), &window);
  
  gtk_window_set_title(GTK_WINDOW (window), "GtkTree Sample");
  gtk_container_border_width(GTK_CONTAINER (window), 0);
  
  tree = make_tree(window);
  
  vbox = gtk_vbox_new( FALSE, 0 );
  gtk_container_add(GTK_CONTAINER (window), vbox);
  
  gtk_box_pack_start( GTK_BOX( vbox ), tree, FALSE, FALSE, 0 );
  gtk_widget_show_all( vbox );
  
  gtk_main();
}

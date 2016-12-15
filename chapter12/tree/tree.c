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
  GtkWidget *root, *subtree, *node, *node1, *node2, *node3;

  root = gtk_tree_new();
  gtk_widget_show( root );

  node1 = node = gtk_tree_item_new_with_label("Fish");
  gtk_tree_append(GTK_TREE(root), node);
  gtk_widget_show(node);	

  node2 = node = gtk_tree_item_new_with_label("Invertebrates");
  gtk_tree_append(GTK_TREE(root), node);
  gtk_widget_show(node);	

  node3 = node = gtk_tree_item_new_with_label("Mammals");
  gtk_tree_append(GTK_TREE(root), node);
  gtk_widget_show(node);	

  subtree = gtk_tree_new();
  gtk_widget_show( subtree );

  node = gtk_tree_item_new_with_label("Great White Shark");
  gtk_tree_append(GTK_TREE(subtree), node);
  gtk_widget_show(node);	

  node = gtk_tree_item_new_with_label("Blue Banded Goby");
  gtk_tree_append(GTK_TREE(subtree), node);
  gtk_widget_show(node);	

  node = gtk_tree_item_new_with_label("Grunion");
  gtk_tree_append(GTK_TREE(subtree), node);
  gtk_widget_show(node);	

  node = gtk_tree_item_new_with_label("Stonefish");
  gtk_tree_append(GTK_TREE(subtree), node);
  gtk_widget_show(node);	

  node = gtk_tree_item_new_with_label("Leopard Shark");
  gtk_tree_append(GTK_TREE(subtree), node);
  gtk_widget_show(node);	

  node = gtk_tree_item_new_with_label("Thornback");
  gtk_tree_append(GTK_TREE(subtree), node);
  gtk_widget_show(node);	

  gtk_tree_item_set_subtree(GTK_TREE_ITEM( node1 ), subtree);

  subtree = gtk_tree_new();
  gtk_widget_show( subtree );

  node = gtk_tree_item_new_with_label("Ochre Star");
  gtk_tree_append(GTK_TREE(subtree), node);
  gtk_widget_show(node);	

  node = gtk_tree_item_new_with_label("Sea Pen");
  gtk_tree_append(GTK_TREE(subtree), node);
  gtk_widget_show(node);	

  node = gtk_tree_item_new_with_label("Pacific Octopus");
  gtk_tree_append(GTK_TREE(subtree), node);
  gtk_widget_show(node);	

  node = gtk_tree_item_new_with_label("Sea Wasp");
  gtk_tree_append(GTK_TREE(subtree), node);
  gtk_widget_show(node);	

  node = gtk_tree_item_new_with_label("Sea Urchin");
  gtk_tree_append(GTK_TREE(subtree), node);
  gtk_widget_show(node);	

  gtk_tree_item_set_subtree(GTK_TREE_ITEM( node2 ), subtree);

  subtree = gtk_tree_new();
  gtk_widget_show( subtree );

  node = gtk_tree_item_new_with_label("Gray Whale");
  gtk_tree_append(GTK_TREE(subtree), node);
  gtk_widget_show(node);	

  node = gtk_tree_item_new_with_label("Sea Otter");
  gtk_tree_append(GTK_TREE(subtree), node);
  gtk_widget_show(node);	

  node = gtk_tree_item_new_with_label("Bottlenose Dolphin");
  gtk_tree_append(GTK_TREE(subtree), node);
  gtk_widget_show(node);	

  node = gtk_tree_item_new_with_label("Killer Whale");
  gtk_tree_append(GTK_TREE(subtree), node);
  gtk_widget_show(node);	

  gtk_tree_item_set_subtree(GTK_TREE_ITEM( node3 ), subtree);

  return root;
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

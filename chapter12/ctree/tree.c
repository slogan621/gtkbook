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

void        
ChangeFocusRowExpansion(GtkCTree *ctree, GtkCTreeExpansionType expansion, 
  gpointer user_data)
{
	printf( "Hello World\n" );
}

static GtkWidget *
make_tree ( void )
{
  GtkWidget *root;
  GtkCTreeNode *parent, *node;
  gchar *text[1];

  // create the root node of the tree.

  root = gtk_ctree_new( 1, 0 );

  // Fish

  text[0] = "Fish";
  parent = gtk_ctree_insert_node(GTK_CTREE(root),
    NULL, NULL, text, 5, NULL, NULL, NULL, NULL, FALSE, TRUE);

  text[0] = "Dangerous";
  node = gtk_ctree_insert_node(GTK_CTREE(root),
    parent, NULL, text, 5, NULL, NULL, NULL, NULL, FALSE, TRUE);

  text[0] = "Great White Shark";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Stonefish";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node,  NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Non-Dangerous";
  node = gtk_ctree_insert_node(GTK_CTREE(root),
    parent,  NULL, text, 5, NULL, NULL, NULL, NULL, FALSE, TRUE);

  text[0] = "Blue Banded Goby";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Grunion";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node,  NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Leopard Shark";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Thornback";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  // Invertebrates

  text[0] = "Invertebrates";
  parent = gtk_ctree_insert_node(GTK_CTREE(root),
    NULL, NULL, text, 5, NULL, NULL, NULL, NULL, FALSE, TRUE);

  text[0] = "Dangerous";
  node = gtk_ctree_insert_node(GTK_CTREE(root),
    parent, NULL, text, 5, NULL, NULL, NULL, NULL, FALSE, TRUE);

  text[0] = "Sea Wasp";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Non-Dangerous";
  node = gtk_ctree_insert_node(GTK_CTREE(root),
    parent, NULL, text, 5, NULL, NULL, NULL, NULL, FALSE, TRUE);

  text[0] = "Ochre Star";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Sea Pen";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Pacific Octopus";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Sea Urchin";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  // Mammals

  text[0] = "Mammals";
  parent = gtk_ctree_insert_node(GTK_CTREE(root),
    NULL, NULL, text, 5, NULL, NULL, NULL, NULL, FALSE, TRUE);

  text[0] = "Dangerous";
  node = gtk_ctree_insert_node(GTK_CTREE(root),
    parent, NULL, text, 5, NULL, NULL, NULL, NULL, FALSE, TRUE);

  text[0] = "Killer Whale";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Non-Dangerous";
  node = gtk_ctree_insert_node(GTK_CTREE(root),
    parent, NULL, text, 5, NULL, NULL, NULL, NULL, FALSE, TRUE);

  text[0] = "Gray Whale";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Sea Otter";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Bottlenose Dolphin";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  gtk_signal_connect(GTK_OBJECT (root), "change_focus_row_expansion",
    GTK_SIGNAL_FUNC(ChangeFocusRowExpansion), root);
  return root;
}

main( argc, argv )
int argc;
char *argv[];
{
  GtkWidget *window, *tree;

  gtk_init( &argc, &argv );

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_usize( window, 200, -1 );

  gtk_signal_connect(GTK_OBJECT (window), "destroy",
    GTK_SIGNAL_FUNC(gtk_widget_destroy), &window);

  gtk_window_set_title(GTK_WINDOW (window), "GtkCTree Sample");
  gtk_container_border_width(GTK_CONTAINER (window), 0);

  tree = make_tree();

  gtk_container_add(GTK_CONTAINER(window), tree);
  gtk_window_position(GTK_WINDOW (window), GTK_WIN_POS_CENTER);

  gtk_widget_show_all( window );

  gtk_main();
}

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
  gchar *text[2];
  gchar *titles[2];
  int i;

  // create the root node of the tree.

  titles[0] = "Animal";
  titles[1] = "Habitat";
  root = gtk_ctree_new_with_titles( 2, 0, titles );
#if 1
  for ( i = 0; i < 2; i++ )
  	gtk_clist_set_column_auto_resize(GTK_CLIST(root), i, TRUE );
#endif
  gtk_ctree_set_expander_style(GTK_CTREE(root), GTK_CTREE_EXPANDER_CIRCULAR );

  // Fish

  text[0] = "Fish";
  text[1] = "";
  parent = gtk_ctree_insert_node(GTK_CTREE(root),
    NULL, NULL, text, 5, NULL, NULL, NULL, NULL, FALSE, TRUE);

  text[0] = "Dangerous";
  text[1] = "";
  node = gtk_ctree_insert_node(GTK_CTREE(root),
    parent, NULL, text, 5, NULL, NULL, NULL, NULL, FALSE, TRUE);

  text[0] = "Great White Shark";
  text[1] = "Open ocean";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Stonefish";
  text[1] = "Intertidal";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node,  NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Non-Dangerous";
  text[1] = "";
  node = gtk_ctree_insert_node(GTK_CTREE(root),
    parent,  NULL, text, 5, NULL, NULL, NULL, NULL, FALSE, TRUE);

  text[0] = "Blue Banded Goby";
  text[1] = "Coastal waters";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Grunion";
  text[1] = "Open ocean";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node,  NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Leopard Shark";
  text[1] = "Bays and estuaries";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Thornback";
  text[1] = "Coastal waters, sand";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  // Invertebrates

  text[0] = "Invertebrates";
  text[1] = "";
  parent = gtk_ctree_insert_node(GTK_CTREE(root),
    NULL, NULL, text, 5, NULL, NULL, NULL, NULL, FALSE, TRUE);

  text[0] = "Dangerous";
  text[1] = "";
  node = gtk_ctree_insert_node(GTK_CTREE(root),
    parent, NULL, text, 5, NULL, NULL, NULL, NULL, FALSE, TRUE);

  text[0] = "Sea Wasp";
  text[1] = "Sandy bottoms, coastal";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Non-Dangerous";
  text[1] = "";
  node = gtk_ctree_insert_node(GTK_CTREE(root),
    parent, NULL, text, 5, NULL, NULL, NULL, NULL, FALSE, TRUE);

  text[0] = "Ochre Star";
  text[1] = "Piers, tide pools";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Sea Pen";
  text[1] = "Sandy bottoms, coastal";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Pacific Octopus";
  text[1] = "Tidepools, tidal waters";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Sea Urchin";
  text[1] = "Coastal waters, kelp beds";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  // Mammals

  text[0] = "Mammals";
  text[1] = "";
  parent = gtk_ctree_insert_node(GTK_CTREE(root),
    NULL, NULL, text, 5, NULL, NULL, NULL, NULL, FALSE, TRUE);

  text[0] = "Dangerous";
  text[1] = "";
  node = gtk_ctree_insert_node(GTK_CTREE(root),
    parent, NULL, text, 5, NULL, NULL, NULL, NULL, FALSE, TRUE);

  text[0] = "Killer Whale";
  text[1] = "Open oceans, bays";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Non-Dangerous";
  text[1] = "";
  node = gtk_ctree_insert_node(GTK_CTREE(root),
    parent, NULL, text, 5, NULL, NULL, NULL, NULL, FALSE, TRUE);

  text[0] = "Gray Whale";
  text[1] = "Open oceans";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Sea Otter";
  text[1] = "Tidal waters, kelp beds";
  gtk_ctree_insert_node(GTK_CTREE(root),
    node, NULL, text, 5, NULL, NULL, NULL, NULL, TRUE, TRUE);

  text[0] = "Bottlenose Dolphin";
  text[1] = "Open ocean, shallows";
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
//    gtk_widget_set_usize( window, 200, -1 );

    gtk_signal_connect(GTK_OBJECT (window), "destroy",
      GTK_SIGNAL_FUNC(gtk_widget_destroy), &window);

    gtk_window_set_title(GTK_WINDOW (window), "GtkTree Sample");
    gtk_container_border_width(GTK_CONTAINER (window), 0);

    tree = make_tree();

    gtk_container_add(GTK_CONTAINER(window), tree);
    gtk_window_position(GTK_WINDOW (window), GTK_WIN_POS_CENTER);

    gtk_widget_show_all( window );

    gtk_main();
}

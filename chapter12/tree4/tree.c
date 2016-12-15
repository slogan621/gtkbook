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

// data structure to hold information about our colors
typedef struct _colorent {
  unsigned char red;      // red component of rgb value
  unsigned char green;    // green component of rgb value
  unsigned char blue;     // blue component of rgb value
  char *label;            // label to display for tree item
  char *filename;         // filename that stores the image
} colorent;

// table describing the colors we will be displaying

colorent colortable[] = {
{ 205,  92,  92, "indian red", "indianred.xpm"},
{ 255,  69,   0, "orange red", "orangered.xpm"},
{ 255,   0,   0, "red", "red.xpm"},
{ 219, 112, 147, "pale violet red", "palevioletred.xpm"},
{ 199,  21, 133, "medium violet red", "mediumvioletred.xpm"},
{ 208,  32, 144, "violet red", "violetred.xpm"},
{ 255, 106, 106, "IndianRed1", "indianred1.xpm"},
{ 238,  99,  99, "IndianRed2", "indianred2.xpm"},
{ 255,  69,   0, "OrangeRed1", "orangered1.xpm"},
{ 238,  64,   0, "OrangeRed2", "orangered2.xpm"},
{ 255,   0,   0, "red1", "red1.xpm"},
{ 238,   0,   0, "red2", "red2.xpm"},
{ 255, 130, 171, "PaleVioletRed1", "palevioletred1.xpm"},
{ 238, 121, 159, "PaleVioletRed2", "palevioletred2.xpm"},
{ 255,  62, 150, "VioletRed1", "violetred1.xpm"},
{ 238,  58, 140, "VioletRed2", "violetred2.xpm"},
{ 139,   0,   0, "dark red", "darkred.xpm"},
};

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

static GtkWidget *
make_tree(GtkWidget *window)
{
  GtkWidget *hbox, *label, *root, *image, *subtree, *node, *node_colors;
  int i;
   // create the root node of the tree.
  root = gtk_tree_new();
  gtk_widget_show( root );
  node_colors = node = gtk_tree_item_new_with_label("Colors");
  gtk_tree_append(GTK_TREE(root), node_colors);
  gtk_widget_show(node_colors);
  subtree = gtk_tree_new();
  gtk_widget_show( subtree );
  gtk_tree_item_set_subtree(GTK_TREE_ITEM( node_colors ), subtree);
  for ( i = 0; i < sizeof( colortable ) / sizeof( colorent ); i++ ) {
#if 1
    node = gtk_tree_item_new();
    image = new_pixmap(colortable[i].filename,
      window->window, &window->style->bg[GTK_STATE_NORMAL]);
	  label = gtk_label_new( colortable[i].label );
	  hbox = gtk_hbox_new( FALSE, 0 );
	  gtk_box_set_spacing( GTK_BOX( hbox ), 10 );
    gtk_container_add(GTK_CONTAINER(node), hbox);
    gtk_box_pack_start( GTK_BOX( hbox ), image, FALSE, FALSE, 0 );
	  gtk_box_pack_start( GTK_BOX( hbox ), label, FALSE, FALSE, 0 );
#else
    node = gtk_tree_item_new_with_label(colortable[i].filename);
#endif
    gtk_tree_append(GTK_TREE(subtree), node);
    gtk_widget_show_all(node);
  }
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

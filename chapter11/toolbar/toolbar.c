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

/*
 * GtkToolBar
 */

static GtkWidget*
new_pixmap (char *filename, GdkWindow *window, GdkColor *background)
{
  GtkWidget *wpixmap;
  GdkPixmap *pixmap;
  GdkBitmap *mask;

  pixmap = gdk_pixmap_create_from_xpm (window, &mask,
    background, filename);
  wpixmap = gtk_pixmap_new (pixmap, mask);

  return wpixmap;
}

static void
button_callback(GtkWidget *widget, gpointer data)
{
	printf( "%s\n" , (char *) data );
}

static GtkWidget*
make_toolbar (GtkWidget *window)
{
  GtkWidget *toolbar;

  toolbar = gtk_toolbar_new (GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH);

  gtk_toolbar_append_item (GTK_TOOLBAR (toolbar), "Go", "Green Means Go", NULL,
    new_pixmap ("go.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
   (GtkSignalFunc) button_callback, "Go button was pressed" );
  gtk_toolbar_append_item (GTK_TOOLBAR (toolbar), "Caution", 
    "Yellow Means Caution", NULL,
	  new_pixmap ("caution.xpm", window->window, 
    &window->style->bg[GTK_STATE_NORMAL]),
	  (GtkSignalFunc) button_callback, "Caution button was pressed" );
  gtk_toolbar_append_item (GTK_TOOLBAR (toolbar), "Stop", "Red Means Stop", 
    NULL, new_pixmap ("stop.xpm", window->window, 
    &window->style->bg[GTK_STATE_NORMAL]), (GtkSignalFunc) button_callback, 
    "Stop button was pressed" );
    return toolbar;
}

main( argc, argv )
int argc;
char *argv[];
{
  GtkWidget *window, *toolbar, *vbox;

  gtk_init( &argc, &argv );

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_show( window );
  gtk_window_position (GTK_WINDOW (window), GTK_WIN_POS_CENTER);

  gtk_signal_connect (GTK_OBJECT (window), "destroy",
    GTK_SIGNAL_FUNC(gtk_widget_destroy), &window);

  gtk_window_set_title (GTK_WINDOW (window), "GtkToolbar Sample");
  gtk_container_border_width (GTK_CONTAINER (window), 0);

  toolbar = make_toolbar(window);

  vbox = gtk_vbox_new( FALSE, 0 );
  gtk_container_add (GTK_CONTAINER (window), vbox);

  gtk_box_pack_start( GTK_BOX( vbox ), toolbar, FALSE, FALSE, 0 );
  gtk_widget_show_all( vbox );

  gtk_main();
}

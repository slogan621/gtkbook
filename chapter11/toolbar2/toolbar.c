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
set_toolbar_horizontal (GtkWidget *widget, gpointer data)
{
  printf( "gtk_toolbar_set_orientation (GTK_TOOLBAR (data), GTK_ORIENTATION_HORIZONTAL);\n" );
  gtk_toolbar_set_orientation (GTK_TOOLBAR (data), GTK_ORIENTATION_HORIZONTAL);
}

static void
set_toolbar_vertical (GtkWidget *widget, gpointer data)
{
  printf( "gtk_toolbar_set_orientation (GTK_TOOLBAR (data), GTK_ORIENTATION_VERTICAL);\n" );
  gtk_toolbar_set_orientation (GTK_TOOLBAR (data), GTK_ORIENTATION_VERTICAL);
}

static void
set_toolbar_icons (GtkWidget *widget, gpointer data)
{
  printf( "gtk_toolbar_set_style (GTK_TOOLBAR (data), GTK_TOOLBAR_ICONS);\n" );
  gtk_toolbar_set_style (GTK_TOOLBAR (data), GTK_TOOLBAR_ICONS);
}

static void
set_toolbar_text (GtkWidget *widget, gpointer data)
{
  printf( "gtk_toolbar_set_style (GTK_TOOLBAR (data), GTK_TOOLBAR_TEXT);\n" );
  gtk_toolbar_set_style (GTK_TOOLBAR (data), GTK_TOOLBAR_TEXT);
}

static void
set_toolbar_both (GtkWidget *widget, gpointer data)
{
  printf( "gtk_toolbar_set_style (GTK_TOOLBAR (data), GTK_TOOLBAR_BOTH);\n" );
  gtk_toolbar_set_style (GTK_TOOLBAR (data), GTK_TOOLBAR_BOTH);
}

static void
set_toolbar_small_space (GtkWidget *widget, gpointer data)
{
  printf( "gtk_toolbar_set_space_size (GTK_TOOLBAR (data), 5);\n" );
  gtk_toolbar_set_space_size (GTK_TOOLBAR (data), 5);
}

static void
set_toolbar_big_space (GtkWidget *widget, gpointer data)
{
  printf( "gtk_toolbar_set_space_size (GTK_TOOLBAR (data), 10);\n" );
  gtk_toolbar_set_space_size (GTK_TOOLBAR (data), 10);
}

static void
set_toolbar_enable (GtkWidget *widget, gpointer data)
{
  printf( "gtk_toolbar_set_tooltips (GTK_TOOLBAR (data), TRUE);\n" ); 
  gtk_toolbar_set_tooltips (GTK_TOOLBAR (data), TRUE);
}

static void
set_toolbar_disable (GtkWidget *widget, gpointer data)
{
  printf( "gtk_toolbar_set_tooltips (GTK_TOOLBAR (data), FALSE);\n" );
  gtk_toolbar_set_tooltips (GTK_TOOLBAR (data), FALSE);
}

static void
set_toolbar_borders (GtkWidget *widget, gpointer data)
{
  printf( "gtk_toolbar_set_button_relief (GTK_TOOLBAR (data), GTK_RELIEF_NORMAL);\n" );
  gtk_toolbar_set_button_relief (GTK_TOOLBAR (data), GTK_RELIEF_NORMAL);
}

static void
set_toolbar_borderless (GtkWidget *widget, gpointer data)
{
  printf( "gtk_toolbar_set_button_relief (GTK_TOOLBAR (data), GTK_RELIEF_NONE);\n" );
  gtk_toolbar_set_button_relief (GTK_TOOLBAR (data), GTK_RELIEF_NONE);
}

static void
set_toolbar_space_style_empty (GtkWidget *widget, gpointer data)
{
  printf( "gtk_toolbar_set_space_style (GTK_TOOLBAR (data), GTK_TOOLBAR_SPACE_EMPTY);\n" );
  gtk_toolbar_set_space_style (GTK_TOOLBAR (data), GTK_TOOLBAR_SPACE_EMPTY);
}

static void
set_toolbar_space_style_line (GtkWidget *widget, gpointer data)
{
  printf( "gtk_toolbar_set_space_style (GTK_TOOLBAR (data), GTK_TOOLBAR_SPACE_LINE);\n" );
  gtk_toolbar_set_space_style (GTK_TOOLBAR (data), GTK_TOOLBAR_SPACE_LINE);
}

static void
create_toolbar (void)
{
  static GtkWidget *window = NULL;
  GtkWidget *toolbar;
  GtkWidget *entry;

  if (!window) {
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "Toolbar test");
    gtk_window_set_policy (GTK_WINDOW (window), FALSE, TRUE, TRUE);

    gtk_signal_connect (GTK_OBJECT (window), "destroy",
      GTK_SIGNAL_FUNC (gtk_widget_destroyed), &window);

    gtk_container_set_border_width (GTK_CONTAINER (window), 0);
    gtk_widget_realize (window);

    toolbar = gtk_toolbar_new (GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH);
    gtk_toolbar_set_button_relief (GTK_TOOLBAR (toolbar), GTK_RELIEF_NONE);

    gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
		  "Horizontal", "Horizontal toolbar layout", "Toolbar/Horizontal",
//      new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
			NULL, (GtkSignalFunc) set_toolbar_horizontal, toolbar);
    gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
		  "Vertical", "Vertical toolbar layout", "Toolbar/Vertical",
//      new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
      NULL, (GtkSignalFunc) set_toolbar_vertical, toolbar);

    gtk_toolbar_append_space (GTK_TOOLBAR(toolbar));

    gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
      "Icons", "Only show toolbar icons", "Toolbar/IconsOnly",
//      new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
			NULL, (GtkSignalFunc) set_toolbar_icons, toolbar);
    gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
		  "Text", "Only show toolbar text", "Toolbar/TextOnly",
//      new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
      NULL, (GtkSignalFunc) set_toolbar_text, toolbar);
    gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
	    "Both", "Show toolbar icons and text", "Toolbar/Both",
//      new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
		  NULL, (GtkSignalFunc) set_toolbar_both, toolbar);

    gtk_toolbar_append_space (GTK_TOOLBAR (toolbar));

    entry = gtk_entry_new ();

    gtk_toolbar_append_widget (GTK_TOOLBAR (toolbar), entry, 
      "This is an unusable GtkEntry ;)", "Hey don't click me!!!");

    gtk_toolbar_append_space (GTK_TOOLBAR (toolbar));

    gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
		  "Small", "Use small spaces", "Toolbar/Small",
//        new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
			NULL, (GtkSignalFunc) set_toolbar_small_space, toolbar);
    gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
		  "Big", "Use big spaces", "Toolbar/Big",
//      new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
		  NULL, (GtkSignalFunc) set_toolbar_big_space, toolbar);

    gtk_toolbar_append_space (GTK_TOOLBAR (toolbar));

    gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
		  "Enable", "Enable tooltips", NULL,
//      new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
			NULL, (GtkSignalFunc) set_toolbar_enable, toolbar);
    gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
		  "Disable", "Disable tooltips", NULL,
//      new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
			NULL, (GtkSignalFunc) set_toolbar_disable, toolbar);

    gtk_toolbar_append_space (GTK_TOOLBAR (toolbar));

    gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
		  "Borders", "Show Borders", NULL,
//		  new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
			NULL, (GtkSignalFunc) set_toolbar_borders, toolbar);
    gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
		  "Borderless", "Hide Borders", NULL,
//      new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
			NULL, (GtkSignalFunc) set_toolbar_borderless, toolbar);

    gtk_toolbar_append_space (GTK_TOOLBAR (toolbar));
      
    gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
		  "Empty", "Empty spaces", NULL,
//      new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
			NULL, (GtkSignalFunc) set_toolbar_space_style_empty, toolbar);
    gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
		  "Lines", "Lines in spaces", NULL,
//      new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
			NULL, (GtkSignalFunc) set_toolbar_space_style_line, toolbar);

    gtk_container_add (GTK_CONTAINER (window), toolbar);
  }

  if (!GTK_WIDGET_VISIBLE (window))
    gtk_widget_show_all (window);
  else
    gtk_widget_destroy (window);
}

static GtkWidget*
make_toolbar (GtkWidget *window)
{
  GtkWidget *toolbar;

  if (!GTK_WIDGET_REALIZED (window))
    gtk_widget_realize (window);

  toolbar = gtk_toolbar_new (GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH);
  gtk_toolbar_set_button_relief (GTK_TOOLBAR (toolbar), GTK_RELIEF_NONE);

  gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
    "Horizontal", "Horizontal toolbar layout", NULL,
    new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
    (GtkSignalFunc) set_toolbar_horizontal, toolbar);
  gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
    "Vertical", "Vertical toolbar layout", NULL,
    new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
    (GtkSignalFunc) set_toolbar_vertical, toolbar);

  gtk_toolbar_append_space (GTK_TOOLBAR(toolbar));

  gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
    "Icons", "Only show toolbar icons", NULL,
    new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
    (GtkSignalFunc) set_toolbar_icons, toolbar);
  gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
    "Text", "Only show toolbar text", NULL,
    new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
    (GtkSignalFunc) set_toolbar_text, toolbar);
  gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
    "Both", "Show toolbar icons and text", NULL,
    new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
    (GtkSignalFunc) set_toolbar_both, toolbar);

  gtk_toolbar_append_space (GTK_TOOLBAR (toolbar));

  gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
    "Small", "Use small spaces", NULL,
    new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
    (GtkSignalFunc) set_toolbar_small_space, toolbar);
  gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
    "Big", "Use big spaces", "Toolbar/Big",
    new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
    (GtkSignalFunc) set_toolbar_big_space, toolbar);

  gtk_toolbar_append_space (GTK_TOOLBAR (toolbar));

  gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
    "Enable", "Enable tooltips", NULL,
    new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
    (GtkSignalFunc) set_toolbar_enable, toolbar);
  gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
    "Disable", "Disable tooltips", NULL,
    new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
    (GtkSignalFunc) set_toolbar_disable, toolbar);

  gtk_toolbar_append_space (GTK_TOOLBAR (toolbar));
 
  gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
    "Borders", "Show Borders", NULL,
    new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
    (GtkSignalFunc) set_toolbar_borders, toolbar);
  gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
    "Borderless", "Hide Borders", NULL,
    new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
    (GtkSignalFunc) set_toolbar_borderless, toolbar);

  gtk_toolbar_append_space (GTK_TOOLBAR (toolbar));

  gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
    "Empty", "Empty spaces", NULL,
    new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
    (GtkSignalFunc) set_toolbar_space_style_empty, toolbar);
  gtk_toolbar_append_item (GTK_TOOLBAR (toolbar),
    "Lines", "Lines in spaces", NULL,
    new_pixmap ("test.xpm", window->window, &window->style->bg[GTK_STATE_NORMAL]),
    (GtkSignalFunc) set_toolbar_space_style_line, toolbar);

  return toolbar;
}

main( argc, argv )
int argc;
char *argv[];
{
  GtkWidget *window, *toolbar;

  gtk_init( &argc, &argv );

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_position (GTK_WINDOW (window), GTK_WIN_POS_MOUSE);

  gtk_signal_connect (GTK_OBJECT (window), "destroy",
    GTK_SIGNAL_FUNC(gtk_widget_destroy), &window);

  gtk_window_set_title (GTK_WINDOW (window), "GtkToolbar Demo");
  gtk_container_border_width (GTK_CONTAINER (window), 0);

	toolbar = make_toolbar(window);

 	gtk_container_add (GTK_CONTAINER (window), toolbar);
	gtk_widget_show_all(window);

	gtk_main();
}

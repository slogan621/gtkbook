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
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

static GdkPixmap *pmap;
static GdkGC *gc;
GtkObject *adj1, *adj2;

#define RAND( x ) ((int) (((float) random() / (RAND_MAX - 1)) * x))

void
BuildPixmap( GdkWindow * window )
{
  int i, j;
  GdkColor color;

  pmap = gdk_pixmap_new( window, 512, 512, -1 ); 
  for ( i = 0; i < 32; i++ )
    for ( j = 0; j < 32; j++ ) {
      color.red = RAND( 65535 );
      color.green = RAND( 65535 );
      color.blue = RAND( 65535 );
      gdk_color_alloc(gdk_colormap_get_system (), &color);
      gdk_gc_set_foreground( gc, &color );
      gdk_draw_rectangle((GdkDrawable *) pmap, gc,
        TRUE, i * 16, j * 16, 16, 16 );
  }
}

void
SetAdjustments( GtkObject *adj1, GtkObject *adj2, int width, int height )
{
  GTK_ADJUSTMENT( adj1 )->lower = 0.0;
  GTK_ADJUSTMENT( adj1 )->upper = (float) height - 16.0;
  GTK_ADJUSTMENT( adj1 )->step_increment = 16.0;
  GTK_ADJUSTMENT( adj1 )->page_increment = 32.0;
  GTK_ADJUSTMENT( adj1 )->page_size = 16.0;
  GTK_ADJUSTMENT( adj1 )->value = 0.0;

  GTK_ADJUSTMENT( adj2 )->lower = 0.0;
  GTK_ADJUSTMENT( adj2 )->upper = (float) width - 16.0;
  GTK_ADJUSTMENT( adj2 )->step_increment = 16.0;
  GTK_ADJUSTMENT( adj2 )->page_increment = 32.0;
  GTK_ADJUSTMENT( adj2 )->page_size = 16.0;
  GTK_ADJUSTMENT( adj2 )->value = 0.0;
}

static void
AdjustmentChanged(GtkAdjustment *w, gpointer data)
{
  GtkWidget *drawing = (GtkWidget *) data;
  int x = GTK_ADJUSTMENT(adj2)->value;
  int y = GTK_ADJUSTMENT(adj1)->value;

  gdk_draw_pixmap(drawing->window, gc, pmap, x, y, 0, 0, 256, 192);
}

main( argc, argv )
int argc;
char *argv[];
{
  GtkWidget *window, *hsb, *vsb, *vbox, *hbox, *drawing;
  int width, height, x, y, depth;
  int hsbwidth, hsbheight, vsbwidth, vsbheight;

  gtk_init( &argc, &argv );

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_position(GTK_WINDOW(window), GTK_WIN_POS_MOUSE);
  gtk_widget_set_usize(window, 256, 192);
  gtk_window_set_policy(GTK_WINDOW( window ), FALSE, FALSE, TRUE); 
  gtk_widget_show( window );

  gtk_signal_connect(GTK_OBJECT(window), "destroy",
    GTK_SIGNAL_FUNC(gtk_widget_destroyed), &window);

  gtk_window_set_title(GTK_WINDOW (window), "GtkAdjustment Demo");

  vbox = gtk_vbox_new( FALSE, 0 );
  gtk_container_add( GTK_CONTAINER( window ), vbox );

  hbox = gtk_hbox_new( FALSE, 0 );
  gtk_box_pack_start( GTK_BOX( vbox ), hbox, TRUE, TRUE, 0 );

  drawing = gtk_drawing_area_new();

  adj1 = gtk_adjustment_new(0.0, 0.0, 0.0, 1.0, 5.0, 0.0);
  gtk_signal_connect(GTK_OBJECT(adj1), "value_changed",
    GTK_SIGNAL_FUNC(AdjustmentChanged), drawing);

  vsb = gtk_vscrollbar_new( GTK_ADJUSTMENT(adj1) );

  gtk_box_pack_end( GTK_BOX( hbox ), vsb, FALSE, TRUE, 0 );

  adj2 = gtk_adjustment_new(0.0, 0.0, 0.0, 1.0, 5.0, 0.0);
  gtk_signal_connect(GTK_OBJECT(adj2), "value_changed",
    GTK_SIGNAL_FUNC(AdjustmentChanged), drawing);

  hsb = gtk_hscrollbar_new( GTK_ADJUSTMENT(adj2) );

  gtk_box_pack_end( GTK_BOX( vbox ), hsb, FALSE, TRUE, 0 );

  gtk_box_pack_start( GTK_BOX( hbox ), drawing, TRUE, TRUE, 0 );

  gtk_widget_show_all( GTK_WIDGET( window ) );

  gc = gdk_gc_new( drawing->window );

  BuildPixmap( drawing->window );

  gdk_window_get_geometry((GdkWindow *) hsb->window, &x, &y, &hsbwidth, 
    &hsbheight, &depth);

  gdk_window_get_geometry((GdkWindow *) vsb->window, &x, &y, &vsbwidth, 
    &vsbheight, &depth);

  gdk_window_get_geometry((GdkWindow *) pmap, &x, &y, &width, &height,
    &depth);

  SetAdjustments( adj1, adj2, (width - 256) + vsbwidth, 
    (height - 256) + hsbheight );
	
  gtk_main();
}

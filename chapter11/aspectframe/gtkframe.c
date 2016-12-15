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

static gint
DrawingExposeFunc( GtkWidget *widget, GdkEvent *event, gpointer user_data )
{
  GtkDrawingArea *darea;
  GdkDrawable *drawable;
  GdkGC *black_gc, *gray_gc, *white_gc;
  guint max_width, max_height;

  darea = GTK_DRAWING_AREA(widget);
  drawable = widget->window;
  white_gc = widget->style->white_gc;
  gray_gc = widget->style->bg_gc[GTK_STATE_NORMAL];
  black_gc = widget->style->black_gc;
  max_width = widget->allocation.width;
  max_height = widget->allocation.height;

  gdk_draw_rectangle (drawable, white_gc,
    TRUE,
    0,
    0,
    max_width,
    max_height / 2);

  gdk_draw_rectangle (drawable, black_gc,
    TRUE,
    0,
    max_height / 2,
    max_width,
    max_height / 2);

  gdk_draw_rectangle (drawable, gray_gc,
    TRUE,
    max_width / 3,
    max_height / 3,
    max_width / 3,
    max_height / 3);

  return TRUE;
}

gint
MyTimeoutFunc( gpointer data )
{
  static float xalign = 0.0;
  static float yalign = 0.0;
  static float ratio = 0.1;
  GtkAspectFrame *frame = (GtkAspectFrame *) data;

  gtk_aspect_frame_set( frame, xalign, yalign, ratio, FALSE );
  xalign += 0.1;
  if ( xalign > 1.0 )
	  xalign = 0.0;
  yalign += 0.1;
  if ( yalign > 1.0 )
	  yalign = 0.0;
  ratio += 0.1;
  if ( ratio > 2.0 )
	  ratio = 0.1;
  return TRUE;
}

void
GtkFrameDialog()
{
  GtkWidget *frame, *dialog_window, *drawing;

  dialog_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_position (GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);

  gtk_signal_connect (GTK_OBJECT (dialog_window), "destroy",
    GTK_SIGNAL_FUNC(gtk_widget_destroyed), &dialog_window);

  gtk_window_set_title (GTK_WINDOW (dialog_window), "GtkAspectFrame Demo");
  gtk_container_border_width (GTK_CONTAINER (dialog_window), 0);

  frame = gtk_aspect_frame_new( "Drawing", 0.5, 0.5, 1.0, TRUE );
  gtk_timeout_add (500, MyTimeoutFunc, frame);
  gtk_frame_set_label_align( GTK_FRAME( frame ), 0.0, 0.0 );
  gtk_container_add (GTK_CONTAINER (dialog_window), frame);

  drawing = gtk_drawing_area_new();
  gtk_drawing_area_size( GTK_DRAWING_AREA( drawing ), 100, 100 );
  gtk_signal_connect( GTK_OBJECT( drawing ), "expose_event",
    GTK_SIGNAL_FUNC( DrawingExposeFunc ), NULL);
  gtk_widget_set_events( drawing, GDK_EXPOSURE_MASK );


  gtk_container_add (GTK_CONTAINER (frame), drawing);

  gtk_widget_show_all (dialog_window);
}

main( argc, argv )
int argc;
char *argv[];
{
	gtk_init( &argc, &argv );

	GtkFrameDialog();

	gtk_main();
}

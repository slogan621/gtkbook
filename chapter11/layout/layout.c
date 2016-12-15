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
 
gint
HandleExposeEvent (GtkWidget *widget, GdkEventExpose *event)
{
  GtkLayout *layout;
 
  gint i,j;
  char buf[128];
  gint imin, imax, jmin, jmax;
 
  layout = GTK_LAYOUT (widget);
 
  // compute loop ranges 
 
  imin = (layout->xoffset + event->area.x) / 10;
  imax = (layout->xoffset + event->area.x + event->area.width + 9) / 10;
 
  jmin = (layout->yoffset + event->area.y) / 10;
  jmax = (layout->yoffset + event->area.y + event->area.height + 9) / 10;
 
  // clear the area that was exposed
 
  gdk_window_clear_area (widget->window, event->area.x, event->area.y,
    event->area.width, event->area.height);

  for (i=imin; i<imax; i++)
    for (j=jmin; j<jmax; j++)
      if ( (i + j) % 2 == 0 ) // draw every other arc/rectangle on a line
        if ( j % 2 == 0 ) // even lines rectangles, others get arcs
          gdk_draw_rectangle(layout->bin_window, 
            widget->style->black_gc, TRUE, 
            10*i - layout->xoffset, 
            10*j - layout->yoffset, 10, 10);
        else
          gdk_draw_arc(layout->bin_window, 
            widget->style->black_gc, TRUE, 
            10*i - layout->xoffset, 
            10*j - layout->yoffset, 10, 10, 
            0, 360 * 64);
  return TRUE;
}
 
void
GtkLayoutDialog()
{
  GtkWidget *dialog_window, *scrolledwindow, *layout;
 
  dialog_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_position (GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);
  gtk_widget_set_usize (dialog_window, 200, 200);
 
  gtk_signal_connect (GTK_OBJECT (dialog_window), "destroy",
    GTK_SIGNAL_FUNC(gtk_widget_destroyed), &dialog_window);
 
  gtk_window_set_title (GTK_WINDOW (dialog_window), "GtkLayout Demo");
  gtk_container_border_width (GTK_CONTAINER (dialog_window), 0);
 
  scrolledwindow = gtk_scrolled_window_new (NULL, NULL);
 
  gtk_container_add (GTK_CONTAINER (dialog_window), scrolledwindow);
 
  layout = gtk_layout_new (NULL, NULL);
  gtk_container_add (GTK_CONTAINER (scrolledwindow), layout);
 
  // set the scrollbar step sizes to 10 pixels 
 
  GTK_LAYOUT (layout)->hadjustment->step_increment = 10.0;
  GTK_LAYOUT (layout)->vadjustment->step_increment = 10.0;
 
  // solicit expose events on the layout widget
 
  gtk_widget_set_events (layout, GDK_EXPOSURE_MASK);
  gtk_signal_connect (GTK_OBJECT (layout), "expose_event",
    GTK_SIGNAL_FUNC (HandleExposeEvent), NULL);
 
  gtk_layout_set_size (GTK_LAYOUT (layout), 1600, 128000);
 
  gtk_widget_show_all (dialog_window);
}
 
main( argc, argv )
int argc;
char *argv[];
{
  gtk_init( &argc, &argv );
 
  GtkLayoutDialog();
  gtk_main();
}

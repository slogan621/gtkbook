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

static GtkWidget *vruler, *hruler;

static void
ToggleCallback(GtkWidget *widget, gpointer dummy)
{
  static int foo = 1;
printf( "foo %d\n", foo );
  gtk_ruler_set_range (GTK_RULER (hruler), 0, 300, 0, foo );
  gtk_ruler_set_range (GTK_RULER (vruler), 0, 300, 0, foo );
  foo = foo * 2;
  if ( foo > 800 )
    foo = 1;
#if 0
  static GtkMetricType metric = GTK_PIXELS;

  if ( metric == GTK_PIXELS )
    metric = GTK_INCHES;
  else if ( metric == GTK_INCHES )
    metric = GTK_CENTIMETERS;
  else
    metric = GTK_PIXELS;

  gtk_ruler_set_metric (GTK_RULER (hruler), metric);
  gtk_ruler_set_metric (GTK_RULER (vruler), metric);
#endif
}

main( int argc, char *argv[] )
{
  GtkWidget *dialog_window, *table;
  GtkWidget *button;

  gtk_init( &argc, &argv );

  dialog_window = gtk_dialog_new();
  gtk_window_position (GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);

  gtk_widget_set_usize (dialog_window, 300, 300);
  gtk_widget_show( dialog_window );


  table = gtk_table_new (2, 2, FALSE);
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->vbox), 
    table, TRUE, TRUE, 0);

  hruler = gtk_hruler_new();	
  gtk_ruler_set_range (GTK_RULER (hruler), 0, 300, 0, 1);
  gtk_table_attach (GTK_TABLE (table), hruler, 1, 2, 0, 1,
    GTK_EXPAND | GTK_FILL, GTK_FILL, 0, 0);

  vruler = gtk_vruler_new();	
  gtk_ruler_set_range (GTK_RULER (vruler), 0, 300, 0, 1);
  gtk_table_attach (GTK_TABLE (table), vruler, 0, 1, 1, 2,
    GTK_FILL, GTK_EXPAND | GTK_FILL, 0, 0);


  button = gtk_button_new_with_label("Toggle");
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area), 
    button, TRUE, TRUE, 0);

  gtk_signal_connect (GTK_OBJECT (button), "clicked", 
    GTK_SIGNAL_FUNC(ToggleCallback), dialog_window);

  gtk_widget_show_all (dialog_window);
  gtk_main();
}

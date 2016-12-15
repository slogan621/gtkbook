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

main( int argc, char *argv[] )
{
  GtkWidget *dialog_window, *table;
  GtkWidget *vruler, *hruler;

  gtk_init( &argc, &argv );

  dialog_window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
  gtk_window_position (GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);

  gtk_widget_set_usize (dialog_window, 300, 300);

  table = gtk_table_new (2, 2, FALSE);
  gtk_container_add (GTK_CONTAINER (dialog_window), table );

  hruler = gtk_hruler_new();	
  gtk_ruler_set_range (GTK_RULER (hruler), 0, 300, 0, 128);
  gtk_table_attach (GTK_TABLE (table), hruler, 1, 2, 0, 1,
    GTK_EXPAND | GTK_FILL, GTK_FILL, 0, 0);

  vruler = gtk_vruler_new();	
  gtk_ruler_set_range (GTK_RULER (vruler), 0, 300, 0, 128);
  gtk_table_attach (GTK_TABLE (table), vruler, 0, 1, 1, 2,
    GTK_FILL, GTK_EXPAND | GTK_FILL, 0, 0);

  gtk_widget_show_all (dialog_window);
  gtk_main();
}

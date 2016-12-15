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
  GtkWidget *dialog_window, *statusbar, *button;
  GList *cbitems = NULL;

  gtk_init( &argc, &argv );

  dialog_window = gtk_dialog_new();
  gtk_window_position (GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);

  statusbar = gtk_statusbar_new();

  gtk_statusbar_push(GTK_STATUSBAR(statusbar), 1, "Hello World 1");
  gtk_statusbar_push(GTK_STATUSBAR(statusbar), 1, "Hello World 2");
  gtk_statusbar_push(GTK_STATUSBAR(statusbar), 1, "Hello World 3");
  gtk_statusbar_push(GTK_STATUSBAR(statusbar), 1, "Hello World 4");
  gtk_statusbar_push(GTK_STATUSBAR(statusbar), 2, "Hello World 5");
  gtk_statusbar_pop(GTK_STATUSBAR(statusbar), 2 ); 

  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->vbox), 
    statusbar, TRUE, TRUE, 0);

  gtk_widget_show_all (dialog_window);
  gtk_main();
}

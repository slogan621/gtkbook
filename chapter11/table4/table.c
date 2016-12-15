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
GtkTableDialog()
{
  GtkWidget *button, *table, *dialog_window, *outervbox;

  dialog_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_position (GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);

  gtk_signal_connect (GTK_OBJECT (dialog_window), "destroy",
    GTK_SIGNAL_FUNC(gtk_widget_destroyed), &dialog_window);

  gtk_window_set_title (GTK_WINDOW (dialog_window), "GtkTable Demo");
  gtk_container_border_width (GTK_CONTAINER (dialog_window), 0);

  outervbox = gtk_vbox_new (FALSE, 0);
  gtk_container_add (GTK_CONTAINER (dialog_window), outervbox);

  table = gtk_table_new( 3, 3, TRUE );
  gtk_box_pack_start( GTK_BOX(outervbox), table, TRUE, TRUE, 0);

  button = gtk_button_new_with_label( "Button 1" );
  gtk_table_attach( GTK_TABLE( table ), button, 1, 3, 0, 1,
    GTK_FILL, GTK_FILL, 0, 0 );

  button = gtk_button_new_with_label( "Button 2" );
  gtk_table_attach_defaults( GTK_TABLE( table ), button, 0, 1, 1, 2 );

  button = gtk_button_new_with_label( "Button 3" );
  gtk_table_attach_defaults( GTK_TABLE( table ), button, 1, 2, 1, 2 );

  button = gtk_button_new_with_label( "Button 4" );
  gtk_table_attach_defaults( GTK_TABLE( table ), button, 2, 3, 2, 3 );

  gtk_widget_show_all (dialog_window);
}

main( argc, argv )
int argc;
char *argv[];
{
  gtk_init( &argc, &argv );

  GtkTableDialog();
  gtk_main();
}

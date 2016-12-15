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
  GtkWidget *button, *entry, *table, *dialog_window, *outervbox;
  int i;

  dialog_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_position(GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);

  gtk_signal_connect(GTK_OBJECT (dialog_window), "destroy",
    GTK_SIGNAL_FUNC(gtk_widget_destroyed), &dialog_window);

  gtk_window_set_title(GTK_WINDOW (dialog_window), "GtkTable Demo");
  gtk_container_border_width(GTK_CONTAINER (dialog_window), 0);

  outervbox = gtk_vbox_new (FALSE, 0);
  gtk_container_add(GTK_CONTAINER (dialog_window), outervbox);

  table = gtk_table_new( 3, 5, TRUE );
  gtk_box_pack_start( GTK_BOX(outervbox), table, TRUE, TRUE, 0 );

  button = gtk_button_new_with_label( "Submit" );
  gtk_table_attach( GTK_TABLE( table ), button, 0, 1, 1, 2,
	  0, 0, 0, 0 );

  entry = gtk_entry_new();
  gtk_table_attach_defaults( GTK_TABLE( table ), entry, 1, 5, 1, 2 );

  for ( i = 0; i < 4; i++ )
    gtk_table_set_col_spacing( GTK_TABLE( table ), i, 10 );

  gtk_widget_show_all(dialog_window);
}

main( argc, argv )
int argc;
char *argv[];
{
  gtk_init( &argc, &argv );

  GtkTableDialog();
  gtk_main();
}

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
GtkLayoutDialog()
{
  GtkWidget *layout, *scrolled_window, *label, *dialog_window;
  int i, j;
  char buf[128];

  dialog_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_position (GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);
  gtk_widget_set_usize( GTK_WIDGET( dialog_window ), 200, 200 );

  gtk_signal_connect (GTK_OBJECT (dialog_window), "destroy",
    GTK_SIGNAL_FUNC(gtk_widget_destroyed), &dialog_window);

  gtk_window_set_title (GTK_WINDOW (dialog_window), "GtkLayout Demo");
  gtk_container_border_width (GTK_CONTAINER (dialog_window), 0);

  scrolled_window = gtk_scrolled_window_new( NULL, NULL );
  gtk_container_add (GTK_CONTAINER (dialog_window), scrolled_window);
  layout = gtk_layout_new( NULL, NULL );

  gtk_layout_set_size (GTK_LAYOUT (layout), 800, 128000);

  for ( i = 0; i < 800; i+=200 )
	  for ( j = 0; j < 128000; j+= 200 ) {
		  sprintf( buf, "%d %ld", i, j );
		  label = gtk_button_new_with_label( buf );	
		  gtk_layout_put( GTK_LAYOUT( layout ), label, i, j );
	  }	

  gtk_container_add (GTK_CONTAINER (scrolled_window), layout);

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

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

int
DestroyWindow( gpointer data )
{
  GtkWidget *window = GTK_WIDGET( data );
  gdk_window_destroy( window->window );
  return FALSE;
}

void
PopupWindow( GtkWidget *widget, gpointer ignored ) 
{
  GtkWidget *window;

  window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
  gtk_window_position(GTK_WINDOW (window), GTK_WIN_POS_MOUSE);
  gtk_widget_set_usize( window, 100, 100 );
  gtk_timeout_add( 1000, DestroyWindow, window ); 

  gtk_widget_show(window);
}

main( int argc, char *argv[] )
{
  GtkWidget *button, *dialog_window;

  gtk_init( &argc, &argv );

  dialog_window = gtk_dialog_new();
  gtk_window_position(GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);

  button = gtk_button_new_with_label ("Popup Window");
  gtk_signal_connect(GTK_OBJECT (button), "clicked",
    GTK_SIGNAL_FUNC(PopupWindow), NULL );
  gtk_box_pack_start(GTK_BOX (GTK_DIALOG (dialog_window)->action_area),
    button, FALSE, FALSE, 0);

  gtk_widget_show_all(dialog_window);
	
  gtk_main();
}


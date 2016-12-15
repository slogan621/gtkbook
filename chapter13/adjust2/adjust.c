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
#include <stdio.h>
#include <stdlib.h>

static void
HandleOkButton(GtkWidget *w, gpointer data)
{
  GtkAdjustment *adj = (GtkAdjustment *) data;
  char buf[128];
  gfloat lower, upper;

  printf( "Enter lower: " );
  fgets( buf, sizeof( buf ), stdin );
  lower = atof( buf );
  printf( "Enter upper: " );
  fgets( buf, sizeof( buf ), stdin);
  upper = atof( buf );

  gtk_adjustment_clamp_page( adj, lower, upper );
}

// called when the user changes the value of the first scale widget

static void
AdjustmentChanged(GtkAdjustment *w, gpointer data)
{
  fprintf( stderr, "Adjustment is %.1f\n", w->value );
}

main( argc, argv )
int argc;
char *argv[];
{
  GtkWidget *hscale, *vscale, *vbox, *hbox, *window, *button;
  GtkObject *adj;

  gtk_init( &argc, &argv );

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_position(GTK_WINDOW(window), GTK_WIN_POS_MOUSE);

  gtk_signal_connect(GTK_OBJECT(window), "destroy",
    GTK_SIGNAL_FUNC(gtk_widget_destroyed), &window);

  gtk_window_set_title(GTK_WINDOW (window), "GtkScale Demo");

  vbox = gtk_vbox_new( FALSE, 0 );
  gtk_container_add( GTK_CONTAINER( window ), vbox );

  hbox = gtk_hbox_new( FALSE, 0 );
	gtk_box_pack_start( GTK_BOX( vbox ), hbox, TRUE, TRUE, 0 );

  // create an adjustment object for the first scale widget

  adj = gtk_adjustment_new(30.0, 25.0, 75.0, 1.0, 5.0, 10.0);
  gtk_signal_connect(GTK_OBJECT(adj), "value_changed",
    GTK_SIGNAL_FUNC(AdjustmentChanged), NULL);

  // create a horizontal scale widget. Display the value to the
  // left of the scale, and display scale value as an integer

  hscale = gtk_hscale_new( GTK_ADJUSTMENT(adj) );
  gtk_scale_set_value_pos( GTK_SCALE(hscale), GTK_POS_LEFT );
  gtk_scale_set_digits( GTK_SCALE(hscale), 0 );

  gtk_box_pack_start( GTK_BOX( hbox ), hscale, TRUE, TRUE, 0 );

  // create a vertical scale widget using widget-supplied defaults

  vscale = gtk_vscale_new( GTK_ADJUSTMENT(adj) );

  gtk_box_pack_start( GTK_BOX( hbox ), vscale, TRUE, TRUE, 0 );

  button = gtk_button_new_with_label( "Ok" );
  gtk_signal_connect(GTK_OBJECT(button), "clicked",
    (GtkSignalFunc) HandleOkButton, adj);

  gtk_box_pack_end( GTK_BOX( vbox ), button, FALSE, FALSE, 0 );

  gtk_widget_show_all( GTK_WIDGET( window ) );
        
  gtk_main();
}


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

// a data type that makes it possible to pass both adjustment objects as
// client data to the HandleOkButton() signal function

typedef struct _adjustments {
  GtkAdjustment *adj1;
  GtkAdjustment *adj2;
} Adjustments;

// called when the user presses the Ok button

static void
HandleOkButton(GtkWidget *w, gpointer data)
{
  Adjustments *adjs = (Adjustments *) data;

  fprintf( stderr, "Hscale value is %d vscale value is %.1f\n",
    (int) adjs->adj1->value, adjs->adj2->value );
}

// called when the user changes the value of the first scale widget

static void
Adjustment1Changed(GtkAdjustment *w, gpointer data)
{
  fprintf( stderr, "Adjustment 1 is %d\n", (int) w->value );
}

// called when the user changes the value of the second scale widget

static void
Adjustment2Changed(GtkAdjustment *w, gpointer data)
{
  fprintf( stderr, "Adjustment 2 is %.1f\n", w->value );
}

main( argc, argv )
int argc;
char *argv[];
{
  GtkWidget *hscale, *vscale, *vbox, *hbox, *window, *button;
  GtkObject *adj1, *adj2;
  Adjustments adjustments;

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

  adj1 = gtk_adjustment_new(0.0, 0.0, 100.0, 1.0, 5.0, 1.0);
  gtk_signal_connect(GTK_OBJECT(adj1), "value_changed",
    GTK_SIGNAL_FUNC(Adjustment1Changed), NULL);

  // create a horizontal scale widget. Display the value to the
  // left of the scale, and display scale value as an integer

  hscale = gtk_hscale_new( GTK_ADJUSTMENT(adj1) );
  gtk_scale_set_value_pos( GTK_SCALE(hscale), GTK_POS_LEFT );
  gtk_scale_set_digits( GTK_SCALE(hscale), 0 );

  gtk_box_pack_start( GTK_BOX( hbox ), hscale, TRUE, TRUE, 0 );

  // create an adjustment object for the second scale widget
        
  adj2 = gtk_adjustment_new(0.0, 0.0, 100.0, 1.0, 5.0, 50.0);
  gtk_signal_connect(GTK_OBJECT(adj2), "value_changed",
    GTK_SIGNAL_FUNC(Adjustment2Changed), NULL);

  // create a vertical scale widget using widget-supplied defaults

  vscale = gtk_vscale_new( GTK_ADJUSTMENT(adj2) );

  gtk_box_pack_start( GTK_BOX( hbox ), vscale, TRUE, TRUE, 0 );

  adjustments.adj1 = GTK_ADJUSTMENT(adj1);
  adjustments.adj2 = GTK_ADJUSTMENT(adj2);

#if 0
  button = gtk_button_new_with_label( "Ok" );
  gtk_signal_connect(GTK_OBJECT(button), "clicked",
    (GtkSignalFunc) HandleOkButton, &adjustments);

  gtk_box_pack_end( GTK_BOX( vbox ), button, FALSE, FALSE, 0 );
#endif

  gtk_widget_show_all( GTK_WIDGET( window ) );
        
  gtk_main();
}


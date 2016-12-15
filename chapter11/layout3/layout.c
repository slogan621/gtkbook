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
  GtkWidget *layout, *spinner, *scrolled_window, *button, *vbox, 
    *dialog_window, *hbox;
  GtkAdjustment *adj1, *adj2;
  char buf[128];
  int i, j;

  dialog_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_position (GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);
  gtk_widget_set_usize( GTK_WIDGET( dialog_window ), 200, 200 );

  gtk_signal_connect (GTK_OBJECT (dialog_window), "destroy",
    GTK_SIGNAL_FUNC(gtk_widget_destroyed), &dialog_window);

  gtk_window_set_title (GTK_WINDOW (dialog_window), "GtkLayout Demo");
  gtk_container_border_width (GTK_CONTAINER (dialog_window), 0);

  vbox = gtk_vbox_new( FALSE, 0 );
  gtk_container_add (GTK_CONTAINER (dialog_window), vbox);
 
  layout = gtk_layout_new( NULL, NULL );

  gtk_layout_set_size (GTK_LAYOUT (layout), 800, 128000);

  for ( i = 0; i < 800; i+=200 )
	  for ( j = 0; j < 128000; j+= 200 ) {
		  sprintf( buf, "%d %ld", i, j );
		  button = gtk_button_new_with_label( buf );	
		  gtk_layout_put( GTK_LAYOUT( layout ), button, i, j );
	  }	

  GTK_LAYOUT (layout)->hadjustment->step_increment = 10.0;
  GTK_LAYOUT (layout)->vadjustment->step_increment = 10.0;

  gtk_box_pack_start(GTK_BOX(vbox), layout, TRUE, TRUE, 0);

  hbox = gtk_hbox_new( FALSE, 0 );
  gtk_box_pack_end(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

  adj1 = (GtkAdjustment *) gtk_adjustment_new (400, 1.0, 800, 
    10.0, 100.0, 0.0);
  spinner = gtk_spin_button_new (adj1, 0, 0);
  gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (spinner), TRUE);
  gtk_box_pack_start (GTK_BOX (hbox), spinner, TRUE, TRUE, 0);

  adj2 = (GtkAdjustment *) gtk_adjustment_new (64000, 1.0,
    128000, 10.0, 100.0, 0.0);
  spinner = gtk_spin_button_new (adj2, 0, 0);
  gtk_spin_button_set_wrap (GTK_SPIN_BUTTON (spinner), TRUE);
  gtk_box_pack_start (GTK_BOX (hbox), spinner, TRUE, TRUE, 0);

  gtk_layout_set_hadjustment( GTK_LAYOUT( layout ), adj1 ); 
  gtk_layout_set_vadjustment( GTK_LAYOUT( layout ), adj2 ); 

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

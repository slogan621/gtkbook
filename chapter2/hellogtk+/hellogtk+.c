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

#include <stdio.h>
#include <gtk/gtk.h>

static GtkWidget *entry;

void
PrintAndExit (GtkWidget *widget, GtkWidget *window)
{
  char	*str;

  str = gtk_entry_get_text( GTK_ENTRY(entry) );
  if ( str != (char *) NULL )
    printf( "%s\n", str );

  gtk_widget_destroy (window);
  gtk_main_quit ();
}

void
PrintByeAndExit (GtkWidget *widget, gpointer data)
{
  printf( "Goodbye, world!\n" );
  gtk_exit(0);
}

int
main( int argc, char *argv[] )
{
  GtkWidget *window, *label, *vbox, *hbox, *button, *separator;

  gtk_set_locale ();

  gtk_init (&argc, &argv);

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_policy( GTK_WINDOW( window ), FALSE, FALSE, FALSE );

  gtk_signal_connect (GTK_OBJECT(window), "destroy", 
    GTK_SIGNAL_FUNC(PrintByeAndExit), NULL);

  gtk_window_set_title (GTK_WINDOW (window), "Hello Gtk+!");
  gtk_container_border_width (GTK_CONTAINER (window), 0);

 	vbox = gtk_vbox_new (FALSE, 0);
 	gtk_container_add (GTK_CONTAINER (window), vbox);

 	hbox = gtk_hbox_new (FALSE, 0);
 	gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

	label = gtk_label_new( "Enter a message:" );
 	gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, FALSE, 0);
 	entry = gtk_entry_new ();
 	gtk_entry_set_text (GTK_ENTRY (entry), "");
 	gtk_editable_select_region (GTK_EDITABLE (entry), 0, -1);
 	gtk_box_pack_start (GTK_BOX (hbox), entry, FALSE, FALSE, 0);

 	separator = gtk_hseparator_new ();
 	gtk_box_pack_start (GTK_BOX (vbox), separator, FALSE, FALSE, 0);

 	button = gtk_button_new_with_label ("Print");
 	gtk_signal_connect_object (GTK_OBJECT (button), "clicked",
 	  GTK_SIGNAL_FUNC(PrintAndExit), GTK_OBJECT (window));
 	gtk_box_pack_start (GTK_BOX (vbox), button, FALSE, FALSE, 0);
 	GTK_WIDGET_SET_FLAGS (button, GTK_CAN_DEFAULT);
 	gtk_widget_grab_default (button);

	gtk_widget_show_all (window);

	gtk_main ();

	return( 0 );
}


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

/*
 * Simple MessageBox, without using GtkDialog
 */

void
MessageBox2( char *message )
{
  GtkWidget *hbox, *vbox1, *vbox2, *separator, *label, *button,
    *dialog_window;

  dialog_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_position (GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);

  gtk_signal_connect (GTK_OBJECT (dialog_window), "destroy",
    GTK_SIGNAL_FUNC(gtk_widget_destroyed), &dialog_window);

  gtk_window_set_title (GTK_WINDOW (dialog_window), "Message");
  gtk_container_border_width (GTK_CONTAINER (dialog_window), 0);

  /* create the outer vbox that holds the control area vbox, the action
     area hbox, and the separator between them */

  vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_container_add (GTK_CONTAINER (dialog_window), vbox1);

  /* create the vbox that represents the control area. The message (as an
     instance of GtkLabel) will be added to this vbox. Add the control
     area vbox to the outer vbox */

  vbox2 = gtk_vbox_new (FALSE, 0);
  gtk_box_pack_start ( GTK_BOX (vbox1), vbox2, TRUE, TRUE, 0);

  /* create the separator, and add it to the outer vbox */

  separator = gtk_hseparator_new();
  gtk_box_pack_start ( GTK_BOX (vbox1), separator, TRUE, TRUE, 0);

  /* create the hbox that represents the action area. The OK button will
     be added to this hbox. Add the action area hbox to the outer vbox */

  hbox = gtk_vbox_new (FALSE, 5);
  gtk_container_set_border_width (GTK_CONTAINER (hbox), 10);

  gtk_box_pack_start ( GTK_BOX (vbox1), hbox, TRUE, TRUE, 0);

  /* now, create the message label and the OK button, and add them to the
     control and action areas, respectively. */

  button = gtk_button_new_with_label ("OK");
  GTK_WIDGET_SET_FLAGS (button, GTK_CAN_DEFAULT);
  gtk_box_pack_start ( GTK_BOX (hbox), button, TRUE, TRUE, 0);
  gtk_signal_connect_object (GTK_OBJECT (button), "clicked",
    GTK_SIGNAL_FUNC (gtk_widget_destroy), GTK_OBJECT (dialog_window));

  label = gtk_label_new (message);
  gtk_misc_set_padding (GTK_MISC (label), 10, 10);
  gtk_box_pack_start (GTK_BOX (vbox2), label, TRUE, TRUE, 0);
  gtk_widget_grab_default (button);
  gtk_widget_show_all (dialog_window);
}

main( int argc, char *argv[] )
{
	gtk_init( &argc, &argv );

	MessageBox2( "Hello There!" );
	gtk_main();
}

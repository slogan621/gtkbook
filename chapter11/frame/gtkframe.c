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
GtkFrameDialog()
{
  GtkWidget *vbox1, *separator, *label, *button, *frame, *dialog_window, 
    *hbox1, *hbox2, *outervbox, *list, *list_item;
  GList	*item_list;

  dialog_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_position (GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);

  gtk_signal_connect (GTK_OBJECT (dialog_window), "destroy",
    GTK_SIGNAL_FUNC(gtk_widget_destroyed), &dialog_window);

  gtk_window_set_title (GTK_WINDOW (dialog_window), "GtkFrame Demo");
  gtk_container_border_width (GTK_CONTAINER (dialog_window), 0);

  outervbox = gtk_vbox_new (FALSE, 0);
  gtk_container_add (GTK_CONTAINER (dialog_window), outervbox);

  hbox1 = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start ( GTK_BOX (outervbox), hbox1, TRUE, TRUE, 0);

#if defined( USE_FRAMES )
  frame = gtk_frame_new( "Shirt" );
  gtk_frame_set_label_align( GTK_FRAME( frame ), 0.0, 0.0 );
  gtk_box_pack_start ( GTK_BOX (hbox1), frame, TRUE, TRUE, 0);
#endif
  list = gtk_list_new();
  item_list = NULL;
  list_item = gtk_list_item_new_with_label ("Dress, short sleeve");
  item_list = g_list_append (item_list, list_item);
  list_item = gtk_list_item_new_with_label ("Dress, long sleeve");
  item_list = g_list_append (item_list, list_item);
  list_item = gtk_list_item_new_with_label ("Polo");
  item_list = g_list_append (item_list, list_item);
  list_item = gtk_list_item_new_with_label ("Golf");
  item_list = g_list_append (item_list, list_item);
  list_item = gtk_list_item_new_with_label ("T-Shirt");
  item_list = g_list_append (item_list, list_item);
  gtk_list_insert_items( GTK_LIST(list), item_list, 0 );

#if defined ( USE_FRAMES )
  gtk_container_add (GTK_CONTAINER (frame), list);
#else
  gtk_box_pack_start ( GTK_BOX (hbox1), list, TRUE, TRUE, 0);
#endif

#if defined( USE_FRAMES )
  frame = gtk_frame_new( "Shoes" );
  gtk_box_pack_start ( GTK_BOX (hbox1), frame, TRUE, TRUE, 0);
#endif
  list = gtk_list_new();
  item_list = NULL;
  list_item = gtk_list_item_new_with_label ("Dress, brown");
  item_list = g_list_append (item_list, list_item);
  list_item = gtk_list_item_new_with_label ("Dress, black");
  item_list = g_list_append (item_list, list_item);
  list_item = gtk_list_item_new_with_label ("Running");
  item_list = g_list_append (item_list, list_item);
  list_item = gtk_list_item_new_with_label ("Hiking");
  item_list = g_list_append (item_list, list_item);
  list_item = gtk_list_item_new_with_label ("Sandals");
  item_list = g_list_append (item_list, list_item);
  gtk_list_insert_items( GTK_LIST(list), item_list, 0 );

#if defined ( USE_FRAMES )
  gtk_container_add (GTK_CONTAINER (frame), list);
#else
  gtk_box_pack_start ( GTK_BOX (hbox1), list, TRUE, TRUE, 0);
#endif

#if defined( USE_FRAMES )
  frame = gtk_frame_new( "Accessories" );
  gtk_box_pack_start ( GTK_BOX (hbox1), frame, TRUE, TRUE, 0);
#endif
  list = gtk_list_new();
 item_list = NULL;
  list_item = gtk_list_item_new_with_label ("Jacket");
  item_list = g_list_append (item_list, list_item);
  list_item = gtk_list_item_new_with_label ("Sweater");
  item_list = g_list_append (item_list, list_item);
  list_item = gtk_list_item_new_with_label ("Hat");
  item_list = g_list_append (item_list, list_item);
  list_item = gtk_list_item_new_with_label ("Gloves");
  item_list = g_list_append (item_list, list_item);
  list_item = gtk_list_item_new_with_label ("Belt");
  item_list = g_list_append (item_list, list_item);
  gtk_list_insert_items( GTK_LIST(list), item_list, 0 );

#if defined ( USE_FRAMES )
  gtk_container_add (GTK_CONTAINER (frame), list);
#else
  gtk_box_pack_start ( GTK_BOX (hbox1), list, TRUE, TRUE, 0);
#endif

  separator = gtk_hseparator_new();
  gtk_box_pack_start ( GTK_BOX (outervbox), separator, TRUE, TRUE, 0);

  hbox2 = gtk_hbox_new (FALSE, 5);
  gtk_container_set_border_width (GTK_CONTAINER (hbox2), 10);

  gtk_box_pack_start ( GTK_BOX (outervbox), hbox2, TRUE, TRUE, 0);

  button = gtk_button_new_with_label ("OK");
  GTK_WIDGET_SET_FLAGS (button, GTK_CAN_DEFAULT);
  gtk_box_pack_start ( GTK_BOX (hbox2), button, TRUE, TRUE, 0);
  gtk_signal_connect_object (GTK_OBJECT (button), "clicked",
    GTK_SIGNAL_FUNC (gtk_widget_destroy), GTK_OBJECT (dialog_window));

  gtk_widget_grab_default (button);

  button = gtk_button_new_with_label ("Cancel");
  GTK_WIDGET_SET_FLAGS (button, GTK_CAN_DEFAULT);
  gtk_box_pack_start ( GTK_BOX (hbox2), button, TRUE, TRUE, 0);
  gtk_signal_connect_object (GTK_OBJECT (button), "clicked",
    GTK_SIGNAL_FUNC (gtk_widget_destroy), 
    GTK_OBJECT (dialog_window));

  gtk_widget_show_all (dialog_window);
}

main( argc, argv )
int argc;
char *argv[];
{
	gtk_init( &argc, &argv );

	GtkFrameDialog();
	gtk_main();
}

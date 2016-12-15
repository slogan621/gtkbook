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

/* Create an Arrow widget with the specified parameters
 * and pack it into a button */

GtkWidget *create_arrow_button( GtkArrowType  arrow_type, 
  GtkShadowType shadow_type )
{
 GtkWidget *button;
 GtkWidget *arrow;
 GtkWidget *hbox;
 GtkWidget *label;

 button = gtk_button_new();

 hbox = gtk_hbox_new(FALSE, 0);
 gtk_container_add (GTK_CONTAINER (button), hbox);

 label = gtk_label_new( "Click me" );
 gtk_box_pack_start ( GTK_BOX (hbox), label, TRUE, TRUE, 5);

 arrow = gtk_arrow_new (arrow_type, shadow_type);
 gtk_box_pack_start ( GTK_BOX (hbox), arrow, TRUE, TRUE, 5);
 
 gtk_widget_show_all(button);
 gtk_widget_show(arrow);

 return(button);
}

int main( int argc, char *argv[] )
{
 /* GtkWidget is the storage type for widgets */
 GtkWidget *window;
 GtkWidget *button;
 GtkWidget *box;

 /* Initialize the toolkit */
 gtk_init (&argc, &argv);

 /* Create a new window */
 window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

 gtk_window_set_title (GTK_WINDOW (window), "Arrow Buttons");

 /* It's a good idea to do this for all windows. */
 gtk_signal_connect (GTK_OBJECT (window), "destroy",
 	GTK_SIGNAL_FUNC (gtk_main_quit), NULL);

 /* Sets the border width of the window. */
 gtk_container_set_border_width (GTK_CONTAINER (window), 10);

 /* Create a box to hold the arrows/buttons */
 box = gtk_hbox_new (FALSE, 0);
 gtk_container_set_border_width (GTK_CONTAINER (box), 2);
 gtk_container_add (GTK_CONTAINER (window), box);

 /* Pack and show all our widgets */
 gtk_widget_show(box);

 button = create_arrow_button(GTK_ARROW_UP, GTK_SHADOW_IN);
 gtk_box_pack_start (GTK_BOX (box), button, FALSE, FALSE, 3);

 button = create_arrow_button(GTK_ARROW_DOWN, GTK_SHADOW_OUT);
 gtk_box_pack_start (GTK_BOX (box), button, FALSE, FALSE, 3);
 
 button = create_arrow_button(GTK_ARROW_LEFT, GTK_SHADOW_ETCHED_IN);
 gtk_box_pack_start (GTK_BOX (box), button, FALSE, FALSE, 3);
 
 button = create_arrow_button(GTK_ARROW_RIGHT, GTK_SHADOW_ETCHED_OUT);
 gtk_box_pack_start (GTK_BOX (box), button, FALSE, FALSE, 3);
 
 gtk_widget_show (window);
 
 /* Rest in gtk_main and wait for the fun to begin! */
 gtk_main ();
 
 return(0);
}
/* example-end */

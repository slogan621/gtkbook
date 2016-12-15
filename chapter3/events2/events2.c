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
PrintString (GtkWidget *widget, GtkWidget *window)
{
	char	*str;

	str = gtk_entry_get_text( GTK_ENTRY(entry) );
	if ( str != (char *) NULL )
		printf( "%s\n", str );
}

void
PrintByeAndExit (GtkWidget *widget, gpointer data)
{
	printf( "Goodbye, world!\n" );
	gtk_exit(0);
}

void
MotionNotifyCallback( GtkWidget *widget, GdkEvent *event, gpointer cb_data )
{
	printf( "In MotionNotifyCallback\n" );
}

void
ButtonPressCallback( GtkWidget *widget, GdkEvent *event, gpointer cb_data )
{
	printf( "In ButtonPressCallback\n" );
}

int
main( int argc, char *argv[] )
{
	GtkWidget *window, *box, *button, *separator;

 	gtk_set_locale ();

 	gtk_init (&argc, &argv);

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

 	gtk_signal_connect (GTK_OBJECT(window), "destroy", 
		GTK_SIGNAL_FUNC(PrintByeAndExit), &window);

  gtk_window_set_title (GTK_WINDOW (window), "Hello Gtk+!");
 	gtk_container_border_width (GTK_CONTAINER (window), 0);

 	box = gtk_vbox_new (FALSE, 0);
 	gtk_container_add (GTK_CONTAINER (window), box);

 	entry = gtk_entry_new ();
 	gtk_entry_set_text (GTK_ENTRY (entry), "");
 	gtk_editable_select_region (GTK_EDITABLE (entry), 0, -1);
 	gtk_box_pack_start (GTK_BOX (box), entry, TRUE, TRUE, 0);

 	separator = gtk_hseparator_new ();
 	gtk_box_pack_start (GTK_BOX (box), separator, TRUE, TRUE, 0);

 	button = gtk_button_new_with_label ("Print");
 	gtk_signal_connect_object (GTK_OBJECT (button), "clicked",
 	  GTK_SIGNAL_FUNC(PrintString), GTK_OBJECT (window));
  gtk_box_pack_start (GTK_BOX (box), button, TRUE, TRUE, 0);
  GTK_WIDGET_SET_FLAGS (button, GTK_CAN_DEFAULT);
  gtk_widget_grab_default (button);

#if 0	
	gtk_widget_set_events (button, GDK_POINTER_MOTION_MASK | 
		GDK_BUTTON_PRESS_MASK);
#else
	gtk_widget_set_events (button, GDK_POINTER_MOTION_MASK); 
#endif

	gtk_signal_connect (GTK_OBJECT (button), "motion_notify_event",
    GTK_SIGNAL_FUNC(MotionNotifyCallback), NULL);

	gtk_signal_connect (GTK_OBJECT (button), "button_press_event",
    GTK_SIGNAL_FUNC(ButtonPressCallback), NULL);

	gtk_widget_show_all (window);

	gtk_main ();

	return( 0 );
}


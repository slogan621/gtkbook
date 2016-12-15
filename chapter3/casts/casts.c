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
PrintAndExit (GtkWidget *widget, char *foo)
{
	if ( foo )
		printf( "%s\n", foo );
}

int
main( int argc, char *argv[] )
{
	GtkWidget *widget;
	GtkButton *button;
	GtkObject *object;

 	gtk_set_locale ();

 	gtk_init (&argc, &argv);

	/* widget */

	widget = gtk_button_new_with_label ("foo");

  gtk_signal_connect (GTK_OBJECT(widget), "destroy",
    GTK_SIGNAL_FUNC(PrintAndExit), "widget, object destroy");

	gtk_object_destroy( GTK_OBJECT( widget ) );

	widget = gtk_button_new_with_label ("foo");

  gtk_signal_connect (GTK_OBJECT(widget), "destroy",
    GTK_SIGNAL_FUNC(PrintAndExit), "widget, widget destroy");

	gtk_widget_destroy( widget );

	/* button */

	button = (GtkButton *) gtk_button_new_with_label ("foo");

  gtk_signal_connect (GTK_OBJECT(button), "destroy",
    GTK_SIGNAL_FUNC(PrintAndExit), "button, object destroy");

	gtk_object_destroy( GTK_OBJECT( button ) );

	button = (GtkButton *) gtk_button_new_with_label ("foo");

  gtk_signal_connect (GTK_OBJECT(button), "destroy",
    GTK_SIGNAL_FUNC(PrintAndExit), "button, widget destroy");

	gtk_widget_destroy( GTK_WIDGET( button ) );

	/* object */

	object = (GtkObject *) gtk_button_new_with_label ("foo");

  gtk_signal_connect (object, "destroy",
    GTK_SIGNAL_FUNC(PrintAndExit), "object, object destroy");

	gtk_object_destroy( object );

	object = (GtkObject *) gtk_button_new_with_label ("foo");

  gtk_signal_connect (object, "destroy",
    GTK_SIGNAL_FUNC(PrintAndExit), "object, widget destroy");

	gtk_widget_destroy( GTK_WIDGET( object ) );

	return( 0 );
}


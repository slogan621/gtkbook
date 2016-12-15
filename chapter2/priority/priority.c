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

gint
foo( gpointer data )
{
	fprintf( stderr, "%s\n", data );
	return( 1 );
}

int
main( int argc, char *argv[] )
{
  	gtk_set_locale ();

  	gtk_init (&argc, &argv);

	gtk_idle_add_priority( GTK_PRIORITY_DEFAULT, foo, "GTK_PRIORITY_DEFAULT" );
	gtk_idle_add_priority( GTK_PRIORITY_DEFAULT + 100, foo, "GTK_PRIORITY_DEFAULT + 100" );
	gtk_idle_add_priority( GTK_PRIORITY_DEFAULT - 100, foo, "GTK_PRIORITY_DEFAULT - 100" );
	gtk_idle_add_priority( GTK_PRIORITY_DEFAULT + 200, foo, "GTK_PRIORITY_DEFAULT + 200" );
	gtk_idle_add_priority( GTK_PRIORITY_DEFAULT - 200, foo, "GTK_PRIORITY_DEFAULT - 200" );
	gtk_idle_add_priority( GTK_PRIORITY_DEFAULT + 300, foo, "GTK_PRIORITY_DEFAULT + 300 one" );
	gtk_idle_add_priority( GTK_PRIORITY_DEFAULT + 300, foo, "GTK_PRIORITY_DEFAULT + 300 two" );
	gtk_idle_add_priority( GTK_PRIORITY_DEFAULT + 150, foo, "GTK_PRIORITY_DEFAULT + 150" );
	gtk_idle_add_priority( GTK_PRIORITY_DEFAULT - 300, foo, "GTK_PRIORITY_DEFAULT - 300 one" );
	gtk_idle_add_priority( GTK_PRIORITY_DEFAULT - 300, foo, "GTK_PRIORITY_DEFAULT - 300 two" );
	gtk_idle_add_priority( GTK_PRIORITY_DEFAULT - 150, foo, "GTK_PRIORITY_DEFAULT - 150" );
	gtk_main ();

	return( 0 );
}


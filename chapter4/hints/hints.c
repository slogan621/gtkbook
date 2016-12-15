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
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <gtk/gtk.h>

static GtkWidget *window;

void
AlarmFunc( int foo )
{
	static int i = 1;
	gtk_widget_set_usize( window, i * 100, i * 100 );
	if (i == 1 )
		i = 2;
	else if ( i == 2 )
    i = 3;
  else if ( i == 3 ) 
		i = 4;
  else if ( i == 4 )
    i = 1;
  alarm(5);
}

void
QuitAndExit (GtkWidget *widget, char timestr[4][26])
{
	int	i;

	gtk_main_quit ();
}

int
main( int argc, char *argv[] )
{
  struct sigaction old, act;
  GdkWindowHints geo_mask;
  GdkGeometry geometry;

 	gtk_set_locale();

 	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_widget_set_usize( window, 200, 200 );

 	gtk_signal_connect (GTK_OBJECT(window), "destroy", 
		GTK_SIGNAL_FUNC(QuitAndExit), NULL);

 	gtk_window_set_title(GTK_WINDOW (window), "Hints");
 	gtk_window_set_policy(GTK_WINDOW (window), TRUE, TRUE, TRUE);

	geo_mask = GDK_HINT_MIN_SIZE | GDK_HINT_MAX_SIZE;

	geometry.min_width = 200;
	geometry.max_width = G_MAXINT;
	geometry.min_height = 200;
	geometry.max_height = G_MAXINT;

	gtk_window_set_geometry_hints(GTK_WINDOW(window), window, &geometry, 
		geo_mask );

	gtk_widget_show_all (window);

	act.sa_handler = AlarmFunc;
  act.sa_flags = 0;
  sigaction( SIGALRM, &act, &old );
  alarm( 5L );

	gtk_main ();

	sigaction( SIGALRM, &old, NULL );

	return( 0 );
}


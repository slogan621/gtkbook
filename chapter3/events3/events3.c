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
#include <gtk/gtk.h>
#include <unistd.h>
#include <signal.h>

static GtkWidget *drawing;

void
AlarmFunc( int foo )
{
	GdkEvent event;
	gint retval;

	gtk_signal_emit( GTK_OBJECT(drawing), 
		gtk_signal_lookup( "motion_notify_event", 
		GTK_OBJECT_TYPE(drawing) ), &event, &retval );

	alarm(1L);
}

static void
motion_notify_callback( GtkWidget *widget, GdkEventMotion *event, char *arg )
{
	static int count = 1;

	fprintf( stderr, "In motion_notify_callback %s %03d\n", arg, count++ );
	fflush( stderr );
}

void
Exit (GtkWidget *widget, gpointer arg)
{
	gtk_main_quit ();
}

int
main( int argc, char *argv[] )
{
	GtkWidget *window, *box;
	struct sigaction old, act;

 	gtk_set_locale ();

 	gtk_init (&argc, &argv);

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

 	gtk_signal_connect (GTK_OBJECT(window), "destroy", 
		GTK_SIGNAL_FUNC(Exit), NULL);

 	gtk_window_set_title (GTK_WINDOW (window), "Events 3");
 	gtk_container_border_width (GTK_CONTAINER (window), 0);

 	box = gtk_vbox_new (FALSE, 0);
 	gtk_container_add (GTK_CONTAINER (window), box);

 	drawing = gtk_drawing_area_new ();
	gtk_widget_set_events (drawing, GDK_EXPOSURE_MASK|GDK_POINTER_MOTION_MASK);
  gtk_signal_connect( GTK_OBJECT(drawing), "motion_notify_event",
    GTK_SIGNAL_FUNC(motion_notify_callback), "Hello World" );
  gtk_box_pack_start (GTK_BOX (box), drawing, TRUE, TRUE, 0);

	gtk_widget_show_all (window);

	act.sa_handler = AlarmFunc;
	act.sa_flags = 0;	
	sigaction( SIGALRM, &act, &old );
	alarm( 1L );

	gtk_main ();

  sigaction( SIGALRM, &old, NULL );
	return( 0 );
}


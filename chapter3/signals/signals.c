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

void
Update (GtkWidget *widget, char *timestr)
{
	time_t timeval;

	timeval = time( NULL );
	strcpy( timestr, ctime( &timeval ) );
}

void
PrintAndExit (GtkWidget *widget, char timestr[4][26])
{
	int	i;

	for ( i = 0; i < 4; i++ ) 
		printf( "timestr[ %d ] is %s", i, timestr[ i ] ); 
	gtk_main_quit ();
}

int
main( int argc, char *argv[] )
{
	GtkWidget *window, *box, *button;

	static char times[ 4 ][ 26 ] = 
		{ "Unset\n", "Unset\n", "Unset\n", "Unset\n" };

 	gtk_set_locale ();

 	gtk_init (&argc, &argv);

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

 	gtk_signal_connect (GTK_OBJECT(window), "destroy", 
		GTK_SIGNAL_FUNC(PrintAndExit), times);

 	gtk_window_set_title (GTK_WINDOW (window), "Signals 1");
 	gtk_container_border_width (GTK_CONTAINER (window), 0);

 	box = gtk_vbox_new (FALSE, 0);
 	gtk_container_add (GTK_CONTAINER (window), box);

 	button = gtk_button_new_with_label ("Update 0");
 	gtk_signal_connect (GTK_OBJECT (button), "clicked",
   	GTK_SIGNAL_FUNC(Update), &times[0]);
 	gtk_box_pack_start (GTK_BOX (box), button, TRUE, TRUE, 0);

 	button = gtk_button_new_with_label ("Update 1");
 	gtk_signal_connect (GTK_OBJECT (button), "clicked",
   	GTK_SIGNAL_FUNC(Update), &times[1]);
 	gtk_box_pack_start (GTK_BOX (box), button, TRUE, TRUE, 0);

	button = gtk_button_new_with_label ("Update 2");
 	gtk_signal_connect (GTK_OBJECT (button), "clicked",
   	GTK_SIGNAL_FUNC(Update), &times[2]);
 	gtk_box_pack_start (GTK_BOX (box), button, TRUE, TRUE, 0);

 	button = gtk_button_new_with_label ("Update 3");
 	gtk_signal_connect (GTK_OBJECT (button), "clicked",
   	GTK_SIGNAL_FUNC(Update), &times[3]);
 	gtk_box_pack_start (GTK_BOX (box), button, TRUE, TRUE, 0);

	gtk_widget_show_all (window);

	gtk_main ();

	return( 0 );
}


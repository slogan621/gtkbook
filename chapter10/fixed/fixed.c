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
#include <stdlib.h>

/* number of GtkLabel widgets */

#define NUM_LABELS 10

/* width, height of window. used to determine if we need to change direction
   of movement */

#define WIN_WIDTH 300
#define WIN_HEIGHT 200

/* what we know about a label: its widget, its current position, and direction
   of movement */

typedef struct _labels
{
	GtkWidget *w;
	gint x;
	gint y;
	gint x_trend;
	gint y_trend;
} Labels;

static Labels labels[NUM_LABELS];
static GtkWidget *fixed;

/* called 10 times a second to compute new positions for all of the labels, 
   and adjust directions of movement if necessary */
 
gint
fixed_timeout (gpointer data)
{
	gint x_inc, y_inc;
	int i;

	for ( i = 0; i < NUM_LABELS; i++ ) {

		/* compute new movement in range of 0 to 10 pixels */

		x_inc = ((float) rand() / RAND_MAX) * 10;
		y_inc = ((float) rand() / RAND_MAX) * 10;

		/* add (or subtract) increment to (from)  both x and y 
		   positions of widget */

		labels[i].x += x_inc * labels[i].x_trend;
		labels[i].y += y_inc * labels[i].y_trend;

		/* 
		   if label has gone offscreen, flip the direction of 
		   movement for the label (only flip the component that 
	     went offscreen)
		*/

		if ( labels[i].x > WIN_WIDTH ) 
			labels[i].x_trend = -1; 
		else if ( labels[i].x < 0 )
			labels[i].x_trend = 1; 
		if ( labels[i].y > WIN_HEIGHT ) 
			labels[i].y_trend = -1; 
		else if ( labels[i].y < 0 )
			labels[i].y_trend = 1; 

		/* clear the previous position. GtkFixed doesn't do this 
		   very cleanly */

		gtk_widget_queue_clear (labels[i].w);

		/* reposition the widget */

		gtk_fixed_move( GTK_FIXED( fixed ), labels[i].w, 
      labels[i].x, labels[i].y );
	}
		
}

int main( int argc, char *argv[] )
{
 	GtkWidget *window;
	int i, timer;
 
 	gtk_init (&argc, &argv);

 	/* create a window, sets its size and title */
 
 	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
 	gtk_signal_connect (GTK_OBJECT(window), "destroy", 
		GTK_SIGNAL_FUNC (gtk_main_quit), "WM destroy");
 	gtk_window_set_title (GTK_WINDOW(window), "Fixed");
 	gtk_widget_set_usize (GTK_WIDGET(window), WIN_WIDTH, WIN_HEIGHT);

	/* create an instance of GtkFixed, add it to the window */

 	fixed = gtk_fixed_new();
 	gtk_container_add( GTK_CONTAINER( window ), fixed );
 	gtk_widget_show (fixed);

	/* create the labels, placing them in the middle of the window 
     using gtk_fixed_put(). Set the direction trends to random values */

 	for ( i = 0; i < NUM_LABELS; i++ ) {
 		labels[i].w = gtk_label_new ("Gtk+ Rules!");
		labels[i].x = WIN_WIDTH / 2; labels[i].y = WIN_HEIGHT / 2;
		labels[i].x_trend = (rand() > RAND_MAX / 2 ? 1 : -1 ); 
		labels[i].y_trend = (rand() > RAND_MAX / 2 ? 1 : -1 );
 		gtk_widget_show( labels[i].w );
		gtk_fixed_put( GTK_FIXED( fixed ), labels[i].w, 
			labels[i].x, labels[i].y );
 	}

 	gtk_widget_show (window);

	/* register a timeout callback with Gtk+ to fire every 100ms */

 	timer = gtk_timeout_add (100, fixed_timeout, NULL);
 	gtk_main ();
 
 	return(0);
}

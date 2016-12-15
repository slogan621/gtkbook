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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static GtkWidget *list;

static void
QuitCallback(GtkWidget *widget, GtkWidget *dialog_window)
{
	gtk_main_quit();
	exit( 0 );
}

static void
AddCallback(GtkWidget *widget, GtkWidget *dialog_window)
{
	int	i;
	char 	*texts[5];
	char 	buf[10];

	for ( i = 0; i < 100; i++ )
	{
	  texts[0] = "36123-A";
	  texts[1] = "Wood Chisel Set";
	  texts[2] = "9.99";
	  sprintf( buf, "%d", i );
	  texts[3] = buf;
	  texts[4] = "9.99";
	  gtk_clist_append( GTK_CLIST( list ), texts );
	}
	gtk_clist_moveto( GTK_CLIST( list ), 75 + 4, -1, 0.5, 0.5 );
}

main( int argc, char *argv[] )
{
	GtkWidget *button, *scrolled_win, *dialog_window;
	char *texts[5];

	static char *titles[] =
	{
	  "Part #",
	  "Description",
	  "Unit Price",
	  "Quantity",
	  "Total",
	};

	gtk_init( &argc, &argv );

	dialog_window = gtk_dialog_new();
 	gtk_window_position (GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);

 	scrolled_win = gtk_scrolled_window_new (NULL, NULL);

	gtk_widget_set_usize( scrolled_win, 300, 100 );

 	gtk_container_set_border_width (GTK_CONTAINER (scrolled_win), 5);
 	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled_win), 
		GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

	gtk_container_add (GTK_CONTAINER (GTK_DIALOG (dialog_window)->vbox), 
		scrolled_win);

  list = gtk_clist_new_with_titles( 5, titles );

	texts[0] = "36123-A";
	texts[1] = "Wood Chisel Set";
	texts[2] = "9.99";
	texts[3] = "1";
	texts[4] = "9.99";
	gtk_clist_append( GTK_CLIST( list ), texts );
	texts[0] = "45661-A";
	texts[1] = "Work Gloves";
	texts[2] = "5.99";
	texts[3] = "1";
	texts[4] = "5.99";
	gtk_clist_append( GTK_CLIST( list ), texts );
	texts[0] = "34991-Q";
	texts[1] = "Claw Hammer";
	texts[2] = "7.99";
	texts[3] = "1";
	texts[4] = "7.99";
	gtk_clist_append( GTK_CLIST( list ), texts );
	texts[0] = "30125-S";
	texts[1] = "Deluxe Lawn Rake";
	texts[2] = "12.99";
	texts[3] = "1";
	texts[4] = "12.99";
	gtk_clist_append( GTK_CLIST( list ), texts );

	gtk_clist_set_column_auto_resize(GTK_CLIST(list), 0, TRUE );
	gtk_clist_set_column_auto_resize(GTK_CLIST(list), 1, TRUE );
	gtk_clist_set_column_auto_resize(GTK_CLIST(list), 2, TRUE );
	gtk_clist_set_column_auto_resize(GTK_CLIST(list), 3, TRUE );
	gtk_clist_set_column_auto_resize(GTK_CLIST(list), 4, TRUE );

	gtk_container_add (GTK_CONTAINER (scrolled_win), list);

 	button = gtk_button_new_with_label ("Quit");
 	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area), 
		button, TRUE, TRUE, 0);
 	gtk_signal_connect (GTK_OBJECT (button), "clicked", 
		GTK_SIGNAL_FUNC(QuitCallback), dialog_window);
 	button = gtk_button_new_with_label ("Add");
 	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area), 
		button, TRUE, TRUE, 0);
 	gtk_signal_connect (GTK_OBJECT (button), "clicked", 
	  GTK_SIGNAL_FUNC(AddCallback), dialog_window);
  gtk_widget_show_all (dialog_window);
	gtk_main();
}

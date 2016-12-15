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
foo( GtkWidget *widget, GdkEventKey *event, gpointer data )
{
	static char tmp[2];
	static char password[1024] = "";
	char c;

	if ( (c = (char) event->keyval) == '\n' || c == '\r' ) {
		printf( "Password is '%s'\n", password );
		gtk_exit( 0 );
	}
		
	tmp[0] = c; 
	tmp[1] = '\0';
	strcat( password, tmp );
	event->keyval = event->string[0] = '*';
	return( 0 );
}

int
main( int argc, char *argv[] )
{
	GtkWidget *window, *box, *entry;

  	gtk_set_locale ();

  	gtk_init (&argc, &argv);

        window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title( GTK_WINDOW( window ), "Enter Password" );

        box = gtk_vbox_new (FALSE, 0);
        gtk_container_add (GTK_CONTAINER (window), box);

        entry = gtk_entry_new ();
        gtk_entry_set_text (GTK_ENTRY (entry), "");
        gtk_editable_select_region (GTK_EDITABLE (entry), 0, -1);
        gtk_box_pack_start (GTK_BOX (box), entry, TRUE, TRUE, 0);

	gtk_key_snooper_install( foo, (gpointer) NULL );

	gtk_widget_show_all( window );

	gtk_main ();

	return( 0 );
}


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
#include <sys/stat.h>

gboolean
IsFile( char *path )
{
	struct stat buf;

	lstat( path, &buf );
	return(S_ISREG( buf.st_mode ));
}

void
FileSelOk(GtkWidget *w, gpointer arg)
{
	GtkFileSelection *fileSel = GTK_FILE_SELECTION( arg );
        char *name = gtk_file_selection_get_filename(fileSel);
	printf( "%s\n", name );
	if ( IsFile( name ) )
		printf( "Is a file\n" );
	else
		printf( "Is a directory\n" );
	gtk_widget_hide( GTK_WIDGET( fileSel ) );
	gtk_widget_show( GTK_WIDGET( fileSel ) );
}

main( int argc, char *argv[] )
{
	GtkWidget *fileSel, *checkbutton, *hbox;

	gtk_init( &argc, &argv );

	fileSel = gtk_file_selection_new( "GtkFileSelection" );

	gtk_file_selection_complete(GTK_FILE_SELECTION(fileSel), "/tmp/fig5-14.gif" );
	gtk_file_selection_set_filename(GTK_FILE_SELECTION(fileSel), "file.txt");

	hbox = gtk_hbox_new( FALSE, 0 );

	gtk_box_pack_start( GTK_BOX( GTK_FILE_SELECTION(fileSel)->main_vbox ),
		hbox, FALSE, FALSE, 0 );

	checkbutton = gtk_check_button_new_with_label(
		"Automatically create a log file" );
	gtk_box_pack_start( GTK_BOX( hbox ), checkbutton, FALSE, FALSE, 0 );

	gtk_widget_show( hbox );
	gtk_widget_show( checkbutton );

	gtk_signal_connect(GTK_OBJECT(GTK_FILE_SELECTION(fileSel)->ok_button),
 	  "clicked", (GtkSignalFunc) FileSelOk, fileSel );

  gtk_signal_connect_object(GTK_OBJECT( 
    GTK_FILE_SELECTION(fileSel)->cancel_button), "clicked", 
		(GtkSignalFunc) gtk_widget_destroy, GTK_OBJECT(fileSel));
	
	gtk_widget_show( fileSel );
	gtk_main();
}


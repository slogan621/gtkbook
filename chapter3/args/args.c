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
#include <stdio.h>

int
main( int argc, char *argv[] )
{
	GtkWidget *widget;
	GtkArg *args;
	guint nArgs;
	guint32 *flags = (guint32 *) NULL;
	int i;

 	gtk_init (&argc, &argv);

	widget = gtk_button_new_with_label( "This is a test" );

  args = gtk_object_query_args( gtk_button_get_type(), &flags, &nArgs );
	
	if ( args == (GtkArg *) NULL ) {
		fprintf( stderr, "Unable to query widget's args\n" );
		exit( 1 );
	}

	printf( "There %s %d arg%s found%s\n", (nArgs == 1 ? "was" : "were" ),
		nArgs, (nArgs == 1 ? "" : "s" ), (nArgs == 0 ? "." : ":" ) );

	for ( i = 0; i < nArgs; i++ ) {
		printf( "Name: '%s', type: ", args[i].name );	

		switch( GTK_FUNDAMENTAL_TYPE (args[i].type) ) {
		case GTK_TYPE_CHAR :
			printf( "GTK_TYPE_CHAR, " );
			break;	
		case GTK_TYPE_UCHAR :
			printf( "GTK_TYPE_UCHAR, " ); 
			break;	
		case GTK_TYPE_BOOL :
			printf( "GTK_TYPE_BOOL, " );
			break;	
		case GTK_TYPE_INT :
			printf( "GTK_TYPE_INT, " );
			break;	
		case GTK_TYPE_UINT :
			printf( "GTK_TYPE_UINT, " );
			break;	
		case GTK_TYPE_LONG :
			printf( "GTK_TYPE_LONG, " );
			break;	
		case GTK_TYPE_ULONG :
			printf( "GTK_TYPE_ULONG, " );
			break;	
		case GTK_TYPE_FLOAT :
			printf( "GTK_TYPE_FLOAT, " );
			break;	
		case GTK_TYPE_DOUBLE :
			printf( "GTK_TYPE_DOUBLE, " );
			break;	
		case GTK_TYPE_STRING :
			printf( "GTK_TYPE_STRING, " ); 
			break;	
		case GTK_TYPE_ENUM :
			printf( "GTK_TYPE_ENUM, " );
			break;	
		case GTK_TYPE_FLAGS :
			printf( "GTK_TYPE_FLAGS, " );
			break;	
		case GTK_TYPE_BOXED :
			printf( "GTK_TYPE_BOXED, " );
			break;	
		case GTK_TYPE_POINTER :
			printf( "GTK_TYPE_POINTER, " );
			break;	
		case GTK_TYPE_INVALID:
		case GTK_TYPE_NONE:
		default:
			printf( "GTK_TYPE_INVALID, GTK_TYPE_NONE, or unknown, " );
			break;
		}	
		printf( "Flags: " ); 
		switch( flags[i] ) {
 		case GTK_ARG_READABLE :
			printf( "GTK_ARG_READABLE\n" );
		  break;
  	case GTK_ARG_WRITABLE :
			printf( "GTK_ARG_WRITABLE\n" );
			break;
  	case GTK_ARG_CONSTRUCT :
			printf( "GTK_ARG_CONSTRUCT\n" );
			break;
  	case GTK_ARG_CONSTRUCT_ONLY :
			printf( "GTK_ARG_CONSTRUCT_ONLY\n" );
			break;
  	case GTK_ARG_CHILD_ARG :
			printf( "GTK_ARG_CHILD_ARG\n" );
			break;
  	case GTK_ARG_READWRITE :
			printf( "GTK_ARG_READWRITE\n" );
			break;
		}
	}

	/* not really needed, as we are exiting */

	if ( flags )
		g_free( flags );
	if ( args )
		g_free( args );		

	return( 0 );
}


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

int
main( int argc, char *argv[] )
{
	GtkWidget *widget;
	GtkArg *args;
	guint nArgs;
	guint32 *flags = (guint32 *) NULL;
	int i;

 	gtk_set_locale ();

 	gtk_init (&argc, &argv);

	widget = gtk_button_new_with_label( "This is a test" );

  args = gtk_object_query_args( gtk_button_get_type(), &flags, &nArgs );
	
	if ( args == (GtkArg *) NULL ) {
		fprintf( stderr, "Unable to query widget's args\n" );
		exit( 1 );
	}

	for ( i = 0; i < nArgs; i++ ) {

		printf( "Name: '%s', value: ", args[i].name );	

		if ( flags[i] == GTK_ARG_READABLE 
			|| flags[i] == GTK_ARG_READWRITE ) {

			gtk_object_arg_get( GTK_OBJECT( widget ), &args[i], NULL );

			switch( GTK_FUNDAMENTAL_TYPE (args[i].type) ) {
			case GTK_TYPE_CHAR :
				printf( "%c\n", GTK_VALUE_CHAR (args[i]) );
				break;	
			case GTK_TYPE_UCHAR :
				printf( "%c\n", GTK_VALUE_UCHAR (args[i]) );
				break;	
			case GTK_TYPE_BOOL :
				printf( "%s\n", (GTK_VALUE_BOOL(args[i])==TRUE?  "TRUE":"FALSE"));
				break;	
			case GTK_TYPE_INT :
				printf( "%d\n", GTK_VALUE_INT (args[i]) );
				break;	
			case GTK_TYPE_UINT :
				printf( "%u\n", GTK_VALUE_UINT (args[i]) );
				break;	
			case GTK_TYPE_LONG :
				printf( "%ld\n", GTK_VALUE_LONG (args[i]) );
				break;	
			case GTK_TYPE_ULONG :
				printf( "%lu\n", GTK_VALUE_ULONG (args[i]) );
				break;	
			case GTK_TYPE_FLOAT :
				printf( "%f\n", GTK_VALUE_FLOAT (args[i]) );
				break;	
			case GTK_TYPE_DOUBLE :
				printf( "%lf\n", GTK_VALUE_DOUBLE (args[i]) );
				break;	
			case GTK_TYPE_STRING :
				printf( "%s\n", GTK_VALUE_STRING (args[i]) );
				g_free (GTK_VALUE_STRING (args[i]));
				break;	
			case GTK_TYPE_ENUM :
				printf( "%d\n", GTK_VALUE_ENUM (args[i]) );
				break;	
			case GTK_TYPE_FLAGS :
				printf( "%xd\n", GTK_VALUE_FLAGS (args[i]) );
				break;	
			case GTK_TYPE_BOXED :
				printf( "%x\n", GTK_VALUE_BOXED (args[i]) );
				break;	
			case GTK_TYPE_POINTER :
				printf( "%x\n", GTK_VALUE_POINTER (args[i]) );
				break;	
			case GTK_TYPE_INVALID:
				printf( "Attribute is invalid\n" );
				break;
			case GTK_TYPE_NONE:
				printf( "Attribute is none\n" );
				break;
			default:
				break;
			}	
		}
	}

	/* not really needed, as we are exiting */

	if ( flags )
		g_free( flags );
	if ( args )
		g_free( args );		

	return( 0 );
}


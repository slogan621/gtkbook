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
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

static void
SetPointCB(GtkWidget *widget, GtkWidget *text)
{
  gtk_text_set_point(GTK_TEXT(text), 100);
}

static void
InsertCB(GtkWidget *widget, GtkWidget *text)
{
  char *buf;
  GdkFont *font;
  GdkColor col1, col2;
  struct stat statbuf;
  int fd;

  col1.red   = 0;
  col1.green = 56000;
  col1.blue  = 0;

  col2.red   = 32000;
  col2.green = 0;
  col2.blue  = 56000;

  font = gdk_font_load("-*-helvetica-bold-r-normal-*-20-*-*-*-*-*-*-*");

  gdk_color_alloc(gtk_widget_get_colormap(text), &col1);
  gdk_color_alloc(gtk_widget_get_colormap(text), &col2);

  fd = open( "/etc/passwd", O_RDONLY );

  fstat( fd, &statbuf );

  buf = (char *) malloc( statbuf.st_size );

  read( fd, buf, statbuf.st_size );

  gtk_text_freeze( GTK_TEXT( text ) );
  gtk_text_insert(GTK_TEXT(text), font, &col1, &col2, 
    buf, statbuf.st_size );

  gtk_text_thaw( GTK_TEXT( text ) );
  close( fd );
  free( buf );
}

static void
ForwardDelCB(GtkWidget *widget, GtkWidget *text)
{
  gtk_text_forward_delete(GTK_TEXT(text), 25);
}

static void
QueryCB(GtkWidget *widget, GtkWidget *text)
{
  printf( "point is %d length is %d\n", gtk_text_get_point( 
    GTK_TEXT( text ) ), gtk_text_get_length( GTK_TEXT( text ) ) );
}

static void
GetCB(GtkWidget *widget, GtkWidget *text)
{
  printf( "text is:\n %s\n", gtk_editable_get_chars( GTK_EDITABLE(text), 0, 
    gtk_text_get_length( GTK_TEXT( text ) ) - 1 ) );
}

static void
BackwardDelCB(GtkWidget *widget, GtkWidget *text)
{
  gtk_text_backward_delete(GTK_TEXT(text), 25);
}

main( argc, argv )
int argc;
char *argv[];
{
  GtkWidget *vbox, *bbox, *window, *swin, *text, *button;

  gtk_init( &argc, &argv );

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_position(GTK_WINDOW(window), GTK_WIN_POS_MOUSE);

  gtk_signal_connect(GTK_OBJECT(window), "destroy",
    GTK_SIGNAL_FUNC(gtk_widget_destroyed), &window);

  gtk_window_set_title(GTK_WINDOW (window), "GtkText Demo");

  vbox = gtk_vbox_new( FALSE, 0 );
  gtk_container_add( GTK_CONTAINER( window ), vbox );

#if 1
  swin = gtk_scrolled_window_new( NULL, NULL );
  gtk_box_pack_start( GTK_BOX( vbox ), swin, TRUE, TRUE, 0 );
#endif

  text = gtk_text_new( NULL, NULL );

  gtk_text_set_editable( GTK_TEXT( text ), FALSE );
  gtk_text_set_word_wrap( GTK_TEXT( text ), TRUE );
  gtk_text_set_line_wrap( GTK_TEXT( text ), TRUE );

#if 1
  gtk_container_add( GTK_CONTAINER( swin ), text );
#else
  gtk_box_pack_start( GTK_BOX( vbox ), text, TRUE, TRUE, 0 );
#endif

  bbox = gtk_hbutton_box_new();

  gtk_box_pack_end( GTK_BOX( vbox ), bbox, FALSE, FALSE, 0 );

  button = gtk_button_new_with_label( "Set Point" );
  gtk_box_pack_start(GTK_BOX(bbox), button, FALSE, TRUE, 0);

  gtk_signal_connect(GTK_OBJECT(button), "clicked",
    GTK_SIGNAL_FUNC(SetPointCB), text);

  button = gtk_button_new_with_label( "Insert Text" );
  gtk_box_pack_start(GTK_BOX(bbox), button, FALSE, TRUE, 0);

  gtk_signal_connect(GTK_OBJECT(button), "clicked",
    GTK_SIGNAL_FUNC(InsertCB), text);

  button = gtk_button_new_with_label( "Forward Del" );
  gtk_box_pack_start(GTK_BOX(bbox), button, FALSE, TRUE, 0);

  gtk_signal_connect(GTK_OBJECT(button), "clicked",
    GTK_SIGNAL_FUNC(ForwardDelCB), text);

  button = gtk_button_new_with_label( "Backward Del" );
  gtk_box_pack_start(GTK_BOX(bbox), button, FALSE, TRUE, 0);

  gtk_signal_connect(GTK_OBJECT(button), "clicked",
    GTK_SIGNAL_FUNC(BackwardDelCB), text);

  button = gtk_button_new_with_label( "Query" );
  gtk_box_pack_start(GTK_BOX(bbox), button, FALSE, TRUE, 0);

  gtk_signal_connect(GTK_OBJECT(button), "clicked",
    GTK_SIGNAL_FUNC(QueryCB), text);

  button = gtk_button_new_with_label( "Get" );
  gtk_box_pack_start(GTK_BOX(bbox), button, FALSE, TRUE, 0);

  gtk_signal_connect(GTK_OBJECT(button), "clicked",
    GTK_SIGNAL_FUNC(GetCB), text);

  gtk_widget_show_all( GTK_WIDGET( window ) );

  // call the insert text callback directly and seed the widget with text

  InsertCB((GtkWidget *) NULL, text);
        
  gtk_main();
}


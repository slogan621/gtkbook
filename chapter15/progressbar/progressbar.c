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

// make life easier and make these external

static int timer1, timer2;
static GtkWidget *dloadwin;

#define NUMFILES 25

// generate a random connection time

#define RAND(lower, upper) (int) ((((float) random() / RAND_MAX) * \
  (upper - lower ) ) + lower )

// user canceled the download operation

static void
CancelDownload(GtkWidget *widget, GtkWidget *window)
{
  gtk_timeout_remove( timer1 );
  gtk_widget_destroy( window );
}

// simulate the completion of a single file download 

static gint
DownloadTimeout(gpointer data)
{
  gfloat new_val;
  GtkAdjustment *adj;

  adj = GTK_PROGRESS (data)->adjustment;

  new_val = adj->value + 1;
  if (new_val > adj->upper) {
    CancelDownload( (GtkWidget *) NULL, dloadwin );
    return( FALSE );
  }

  gtk_progress_set_value (GTK_PROGRESS (data), new_val);

  return TRUE;
}

// simulate the download of a set of files

static void
DownloadFile()
{
  GtkWidget *dialog_window, *label, *progress, *button; 

  dialog_window = dloadwin = gtk_dialog_new();
  gtk_window_set_modal (GTK_WINDOW(dialog_window),TRUE);

  gtk_window_position(GTK_WINDOW(dialog_window), GTK_WIN_POS_MOUSE);

  label = gtk_label_new( "Downloading files..." );

  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->vbox), 
    label, TRUE, TRUE, 0);

  progress = gtk_progress_bar_new();

  gtk_progress_bar_set_bar_style(GTK_PROGRESS_BAR(progress), 
    GTK_PROGRESS_DISCRETE );

  gtk_progress_configure( GTK_PROGRESS(progress), 1.0, 1.0, 
    (float) NUMFILES );

  gtk_progress_set_show_text( GTK_PROGRESS(progress), TRUE );
	
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->vbox), 
    progress, TRUE, TRUE, 0);

  button = gtk_button_new_with_label( "Cancel" );

  gtk_signal_connect (GTK_OBJECT (button), "clicked",
    GTK_SIGNAL_FUNC(CancelDownload), dialog_window); 

  gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog_window)->action_area),
    button, TRUE, TRUE, 0);

  timer1 = gtk_timeout_add(200, DownloadTimeout, progress);

  gtk_widget_show_all (dialog_window);
}

// user hit the "Cancel" button while connecting

static void
CancelConnect(GtkWidget *widget, GtkWidget *window)
{
  gtk_timeout_remove( timer1 );
  gtk_timeout_remove( timer2 );
  gtk_widget_destroy( window );
}

// simulate the connection finishing

static gint 
ActivityProgressDone(gpointer data)
{
  GtkWidget *window = (GtkWidget *) data;

  gtk_timeout_remove( timer1 );
  gtk_widget_destroy( window );

  DownloadFile();
  return FALSE;
}

// process an activity mode timeout (simulate the passing of time
// while connecting

static gint
ActivityProgressTimeout(gpointer data)
{
  gfloat new_val;
  GtkAdjustment *adj;

  adj = GTK_PROGRESS (data)->adjustment;

  new_val = adj->value + 1;
  if (new_val > adj->upper)
    new_val = adj->lower;

  gtk_progress_set_value (GTK_PROGRESS (data), new_val);

  return TRUE;
}

// user hit the "Connect" button in the main dialog

static void
Connect(GtkWidget *widget, GtkEntry *entry)
{
  GtkWidget *dialog_window, *label, *progress, *button; 
  char buf[ 128 ];
  int connecttime;

  char *server = gtk_entry_get_text( entry );

  snprintf( buf, sizeof(buf) - 1, "Connecting to '%s'...", server ); 

  dialog_window = gtk_dialog_new();
  gtk_window_set_modal (GTK_WINDOW(dialog_window),TRUE);

  gtk_window_position(GTK_WINDOW(dialog_window), GTK_WIN_POS_MOUSE);

  label = gtk_label_new( buf );

  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->vbox), 
    label, TRUE, TRUE, 0);

  progress = gtk_progress_bar_new();

  gtk_progress_set_activity_mode( GTK_PROGRESS( progress ), TRUE );

  gtk_progress_configure( GTK_PROGRESS(progress), 1.0, 1.0, 10.0 );
	
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->vbox), 
    progress, TRUE, TRUE, 0);

  button = gtk_button_new_with_label( "Cancel" );

  gtk_signal_connect (GTK_OBJECT (button), "clicked",
    GTK_SIGNAL_FUNC(CancelConnect), dialog_window); 

  gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog_window)->action_area),
    button, TRUE, TRUE, 0);

  timer1 = gtk_timeout_add(100, ActivityProgressTimeout, progress);
  connecttime = RAND(1000, 8000 );
  timer2 = gtk_timeout_add(connecttime, ActivityProgressDone, 
    (gpointer) dialog_window);

  gtk_widget_show_all (dialog_window);
}

main( int argc, char *argv[] )
{
  GtkWidget *dialog_window, *hbox, *button, *label, *entry;

  gtk_init( &argc, &argv );

  dialog_window = gtk_dialog_new();
  gtk_window_position(GTK_WINDOW(dialog_window), GTK_WIN_POS_MOUSE);

  hbox = gtk_hbox_new( FALSE, 5 );
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->vbox), 
    hbox, TRUE, TRUE, 0);

  label = gtk_label_new( "Server:" );
  entry = gtk_entry_new();
  gtk_entry_set_text( GTK_ENTRY( entry ), "ftp.gtk.org" );
	
  gtk_box_pack_start (GTK_BOX (hbox), label, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (hbox), entry, TRUE, TRUE, 0);

  button = gtk_button_new_with_label( "Connect" );

  gtk_signal_connect (GTK_OBJECT (button), "clicked",
    GTK_SIGNAL_FUNC(Connect), entry);

  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area),
    button, TRUE, TRUE, 0);

  gtk_widget_show_all (dialog_window);
  gtk_main();
}

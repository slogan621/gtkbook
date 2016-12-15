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

// an appointment book entry

typedef struct _calentry {
  int day;		// day of the month
  char *timestr;		// time of the appointment
  char *title;		// appointment title
  char *location;		// appointment location
} CalEntry;

// Appointment book (only 1 month of data here, all hardcoded, for 
// simplicity sake 

static CalEntry entries[] = {
  { 3, "11:30 AM", "Lunch with Bob", "Joe's Grill"},
  { 6, "5:00 PM", "Pick up Sally at airport", "Airport" },
  { 7, "3:40 PM", "Dentist", "Dr. Jones"},
  { 14, "6:15 PM", "Dinner with team", "TBD"},
  { 17, "9:00 AM", "Golf", "Torrey Pines, North Course"},
  { 18, "1:00 PM", "Sally's flight home", "Airport" },
  { 19, "11:30 AM", "Phone roofer", "N/A"},
  { 22, "7:30 PM", "Take cousin to movies", "City Theatre" }
};

// format and display a message in a modal dialog

void
DisplayMessage( char *title, char *location, char *timestr )
{
  char buf[1024];
  GtkWidget *dialog, *label, *button;
	
  sprintf( buf, "%s\n Time: %s Location: %s", title, timestr, location );

  dialog = gtk_dialog_new();
  gtk_window_position(GTK_WINDOW (dialog), GTK_WIN_POS_MOUSE);
  gtk_window_set_modal(GTK_WINDOW (dialog), TRUE);

  label = gtk_label_new( buf );
  gtk_box_pack_start(GTK_BOX (GTK_DIALOG (dialog)->vbox), 
    label, TRUE, TRUE, 0);

  button = gtk_button_new_with_label ("Ok");
  gtk_signal_connect_object(GTK_OBJECT (button), "clicked",
    GTK_SIGNAL_FUNC(gtk_widget_destroy), GTK_OBJECT(dialog));
  gtk_box_pack_start(GTK_BOX (GTK_DIALOG (dialog)->action_area),
    button, FALSE, FALSE, 0);
  gtk_widget_show_all( dialog );
}

// GtkCalendar day_selected signal function. See if the selected day is in
// the appointment book and, if so, display it in a dialog 

void
SelectDay (GtkWidget *widget, gpointer data)
{
  guint year, month, day;
  int i;

  // retrieve the selected date

  gtk_calendar_get_date(GTK_CALENDAR(widget), &year, &month, &day);

  // see if it exists in the appointment book, and if it does
  // display the entry

  for ( i = 0; i < sizeof( entries ) / sizeof( CalEntry ); i++ )
    if ( entries[i].day == day ) 
      DisplayMessage( entries[i].title, 
        entries[i].location, entries[i].timestr );
}

main( int argc, char *argv[] )
{
  GtkWidget *button, *calendar, *dialog;
  GtkCalendarDisplayOptions flags;
  int i;

  gtk_init( &argc, &argv );

	dialog = gtk_dialog_new();
  gtk_window_position(GTK_WINDOW (dialog), GTK_WIN_POS_MOUSE);

  // create the calendar widget

  calendar = gtk_calendar_new();

  // retrieve the default flags

  flags = GTK_CALENDAR( calendar )->display_flags;

  // turn off the ability to change the date

#if 1
  gtk_calendar_display_options( GTK_CALENDAR( calendar ),
    flags | GTK_CALENDAR_NO_MONTH_CHANGE );
#endif

  // handle a mouse button 1 press over a day in the calendar

  gtk_signal_connect (GTK_OBJECT (calendar), "day_selected",
    GTK_SIGNAL_FUNC (SelectDay), NULL);

  // mark all days that have an entry in the appointment book

  for ( i = 0; i < sizeof( entries ) / sizeof( CalEntry ); i++ )
    gtk_calendar_mark_day( GTK_CALENDAR(calendar), entries[i].day );

  gtk_box_pack_start(GTK_BOX (GTK_DIALOG (dialog)->vbox), 
    calendar, TRUE, TRUE, 0);

  button = gtk_button_new_with_label ("Quit");
  gtk_signal_connect_object(GTK_OBJECT (button), "clicked",
    GTK_SIGNAL_FUNC(gtk_widget_destroy), GTK_OBJECT(dialog));
  gtk_box_pack_start(GTK_BOX (GTK_DIALOG (dialog)->action_area),
    button, FALSE, FALSE, 0);

  gtk_widget_show_all(dialog);
  gtk_main();
}

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

GtkWidget *callerbutton;

int
DoHelpSystem( const char *text )
{
  printf( "Help is %s\n", text );
}

static gint
tips_query_widget_selected(GtkWidget *tips_query, GtkWidget *widget,
  const gchar *tip_text, const gchar *tip_private, 
  GdkEventButton *event, gpointer func_data)
{
  if (event->type == GDK_BUTTON_RELEASE )
    return FALSE;
  if ( tip_private != (char *) NULL )
    DoHelpSystem( tip_private );
  return FALSE;
}

main( int argc, char *argv[] )
{
  GtkWidget *dialog_window, *button, *tipsq;
  GtkTooltips *tips;

  gtk_init( &argc, &argv );

  dialog_window = gtk_dialog_new();
  gtk_window_position(GTK_WINDOW(dialog_window), GTK_WIN_POS_MOUSE);

  button = gtk_button_new_with_label("Button that needs help");
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->vbox), 
    button, TRUE, TRUE, 0);
  gtk_widget_show( button );

  tips = gtk_tooltips_new();

  gtk_tooltips_set_tip(GTK_TOOLTIPS(tips), button, 
    "Click on this button to do something", "help:button1" ); 

  tipsq = gtk_tips_query_new();

//  gtk_tips_query_set_labels(tipsq, "inactive!!!!", "no tips!!!!" );

  gtk_signal_connect_object (GTK_OBJECT (tipsq), "widget_selected",
    GTK_SIGNAL_FUNC(tips_query_widget_selected), GTK_OBJECT(tipsq));

  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->vbox), 
    tipsq, TRUE, TRUE, 0);
  gtk_widget_show( tipsq );

  callerbutton = button = 
    gtk_button_new_with_label("Button that doesn't need help");
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->vbox), 
    button, TRUE, TRUE, 0);
//  gtk_tips_query_set_caller(tipsq, callerbutton );
  gtk_tooltips_set_tip(GTK_TOOLTIPS(tips), button, 
    "Click on this button to do something also", "help:button2" ); 
  gtk_widget_show( button );

  button = gtk_button_new_with_label( "Click to enter query mode!" );
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog_window)->action_area), 
    button, TRUE, TRUE, 0);
  gtk_tooltips_set_tip(GTK_TOOLTIPS(tips), button, 
    "Click on this button to do something also", "help:button3" ); 
  gtk_widget_show( button );
  gtk_tips_query_set_caller(GTK_TIPS_QUERY(tipsq), callerbutton );

  gtk_signal_connect_object (GTK_OBJECT (button), "clicked",
    GTK_SIGNAL_FUNC(gtk_tips_query_start_query), 
  GTK_OBJECT (tipsq));

  gtk_widget_show(dialog_window);
  gtk_main();
}

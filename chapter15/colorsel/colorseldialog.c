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

void
ColorSelDialogOk( GtkWidget *widget, GtkWidget *colorsel )
{
  GtkColorSelectionDialog *cseldialog = 
    GTK_COLOR_SELECTION_DIALOG( colorsel );
  GtkColorSelection *csel = GTK_COLOR_SELECTION(cseldialog->colorsel); 
  gdouble color[4];

  gtk_color_selection_get_color(csel, color);

  printf( "r %d g %d b %d\n", (int)( color[0] * 255 ), 
    (int) (color[1] * 255), (int) (color[2] * 255 ));
  gtk_widget_destroy( colorsel );
}

void
ColorSelDialogCancel( GtkWidget *widget, GtkWidget *colorsel )
{
  gtk_widget_destroy( colorsel );
}

void
PopupColorSelection( GtkWidget *widget, gpointer ignored ) 
{
  GtkWidget *colorsel;

  colorsel = gtk_color_selection_dialog_new("Select a color!");

  gtk_signal_connect(GTK_OBJECT(
    GTK_COLOR_SELECTION_DIALOG(colorsel)->ok_button), 
  "clicked", GTK_SIGNAL_FUNC(ColorSelDialogOk), colorsel );

  gtk_signal_connect(GTK_OBJECT(
    GTK_COLOR_SELECTION_DIALOG(colorsel)->cancel_button), 
    "clicked", GTK_SIGNAL_FUNC(ColorSelDialogCancel), colorsel );

  gtk_widget_show_all(colorsel);

  gtk_widget_hide(GTK_WIDGET( 
    GTK_COLOR_SELECTION_DIALOG(colorsel)->help_button));
}

main( int argc, char *argv[] )
{
  GtkWidget *button, *dialog_window;

  gtk_init( &argc, &argv );

  dialog_window = gtk_dialog_new();
  gtk_window_position(GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);

  button = gtk_button_new_with_label ("Get Color..");
  gtk_signal_connect(GTK_OBJECT (button), "clicked",
    GTK_SIGNAL_FUNC(PopupColorSelection), NULL );
  gtk_box_pack_start(GTK_BOX (GTK_DIALOG (dialog_window)->action_area),
    button, FALSE, FALSE, 0);

  gtk_widget_show_all(dialog_window);
	
  gtk_main();
}


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
GetColorSel( GtkWidget *widget, GtkWidget *colorsel )
{
  GtkColorSelection *csel = GTK_COLOR_SELECTION( colorsel );
  gdouble color[4];

  gtk_color_selection_get_color(csel, color);

  printf( "r %d g %d b %d\n", (int)( color[0] * 255 ), 
    (int) (color[1] * 255), (int) (color[2] * 255 ));
}

main( int argc, char *argv[] )
{
  GtkWidget *button, *colorsel, *dialog_window;

  gtk_init( &argc, &argv );

  dialog_window = gtk_dialog_new();
  gtk_window_position(GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);

  colorsel = gtk_color_selection_new();

  gtk_box_pack_start(GTK_BOX (GTK_DIALOG (dialog_window)->vbox), 
    colorsel, TRUE, TRUE, 0);

  button = gtk_button_new_with_label ("Close");
  gtk_signal_connect_object(GTK_OBJECT (button), "clicked",
    GTK_SIGNAL_FUNC(gtk_widget_destroy),
    GTK_OBJECT(dialog_window));
  gtk_box_pack_start(GTK_BOX (GTK_DIALOG (dialog_window)->action_area),
    button, FALSE, FALSE, 0);

  button = gtk_button_new_with_label ("Get Color");
  gtk_signal_connect(GTK_OBJECT (button), "clicked",
    GTK_SIGNAL_FUNC(GetColorSel), colorsel );
  gtk_box_pack_start(GTK_BOX (GTK_DIALOG (dialog_window)->action_area),
    button, FALSE, FALSE, 0);

  gtk_widget_show_all(dialog_window);
  gtk_main();
}

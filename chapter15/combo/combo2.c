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

typedef struct cdata {
  GtkWidget *combo;
  GList *cbitems;
} CData;

static void
GetComboEntry(GtkWidget *widget, CData *data)
{
  char *val = (char *) NULL;

  val = gtk_entry_get_text(GTK_ENTRY(GTK_COMBO(data->combo)->entry));
  if ( val )
    printf( "Value entered/selected is %s\n", val );
}

static void
AddComboEntry(GtkWidget *widget, CData *data)
{
  char *buf, *val = (char *) NULL;

  val = gtk_entry_get_text(GTK_ENTRY(GTK_COMBO(data->combo)->entry));
  if ( val != (char *) NULL ) {
    buf = (char *) malloc( strlen( val ) + 1 );
    if ( buf != (char *) NULL ) {
      strcpy( buf, val );
      data->cbitems = g_list_append(data->cbitems, buf );
      gtk_combo_set_popdown_strings(GTK_COMBO(data->combo), 
        data->cbitems);
    }
  }
}

main( int argc, char *argv[] )
{
	GtkWidget *dialog_window, *button;
	CData data;

  data.cbitems = NULL;
  gtk_init( &argc, &argv );

  dialog_window = gtk_dialog_new();
  gtk_window_position (GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);

  data.combo = gtk_combo_new();
  data.cbitems = g_list_append(data.cbitems, "Joe's Pizza Shack" );
  data.cbitems = g_list_append(data.cbitems, "Burgers And Stuff" );
  data.cbitems = g_list_append(data.cbitems, "Vegetarian Delights" );
  data.cbitems = g_list_append(data.cbitems, "El Taco Shop" );

  gtk_combo_set_popdown_strings (GTK_COMBO (data.combo), data.cbitems);

  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->vbox), 
    data.combo, TRUE, TRUE, 0);

  button = gtk_button_new_with_label ("Ok");
  gtk_signal_connect (GTK_OBJECT (button), "clicked",
    GTK_SIGNAL_FUNC(GetComboEntry), &data);

  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area),
    button, TRUE, TRUE, 0);

  button = gtk_button_new_with_label ("Add");
  gtk_signal_connect (GTK_OBJECT (button), "clicked",
    GTK_SIGNAL_FUNC(AddComboEntry), &data);

  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area),
    button, TRUE, TRUE, 0);

  gtk_widget_show_all (dialog_window);
  gtk_main();
}

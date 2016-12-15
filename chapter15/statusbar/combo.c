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

main( int argc, char *argv[] )
{
  GtkWidget *entry, *dialog_window, *combo, *button;
  GList *cbitems = NULL;

  gtk_init( &argc, &argv );

  dialog_window = gtk_dialog_new();
  gtk_window_position (GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);

  combo = gtk_combo_new();
  cbitems = g_list_append(cbitems, "Joe's Pizza Shack" );
  cbitems = g_list_append(cbitems, "Burgers And Stuff" );
  cbitems = g_list_append(cbitems, "Vegetarian Delights" );
  cbitems = g_list_append(cbitems, "El Taco Shop" );

  gtk_combo_set_popdown_strings (GTK_COMBO (combo), cbitems);
//  gtk_combo_set_use_arrows (GTK_COMBO (combo), FALSE);
  gtk_combo_set_use_arrows_always (GTK_COMBO (combo), TRUE);
//  gtk_combo_set_case_sensitive (GTK_COMBO (combo), FALSE);
//  gtk_entry_set_text (GTK_ENTRY (GTK_COMBO(combo)->entry), 
//    "hello world");

  gtk_combo_set_value_in_list(GTK_COMBO(combo), TRUE, FALSE );
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->vbox), 
    combo, TRUE, TRUE, 0);

  entry = gtk_entry_new();	
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->vbox), 
    entry, TRUE, TRUE, 0);

  button = gtk_button_new_with_label ("Close");
  gtk_signal_connect_object (GTK_OBJECT (button), "clicked",
    GTK_SIGNAL_FUNC(gtk_widget_destroy),
    GTK_OBJECT (dialog_window));
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area),
    button, TRUE, TRUE, 0);

  gtk_widget_show_all (dialog_window);
  gtk_main();
}

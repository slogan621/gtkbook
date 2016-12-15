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

static void menuitem_response (gchar *);

void
callback_func( GtkWidget *widget, gpointer callback_data )
{
	printf( "widget %x callback_data %s\n", widget, callback_data );
}

static void 
menuitem_response (gchar *foo)
{
	printf( "In menuitem_response '%s'\n", foo );
}

static void 
menuactivateitem_response (gchar *foo)
{
	printf( "In menuactivateitem_response '%s'\n", foo );
}

void menu_bar_deactivate()
{
	printf( "menu_bar_deactivate\n" );
}

void menu_bar_move_current()
{
	printf( "menu_bar_move_current\n" );
}

void menu_bar_activate_current()
{
	printf( "menu_bar_activate_current\n" );
}

void menu_bar_cancel()
{
	printf( "menu_bar_cancel\n" );
}

void menu_bar_selection_done()
{
	printf( "menu_bar_selection_done\n" );
}

void menu_deactivate()
{
	printf( "menu_deactivate\n" );
}

void menu_move_current()
{
	printf( "menu_move_current\n" );
}

void menu_activate_current()
{
	printf( "menu_activate_current\n" );
}

void menu_cancel()
{
	printf( "menu_cancel\n" );
}

void menu_selection_done()
{
	printf( "menu_selection_done\n" );
}

int main( int argc, char *argv[] )
{

  GtkWidget *window, *menu, *menu_2, *menu_bar, *root_menu, *menu_items, 
    *vbox;
  GtkMenuItem *myMenuItem;
  char buf[128];
  int i;

  gtk_init (&argc, &argv);

  /* create a new window */
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_usize (GTK_WIDGET (window), 200, 100);
  gtk_window_set_title (GTK_WINDOW (window), "GTK Menu Test");
  gtk_signal_connect (GTK_OBJECT (window), "delete_event",
	  (GtkSignalFunc) gtk_main_quit, NULL);

  menu = gtk_menu_new ();
  menu_2 = gtk_menu_new ();

  gtk_signal_connect (GTK_OBJECT (menu), "deactivate",
		(GtkSignalFunc) menu_deactivate, NULL);
  gtk_signal_connect (GTK_OBJECT (menu), "selection_done",
		(GtkSignalFunc) menu_selection_done, NULL);
  gtk_signal_connect (GTK_OBJECT (menu), "move_current",
		(GtkSignalFunc) menu_move_current, NULL);
  gtk_signal_connect (GTK_OBJECT (menu), "activate_current",
		(GtkSignalFunc) menu_activate_current, NULL);
  gtk_signal_connect (GTK_OBJECT (menu), "cancel",
		(GtkSignalFunc) menu_cancel, NULL);

  gtk_signal_connect (GTK_OBJECT (menu_2), "deactivate",
		(GtkSignalFunc) menu_deactivate, NULL);
  gtk_signal_connect (GTK_OBJECT (menu_2), "selection_done",
		(GtkSignalFunc) menu_selection_done, NULL);
  gtk_signal_connect (GTK_OBJECT (menu_2), "move_current",
		(GtkSignalFunc) menu_move_current, NULL);
  gtk_signal_connect (GTK_OBJECT (menu_2), "activate_current",
		(GtkSignalFunc) menu_activate_current, NULL);
  gtk_signal_connect (GTK_OBJECT (menu_2), "cancel",
		(GtkSignalFunc) menu_cancel, NULL);

  for (i = 0; i < 3; i++) {
	  sprintf (buf, "Test-undermenu - %d", i);

	  myMenuItem = (GtkMenuItem *) menu_items = 
      gtk_check_menu_item_new_with_label (buf);
	  myMenuItem->show_submenu_indicator = 0;
	  if ( i == 0 ) {
		  gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_items), menu_2);
   	  gtk_menu_item_configure( GTK_MENU_ITEM( menu_items ), FALSE, FALSE );
	  }

	  gtk_signal_connect_object (GTK_OBJECT (menu_items), "activate",
	    GTK_SIGNAL_FUNC (menuitem_response), (gpointer) g_strdup (buf));
	  gtk_signal_connect_object (GTK_OBJECT (menu_items), "activate_item",
	    GTK_SIGNAL_FUNC (menuactivateitem_response), (gpointer) g_strdup (buf));

	  gtk_menu_append (GTK_MENU (menu), menu_items);

	  gtk_widget_show (menu_items);

	  myMenuItem = (GtkMenuItem *) menu_items = 
      gtk_check_menu_item_new_with_label (buf);
	  gtk_signal_connect (GTK_OBJECT (menu_items), "toggled",
	    GTK_SIGNAL_FUNC (callback_func), (gpointer) g_strdup (buf));
	  myMenuItem->show_submenu_indicator = 0;

	  gtk_menu_append (GTK_MENU (menu_2), menu_items);

	  gtk_signal_connect_object (GTK_OBJECT (menu_items), "activate",
	    GTK_SIGNAL_FUNC (menuitem_response), (gpointer) g_strdup (buf));
	  gtk_signal_connect_object (GTK_OBJECT (menu_items), "activate_item",
	    GTK_SIGNAL_FUNC (menuactivateitem_response), (gpointer) g_strdup (buf));

	  gtk_widget_show (menu_items);
  }

  root_menu = gtk_menu_item_new_with_label ("Root Menu");

  gtk_widget_show (root_menu);

  gtk_menu_item_set_submenu (GTK_MENU_ITEM (root_menu), menu);

  vbox = gtk_vbox_new (FALSE, 0);
  gtk_container_add (GTK_CONTAINER (window), vbox);
  gtk_widget_show (vbox);

  menu_bar = gtk_menu_bar_new ();
  gtk_box_pack_start (GTK_BOX (vbox), menu_bar, FALSE, FALSE, 2);
  gtk_signal_connect (GTK_OBJECT (menu_bar), "deactivate",
		(GtkSignalFunc) menu_bar_deactivate, NULL);
  gtk_signal_connect (GTK_OBJECT (menu_bar), "selection_done",
		(GtkSignalFunc) menu_bar_selection_done, NULL);
  gtk_signal_connect (GTK_OBJECT (menu_bar), "move_current",
		(GtkSignalFunc) menu_bar_move_current, NULL);
  gtk_signal_connect (GTK_OBJECT (menu_bar), "activate_current",
		(GtkSignalFunc) menu_bar_activate_current, NULL);
  gtk_signal_connect (GTK_OBJECT (menu_bar), "cancel",
		(GtkSignalFunc) menu_bar_cancel, NULL);
  gtk_widget_show (menu_bar);

  gtk_menu_bar_append (GTK_MENU_BAR (menu_bar), root_menu);

  gtk_widget_show (window);

  gtk_main ();

  return(0);
}

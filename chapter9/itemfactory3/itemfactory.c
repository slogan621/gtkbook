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

/* example-start menu itemfactory.c */

#include <gtk/gtk.h>
#include <strings.h>
#include <time.h>

GtkItemFactory *item_factory;

static void 
print_hello( gpointer data, guint callback_action, GtkWidget *w )
{
	GtkWidget *myWidget;
	printf( "widget is %x data is %s\n", w, data );
	g_message ("Hello, World!\n");

	myWidget = gtk_item_factory_get_widget (item_factory, "/File/New");
	printf( "File/New is %x\n", myWidget );

	gtk_item_factory_delete_item( item_factory, "/Edit" );
}

static void handle_option( gpointer data, guint callback_action, GtkWidget *w )
{
	GtkCheckMenuItem *checkMenuItem = (GtkCheckMenuItem *) w;

	printf( "widget is %x data is %s\n", w, data );
	g_message ("Hello, World!\n");
}

void
DestroyNotifyFunc( gpointer data )
{
	printf( "data is %x\n", data );	
}

static GtkItemFactoryEntry menu_items[] = {
 { "/Option1",  NULL,      handle_option, 1, NULL },
 { "/Option2",  NULL,      handle_option, 2, NULL },
 { "/Option3",  NULL,      handle_option, 3, NULL },
 { "/Option4",  NULL,      handle_option, 4, NULL },
};

void get_main_menu( GtkWidget  *window, GtkWidget **menubar )
{
  GtkAccelGroup *accel_group;
  gint nmenu_items = sizeof (menu_items) / sizeof (menu_items[0]);
  GtkWidget *widget;

  accel_group = gtk_accel_group_new ();

  item_factory = gtk_item_factory_new (GTK_TYPE_MENU, "<main>", accel_group );

  gtk_item_factory_create_items (item_factory, nmenu_items, menu_items, "foo");

  gtk_accel_group_attach (accel_group, GTK_OBJECT (window));

  if (menubar)
    *menubar = gtk_item_factory_get_widget (item_factory, "<main>");

  widget = (GtkWidget *) gtk_item_factory_from_widget( *menubar );
  if ( widget == (GtkWidget *) item_factory )
	  printf( "widget and item_factory are the same\n" );
  else
	  printf( "widget and item_factory are not the same\n" );
}

int main( int argc, char *argv[] )
{
  GtkWidget *window;
  GtkWidget *main_vbox;
  GtkWidget *menubar;
  GtkWidget *optionMenu;
 
  gtk_init (&argc, &argv);
 
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_signal_connect (GTK_OBJECT(window), "destroy", 
	  GTK_SIGNAL_FUNC (gtk_main_quit), "WM destroy");
  gtk_window_set_title (GTK_WINDOW(window), "Item Factory");
  gtk_widget_set_usize (GTK_WIDGET(window), 300, 200);
 
  main_vbox = gtk_vbox_new (FALSE, 1);

  gtk_container_border_width (GTK_CONTAINER (main_vbox), 1);
  gtk_container_add (GTK_CONTAINER (window), main_vbox);
  gtk_widget_show (main_vbox);
 
  get_main_menu (window, &menubar);
  optionMenu = gtk_option_menu_new();
  gtk_option_menu_set_menu( GTK_OPTION_MENU( optionMenu ), menubar );
  gtk_box_pack_start (GTK_BOX (main_vbox), optionMenu, FALSE, TRUE, 0);
  gtk_widget_show (optionMenu);

  gtk_widget_show (window);
  gtk_main ();
 
  return(0);
}

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

static void print_hello( gpointer data, guint callback_action, GtkWidget *w )
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

static void
PopupCallback(GtkWidget *widget, gpointer ignored)
{
	static gpointer foo = (gpointer0 0x12345678L;
#if 0
	gtk_item_factory_popup_with_data(item_factory, 
		foo, DestroyNotifyFunc, 0, 0, 1, time( NULL ) ); 
#else
	gtk_item_factory_popup(item_factory, 0, 0, 1, time( NULL ) ); 
#endif
}

static GtkItemFactoryEntry menu_items[] = {
 { "/_File",         NULL,         NULL, 0, "<Branch>" },
 { "/File/_New",     "<control>N", print_hello, 2, NULL },
 { "/File/_Open",    "<control>O", print_hello, 0, NULL },
 { "/File/_Save",    "<control>S", print_hello, 0, NULL },
 { "/File/Save _As", NULL,         NULL, 0, NULL },
 { "/File/sep1",     NULL,         NULL, 0, "<Separator>" },
 { "/File/Quit",     "<control>Q", gtk_main_quit, 0, NULL },
 { "/_Edit",         NULL,         NULL, 0, "<Branch>" },
 { "/Edit/Cu_t",     "<control>X", print_hello, 0, NULL },
 { "/Edit/_Copy",    "<control>C", print_hello, 0, NULL },
 { "/Edit/_Paste",    "<control>V", print_hello, 0, NULL },
 { "/_Options",      NULL,         NULL, 0, "<Branch>" },
 { "/Options/Option1",  NULL,      handle_option, 1, "<CheckItem>" },
 { "/Options/Option2",  NULL,      handle_option, 2, "<ToggleItem>" },
 { "/Options/Option3",  NULL,      handle_option, 3, "<CheckItem>" },
 { "/Options/Option4",  NULL,      handle_option, 4, "<ToggleItem>" },
 { "/_Help",         NULL,         NULL, 0, "<LastBranch>" },
 { "/Help/One",   NULL,            NULL, 0, NULL },
 { "/Help/Two",   NULL,            NULL, 0, "<Branch>" },
 { "/Help/Two/A",   NULL,          NULL, 0, "<RadioItem>" },
 { "/Help/Two/B",   NULL,          NULL, 0, "/Help/Two/A" },
 { "/Help/Two/C",   NULL,          NULL, 0, "/Help/Two/A" },
 { "/Help/Two/D",   NULL,          NULL, 0, "/Help/Two/A" },
 { "/Help/Two/E",   NULL,          NULL, 0, "/Help/Two/A" },
 { "/Help/Three",   NULL,          NULL, 0, NULL },
};

void get_main_menu( GtkWidget  *window, GtkWidget **menubar )
{
  GtkAccelGroup *accel_group;
  gint nmenu_items = sizeof (menu_items) / sizeof (menu_items[0]);
  GtkWidget *widget;

  accel_group = gtk_accel_group_new ();

  item_factory = gtk_item_factory_new (GTK_TYPE_MENU_BAR, "<main>", 
    accel_group );

  gtk_item_factory_create_items(item_factory, nmenu_items, menu_items, "foo");

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
  GtkWidget *button;
 
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
  gtk_box_pack_start (GTK_BOX (main_vbox), menubar, FALSE, TRUE, 0);
  gtk_widget_show (menubar);

  button = gtk_button_new_with_label ("Popup");
  GTK_WIDGET_SET_FLAGS (button, GTK_CAN_DEFAULT);
  gtk_box_pack_start ( GTK_BOX (main_vbox), button, TRUE, TRUE, 0);
  gtk_signal_connect_object (GTK_OBJECT (button), "clicked",
    GTK_SIGNAL_FUNC (PopupCallback), NULL);

  gtk_widget_show( button );
 
  gtk_widget_show (window);
  gtk_main ();
 
  return(0);
}

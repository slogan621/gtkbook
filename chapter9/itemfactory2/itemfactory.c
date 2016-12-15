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
#include <stdio.h>

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

void
DestroyNotifyFunc( gpointer data )
{
	printf( "data is %x\n", data );	
	fflush( stdout );
}

gint
ButtonPressCallback( GtkWidget *widget, GdkEventButton *event, gpointer callback_data )
{
	gint x, y;
	static gpointer foo = (gpointer) 0x12345678L;
	gpointer fee;

	gdk_window_get_origin(widget->window, &x, &y );

  printf( "event->button is %d\n", event->button );

	gtk_item_factory_popup_with_data(item_factory, foo, DestroyNotifyFunc, 
		event->x + x, event->y + y, event->button, event->time ); 
	fee = gtk_item_factory_popup_data(item_factory ); 
	if ( fee == foo ) 
		printf( "fee and foo are the same\n" );
	else
		printf( "fee and foo are not the same\n" );
}

static GtkItemFactoryEntry menu_items[] = {
 { "/_File",         NULL,         NULL, 0, "<Branch>" },
 { "/File/_New",     "<control>N", print_hello, 0, NULL },
 { "/File/_Open",    "<control>O", print_hello, 0, NULL },
 { "/File/_Save",    "<control>S", print_hello, 0, NULL },
 { "/File/Save _As", NULL,         NULL, 0, NULL },
 { "/File/sep1",     NULL,         NULL, 0, "<Separator>" },
 { "/File/Quit",     "<control>Q", gtk_main_quit, 0, NULL },
};

void 
get_main_menu( GtkWidget  *window, GtkWidget **menubar )
{
  GtkAccelGroup *accel_group;
  gint nmenu_items = sizeof (menu_items) / sizeof (menu_items[0]);
  GtkWidget *widget;

  accel_group = gtk_accel_group_new ();

  item_factory = gtk_item_factory_new (GTK_TYPE_MENU, "<main>", accel_group);

  gtk_item_factory_create_items (item_factory, nmenu_items, menu_items, NULL);

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
  GtkWidget *menu;
 
  gtk_init (&argc, &argv);
 
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_signal_connect (GTK_OBJECT(window), "destroy", 
	  GTK_SIGNAL_FUNC (gtk_main_quit), "WM destroy");
  gtk_window_set_title (GTK_WINDOW(window), "Item Factory");
  gtk_widget_set_usize (GTK_WIDGET(window), 300, 200);

  get_main_menu (window, &menu);

  gtk_widget_set_events (window, GDK_BUTTON_PRESS_MASK);
  gtk_signal_connect (GTK_OBJECT (window), "button_press_event",
    GTK_SIGNAL_FUNC(ButtonPressCallback), NULL);

  gtk_widget_show (window);
  gtk_main ();
 
  return(0);
}

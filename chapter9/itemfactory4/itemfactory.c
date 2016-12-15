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
#include <gdk/gdkkeysyms.h>
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

static void 
handle_option( gpointer data, guint callback_action, GtkWidget *w )
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
PopupCallback(GtkWidget *widget, gpointer pbutton)
{
  GtkWidget *button = (GtkWidget *) pbutton;
  int x, y;

  gdk_window_get_pointer(NULL, &x, &y, NULL);
	gtk_item_factory_popup(item_factory, x, y, 1, time( NULL ) ); 
}

static GtkItemFactoryEntry menu_items_1[] = {
 { "/_New",     "<control>N", print_hello, 2, NULL },
 { "/_Open",    "<control>O", print_hello, 0, NULL },
 { "/_Save",    "<control>S", print_hello, 0, NULL },
 { "/Save _As", NULL,         NULL, 0, NULL },
 { "/sep1",     NULL,         NULL, 0, "<Separator>" },
 { "/Quit",     "<control>Q", gtk_main_quit, 0, NULL },
};
static GtkItemFactoryEntry menu_items_2[] = {
 { "/Cu_t",     "<control>X", print_hello, 0, NULL },
 { "/_Copy",    "<control>C", print_hello, 0, NULL },
 { "/_Paste",    "<control>V", print_hello, 0, NULL },
};
static GtkItemFactoryEntry menu_items_3[] = {
 { "/Option1",  NULL,      handle_option, 1, "<CheckItem>" },
 { "/Option2",  NULL,      handle_option, 2, "<ToggleItem>" },
 { "/Option3",  NULL,      handle_option, 3, "<CheckItem>" },
 { "/Option4",  NULL,      handle_option, 4, "<ToggleItem>" },
};
static GtkItemFactoryEntry menu_items_4[] = {
 { "/One",   NULL,            NULL, 0, NULL },
 { "/Two",   NULL,            NULL, 0, "<Branch>" },
 { "/Two/A",   NULL,          NULL, 0, "<RadioItem>" },
 { "/Two/B",   NULL,          NULL, 0, "/Two/A" },
 { "/Two/C",   NULL,          NULL, 0, "/Two/A" },
 { "/Two/D",   NULL,          NULL, 0, "/Two/A" },
 { "/Two/E",   NULL,          NULL, 0, "/Two/A" },
 { "/Three",   NULL,          NULL, 0, NULL },
};

void get_main_menu1( GtkWidget  *window, GtkWidget **menubar,
  GtkAccelGroup *accel_group )
{
  gint nmenu_items_1 = sizeof (menu_items_1) / sizeof (menu_items_1[0]);
  GtkWidget *widget;

  item_factory = gtk_item_factory_new (GTK_TYPE_MENU, "<main_1>", accel_group );

  gtk_item_factory_create_items (item_factory, 
    nmenu_items_1, menu_items_1, "foo");

  if (menubar)
    *menubar = gtk_item_factory_get_widget (item_factory, "<main_1>");

  widget = (GtkWidget *) gtk_item_factory_from_widget( *menubar );
  if ( widget == (GtkWidget *) item_factory )
	  printf( "widget and item_factory are the same\n" );
  else
	  printf( "widget and item_factory are not the same\n" );
}

void get_main_menu2( GtkWidget  *window, GtkWidget **menubar,
  GtkAccelGroup *accel_group )
{
  gint nmenu_items_2 = sizeof (menu_items_2) / sizeof (menu_items_2[0]);
  GtkWidget *widget;

  item_factory = gtk_item_factory_new (GTK_TYPE_MENU, "<main_2>", accel_group );

  gtk_item_factory_create_items (item_factory, nmenu_items_2, 
    menu_items_2, "foo");

  if (menubar)
    *menubar = gtk_item_factory_get_widget (item_factory, "<main_2>");

  widget = (GtkWidget *) gtk_item_factory_from_widget( *menubar );
  if ( widget == (GtkWidget *) item_factory )
	  printf( "widget and item_factory are the same\n" );
  else
	  printf( "widget and item_factory are not the same\n" );
}

void get_main_menu3( GtkWidget  *window, GtkWidget **menubar,
  GtkAccelGroup *accel_group )
{
  gint nmenu_items_3 = sizeof (menu_items_3) / sizeof (menu_items_3[0]);
  GtkWidget *widget;

  item_factory = gtk_item_factory_new (GTK_TYPE_MENU, "<main_3>", accel_group );

  gtk_item_factory_create_items (item_factory, nmenu_items_3, 
    menu_items_3, "foo");

  if (menubar)
    *menubar = gtk_item_factory_get_widget (item_factory, "<main_3>");

  widget = (GtkWidget *) gtk_item_factory_from_widget( *menubar );
  if ( widget == (GtkWidget *) item_factory )
	  printf( "widget and item_factory are the same\n" );
  else
	  printf( "widget and item_factory are not the same\n" );
}

void 
get_main_menu4( GtkWidget  *window, GtkWidget **menubar, 
  GtkAccelGroup *accel_group )
{
  gint nmenu_items_4 = sizeof (menu_items_4) / sizeof (menu_items_4[0]);
  GtkWidget *widget;

  item_factory = gtk_item_factory_new (GTK_TYPE_MENU, "<main_4>", accel_group );

  gtk_item_factory_create_items (item_factory, nmenu_items_4, 
    menu_items_4, "foo");

  if (menubar)
    *menubar = gtk_item_factory_get_widget (item_factory, "<main_4>");

  widget = (GtkWidget *) gtk_item_factory_from_widget( *menubar );
  if ( widget == (GtkWidget *) item_factory )
	  printf( "widget and item_factory are the same\n" );
  else
	  printf( "widget and item_factory are not the same\n" );
}

int 
main( int argc, char *argv[] )
{
  GtkWidget *window, *main_vbox, *menubar, *menu1, *menu2, *menu3, *menu4,
    *menu_item_1, *menu_item_2, *menu_item_3, *menu_item_4, *button, *label;
  GtkAccelGroup *accel_group;
  guint accel_key;
 
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
 
  menubar = gtk_menu_bar_new();
  gtk_box_pack_start (GTK_BOX (main_vbox), menubar, FALSE, TRUE, 0);
  gtk_widget_show (menubar);

  accel_group = gtk_accel_group_new ();
  gtk_accel_group_attach (accel_group, GTK_OBJECT (window));
  get_main_menu1 (window, &menu1, accel_group);
  menu_item_1 = gtk_menu_item_new();
  label = gtk_accel_label_new( "_File" );
  accel_key = gtk_label_parse_uline (GTK_LABEL(label), "_File" );
  gtk_widget_add_accelerator (menu_item_1, "activate_item", accel_group,
 	  accel_key, GDK_MOD1_MASK, GTK_ACCEL_LOCKED);
  gtk_container_add( GTK_CONTAINER( menu_item_1 ), label );
  gtk_widget_show( label );
  gtk_menu_bar_append( GTK_MENU_BAR( menubar ), menu_item_1 );
  gtk_menu_item_set_submenu( GTK_MENU_ITEM( menu_item_1 ), menu1 );
  gtk_widget_show (menu_item_1);
  get_main_menu2 (window, &menu2, accel_group);
  menu_item_2 = gtk_menu_item_new_with_label( "Edit" );
  gtk_menu_bar_insert( GTK_MENU_BAR( menubar ), menu_item_2, 3 );
  gtk_menu_item_set_submenu( GTK_MENU_ITEM( menu_item_2 ), menu2 );
  gtk_widget_show (menu_item_2);
  get_main_menu3 (window, &menu3, accel_group);
  menu_item_3 = gtk_menu_item_new_with_label( "Options" );
  gtk_menu_bar_append( GTK_MENU_BAR( menubar ), menu_item_3 );
  gtk_menu_item_set_submenu( GTK_MENU_ITEM( menu_item_3 ), menu3 );
  gtk_menu_item_right_justify( GTK_MENU_ITEM(menu_item_3) );
  gtk_widget_show (menu_item_3);
  get_main_menu4 (window, &menu4, accel_group);
  menu_item_4 = gtk_menu_item_new_with_label( "Help" );
  gtk_menu_bar_append( GTK_MENU_BAR( menubar ), menu_item_4 );
  gtk_menu_item_set_submenu( GTK_MENU_ITEM( menu_item_4 ), menu4 );
  gtk_menu_item_right_justify( GTK_MENU_ITEM( menu_item_4 ) );
  gtk_widget_show (menu_item_4);

  button = gtk_button_new_with_label ("Popup");
  GTK_WIDGET_SET_FLAGS (button, GTK_CAN_DEFAULT);
  gtk_box_pack_start ( GTK_BOX (main_vbox), button, TRUE, TRUE, 0);
  gtk_signal_connect_object (GTK_OBJECT (button), "clicked",
    GTK_SIGNAL_FUNC (PopupCallback), (gpointer) button);

  gtk_widget_show( button );
 
  gtk_widget_show (window);
  gtk_main ();
 
  return(0);
}

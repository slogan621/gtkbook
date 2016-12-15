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

// forward declarations to avoid compiler warnings

void ResetSettingsMenuItems( void );
void UpdateChildren( void );
void MessageBox( char *message );

#define VERSION_MAJOR 1
#define VERSION_MINOR 0

// some globals to make life easy

static GtkWidget *container;
static GNode *root;
static GNode *current;
static int n = 1;

// tree node

typedef struct _boxdata {
	GtkWidget *container;		// the vbox or hbox instance
	int spacing;			// current spacing
	gboolean homogeneous;		// current homogeneous
	int padding;			// current padding 
	gboolean fill;			// current child fill 
	gboolean expand;		// current child expand 
} BoxData;

// used to hold callback data for settings dialog

typedef struct _settingsData {
	GtkWidget *dialog;		// Padding/Spacing dialog
	GtkWidget *pad_entry;		// Padding entry widget
	GtkWidget *space_entry;		// Space entry widget
} SettingsData;

static SettingsData settingsData;	// dialog is modal, only need one

// dump tree to stdout

gboolean
traverse_func( GNode *node, gpointer data )
{
	int i;

	// indent

	for ( i = 0; i < g_node_depth( node ) - 1; i++ )
		printf( "  " );

	// print the node

	printf( "Node %x parent %x [%x] %s %s\n", node, node->parent, 
		((BoxData *) node->data)->container, 
		(GTK_IS_VBOX(((BoxData *)node->data)->container) 
		? "VBox" : "Hbox" ), (node == current ? "<--" : "" ) );
	return( FALSE );	// continue traversal
}

void
dump_tree( gpointer data, guint callback_action, GtkWidget *w )
{
	printf( "Tree Dump ********************************************************************\n" );
	printf( "<-- is current box\n" );
	g_node_traverse( root, G_PRE_ORDER, G_TRAVERSE_ALL, 999, 
		traverse_func, NULL );
}

// traversal functions

static void 
go_up( gpointer data, guint callback_action, GtkWidget *w )
{
	if ( current != root ) {	
		current = current->parent;
		container = (GtkWidget *)((BoxData *)current->data)->container;	
	}
	dump_tree( (gpointer) NULL, 0, (GtkWidget *) NULL );
	ResetSettingsMenuItems();
}

static void 
go_down( gpointer data, guint callback_action, GtkWidget *w )
{
	GNode *node;
	node = g_node_first_child( current );
	if ( node != (GNode *) NULL ) 
		current = node;
	container = (GtkWidget *)((BoxData *)current->data)->container;	
	dump_tree( (gpointer) NULL, 0, (GtkWidget *) NULL );
	ResetSettingsMenuItems();
}

static void 
go_previous( gpointer data, guint callback_action, GtkWidget *w )
{
	GNode *node;

	node = g_node_prev_sibling( current );
	if ( node != (GNode *) NULL ) 
		current = node;
	container = (GtkWidget *)((BoxData *)current->data)->container;	
	dump_tree( (gpointer) NULL, 0, (GtkWidget *) NULL );
	ResetSettingsMenuItems();
}

static void 
go_next( gpointer data, guint callback_action, GtkWidget *w )
{
	GNode *node;

	node = g_node_next_sibling( current );
	if ( node != (GNode *) NULL ) 
		current = node;
	container = (GtkWidget *)((BoxData *)current->data)->container;	
	dump_tree( (gpointer) NULL, 0, (GtkWidget *) NULL );
	ResetSettingsMenuItems();
}

// box add functions

static void 
add_horz_box( gpointer data, guint callback_action, GtkWidget *w )
{
	GtkWidget *hbox;
	GNode *node;
	BoxData *boxData;

	boxData = g_malloc( sizeof( BoxData ) );
 	hbox = gtk_hbox_new(FALSE, 0);
	boxData->container = hbox;
	boxData->homogeneous = FALSE;
	boxData->fill = TRUE;			
	boxData->expand = TRUE;
	boxData->padding = 0;
	boxData->spacing = 0;
	if ( callback_action == 0 )
		gtk_box_pack_start( GTK_BOX(container), hbox, 
			boxData->expand, boxData->fill, boxData->padding );
	else
		gtk_box_pack_end( GTK_BOX(container), hbox, 
			boxData->expand, boxData->fill, boxData->padding );
	node = g_node_new( (gpointer) boxData );
	g_node_insert( current, -1, node );	
	dump_tree( (gpointer) NULL, 0, (GtkWidget *) NULL );
	ResetSettingsMenuItems();
 	gtk_widget_show (hbox);
}

static void 
add_vert_box( gpointer data, guint callback_action, GtkWidget *w )
{
	GtkWidget *vbox;
	GNode *node;
	BoxData *boxData;

	boxData = g_malloc( sizeof( BoxData ) );
 	vbox = gtk_vbox_new(FALSE, 0);
 	gtk_container_add(GTK_CONTAINER(container), vbox);
	boxData->container = vbox;
	boxData->homogeneous = FALSE;
	boxData->fill = TRUE;			
	boxData->expand = TRUE;
	boxData->padding = 0;
	boxData->spacing = 0;
	if ( callback_action == 0 )
		gtk_box_pack_start( GTK_BOX(container), vbox, 
			boxData->expand, boxData->fill, boxData->padding );
	else
		gtk_box_pack_end( GTK_BOX(container), vbox, 
			boxData->expand, boxData->fill, boxData->padding );
	node = g_node_new( (gpointer) boxData );
	g_node_insert( current, -1, node );	
	dump_tree( (gpointer) NULL, 0, (GtkWidget *) NULL );
	ResetSettingsMenuItems();
 	gtk_widget_show (vbox);
}

// child (button) widget add functions

static void 
add_button_to_box_start( gpointer data, guint callback_action, GtkWidget *w )
{
	GtkWidget *button;
	char buf[ 64 ];

	sprintf( buf, "Start %d Box %x", n++, container );
	button = gtk_button_new_with_label( buf );
 	gtk_box_pack_start( GTK_BOX(container), button, 
		((BoxData *) current->data)->expand,
		((BoxData *) current->data)->fill,
		((BoxData *) current->data)->padding );
 	gtk_widget_show(button);
}

static void 
add_button_to_box_end( gpointer data, guint callback_action, GtkWidget *w )
{
	GtkWidget *button;
	char buf[ 64 ];

	sprintf( buf, "End %d Box %x", n++, container );
	button = gtk_button_new_with_label( buf );
 	gtk_box_pack_end( GTK_BOX(container), button, 
		((BoxData *) current->data)->expand,
		((BoxData *) current->data)->fill,
		((BoxData *) current->data)->padding );
 	gtk_widget_show (button);
}

// padding and spacing dialog

static void
ClickedCallback(GtkWidget *widget, gpointer unused)
{
	char *data;
	int spacing;

	data = gtk_entry_get_text( GTK_ENTRY(settingsData.pad_entry) );
	((BoxData *) current->data)->padding = atoi( data );

	// get the spacing

	data = gtk_entry_get_text( GTK_ENTRY(settingsData.space_entry) );
	spacing = ((BoxData *) current->data)->spacing = atoi( data );

	// make the change to spacing

	gtk_box_set_spacing(GTK_BOX(((BoxData *) current->data)->container), 
		spacing);

	UpdateChildren();

	gtk_widget_destroy( settingsData.dialog );
}

// make changes to children after a setting change

void
UpdateChildren( void )
{
	GtkBoxChild *child;
	GList *children;
	GtkBox *box;
	gboolean expand, fill;
	int padding;
	GtkPackType type;

	box = GTK_BOX(((BoxData *) current->data)->container);
	children = box->children;
	while ( children != (GList *) NULL ) {
		child = (GtkBoxChild *) children->data;
		gtk_box_query_child_packing(box, (GtkWidget *)child->widget, 
			&expand, &fill, &padding, &type );
		gtk_box_set_child_packing(box, (GtkWidget *) child->widget,
			((BoxData *) current->data)->expand,
			((BoxData *) current->data)->fill,
			((BoxData *) current->data)->padding, type );
		children = children->next;
	}
}

// user canceled the settings dialog

static void
CancelCallback(GtkWidget *widget, GtkWidget *dialog_window)
{
	gtk_widget_destroy( dialog_window );
}

// display a dialog to get padding and spacing values

void
GetPaddingAndSpacing( void )
{
  GtkWidget *button, *label, *entry, *hbox, *dialog_window;
	char buf[ 64 ];
	
	// create the dialog and set attributes

  settingsData.dialog = dialog_window = gtk_dialog_new();
	gtk_window_set_modal(GTK_WINDOW(dialog_window), TRUE);
  gtk_window_position(GTK_WINDOW (dialog_window), 
		GTK_WIN_POS_MOUSE);
 	gtk_window_set_title(GTK_WINDOW(dialog_window), 
		"Padding and Spacing");

	// fill in the content area

 	hbox = gtk_hbox_new (FALSE, 1);
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG (dialog_window)->vbox),
    hbox, FALSE, FALSE, 0);

	label = gtk_label_new( "Padding: " );
  gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);
	settingsData.pad_entry = entry = gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(hbox), entry, FALSE, FALSE, 0);
	sprintf( buf, "%d", ((BoxData *) current->data)->padding );
	gtk_entry_set_text( GTK_ENTRY(entry), buf );

 	hbox = gtk_hbox_new (FALSE, 1);
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG (dialog_window)->vbox),
    hbox, FALSE, FALSE, 0);

	label = gtk_label_new( "Spacing: " );
  gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);
	settingsData.space_entry = entry = gtk_entry_new();
	sprintf( buf, "%d", ((BoxData *) current->data)->spacing );
	gtk_entry_set_text( GTK_ENTRY(entry), buf );
  gtk_box_pack_start(GTK_BOX(hbox), entry, FALSE, FALSE, 0);

	// fill in the buttons

  button = gtk_button_new_with_label ("OK");
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG (dialog_window)->action_area),
    button, FALSE, FALSE, 0);
  gtk_signal_connect(GTK_OBJECT (button), "clicked", 
	  GTK_SIGNAL_FUNC(ClickedCallback), NULL);

  button = gtk_button_new_with_label ("Cancel");
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG (dialog_window)->action_area),
    button, FALSE, FALSE, 0);
  gtk_signal_connect(GTK_OBJECT(button), "clicked",
    GTK_SIGNAL_FUNC(CancelCallback), dialog_window);

  gtk_widget_show_all (dialog_window);
}

// menu-related code

GtkItemFactory *item_factory;

// make sure settings menu checkboxes jive with settings of current box

void
ResetSettingsMenuItems( void )
{
	GtkCheckMenuItem *item; 

	item = (GtkCheckMenuItem *) gtk_item_factory_get_widget(item_factory, 
		"/Settings/Homogeneous");
	item->active = ((BoxData *) current->data)->homogeneous;
	item = (GtkCheckMenuItem *) gtk_item_factory_get_widget(item_factory, 
		"/Settings/Expand");
	item->active = ((BoxData *) current->data)->expand;
	item = (GtkCheckMenuItem *) gtk_item_factory_get_widget(item_factory, 
		"/Settings/Fill");
	item->active = ((BoxData *) current->data)->fill;
}

// callback for Options menu items

static void 
handle_option( gpointer data, guint callback_action, GtkWidget *w )
{
	GtkCheckMenuItem *item = (GtkCheckMenuItem *) w;
	gboolean homogeneous;

	switch( callback_action )
	{
	case 1:
		((BoxData *) current->data)->expand = item->active; 
		break;
	case 2:
		((BoxData *) current->data)->fill = item->active; 
		break;
	case 3:
		((BoxData *) current->data)->homogeneous = 
			homogeneous = item->active; 
		gtk_box_set_homogeneous(GTK_BOX(((BoxData *) 
			current->data)->container), homogeneous);
		break;
	case 4:
		GetPaddingAndSpacing();
		break;
	}
	UpdateChildren();
}

static void
MoveClickedCallback(GtkWidget *widget, gpointer unused)
{
	char *data;
	int start, end;

	data = gtk_entry_get_text( GTK_ENTRY(settingsData.pad_entry) );
	start = atoi( data );

	data = gtk_entry_get_text( GTK_ENTRY(settingsData.space_entry) );
	end = atoi( data );

	gtk_widget_destroy( settingsData.dialog );
}

// move child widget

static void 
move_child( gpointer data, guint callback_action, GtkWidget *w )
{
  GtkWidget *button, *label, *entry, *hbox, *dialog_window;
	char buf[ 64 ];
	
	// create the dialog and set attributes

  settingsData.dialog = dialog_window = gtk_dialog_new();
	gtk_window_set_modal(GTK_WINDOW(dialog_window), TRUE);
  gtk_window_position(GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);
 	gtk_window_set_title(GTK_WINDOW(dialog_window), "Move Child");

	// fill in the content area

 	hbox = gtk_hbox_new (FALSE, 1);
	gtk_box_set_homogeneous( GTK_BOX( hbox ), FALSE );
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG (dialog_window)->vbox),
    hbox, FALSE, FALSE, 0);

	label = gtk_label_new( "Start: " );
  gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, TRUE, 0);
	settingsData.pad_entry = entry = gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(hbox), entry, TRUE, TRUE, 0);
	sprintf( buf, "%d", ((BoxData *) current->data)->padding );
	gtk_entry_set_text( GTK_ENTRY(entry), buf );

 	hbox = gtk_hbox_new (FALSE, 1);
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG (dialog_window)->vbox),
    hbox, FALSE, FALSE, 0);

	label = gtk_label_new( "End: " );
  gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, TRUE, 0);
	settingsData.space_entry = entry = gtk_entry_new();
	sprintf( buf, "%d", ((BoxData *) current->data)->spacing );
	gtk_entry_set_text( GTK_ENTRY(entry), buf );
  gtk_box_pack_start(GTK_BOX(hbox), entry, TRUE, TRUE, 0);

	// fill in the buttons

  button = gtk_button_new_with_label ("OK");
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG (dialog_window)->action_area),
    button, FALSE, FALSE, 0);
  gtk_signal_connect(GTK_OBJECT (button), "clicked", 
		GTK_SIGNAL_FUNC(MoveClickedCallback), NULL);

  button = gtk_button_new_with_label ("Cancel");
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG (dialog_window)->action_area),
    button, FALSE, FALSE, 0);
  gtk_signal_connect(GTK_OBJECT(button), "clicked",
    GTK_SIGNAL_FUNC(CancelCallback), dialog_window);

  gtk_widget_show_all (dialog_window);
}

static void
show_about( gpointer data, guint callback_action, GtkWidget *w )
{
	char	buf[128];

	sprintf( buf, "Gtk+ Box Office Version %d.%d Copyright 2000, Syd Logan",
		VERSION_MAJOR, VERSION_MINOR );
	MessageBox(buf);
}

// menu definition based on item factory

static GtkItemFactoryEntry menu_items[] = {
 	{ "/_File", NULL, NULL, 0, "<Branch>" },
 	{ "/File/Quit", "<control>Q", gtk_main_quit, 0, NULL },
 	{ "/Settings", NULL, NULL, 0, "<Branch>" },
 	{ "/Settings/Expand", NULL, handle_option, 1, "<CheckItem>" },
 	{ "/Settings/Fill", NULL, handle_option, 2, "<CheckItem>" },
 	{ "/Settings/Homogeneous", NULL, handle_option, 3, "<CheckItem>" },
 	{ "/Settings/sep1",     NULL,         NULL, 0, "<Separator>" },
 	{ "/Settings/Padding and Spacing...", NULL, handle_option, 4, "" },
 	{ "/_Traverse", NULL, NULL, 0, "<Branch>" },
 	{ "/Traverse/Up", NULL, go_up, 0, NULL },
 	{ "/Traverse/Down", NULL, go_down, 0, NULL },
 	{ "/Traverse/Next", NULL, go_next, 0, NULL },
 	{ "/Traverse/Previous", NULL, go_previous, 0, NULL },
 	{ "/Add _Box", NULL, NULL, 0, "<Branch>" },
 	{ "/Add Box/Vertical Box, Start", NULL, add_vert_box, 0, NULL },
 	{ "/Add Box/Vertical Box, End", NULL, add_vert_box, 1, NULL },
 	{ "/Add Box/Horizontal Box, Start", NULL, add_horz_box, 0, NULL },
 	{ "/Add Box/Horizontal Box, End", NULL, add_horz_box, 1, NULL },
 	{ "/Add _Child", NULL, NULL, 0, "<Branch>" },
 	{ "/Add Child/Pack Start", NULL, add_button_to_box_start, 0, NULL },
 	{ "/Add Child/Pack End", NULL, add_button_to_box_end, 0, NULL },
 	{ "/Add Child/Move child", NULL, move_child, 0, NULL },
 	{ "/_View", NULL, NULL, 0, "<Branch>" },
 	{ "/View/Tree", NULL, dump_tree, 0, NULL },
	{ "/_Help",         NULL,         NULL, 0, "<LastBranch>" },
 	{ "/Help/About...", NULL, show_about, 0, NULL }
};

// create menu bar and menus using item factory

void 
get_main_menu( GtkWidget  *window, GtkWidget **menubar )
{
 	GtkAccelGroup *accel_group;
 	gint nmenu_items = sizeof (menu_items) / sizeof (menu_items[0]);
 	GtkWidget *widget;

 	accel_group = gtk_accel_group_new ();

 	item_factory = gtk_item_factory_new (GTK_TYPE_MENU_BAR, 
		"<main>", accel_group );

 	gtk_item_factory_create_items(item_factory, nmenu_items, 
		menu_items, NULL);

 	gtk_accel_group_attach (accel_group, GTK_OBJECT (window));

 	if (menubar)
   		*menubar = gtk_item_factory_get_widget (item_factory, "<main>");
}

// main

int main( int argc, char *argv[] )
{
 	GtkWidget *window, *menubar, *button, *widget, *vbox;
 	GdkColormap *default_colormap;
	char buf[64];
	BoxData *boxData;

 	gtk_init(&argc, &argv);
 
 	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 	gtk_signal_connect(GTK_OBJECT(window), "destroy", 
    GTK_SIGNAL_FUNC (gtk_main_quit), "WM destroy");
	sprintf( buf, "Gtk+ Box Office %d.%d", VERSION_MAJOR, VERSION_MINOR );
 	gtk_window_set_title(GTK_WINDOW(window), buf);
 	gtk_widget_set_usize(GTK_WIDGET(window), 640, 480);

 	vbox = gtk_vbox_new (FALSE, 1);

 	gtk_container_add(GTK_CONTAINER (window), vbox);

 	gtk_widget_show( vbox );

 	get_main_menu(window, &menubar);
 	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, TRUE, 0);
 	gtk_widget_show(menubar);
 
	boxData = g_malloc( sizeof( BoxData ) );
 	root = current = g_node_new( (gpointer) boxData );
 	container = boxData->container = gtk_vbox_new (FALSE, 0);
	boxData->homogeneous = FALSE;
	boxData->fill = TRUE;			
	boxData->expand = TRUE;
	boxData->padding = 0;
	boxData->spacing = 0;

	ResetSettingsMenuItems();
 	gtk_container_add(GTK_CONTAINER(vbox), container);

 	gtk_widget_show(container);

 	gtk_widget_show(window);
 	gtk_main ();
 
 	return(0);
}

/*
 * Simple MessageBox
 */

void
MessageBox( char *message )
{
  static GtkWidget *label, *button, *dialog_window = (GtkWidget *) NULL;

  if ( dialog_window == (GtkWidget *) NULL ) {
    dialog_window = gtk_dialog_new();

    gtk_signal_connect (GTK_OBJECT (dialog_window), "destroy",
      GTK_SIGNAL_FUNC(gtk_widget_destroyed), &dialog_window);

    gtk_window_set_title (GTK_WINDOW (dialog_window), "Message");
    gtk_container_border_width (GTK_CONTAINER (dialog_window), 0);

    button = gtk_button_new_with_label ("OK");
    GTK_WIDGET_SET_FLAGS (button, GTK_CAN_DEFAULT);
    gtk_box_pack_start (
      GTK_BOX (GTK_DIALOG (dialog_window)->action_area),
      button, TRUE, TRUE, 0);
    gtk_signal_connect_object (GTK_OBJECT (button), "clicked",
      GTK_SIGNAL_FUNC (gtk_widget_hide_all),
      GTK_OBJECT (dialog_window));

    label = gtk_label_new (message);
    gtk_misc_set_padding (GTK_MISC (label), 10, 10);
    gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->vbox),
    label, FALSE, FALSE, 0);
  } else
    gtk_label_set_text( GTK_LABEL(label), message );

  gtk_window_position (GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);
  gtk_widget_grab_default (button);
  gtk_widget_show_all (dialog_window);
}


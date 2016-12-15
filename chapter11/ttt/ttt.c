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
#include <stdlib.h>

#define SQUARE_X 0
#define SQUARE_O 1
#define SQUARE_BLANK 2

static GtkWidget *table, *dialog, *entryrow, *entrycol;

typedef struct _square {
	unsigned char type;
	GtkWidget *child;
} Square;

static Square board[9] = { 
{ SQUARE_BLANK, NULL }, { SQUARE_BLANK, NULL }, { SQUARE_BLANK, NULL }, 
{ SQUARE_BLANK, NULL }, { SQUARE_BLANK, NULL }, { SQUARE_BLANK, NULL },
{ SQUARE_BLANK, NULL }, { SQUARE_BLANK, NULL }, { SQUARE_BLANK, NULL }
};

static GtkWidget *
MakeXSquare( GtkWidget *window )
{
	GdkPixmap *pixmap;
	GdkBitmap *mask;
	GtkWidget *wpmap;

	pixmap = gdk_pixmap_create_from_xpm( window->window, &mask,
		&window->style->bg[GTK_STATE_NORMAL], "x.xpm" );
	wpmap = gtk_pixmap_new(pixmap, mask);
	return( wpmap );
}

static GtkWidget *
MakeOSquare( GtkWidget *window )
{
	GdkPixmap *pixmap;
	GdkBitmap *mask;
	GtkWidget *wpmap;

	pixmap = gdk_pixmap_create_from_xpm( window->window, &mask,
		&window->style->bg[GTK_STATE_NORMAL], "o.xpm" );
	wpmap = gtk_pixmap_new(pixmap, mask);
	return( wpmap );
}

static void
ComputeNextMove( int *row, int *col )
{
	/* a simple, semi-brute force algorithm:

	1) if there is a winning move, then take it
	2) if our competitor can win on the next move, then block it
	3) if the center square is available, then take it
	4) if there is a set of 3 cells in a row, any 1 cell containing our
	   piece, and the other two empty, then take one of the empty cells. 
	5) take the first empty cell that we find in a left to right scan.

	*/
}

static GtkWidget *
MakeBlankSquare( GtkWidget *window )
{
	GdkPixmap *pixmap;
	GdkBitmap *mask;
	GtkWidget *wpmap;

	pixmap = gdk_pixmap_create_from_xpm( window->window, &mask,
		&window->style->bg[GTK_STATE_NORMAL], "empty.xpm" );
	wpmap = gtk_pixmap_new(pixmap, mask);
	return( wpmap );
}

static int
TryMoveTo( int row, int col )
{
	GtkWidget *widget;
	if ( board[ row * 3 + col ].type == SQUARE_BLANK ) {
		widget = MakeOSquare( dialog );	
		gtk_table_attach_defaults( GTK_TABLE( table ), 
			widget, col, col + 1, row, row + 1 );
		gtk_widget_destroy( board[ row * 3 + col ].child );
		gtk_widget_show( widget );
		board[ row * 3 + col ].type = SQUARE_O;
		board[ row * 3 + col ].child = widget; 
		return( 1 );
	}
	return( 0 );
}

static int
CheckForWin( void )
{
	int i, blank = 0;

	for ( i = 0; i < 9; i++ )
		if ( board[i].type == SQUARE_BLANK ) {
			blank = 1;
			break;
		}
	if ( blank == 0 )
		return( 1 );

	if ( board[ 0 ].type != SQUARE_BLANK && board[ 0 ].type == 
		board[ 1 ].type && board[ 1 ].type == board[ 2 ].type )
		return( 1 );
	if ( board[ 0 ].type != SQUARE_BLANK && board[ 0 ].type == 
		board[ 4 ].type && board[ 4 ].type == board[ 8 ].type )
		return( 1 );
	if ( board[ 0 ].type != SQUARE_BLANK && board[ 0 ].type == 
		board[ 3 ].type && board[ 3 ].type == board[ 6 ].type ) 
		return( 1 );
	if ( board[ 1 ].type != SQUARE_BLANK && board[ 1 ].type == 
		board[ 4 ].type && board[ 4 ].type == board[ 7 ].type )
		return( 1 );
	if ( board[ 2 ].type != SQUARE_BLANK && board[ 2 ].type == 
		board[ 5 ].type && board[ 5 ].type == board[ 8 ].type )
		return( 1 );
	if ( board[ 2 ].type != SQUARE_BLANK && board[ 2 ].type == 
		board[ 4 ].type && board[ 4 ].type == board[ 6 ].type )
		return( 1 );
	if ( board[ 3 ].type != SQUARE_BLANK && board[ 3 ].type == 
		board[ 4 ].type && board[ 4 ].type == board[ 5 ].type )
		return( 1 );
	if ( board[ 6 ].type != SQUARE_BLANK && board[ 6 ].type == 
		board[ 7 ].type && board[ 7 ].type == board[ 8 ].type )
		return( 1 );
	if ( board[ 3 ].type != SQUARE_BLANK && board[ 3 ].type == 
		board[ 4 ].type && board[ 4 ].type == board[ 6 ].type )
		return( 1 );
	return( 0 );
}

static void
InitializeBoard( void )
{
	GtkWidget *blank, *button;
	int i, j;

	for ( i = 0; i < 3; i ++ ) 
		for ( j = 0; j < 3; j++ ) {
			blank = MakeBlankSquare( dialog );	
			gtk_widget_show( blank );
			if ( board[ j * 3 + i ].child != NULL )
				gtk_widget_destroy( 
					board[ j * 3 + i ].child );
			gtk_table_attach_defaults( GTK_TABLE( table ), 
				blank, i, i + 1, j, j + 1 );
			board[ j * 3 + i ].type = SQUARE_BLANK;
			board[ j * 3 + i ].child = blank; 
		}
}

void
NewGame( gpointer ignored )
{
	InitializeBoard();
	if (((float) rand() / RAND_MAX) > 0.5)
		TryMoveTo( 1, 1 );
}

static void
MakeComputerMove( void )
{
	int row, col, done;

	if ( TryMoveTo( 1, 1 ) )
		return;
	done = 0;
	for ( row = 0; row < 3 && !done; row++ ) {
		for ( col = 0; col < 3; col++ ) {
			done = TryMoveTo( row, col );
			if ( done == 1 )
				break;
		}
	}
	if ( CheckForWin() )
		NewGame( NULL );
}

static void
MakeMove( gpointer ignored )
{
	char *text;
	int row, col;
	GtkWidget *widget;

	text = gtk_entry_get_text( GTK_ENTRY( entryrow ) );
	row = atoi( text );	
	text = gtk_entry_get_text( GTK_ENTRY( entrycol ) );
	col = atoi( text );	
	if ( row < 1 || row > 3 || col < 1 || col > 3 )
		return;
	row--; col--;
	if ( board[ row * 3 + col ].type == SQUARE_BLANK ) {
		widget = MakeXSquare( dialog );	
		gtk_table_attach_defaults( GTK_TABLE( table ), widget,
			col, col + 1, row, row + 1 );
		gtk_widget_destroy( board[ row * 3 + col ].child );
		gtk_widget_show( widget );
		board[ row * 3 + col ].type = SQUARE_X;
		board[ row * 3 + col ].child = widget; 
		if ( CheckForWin() )
			NewGame( NULL );
		else
			MakeComputerMove();
	}
}

static GtkWidget * 
GtkTTTDialog( void )
{
  GtkWidget *move, *quit, *newgame, *label, *rule, *bbox, *rlabel, 
	  *dialog_window, *outervbox, *hbox;

  dialog_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_position( GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE );

  gtk_signal_connect( GTK_OBJECT (dialog_window), "destroy",
	  GTK_SIGNAL_FUNC(gtk_main_quit), &dialog_window );

  gtk_window_set_title( GTK_WINDOW(dialog_window), "GtkTicTacToe" );
  gtk_window_set_policy( GTK_WINDOW(dialog_window), FALSE, FALSE, FALSE );
	
  gtk_container_border_width( GTK_CONTAINER (dialog_window), 0 );

  outervbox = gtk_vbox_new( FALSE, 0 );
  gtk_box_set_spacing( GTK_BOX( outervbox ), 10 );
  gtk_container_add( GTK_CONTAINER(dialog_window), outervbox );

  table = gtk_table_new( 3, 3, TRUE );
  gtk_box_pack_start( GTK_BOX(outervbox), table, FALSE, FALSE, 0 );

  rule = gtk_hseparator_new();
  gtk_box_pack_start( GTK_BOX(outervbox), rule, FALSE, FALSE, 0 );

  hbox = gtk_hbox_new( FALSE, 0 );
  gtk_box_pack_start( GTK_BOX(outervbox), hbox, FALSE, FALSE, 0 );

  hbox = gtk_hbox_new( FALSE, 0 );
  gtk_box_set_spacing( GTK_BOX( hbox ), 10 );
  gtk_box_pack_start( GTK_BOX(outervbox), hbox, TRUE, TRUE, 0 );

  rlabel = gtk_label_new( "Row" );
  gtk_box_pack_start( GTK_BOX(hbox), rlabel, TRUE, TRUE, 0 );

  entryrow = gtk_entry_new();
  gtk_widget_set_usize( entryrow, 30, -1 );
  gtk_box_pack_start( GTK_BOX(hbox), entryrow, TRUE, TRUE, 0 );

  rlabel = gtk_label_new( "Column" );
  gtk_box_pack_start( GTK_BOX(hbox), rlabel, TRUE, TRUE, 0 );

  entrycol = gtk_entry_new();
  gtk_widget_set_usize( entrycol, 30, -1 );
  gtk_box_pack_start( GTK_BOX(hbox), entrycol, TRUE, TRUE, 0 );

  move = gtk_button_new_with_label( "Move" );
  gtk_box_pack_start( GTK_BOX(hbox), move, TRUE, TRUE, 10 );
  gtk_signal_connect(GTK_OBJECT(move), "clicked", 
	  GTK_SIGNAL_FUNC(MakeMove), NULL);

  rule = gtk_hseparator_new();
  gtk_box_pack_start( GTK_BOX(outervbox), rule, FALSE, FALSE, 0 );

  bbox = gtk_hbutton_box_new();
  gtk_box_pack_start( GTK_BOX(outervbox), bbox, TRUE, TRUE, 0 );

  newgame = gtk_button_new_with_label( "New Game" );
  gtk_box_pack_start( GTK_BOX(bbox), newgame, FALSE, FALSE, 10 );
  gtk_signal_connect(GTK_OBJECT(newgame), "clicked", 
	  GTK_SIGNAL_FUNC(NewGame), NULL);

  quit = gtk_button_new_with_label( "Quit" );
  gtk_box_pack_start( GTK_BOX(bbox), quit, FALSE, FALSE, 10 );
  gtk_signal_connect_object (GTK_OBJECT (quit), "clicked",
    GTK_SIGNAL_FUNC (gtk_widget_destroy), GTK_OBJECT (dialog_window));

  gtk_widget_show_all( dialog_window );
  return( dialog_window );
}

main( argc, argv )
int argc;
char *argv[];
{
  gtk_init( &argc, &argv );

  dialog = GtkTTTDialog();
  NewGame( NULL );
  gtk_main();
}

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

#define RED 	1
#define GREEN 	2
#define BLUE 	4 

typedef struct piece {
  int x;			// position of the piece
  int y;			
  guint32 time;		// time the piece was added
  unsigned char color;	// its color
} Piece;

typedef struct cleardata {
  GtkWidget *w;
  GList **list;
} ClearData; 

static GtkWidget *gRedPmap, *gGreenPmap, *gBluePmap;
static unsigned char gColor = RED;

static GtkWidget*
NewPixmap( char *filename, GdkWindow *window, GdkColor *background )
{
  GtkWidget *wpixmap;
  GdkPixmap *pixmap;
  GdkBitmap *mask;

  pixmap = gdk_pixmap_create_from_xpm( window, &mask, background,
    filename );
  wpixmap = gtk_pixmap_new( pixmap, mask );

  return wpixmap;
}

static void
SetColor( GtkWidget *widget, gpointer arg )
{
  gColor = (unsigned long ) arg & 0xf;
}

static void
ClearDrawing( GtkWidget *widget, gpointer arg )
{
  ClearData *p = (ClearData *) arg;
  GList **list = p->list;
  GList *tmp_list;

  for (tmp_list = *list; tmp_list; tmp_list = tmp_list->next)
    g_free(tmp_list->data);

  g_list_free(*list);
  *list = (GList *) NULL;

  gdk_window_clear( p->w->window );
}

static int
CompFunc( gconstpointer a, gconstpointer b )
{
  Piece *piece1, *piece2;
	
  piece1 = (Piece *) a;	
  piece2 = (Piece *) b;	

  if ( piece1->time < piece2->time )
    return FALSE;
  return TRUE;
}

static gint
ButtonPress( GtkWidget *widget, GdkEventButton *event, gpointer arg )
{
  ClearData *p = (ClearData *) arg;
  GList **items = (GList **) p->list;
  GtkPixmap *pixmap;
  Piece *piece;

  piece = (Piece *) malloc( sizeof( Piece ) );
  piece->color = gColor;
  piece->x = (gint) event->x;
  piece->y = (gint) event->y;
  piece->time = gdk_event_get_time( (GdkEvent *) event );
  *items = g_list_insert_sorted( *items, piece, CompFunc );

  switch ( piece->color ) {
    case RED:
      pixmap = GTK_PIXMAP( gRedPmap );
      break;
    case GREEN:
      pixmap = GTK_PIXMAP( gGreenPmap );
      break;
    case BLUE:
      pixmap = GTK_PIXMAP( gBluePmap );
      break;
  }

  gdk_draw_pixmap( widget->window, widget->style->black_gc,
    pixmap->pixmap, 0, 0, piece->x, piece->y, -1, -1 );
}

static gint
HandleExpose( GtkWidget *widget, GdkEventExpose *event, gpointer arg )
{
  GList **p = (GList **) arg, *list = (GList *) *p;
  GdkRectangle rect, dest;
  GtkPixmap *pixmap;
  Piece *piece, *temp;
  int i;

  for ( i = 0; *p != (GList *) NULL; i++, *p = g_list_next( *p ) ) {
    piece = g_list_nth_data( (GList *) list, i );
    rect.x = piece->x; 
    rect.y = piece->y;
    rect.width = rect.height = 20;
    if ( gdk_rectangle_intersect( &rect, &event->area, &dest ) == TRUE ) {
      switch ( piece->color ) {
        case RED:
          pixmap = GTK_PIXMAP( gRedPmap );
          break;
        case GREEN:
          pixmap = GTK_PIXMAP( gGreenPmap );
          break;
        case BLUE:
          pixmap = GTK_PIXMAP( gBluePmap );
          break;
        default:
          continue;
      }

      gdk_gc_set_clip_rectangle( widget->style->black_gc, &event->area );
      gdk_draw_pixmap( widget->window, widget->style->black_gc, 
        pixmap->pixmap, 0, 0, piece->x, piece->y, -1, -1 );
      gdk_gc_set_clip_rectangle( widget->style->black_gc, NULL );
    }
  }
  *p = list;
}

main( int argc, char *argv[] )
{
  GtkWidget *dialog, *button, *drawing, *toolbar;
  GList *items = (GList *) NULL;
  ClearData cd;

  gtk_init( &argc, &argv );

  dialog = gtk_dialog_new();
  gtk_window_position( GTK_WINDOW( dialog ), GTK_WIN_POS_MOUSE );
  gtk_widget_show( dialog );

  toolbar = gtk_toolbar_new( GTK_ORIENTATION_HORIZONTAL, GTK_TOOLBAR_BOTH );

  gRedPmap = NewPixmap( "red.xpm", dialog->window, 
    &dialog->style->bg[GTK_STATE_NORMAL] ),
  gtk_toolbar_append_item( GTK_TOOLBAR( toolbar ), "Red", 
    "Draw red square", NULL, gRedPmap,
    (GtkSignalFunc) SetColor, (gpointer) RED );    
  gGreenPmap = NewPixmap( "green.xpm", dialog->window, 
    &dialog->style->bg[GTK_STATE_NORMAL] ),
  gtk_toolbar_append_item( GTK_TOOLBAR( toolbar ), "Green", 
    "Draw green square", NULL, gGreenPmap,
    (GtkSignalFunc) SetColor, (gpointer) GREEN );    
  gBluePmap = NewPixmap( "blue.xpm", dialog->window, 
    &dialog->style->bg[GTK_STATE_NORMAL] ),
  gtk_toolbar_append_item( GTK_TOOLBAR( toolbar ), "Blue", 
    "Draw blue square", NULL, gBluePmap,
    (GtkSignalFunc) SetColor, (gpointer) BLUE );    

  gtk_box_pack_start( GTK_BOX( GTK_DIALOG( dialog )->vbox ), toolbar, 
    FALSE, TRUE, 0 );

  drawing = gtk_drawing_area_new();
  gtk_drawing_area_size( GTK_DRAWING_AREA( drawing ), 320, 200 );
  gtk_signal_connect( GTK_OBJECT( drawing ), "expose_event",
    GTK_SIGNAL_FUNC( HandleExpose ), &items );
  gtk_widget_set_events( drawing, 
    GDK_EXPOSURE_MASK | GDK_BUTTON_PRESS_MASK);
  cd.w = drawing;
  cd.list = &items;
  gtk_signal_connect( GTK_OBJECT( drawing ), "button_press_event",
    GTK_SIGNAL_FUNC( ButtonPress ), &cd );
	
  gtk_box_pack_start( GTK_BOX( GTK_DIALOG( dialog )->vbox ), drawing, 
    TRUE, TRUE, 0 );

  button = gtk_button_new_with_label( "Clear" );
  gtk_box_pack_start( GTK_BOX( GTK_DIALOG( dialog )->action_area ), 
    button, TRUE, FALSE, 0 );
  gtk_signal_connect( GTK_OBJECT( button ), "clicked",
    GTK_SIGNAL_FUNC( ClearDrawing ), &cd );

  gtk_widget_show_all( dialog );
  gtk_main();
}

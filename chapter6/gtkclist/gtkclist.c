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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static GtkWidget *list;

int
CompareDate(char *text1, char *text2)
{
	char    *m1, *m2, *d1, *d2, *y1, *y2;
	int    	im1, im2, id1, id2, iy1, iy2;
	char	delim;

	char t1buf[NAME_MAX], t2buf[NAME_MAX];

	strncpy( t1buf, text1, NAME_MAX );
	strncpy( t2buf, text2, NAME_MAX );

	/* parse first date */

	delim = '/';
	m1 = strtok( t1buf, &delim );
	d1 = strtok( NULL, &delim );
	y1 = strtok( NULL, &delim );

	/* parse second date */

	m2 = strtok( t2buf, &delim );
	d2 = strtok( NULL, &delim );
	y2 = strtok( NULL, &delim );

	/* make sure we got something for each */

	if ( !m1 || !m2 || !d1 || !d2 || !y1 || !y2 )
		return( 0 );

	im1 = atoi( m1 ); id1 = atoi( d1 ); iy1 = atoi( y1 );
	im2 = atoi( m2 ); id2 = atoi( d2 ); iy2 = atoi( y2 );

	/* Year has precedence over month, which has precendence
	   over the day */

	if ( iy1 < iy2 )
		return( -1 );
	else if ( iy1 > iy2 )
		return( 1 );
	else {
		// year is the same

		if ( im1 < im2 )
			return( -1 );
		else if ( im1 > im2 )
			return( 1 );
		else {
			// year, month are the same

			if ( id1 < id2 )
				return( -1 );
			else if ( id1 > id2 )
				return( 1 );

			// fall through since dates are equal
		}
	}
	return( 0 );
}

static gint
MyCompare (GtkCList *clist, gconstpointer ptr1, gconstpointer ptr2)
{
  char *text1 = NULL;
  char *text2 = NULL;

  GtkCListRow *row1 = (GtkCListRow *) ptr1;
  GtkCListRow *row2 = (GtkCListRow *) ptr2;

  switch (row1->cell[clist->sort_column].type)
    {
    case GTK_CELL_TEXT:
      text1 = GTK_CELL_TEXT (row1->cell[clist->sort_column])->text;
      break;
    case GTK_CELL_PIXTEXT:
      text1 = GTK_CELL_PIXTEXT (row1->cell[clist->sort_column])->text;
      break;
    default:
      break;
    }

  switch (row2->cell[clist->sort_column].type)
    {
    case GTK_CELL_TEXT:
      text2 = GTK_CELL_TEXT (row2->cell[clist->sort_column])->text;
      break;
    case GTK_CELL_PIXTEXT:
      text2 = GTK_CELL_PIXTEXT (row2->cell[clist->sort_column])->text;
      break;
    default:
      break;
    }

  if (!text2)
    return (text1 != NULL);

  if (!text1)
    return -1;

  return CompareDate (text1, text2);
}

static gint
CompareEntireRow(GtkCList *clist, gconstpointer ptr1, gconstpointer ptr2)
{
  char *text1 = NULL;
  char *text2 = NULL;
  int i, ret;

  GtkCListRow *row1 = (GtkCListRow *) ptr1;
  GtkCListRow *row2 = (GtkCListRow *) ptr2;

  for ( i = 0; i < clist->columns; i++ ) {
  	switch (row1->cell[i].type)
    	{
    	case GTK_CELL_TEXT:
      		text1 = GTK_CELL_TEXT (row1->cell[i])->text;
      		break;
    	case GTK_CELL_PIXTEXT:
      		text1 = GTK_CELL_PIXTEXT (row1->cell[i])->text;
      		break;
    	default:
      		break;
    	}

    switch (row2->cell[i].type)
    	{
    	case GTK_CELL_TEXT:
      		text2 = GTK_CELL_TEXT (row2->cell[i])->text;
      		break;
    	case GTK_CELL_PIXTEXT:
      		text2 = GTK_CELL_PIXTEXT (row2->cell[i])->text;
      		break;
    	default:
      		break;
    	}

  	if (!text2)
    		return (text1 != NULL);

  	if (!text1)
    		return -1;

  	ret = strcmp (text1, text2);
	  if ( ret != 0 )
		  return( ret );
  }
  return( 0 );
}

static GtkWidget*
new_pixmap(char *filename, GdkWindow *window,
  GdkColor *background, GdkPixmap **pmap, GdkBitmap **mask)
{
  GtkWidget *wpixmap;

  *pmap = gdk_pixmap_create_from_xpm (window, mask, background, filename);
  wpixmap = gtk_pixmap_new (*pmap, *mask);

  return wpixmap;
}

static void
QuitCallback(GtkWidget *widget, GtkWidget *dialog_window)
{
	gtk_main_quit();
	exit( 0 );
}

main( int argc, char *argv[] )
{
	int i;
	GtkWidget *button, *hbox, *dialog_window;
	GtkWidget *pixmap;
	GdkPixmap *pmap;
	GdkBitmap *mask;
	GdkColor color, col1, col2;
	char *texts[3];
	GtkStyle *style = NULL, *style1 = NULL, *style2 = NULL, *style3 = NULL;

	static char *titles[] =
	{
	    "",
	    "Date",
	    "Location",
	};

	gtk_init( &argc, &argv );

	dialog_window = gtk_dialog_new();
 	gtk_window_position (GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);

	gtk_widget_set_usize( dialog_window, 100, 100 );

	hbox = gtk_hbox_new (FALSE, 0);
	gtk_container_add (GTK_CONTAINER (GTK_DIALOG (dialog_window)->vbox), 
		hbox);

 	list = gtk_clist_new_with_titles( 3, titles );

	gtk_clist_set_sort_column(GTK_CLIST(list), 1);
	gtk_clist_set_auto_sort(GTK_CLIST(list), TRUE);
	gtk_clist_set_reorderable (GTK_CLIST(list), TRUE);
	gtk_clist_set_compare_func(GTK_CLIST(list), MyCompare);

	gtk_clist_set_use_drag_icons( GTK_CLIST(list), TRUE );
	for ( i = 0; i < 3; i++ )
		gtk_clist_column_title_passive( GTK_CLIST(list), TRUE );

	texts[0] = "Item 1";
	texts[1] = "3/5/2000";
	texts[2] = "San Jose, CA";
	gtk_clist_append( GTK_CLIST( list ), texts );
	texts[0] = "Item 2";
	texts[1] = "1/12/1999";
	texts[2] = "Williamsburg, VA";
	gtk_clist_append( GTK_CLIST( list ), texts );
	texts[0] = "Item 3";
	texts[1] = "1/12/1997";
	texts[2] = "Seattle, WA";
	gtk_clist_append( GTK_CLIST( list ), texts );
	texts[0] = "Item 4";
	texts[1] = "2/12/1998";
	texts[2] = "New York, NY";
	gtk_clist_append( GTK_CLIST( list ), texts );

	gtk_clist_set_selection_mode(GTK_CLIST(list), GTK_SELECTION_SINGLE);
	gtk_clist_set_column_auto_resize(GTK_CLIST(list), 0, TRUE );
	gtk_clist_set_column_auto_resize(GTK_CLIST(list), 1, TRUE );
	gtk_clist_set_column_auto_resize(GTK_CLIST(list), 2, TRUE );
	gtk_clist_set_shift(GTK_CLIST(list), 1, 0, 5, 5 );
  gtk_box_pack_start (GTK_BOX (hbox), list, FALSE, FALSE, 0);

  button = gtk_button_new_with_label ("Quit");
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area), 
		button, TRUE, TRUE, 0);
  gtk_signal_connect (GTK_OBJECT (button), "clicked", 
		GTK_SIGNAL_FUNC(QuitCallback), dialog_window);
  gtk_widget_show_all (dialog_window);
  pixmap = new_pixmap ("test.xpm", dialog_window->window,
    &dialog_window->style->bg[GTK_STATE_NORMAL], &pmap, &mask);
	gtk_clist_set_column_widget(GTK_CLIST(list), 0, pixmap);
	color.red = color.green = 0; color.blue = 0xffff;
	gtk_clist_set_foreground( GTK_CLIST( list ), 1, &color );
  gtk_clist_set_pixtext (GTK_CLIST(list), 0, 2, "New York, NY", 5, pmap, mask);

  col1.red   = 0;
  col1.green = 56000;
  col1.blue  = 0;
  col2.red   = 32000;
  col2.green = 0;
  col2.blue  = 56000;

  style1 = gtk_style_copy (GTK_WIDGET (list)->style);
  style1->base[GTK_STATE_NORMAL] = col1;
  style1->base[GTK_STATE_SELECTED] = col2;

  style2 = GTK_WIDGET (list)->style;
  style2->fg[GTK_STATE_NORMAL] = col1;
  style2->fg[GTK_STATE_SELECTED] = col2;

  style3 = gtk_style_copy (GTK_WIDGET (list)->style);
  style3->fg[GTK_STATE_NORMAL] = col1;
  style3->base[GTK_STATE_NORMAL] = col2;
  gdk_font_unref (style3->font);
  style3->font = gdk_font_load("-*-courier-medium-*-*-*-*-120-*-*-*-*-*-*");


  style = list->style;
  style = gtk_clist_get_cell_style( GTK_CLIST(list), 0, 0 );	
	style = gtk_clist_get_row_style( GTK_CLIST(list), 0 );	

  gtk_clist_set_cell_style (GTK_CLIST (list), 0, 0, style1);
  gtk_clist_set_cell_style (GTK_CLIST (list), 1, 0, style2);
  gtk_clist_set_cell_style (GTK_CLIST (list), 2, 0, style3);

	gtk_main();
}

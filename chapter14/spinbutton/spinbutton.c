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

static int which = 1, timeout = 0;
static GtkWidget *spinner, *visible, *pixmap1, *pixmap2, *pixmap3;
static GtkWidget *button1, *button2, *button3, *label;
static GtkAdjustment *adj;

static void
NextCallback(GtkWidget *widget, gpointer dummy)
{
  which++;
  if ( which == 4 )
    which = 1;
  gtk_adjustment_set_value( adj, (float) which );
}

static void
PrevCallback(GtkWidget *widget, gpointer dummy)
{
  which--;
  if ( which == 0 )
    which = 3;
  gtk_adjustment_set_value( adj, (float) which );
}

static void
SpinnerCallback( GtkAdjustment *adj, gpointer dummy)
{
  GdkPixmap *gdkPixmap;
  GdkBitmap *gdkBitmap;
  GtkWidget *current;

  which = (int) adj->value;
  if ( which == 1 ) 
    current = pixmap1;
  else if ( which == 2 )
    current = pixmap2;
  else
    current = pixmap3;

  gtk_pixmap_get(GTK_PIXMAP( current ), &gdkPixmap, &gdkBitmap);
  gtk_pixmap_set(GTK_PIXMAP( visible ), gdkPixmap, gdkBitmap);
}

int
SlidesTimerCallback(gpointer dummy)
{
  gtk_spin_button_spin( GTK_SPIN_BUTTON( spinner ), 
    GTK_SPIN_STEP_FORWARD, 0 );
  return 1;
}

static void
SlidesCallback(GtkWidget *widget, gpointer dummy)
{
  static void CancelCallback(GtkWidget *widget, gpointer dummy);

  if ( GTK_WIDGET_SENSITIVE( button1 ) == FALSE ) {
    CancelCallback( widget, dummy );
    return; 
  }

  gtk_spin_button_set_value(GTK_SPIN_BUTTON(spinner), 1.0);
  timeout = gtk_timeout_add(5000, SlidesTimerCallback, NULL);
  gtk_widget_set_sensitive( button1, FALSE );
  gtk_widget_set_sensitive( button2, FALSE );
  gtk_label_set_text( GTK_LABEL( label ), "Cancel Slide Show" );
}

static void
CancelCallback(GtkWidget *widget, gpointer dummy)
{
  if ( timeout ) {
    gtk_timeout_remove(timeout);
    timeout = 0;
  }
  gtk_widget_set_sensitive( button1, TRUE );
  gtk_widget_set_sensitive( button2, TRUE );
  gtk_label_set_text( GTK_LABEL( label ), "Slide Show" );
}

static GtkWidget *
new_pixmap (char *file, GdkWindow *window, GdkColor *background)
{
  GdkPixmap *pmap;
  GdkBitmap *mask;
  GtkWidget *wpmap;

  pmap = gdk_pixmap_create_from_xpm(window, &mask, background, file);
  wpmap = gtk_pixmap_new(pmap, mask);
  return( wpmap );
}

main( int argc, char *argv[] )
{
  GtkWidget *dialog_window;

  gtk_init( &argc, &argv );

  dialog_window = gtk_dialog_new();
  gtk_window_position (GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);

  gtk_widget_show( dialog_window );

  visible = new_pixmap ("pic1.xpm", dialog_window->window, 
    &dialog_window->style->bg[GTK_STATE_NORMAL]);
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->vbox), 
    visible, TRUE, TRUE, 0);

  pixmap1 = new_pixmap ("pic1.xpm", dialog_window->window, 
    &dialog_window->style->bg[GTK_STATE_NORMAL]);
  pixmap2 = new_pixmap ("pic2.xpm", dialog_window->window, 
    &dialog_window->style->bg[GTK_STATE_NORMAL]);
  pixmap3 = new_pixmap ("pic3.xpm", dialog_window->window, 
    &dialog_window->style->bg[GTK_STATE_NORMAL]);

  button2 = gtk_button_new_with_label ("Prev");
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area), 
    button2, TRUE, TRUE, 0);
  gtk_signal_connect (GTK_OBJECT (button2), "clicked", 
    GTK_SIGNAL_FUNC(PrevCallback), dialog_window);

  button1 = gtk_button_new_with_label ("Next");
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area), 
    button1, TRUE, TRUE, 0);
  gtk_signal_connect (GTK_OBJECT (button1), "clicked", 
    GTK_SIGNAL_FUNC(NextCallback), dialog_window);

  adj = (GtkAdjustment *) gtk_adjustment_new( 1.0, 1.0, 3.0, 1.0, 1.0, 1.0 );
  gtk_signal_connect(GTK_OBJECT(adj), "value_changed",
    GTK_SIGNAL_FUNC (SpinnerCallback), NULL);

  spinner = gtk_spin_button_new( GTK_ADJUSTMENT(adj), 0.0, 0.0 );
  gtk_spin_button_set_wrap(GTK_SPIN_BUTTON(spinner), TRUE);
  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area), 
    spinner, TRUE, TRUE, 0);

  button3 = gtk_button_new();
  label = gtk_label_new( "Slide Show" );
  gtk_container_add( GTK_CONTAINER( button3 ), label );

  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area), 
    button3, TRUE, TRUE, 0);
  gtk_signal_connect (GTK_OBJECT (button3), "clicked", 
    GTK_SIGNAL_FUNC(SlidesCallback), NULL);

  gtk_widget_show_all (dialog_window);
  gtk_main();
}

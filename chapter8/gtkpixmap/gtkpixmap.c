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

GtkWidget *pixmap1, *pixmap2;

static void
SwitchCallback(GtkWidget *widget, GtkWidget *dialog_window)
{
	GdkPixmap *gdkPixmap1, *gdkPixmap2;
	GdkBitmap *gdkBitmap1, *gdkBitmap2;
	static int makeSensitive = 0;

	/* retrieve current values */

	gtk_pixmap_get(GTK_PIXMAP(pixmap1), &gdkPixmap1, &gdkBitmap1);
	gtk_pixmap_get(GTK_PIXMAP(pixmap2), &gdkPixmap2, &gdkBitmap2);

	/* and swap them */

	gtk_pixmap_set(GTK_PIXMAP(pixmap1), gdkPixmap2, gdkBitmap2);
	gtk_pixmap_set(GTK_PIXMAP(pixmap2), gdkPixmap1, gdkBitmap1);

	if ( makeSensitive == 0 ) {
		makeSensitive = 1;
		gtk_widget_set_sensitive( pixmap1, FALSE );
		gtk_widget_set_sensitive( pixmap2, FALSE );
	} else {
		makeSensitive = 0;
		gtk_widget_set_sensitive( pixmap1, TRUE );
		gtk_widget_set_sensitive( pixmap2, TRUE );
	}
}

static GtkWidget *
new_pixmap (char *file, GdkWindow *window, GdkColor *background)
{
 	GdkPixmap *pmap;
 	GdkBitmap *mask;
	GtkWidget *wpmap;

	pmap = gdk_pixmap_create_from_xpm(window, &mask, background, file);
 	wpmap = gtk_pixmap_new(pmap, mask);
	gtk_pixmap_set_build_insensitive(GTK_PIXMAP(wpmap), 1);
	return( wpmap );
}

main( int argc, char *argv[] )
{
	GtkWidget *button, *hbox, *dialog_window;

	gtk_init( &argc, &argv );

	dialog_window = gtk_dialog_new();
 	gtk_window_position (GTK_WINDOW (dialog_window), GTK_WIN_POS_MOUSE);

	gtk_widget_show( dialog_window );

	hbox = gtk_hbox_new (FALSE, 0);
	gtk_container_add (GTK_CONTAINER (GTK_DIALOG (dialog_window)->vbox), 
		hbox);

	pixmap1 = new_pixmap ("test1.xpm", dialog_window->window, 
		&dialog_window->style->bg[GTK_STATE_NORMAL]);
  gtk_box_pack_start (GTK_BOX (hbox), pixmap1, TRUE, TRUE, 0);
	pixmap2 = new_pixmap ("test2.xpm", dialog_window->window, 
		&dialog_window->style->bg[GTK_STATE_NORMAL]);
  gtk_box_pack_start (GTK_BOX (hbox), pixmap2, TRUE, TRUE, 0);

 	button = gtk_button_new_with_label ("Switch Pixmaps");
 	gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog_window)->action_area), 
		button, TRUE, TRUE, 0);
 	gtk_signal_connect (GTK_OBJECT (button), "clicked", 
		GTK_SIGNAL_FUNC(SwitchCallback), dialog_window);

 	gtk_widget_show_all (dialog_window);
	gtk_main();
}

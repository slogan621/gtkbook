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
#include <sys/stat.h>

void
FontSelOk(GtkWidget *w, gpointer arg)
{
	GtkFontSelection *fontSel = (GtkFontSelection *) arg;
	char *fontName, *text;
	GdkFont *font;

	fontName = gtk_font_selection_get_font_name(fontSel);
	printf( "font name is %s\n", fontName );

	text = gtk_font_selection_get_preview_text(fontSel);
	printf( "preview text is %s\n", text );

	font = gtk_font_selection_get_font(fontSel);
}

main( int argc, char *argv[] )
{
	GtkWidget *fontSel, *button, *window, *vbox;
	gboolean ret;
	char *foundries[] = { "bitstream", NULL };
	char *weights[] = { "bitstream", NULL };
	char *slants[] = { "bitstream", NULL };
	char *setwidths[] = { "bitstream", NULL };
	char *spacings[] = { "bitstream", NULL };
	char *charsets[] = { "iso8859-1", NULL };

	gtk_init( &argc, &argv );

	window = gtk_window_new( GTK_WINDOW_TOPLEVEL );

	vbox = gtk_vbox_new( FALSE, 0 );

	gtk_container_add( GTK_CONTAINER( window ), vbox );

	fontSel = gtk_font_selection_new();
	gtk_widget_show( fontSel );

  gtk_box_pack_start( GTK_BOX( vbox ), fontSel, FALSE, FALSE, 0 );

	button = gtk_button_new_with_label( "OK" );

  gtk_box_pack_end( GTK_BOX( vbox ), button, FALSE, FALSE, 0 );

  gtk_signal_connect(GTK_OBJECT(button), "clicked", 
		(GtkSignalFunc) FontSelOk, fontSel );

	gtk_widget_show_all( window );

	gtk_font_selection_set_filter(GTK_FONT_SELECTION(fontSel),
		GTK_FONT_FILTER_USER, GTK_FONT_ALL, 
		foundries, NULL, NULL, NULL, NULL, charsets );

#if 0
	ret = gtk_font_selection_set_font_name( GTK_FONT_SELECTION( fontSel ),
		"lalalalala" );
#endif
#if 0
	ret = gtk_font_selection_set_font_name( GTK_FONT_SELECTION( fontSel ),
		"-urw-century schoolbook l-medium-r-normal--15-140-75-75-p-82-iso8859-1" );
#endif
	ret = gtk_font_selection_set_font_name( GTK_FONT_SELECTION( fontSel ),
		"-bitstream-courier-medium-r-normal--15-140-75-75-m-90-iso8859-1" );
	printf( "ret is %d\n", ret );

	gtk_main();
}


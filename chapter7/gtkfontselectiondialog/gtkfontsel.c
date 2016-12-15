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
	GtkFontSelectionDialog *fontSel = (GtkFontSelectionDialog *) arg;
	char *fontName, *text;
	GdkFont *font;

	fontName = gtk_font_selection_dialog_get_font_name(fontSel);
	printf( "font name is %s\n", fontName );

	text = gtk_font_selection_dialog_get_preview_text(fontSel);
	printf( "preview text is %s\n", text );

	font = gtk_font_selection_dialog_get_font(fontSel);
}

main( int argc, char *argv[] )
{
	GtkWidget *fontSel;
	gboolean ret;
	char *foundries[] = { "bitstream", NULL };
	char *weights[] = { "bitstream", NULL };
	char *slants[] = { "bitstream", NULL };
	char *setwidths[] = { "bitstream", NULL };
	char *spacings[] = { "bitstream", NULL };
	char *charsets[] = { "iso8859-1", NULL };

	gtk_init( &argc, &argv );

	fontSel = gtk_font_selection_dialog_new("Font Selection");
	gtk_widget_show( fontSel );

#if 1
	gtk_font_selection_dialog_set_filter(GTK_FONT_SELECTION_DIALOG(fontSel),
		GTK_FONT_FILTER_USER, GTK_FONT_ALL, 
		foundries, NULL, NULL, NULL, NULL, charsets );
#endif

#if 0
	ret = gtk_font_selection_dialog_set_font_name( GTK_FONT_SELECTION_DIALOG( fontSel ),
		"lalalalala" );
#endif
#if 0
	ret = gtk_font_selection_dialog_set_font_name( GTK_FONT_SELECTION_DIALOG( fontSel ),
		"-urw-century schoolbook l-medium-r-normal--15-140-75-75-p-82-iso8859-1" );
#endif
	ret = gtk_font_selection_dialog_set_font_name( GTK_FONT_SELECTION_DIALOG( fontSel ),
		"-bitstream-courier-medium-r-normal--15-140-75-75-m-90-iso8859-1" );
	printf( "ret is %d\n", ret );

	gtk_main();
}


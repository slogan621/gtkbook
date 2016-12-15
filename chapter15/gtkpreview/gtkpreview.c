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

#include <tiffio.h>
#include <stdlib.h>

#include <gtk/gtk.h>
#include <X11/Xlib.h>

static uint32 *raster;
static int width, height;
static GtkWidget *preview;

uint32 *
scale( uint32 *raster, int width, int height )
{
  return raster;
}

int
timeoutfunc( gpointer data )
{
  guint i, j, k, RGB;
  guchar *buf;
  static int foo = 0;
  static int dither = 0;
  static double gamma = 1.0;

#if 0
  if ( allocation->width != widget->requisition.width ||
    allocation->height != widget->requisition.height &&
    preview->expand == TRUE ) 
  {
    width = allocation->width;
    height = allocation->height;
    gtk_preview_size( preview, width, height );
    raster = scale( raster, width, height );
  }
#endif

  buf = (guchar *) malloc(width * 3);
  if ( !buf )
    return;

  gtk_preview_set_gamma( gamma );
  gtk_preview_set_dither(GTK_PREVIEW (preview), dither);
  for ( i = 0; i < height; i++ ) {
    for ( j = 0, k = 0; j < width; j++ ) {
#if 0
      RGB = raster[((height - 1) - i) * width + j];
      buf[k+0] = TIFFGetR(RGB) / (foo ? 2 : 1 );
      buf[k+1] = TIFFGetG(RGB) / (foo ? 2 : 1 );
      buf[k+2] = TIFFGetB(RGB) / (foo ? 2 : 1 );
      k += 3;
#else
      RGB = raster[((height - 1) - i) * width + j];
      buf[k+0] = TIFFGetR(RGB);
      buf[k+1] = TIFFGetG(RGB);
      buf[k+2] = TIFFGetB(RGB);
      k += 3;
#endif
    }
    gtk_preview_draw_row(GTK_PREVIEW(preview), buf, 0, i, width);
  }
  if ( buf )
    free( buf );
  foo = !foo;
  dither++;
  if ( dither == 3 )
    dither = 0;
  gamma += 0.1;
  if ( gamma >= 1.1 )
    gamma = 0.0;
		
  gtk_widget_queue_draw (GTK_WIDGET (preview));

  return TRUE;
}

void
SizeAllocation( GtkWidget *widget, GtkAllocation  *allocation)
{
  guint i, j, k, RGB;
  GtkPreview *preview = GTK_PREVIEW( widget );
  guchar *buf;

#if 0
  if ( allocation->width != widget->requisition.width ||
    allocation->height != widget->requisition.height &&
    preview->expand == TRUE ) 
  {
    width = allocation->width;
    height = allocation->height;
    gtk_preview_size( preview, width, height );
    raster = scale( raster, width, height );
  }
#endif

  buf = (guchar *) malloc(width * 3);
  if ( !buf )
    return;

  for ( i = 0; i < height; i++ ) {
    for ( j = 0, k = 0; j < width; j++ ) {
      RGB = raster[((height - 1) - i) * width + j];
      buf[k+0] = TIFFGetR(RGB);
      buf[k+1] = TIFFGetG(RGB);
      buf[k+2] = TIFFGetB(RGB);
      k += 3;
    }
    gtk_preview_draw_row(GTK_PREVIEW(preview), buf, 0, i, width);
  }
  if ( buf )
    free( buf );
}

int main( int argc, char *argv[] )
{
  uint32 RGB, pixel;
  uint16 bitspersample, samplesperpixel;
  GtkWidget *window, *vbox;
  TIFF *tif;

  gtk_init( &argc, &argv );

  window = gtk_window_new( GTK_WINDOW_TOPLEVEL );

  tif = TIFFOpen(argv[1], "r");

  if ( !tif ) {
    printf( "Unable to open tiff file %s\n", argv[1] );
    exit( 1 );
  }

  TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, &width);
  TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &height);
  TIFFGetField(tif, TIFFTAG_BITSPERSAMPLE, &bitspersample);
  TIFFGetField(tif, TIFFTAG_SAMPLESPERPIXEL, &samplesperpixel);

  if ( samplesperpixel != 3 ) {
    printf( "Error: image is not RGB.\n" );
    exit( 1 );
  }

  raster = (uint32*)malloc(width * height * sizeof (uint32));

  if ( !raster ) {
    perror( "malloc" );
    exit( 1 );
  }

  if (!TIFFReadRGBAImage(tif, width, height, raster, 0)) {
    printf( "TIFFReadRGBAImage() failed\n" );
    exit( 1 );
  }

  gtk_widget_set_usize( window, width, height );
  vbox = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(window), vbox);

  preview = gtk_preview_new(GTK_PREVIEW_COLOR);
  gtk_preview_size(GTK_PREVIEW (preview), width, height);
  gtk_preview_set_expand(GTK_PREVIEW (preview), TRUE);

  gtk_signal_connect(GTK_OBJECT (preview), "size_allocate",
    GTK_SIGNAL_FUNC (SizeAllocation), NULL);

  gtk_box_pack_start( GTK_BOX(vbox), preview, TRUE, TRUE, 0);

  gtk_timeout_add(100, timeoutfunc, NULL);

  gtk_widget_show_all( window );

  gtk_main();
}


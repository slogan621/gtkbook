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

#if 0
#include "mask.bmp"
#endif

int main( int argc, char *argv[] )
{
	uint32 	RGB, pixel, width, height, *raster;
	uint16 	bitspersample, samplesperpixel;
	int	i, j, byteOrder, rshift, gshift, bshift;
	TIFF 	*tif;
	GtkWidget *window, *image, *vbox;
	GdkImage *gimage;
	GdkVisual *visual;
	GdkBitmap *mask;

	gtk_init( &argc, &argv );

	window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
	if ( !window ) {
		printf( "Unable to create a window\n" );
   	exit( 1 );
	}

	visual = gtk_widget_get_visual(window);
	byteOrder = visual->byte_order;
	gshift = 8;
	if ( byteOrder == LSBFirst ) {
		rshift = 16;
		bshift = 0;
	} else {
		rshift = 0;
		bshift = 16;
	}

	tif = TIFFOpen(argv[1], "r");

	if ( !tif ) {
		printf( "Unable to open tiff file %s\n", argv[1] );
		exit( 1 );
	}

	TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, &width);
	TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &height);
	TIFFGetField(tif, TIFFTAG_BITSPERSAMPLE, &bitspersample);
	TIFFGetField(tif, TIFFTAG_SAMPLESPERPIXEL, &samplesperpixel);

	printf( "Image width %d height %d\n", width, height );

	if ( bitspersample != 8 || samplesperpixel != 3 ) {
		printf( "Error: image is not RGB or is not 24-bit\n" );
		exit( 1 );
	}
	raster = (uint32*)malloc(width * height * sizeof (uint32));
	if ( !raster ) {
		perror( "malloc" );
		exit( 1 );
	}
	if (!TIFFReadRGBAImage(tif, width, height, raster, 0)) {
		printf( "TIFFReadRGBAImage failed\n" );
		exit( 1 );
	}

	gtk_widget_set_usize( window, width, height );
	vbox = gtk_vbox_new (FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	gimage = gdk_image_new( GDK_IMAGE_FASTEST, visual, width, height );
	if ( !gimage ) {
		printf( "Unable to create a GDK image\n" );
		exit( 1 );
	}
	for ( i = 0; i < height; i++ ) {
		for ( j = 0; j < width; j++ ) {
			RGB = raster[ i *  width + j ];
			pixel = TIFFGetR(RGB) << rshift | 
				TIFFGetG(RGB) << gshift |
				TIFFGetB(RGB) << bshift; 
			gdk_image_put_pixel( gimage, j, 
				(height - 1) - i, pixel );
		}
	}

#if 0
	mask = (GdkBitmap *) gdk_bitmap_create_from_data (window->window,
		mask_bits, mask_width, mask_height );	
#endif

	image = gtk_image_new( gimage, NULL );

	if ( !image ) {
		printf( "Unable to create a Gtk+ image\n" );
		exit( 1 );
	}
	gtk_box_pack_start( GTK_BOX(vbox), image, TRUE, TRUE, 0);
	gtk_widget_show_all( window );
	gtk_main();
}


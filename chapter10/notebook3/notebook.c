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

static int current_page = 0;
static GtkWidget *prev_button, *next_button, *finish_button;

void
SetSensitivity()
{
	if ( current_page == 2 )
		gtk_widget_set_sensitive( next_button, FALSE );
	else
		gtk_widget_set_sensitive( next_button, TRUE );
	if ( current_page > 0 )
		gtk_widget_set_sensitive( prev_button, TRUE );
	else
		gtk_widget_set_sensitive( prev_button, FALSE );
	if ( current_page == 2 )
		gtk_widget_set_sensitive( finish_button, TRUE );
	else
		gtk_widget_set_sensitive( finish_button, FALSE );
}

void
NextCallback(GtkWidget *widget, GtkNotebook *notebook)
{
	if ( current_page < 2 )
		current_page++;
	SetSensitivity();
	gtk_notebook_set_page( notebook, current_page );
		
}

void
PreviousCallback(GtkWidget *widget, GtkNotebook *notebook)
{
	if ( current_page > 0 )
		current_page--;
	SetSensitivity();
	gtk_notebook_set_page( notebook, current_page );
}

void
FinishCallback(GtkWidget *widget, GtkNotebook *notebook)
{
	gboolean expand, fill, homogeneous;
	static GtkPackType pack = GTK_PACK_START;
	static int which = 0;
	int i;

	switch( which ) {
	case 0:
		pack = GTK_PACK_START;
		fill = FALSE;
		expand = FALSE;
		homogeneous = FALSE;
		break;
	case 1:
		pack = GTK_PACK_START;
		fill = FALSE;
		expand = TRUE;
		homogeneous = FALSE;
		break;
	case 2:
		pack = GTK_PACK_START;
		fill = TRUE;
		expand = FALSE;
		homogeneous = FALSE;
		break;
	case 3:
		pack = GTK_PACK_START;
		fill = FALSE;
		expand = FALSE;
		homogeneous = FALSE;
		break;
	case 4:
		pack = GTK_PACK_START;
		fill = FALSE;
		expand = FALSE;
		homogeneous = TRUE;
		break;
	case 5:
		pack = GTK_PACK_START;
		fill = FALSE;
		expand = TRUE;
		homogeneous = TRUE;
		break;
	case 6:
		pack = GTK_PACK_START;
		fill = TRUE;
		expand = FALSE;
		homogeneous = TRUE;
		break;
	case 7:
		pack = GTK_PACK_START;
		fill = FALSE;
		expand = FALSE;
		homogeneous = TRUE;
		break;
	}
	which++;
	if ( which == 8 )
		which = 0;
	for ( i = 0; i < 3; i++ ) {
		gtk_notebook_set_tab_label_packing( notebook,
			gtk_notebook_get_nth_page( notebook, i ), expand, fill, pack );
		gtk_notebook_set_homogeneous_tabs( notebook, homogeneous );
	}
	printf( "Homogeneous %s expand %s fill %s\n", 
		(homogeneous == FALSE ? "False" : "True" ),
		( expand == FALSE ? "False" : "True" ),
		( fill == FALSE ? "False" : "True" ) );
}

void 
CreatePanelOne( GtkWidget *notebook )
{
	GtkWidget *frame, *vbox, *radio1, *radio2, *radio3;

	frame = gtk_frame_new( "Select a Video Depth" );
	gtk_widget_show( frame );

	vbox = gtk_vbox_new( FALSE, 10 );
	gtk_widget_show( vbox );
	gtk_container_add (GTK_CONTAINER(frame), vbox );

	radio1 = gtk_radio_button_new_with_label( NULL, "8bpp" );
	gtk_box_pack_start( GTK_BOX( vbox ), radio1, TRUE, TRUE, 0 );
	gtk_widget_show( radio1 );
	
	radio2 = gtk_radio_button_new_with_label( 
		gtk_radio_button_group( GTK_RADIO_BUTTON( radio1 )), "16bpp" );
	gtk_box_pack_start( GTK_BOX( vbox ), radio2, TRUE, TRUE, 0 );
	gtk_widget_show( radio2 );
	radio3 = gtk_radio_button_new_with_label( 
		gtk_radio_button_group( GTK_RADIO_BUTTON( radio2 )), "24bpp" );
	gtk_box_pack_start( GTK_BOX( vbox ), radio3, TRUE, TRUE, 0 );
	gtk_widget_show( radio3 );

	gtk_notebook_append_page( GTK_NOTEBOOK( notebook ), frame, NULL ); 
	gtk_notebook_set_tab_label_text( GTK_NOTEBOOK( notebook ), frame,
		"Select a Depth" );
}

void 
CreatePanelTwo( GtkWidget *notebook )
{
	GtkWidget *frame, *vbox, *radio1, *radio2, *radio3;

	frame = gtk_frame_new( "Select a Resolution" );
	gtk_widget_show( frame );

	vbox = gtk_vbox_new( FALSE, 10 );
	gtk_widget_show( vbox );
	gtk_container_add (GTK_CONTAINER(frame), vbox );

	radio1 = gtk_radio_button_new_with_label( NULL, "800x600" );
	gtk_box_pack_start( GTK_BOX( vbox ), radio1, TRUE, TRUE, 0 );
	gtk_widget_show( radio1 );
	
	radio2 = gtk_radio_button_new_with_label( 
		gtk_radio_button_group( GTK_RADIO_BUTTON( radio1 )), "1024x768" );
	gtk_box_pack_start( GTK_BOX( vbox ), radio2, TRUE, TRUE, 0 );
	gtk_widget_show( radio2 );
	radio3 = gtk_radio_button_new_with_label( 
		gtk_radio_button_group( GTK_RADIO_BUTTON( radio2 )), "1280x1024" );
	gtk_box_pack_start( GTK_BOX( vbox ), radio3, TRUE, TRUE, 0 );
	gtk_widget_show( radio3 );

	gtk_notebook_append_page( GTK_NOTEBOOK( notebook ), frame, NULL ); 
	gtk_notebook_set_tab_label_packing( GTK_NOTEBOOK( notebook ), frame,
		FALSE, TRUE, GTK_PACK_START );
	gtk_notebook_set_tab_label_text( GTK_NOTEBOOK( notebook ), frame,
		"Select a Resolution" );
}

void 
CreatePanelThree( GtkWidget *notebook )
{
	GtkWidget *vbox, *label;

	vbox = gtk_vbox_new( FALSE, 10 );

	gtk_widget_show( vbox );

	label = gtk_label_new( "Use Finish to commit changes, or Quit to exit." );
	gtk_widget_show( label );
	gtk_box_pack_start_defaults( GTK_BOX( vbox ), label );

	gtk_notebook_append_page( GTK_NOTEBOOK( notebook ), vbox, NULL ); 
	gtk_notebook_set_tab_label_text( GTK_NOTEBOOK( notebook ), vbox, "Finish" );
}

int main( int argc, char *argv[] )
{
 	GtkWidget *window, *vbox, *hbox, *button, *notebook;

 	gtk_init(&argc, &argv);

	// create a window
 
 	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 	gtk_signal_connect(GTK_OBJECT(window), "destroy", 
    GTK_SIGNAL_FUNC (gtk_main_quit), "WM destroy");
 	gtk_window_set_title(GTK_WINDOW(window), "Video Settings");
 	gtk_widget_set_usize(GTK_WIDGET(window), 300, 200);

	// create a notebook and add it to the window

	vbox = gtk_vbox_new( FALSE, 10 );
 	gtk_container_add(GTK_CONTAINER (window), vbox);

	gtk_widget_show( vbox );

	notebook = gtk_notebook_new();
//	gtk_notebook_set_show_tabs( GTK_NOTEBOOK( notebook ), FALSE );
	gtk_notebook_set_show_border( GTK_NOTEBOOK( notebook ), FALSE );

	gtk_box_pack_start_defaults( GTK_BOX(vbox), notebook );

 	gtk_widget_show( notebook );

	CreatePanelOne( notebook );
	CreatePanelTwo( notebook );
	CreatePanelThree( notebook );

	hbox = gtk_hbox_new( TRUE, 10 );
	gtk_box_pack_start( GTK_BOX(vbox), hbox, FALSE, FALSE, 10 );
	gtk_widget_show( hbox );

	button = gtk_button_new_with_label( "Quit" );
	gtk_box_pack_start( GTK_BOX(hbox), button, TRUE, FALSE, 0 );
	gtk_widget_show( button );
	gtk_signal_connect_object(GTK_OBJECT (button), "clicked",
    GTK_SIGNAL_FUNC(gtk_widget_destroy), GTK_OBJECT(window));

	prev_button = button = gtk_button_new_with_label( "Previous" );
	gtk_box_pack_start( GTK_BOX(hbox), button, TRUE, FALSE, 0 );
	gtk_widget_show( button );
	gtk_signal_connect(GTK_OBJECT (button), "clicked",
		GTK_SIGNAL_FUNC(PreviousCallback), notebook);
	gtk_widget_set_sensitive( button, FALSE );

	next_button = button = gtk_button_new_with_label( "Next" );
	gtk_box_pack_start( GTK_BOX(hbox), button, TRUE, FALSE, 0 );
	gtk_widget_show( button );
	gtk_signal_connect(GTK_OBJECT (button), "clicked",
		GTK_SIGNAL_FUNC(NextCallback), notebook);

	finish_button = button = gtk_button_new_with_label( "Finish" );
	gtk_box_pack_start( GTK_BOX(hbox), button, TRUE, FALSE, 0 );
	gtk_widget_show( button );
	gtk_signal_connect(GTK_OBJECT (button), "clicked",
    GTK_SIGNAL_FUNC(FinishCallback), notebook);
	gtk_widget_set_sensitive( button, FALSE );

	// show the main window and call the main loop

 	gtk_widget_show(window);
 	gtk_main ();
 
 	return(0);
}


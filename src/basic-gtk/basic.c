
#include <gtk/gtk.h>

void
button_clicked(GtkButton *button, gpointer user_data )
{
    gtk_button_set_label( button, "Thank you!" );
}

gint main ( gint argc, gchar* argv[] )
{
    gtk_init( &argc, &argv );

    GtkWidget *window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
    gtk_window_set_title( GTK_WINDOW(window), "First GTK+ Program" );
    gtk_window_set_position( GTK_WINDOW(window), GTK_WIN_POS_CENTER );
    gtk_container_set_border_width( GTK_CONTAINER(window), 10 );
    gtk_window_set_default_size( GTK_WINDOW(window), 350, 70 );
    g_signal_connect ( GTK_WIDGET(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *button = gtk_button_new_with_label( "Click me!" );
    g_signal_connect ( GTK_WIDGET(button), "clicked", G_CALLBACK(button_clicked), NULL);

    gtk_container_add( GTK_CONTAINER(window), button );
    gtk_widget_show_all( GTK_WIDGET( window ) );

    gtk_main();

    return 0;

}

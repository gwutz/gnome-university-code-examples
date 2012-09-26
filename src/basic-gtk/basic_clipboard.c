
#include <gtk/gtk.h>


void
entry_text_changes ( GtkEntry *entry, gpointer data ) {
    g_return_if_fail(data != NULL);
    GtkClipboard *clipboard = (GtkClipboard*)data;
    gtk_clipboard_set_text( clipboard, gtk_entry_get_text( entry ), -1 );
}

gint main ( gint argc, gchar* argv[] )
{
    gtk_init( &argc, &argv );

    GtkWidget *window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
    gtk_window_set_title( GTK_WINDOW(window), "Clipboard Demonstration" );
    g_object_set( window, "window-position", GTK_WIN_POS_CENTER, "border-width", 10, NULL );
    gtk_window_set_default_size( GTK_WINDOW(window), 350, 70 );
    g_signal_connect ( GTK_WIDGET(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *entry = gtk_entry_new();

    gtk_container_add( GTK_CONTAINER(window), entry );
    gtk_widget_show_all( GTK_WIDGET( window ) );

    GdkDisplay *display = gtk_widget_get_display( window );
    GtkClipboard *clipboard = gtk_clipboard_get_for_display( display, GDK_SELECTION_CLIPBOARD );

    gchar *text = gtk_clipboard_wait_for_text( clipboard );
    if ( !text ) {
        text = g_strdup("");
    }
    gtk_entry_set_text( GTK_ENTRY(entry), text );

    g_signal_connect( entry, "changed", G_CALLBACK(entry_text_changes), (gpointer)clipboard);

    gtk_main();

    g_free( text );

    return 0;

}

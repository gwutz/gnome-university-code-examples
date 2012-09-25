
#include <gtk/gtk.h>
#include "sync_window.h"

gint
main( gint argc, gchar *argv[] )
{
    gtk_init( &argc, &argv );

    GuSyncwindow *window = gu_syncwindow_new();

    gtk_widget_show_all(GTK_WIDGET(window));

    gtk_main();

    return 0;
}

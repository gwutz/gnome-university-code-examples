
#include <gtk/gtk.h>
#include "text_window.h"

gint
main( gint argc, gchar *argv[] ) {
    gtk_init(&argc, &argv);

    GuTextwindow *window = gu_textwindow_new();

    gtk_widget_show_all(GTK_WIDGET(window));

    gtk_main();

    return 0;
}

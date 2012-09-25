
#include "sync_window.h"

G_DEFINE_TYPE (GuSyncwindow, gu_syncwindow, GTK_TYPE_WINDOW)

struct _GuSyncwindowPrivate {

};

GuSyncwindow*
gu_syncwindow_new (void)
{
    return g_object_new(GU_TYPE_SYNCWINDOW, NULL);
}

void
spin_value_changed(GtkSpinButton *spinbutton, gpointer user_data) {
    GtkScale *scale = (GtkScale*)user_data;
    gdouble value;
    g_object_get(spinbutton, "value", &value, NULL);
    gtk_range_set_value(GTK_RANGE(scale), value);
}

void
scale_value_changed(GtkScale *scale, gpointer user_data) {
    GtkSpinButton *spin = (GtkSpinButton*)user_data;
    gdouble value = gtk_range_get_value(GTK_RANGE(scale));
    gtk_spin_button_set_value(spin, value);
}

void
gu_syncwindow_init(GuSyncwindow *window) {
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 20);
    gtk_window_set_title(GTK_WINDOW(window), "Enter your Age");
    g_object_set( window, "window-position", GTK_WIN_POS_CENTER, "border-width", 10, NULL );
    g_signal_connect(GTK_WIDGET(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Widgets */
    GtkWidget *spin = gtk_spin_button_new_with_range(0, 130, 1);
    GtkWidget *scale = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 130, 1);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_set_homogeneous(GTK_BOX(box), TRUE);
    gtk_box_pack_start(GTK_BOX(box), spin, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), scale, TRUE, TRUE, 0);
    g_signal_connect(spin, "value-changed", G_CALLBACK(spin_value_changed), scale);
    g_signal_connect(scale, "value-changed", G_CALLBACK(scale_value_changed), spin);

    gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin), 35);

    gtk_container_add(GTK_CONTAINER(window), box);
}

void
gu_syncwindow_class_init(GuSyncwindowClass *klass) {

}

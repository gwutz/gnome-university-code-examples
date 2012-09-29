
#include "text_window.h"

G_DEFINE_TYPE (GuTextwindow, gu_textwindow, GTK_TYPE_WINDOW)

struct _GuTextwindowPrivate {
    GtkTextView* text_view;
};

GuTextwindow*
gu_textwindow_new (void)
{
    return g_object_new(GU_TYPE_TEXTWINDOW, NULL);
}

void
on_open_clicked ( GtkButton* btn, gpointer user_data ) {
    GuTextwindow *window = (GuTextwindow*)user_data;
    GuTextwindowPrivate *priv = window->priv;
    GtkWidget *dialog = gtk_file_chooser_dialog_new(
            "Open File",
            GTK_WINDOW(window),
            GTK_FILE_CHOOSER_ACTION_OPEN,
            GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
            GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
            NULL);

    if ( gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT )
    {
        char *filename;
        filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
        if ( filename ) {
            gchar *content;
            GError *error;
            if ( g_file_get_contents(filename, &content, NULL, &error) ) {
                GtkTextBuffer *buffer = gtk_text_view_get_buffer(priv->text_view);
                gtk_text_buffer_set_text(buffer, content, -1);
                g_free(content);
            } else {
                g_error("%s\n", error->message);
            }
            
            g_free(filename);
        }
        else {

        }
    }
    gtk_widget_destroy(dialog);
}

void
gu_textwindow_init(GuTextwindow *window) {
    window->priv = G_TYPE_INSTANCE_GET_PRIVATE(window, GU_TYPE_TEXTWINDOW, GuTextwindowPrivate);
    GuTextwindowPrivate *priv = window->priv;

    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    gtk_window_set_title(GTK_WINDOW(window), "Text File Viewer");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    g_signal_connect(GTK_WIDGET(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Toolbar */
    GtkWidget* toolbar = gtk_toolbar_new();
    GtkStyleContext* style_context = gtk_widget_get_style_context(toolbar);
    gtk_style_context_add_class(style_context, GTK_STYLE_CLASS_PRIMARY_TOOLBAR);

    GtkToolItem* open_btn = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
    gtk_tool_item_set_is_important(open_btn, TRUE);
    g_signal_connect( GTK_WIDGET(open_btn), "clicked", G_CALLBACK(on_open_clicked), (gpointer)window);
    gtk_container_add(GTK_CONTAINER(toolbar), GTK_WIDGET(open_btn));

    /* TextView */
    priv->text_view = GTK_TEXT_VIEW(gtk_text_view_new());
    gtk_text_view_set_editable(priv->text_view, FALSE);
    gtk_text_view_set_cursor_visible(priv->text_view, FALSE);

    /* ScrollView */
    GtkWidget *scroll = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_container_add(GTK_CONTAINER(scroll), GTK_WIDGET(priv->text_view));

    /* Packing */
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(box), toolbar, FALSE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), scroll, TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(window), box);
    
}

void
gu_textwindow_finalize(GObject *object) {
   GuTextwindowPrivate* priv;
   priv = GU_TEXTWINDOW(object)->priv;
   
   G_OBJECT_CLASS(gu_textwindow_parent_class)->finalize(object);
}

void
gu_textwindow_class_init(GuTextwindowClass *klass) {
    GObjectClass* object_class;
    object_class = G_OBJECT_CLASS(klass);
    object_class->finalize = gu_textwindow_finalize;

    g_type_class_add_private(object_class, sizeof(GuTextwindowPrivate));
}


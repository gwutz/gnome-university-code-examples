#include <glib/gi18n.h>
#include "gucodeviewerappwindow.h"
#include <gtksourceview/gtksource.h>

struct _GuCodeViewerAppWindow
{
  GtkApplicationWindow parent;
};

typedef struct
{
  GtkButton *open_button;
  GtkButton *c_button;
  GtkButton *java_button;
  GtkButton *python_button;
  GtkSourceView *source_view;
  GtkSourceLanguageManager * lm;
} GuCodeViewerAppWindowPrivate;

G_DEFINE_TYPE_WITH_PRIVATE(GuCodeViewerAppWindow, gu_code_viewer_app_window, GTK_TYPE_APPLICATION_WINDOW)

static void
gu_code_viewer_app_window_init (GuCodeViewerAppWindow *win)
{
  gtk_widget_init_template (GTK_WIDGET (win));
}

static void
gu_code_viewer_app_window_class_init (GuCodeViewerAppWindowClass *class)
{
  gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (class),
                                               "/org/gucodeviewerapp/gucodeviewer.ui");
  gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (class), GuCodeViewerAppWindow, open_button);
  gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (class), GuCodeViewerAppWindow, c_button);
  gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (class), GuCodeViewerAppWindow, java_button);
  gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (class), GuCodeViewerAppWindow, python_button);
  gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (class), GuCodeViewerAppWindow, source_view);
}

GuCodeViewerAppWindow *
gu_code_viewer_app_window_new (GuCodeViewerApp *app)
{
  return g_object_new (GU_CODE_VIEWER_APP_WINDOW_TYPE, "application", app, NULL);
}

void
gu_code_viewer_set_lang_highlight (GtkWidget * widget, gpointer user_data)
{
  GtkSourceLanguage * lang;
  GuCodeViewerAppWindowPrivate *priv;

  priv = gu_code_viewer_app_window_get_instance_private (GU_CODE_VIEWER_APP_WINDOW(user_data));
  GtkSourceBuffer *buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW(priv->source_view));

  const gchar * mime_type = gtk_button_get_label (GTK_BUTTON(widget));
  lang = gtk_source_language_manager_get_language (priv->lm, mime_type);

  gtk_source_buffer_set_language (buffer, lang);
}

void
gu_code_viewer_open_file (gpointer user_data)
{
  GtkResponseType response;
  GtkWidget * dialog;
  GtkSourceView *source_view = GTK_SOURCE_VIEW(user_data);
  dialog = gtk_file_chooser_dialog_new ("GU - Code Viewer open file diaog",
                                        gtk_widget_get_toplevel (source_view),
                                        GTK_FILE_CHOOSER_ACTION_OPEN,
                                        _("_Open"), GTK_RESPONSE_ACCEPT, _("_Close"), GTK_RESPONSE_CANCEL,
                                        NULL);

  response = gtk_dialog_run (GTK_DIALOG (dialog));
  if (response == GTK_RESPONSE_ACCEPT)
  {
    const gchar * filename;
    gchar * file_content;
    GError * error = NULL;
    filename = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER(dialog));

    gboolean open = g_file_get_contents (filename, &file_content, NULL, &error);
    if (open == FALSE)
    {
      g_print("[WARNING] Error: %s\n", error->message);
      error = NULL;
    }
    else
    {
      GtkSourceBuffer *buffer = gtk_text_view_get_buffer (source_view);
      gtk_text_buffer_set_text (GTK_TEXT_BUFFER (buffer), file_content, -1);
    }
  }
  gtk_widget_destroy (dialog);
}

void
gu_code_viewer_app_window_open (GuCodeViewerAppWindow *win,
                                GFile                 *file)
{
  GuCodeViewerAppWindowPrivate *priv;
  gchar *basename;
  gchar *contents;
  gsize length;

  priv = gu_code_viewer_app_window_get_instance_private (win);

  priv->lm = gtk_source_language_manager_new ();

  GtkSourceBuffer *buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW(priv->source_view));
  gtk_source_buffer_set_highlight_syntax (buffer, TRUE);

  g_signal_connect_swapped (priv->open_button, "clicked",
                            G_CALLBACK (gu_code_viewer_open_file), priv->source_view);
  g_signal_connect (priv->c_button, "clicked",
                    G_CALLBACK (gu_code_viewer_set_lang_highlight), win);
  g_signal_connect (priv->java_button, "clicked",
                    G_CALLBACK (gu_code_viewer_set_lang_highlight), win);
  g_signal_connect (priv->python_button, "clicked",
                    G_CALLBACK (gu_code_viewer_set_lang_highlight), win);
  g_signal_connect (win, "destroy",
                    G_CALLBACK (gtk_main_quit), NULL);
  basename = g_file_get_basename (file);

  if (g_file_load_contents (file, NULL, &contents, &length, NULL, NULL))
    {
      GtkTextBuffer *buffer;

      buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (priv->source_view));
      gtk_text_buffer_set_text (buffer, contents, length);
      g_free (contents);
    }

  g_free (basename);
}

/*
 * main.c
 *
 * Copyright 2013 userx <userx@AdventChildren>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#include <glib/gi18n.h>
#include <locale.h>
#include <gtk/gtk.h>
#include <gtksourceview/gtksource.h>

void
gu_code_viewer_open_file (gpointer user_data)
{
  GtkResponseType response;
  GtkWidget * dialog;
  GtkSourceView *source_view = GTK_SOURCE_VIEW(user_data);
  dialog = gtk_file_chooser_dialog_new ("GU - Code Viewer open file diaog",
                                        gtk_widget_get_parent_window (source_view),
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
gu_code_viewer_set_lang_highlight (GtkWidget * widget, gpointer user_data)
{
  GtkSourceLanguage * lang;
  GtkSourceLanguageManager * lm;

  const gchar * mime_type = gtk_button_get_label (GTK_BUTTON(widget));
  lm = gtk_source_language_manager_new ();
  lang = gtk_source_language_manager_get_language (GTK_SOURCE_LANGUAGE_MANAGER(lm), mime_type);

  gtk_source_buffer_set_language (GTK_SOURCE_BUFFER (user_data), lang);
}

void startup(GApplication *self, gpointer data) {
  GtkBuilder *builder = g_object_new(GTK_TYPE_BUILDER, NULL);
  gtk_builder_add_from_file(builder, DATADIR "/gucodeviewer.ui", NULL);

  GtkWindow *win = GTK_WINDOW(gtk_builder_get_object(builder, "window"));
  GtkButton *open_button = GTK_BUTTON(gtk_builder_get_object(builder, "open"));
  GtkButton *c_button = GTK_BUTTON(gtk_builder_get_object(builder, "c"));
  GtkButton *java_button = GTK_BUTTON(gtk_builder_get_object(builder, "java"));
  GtkButton *python_button = GTK_BUTTON(gtk_builder_get_object(builder, "python"));
  GtkSourceView *source_view = GTK_SOURCE_VIEW(gtk_builder_get_object(builder, "sourceview"));

  GtkSourceBuffer *buffer = gtk_text_view_get_buffer (source_view);
  gtk_source_buffer_set_highlight_syntax (buffer, TRUE);

  //gtk_text_view_set_buffer (GTK_TEXT_VIEW (priv->view), GTK_TEXT_BUFFER(priv->buffer));

  g_signal_connect_swapped (open_button, "clicked",
                            G_CALLBACK (gu_code_viewer_open_file), source_view);
  g_signal_connect (c_button, "clicked",
                    G_CALLBACK (gu_code_viewer_set_lang_highlight), buffer);
  g_signal_connect (java_button, "clicked",
                    G_CALLBACK (gu_code_viewer_set_lang_highlight), buffer);
  g_signal_connect (python_button, "clicked",
                    G_CALLBACK (gu_code_viewer_set_lang_highlight), buffer);
  g_signal_connect (win, "destroy",
                    G_CALLBACK (gtk_main_quit), NULL);
  gtk_application_add_window(GTK_APPLICATION(self), win);
}

void activate(GApplication *self, gpointer data) {
  GtkWindow *win = gtk_application_get_active_window(GTK_APPLICATION(self));
  gtk_window_present(win);
}

int main(int argc, char **argv)
{
  GtkApplication *app;
  int status;


  setlocale (LC_ALL, "");
  bindtextdomain (GETTEXT_PACKAGE, LOCALEDIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);

  app = gtk_application_new ("org.gucodeviewer", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "startup",  G_CALLBACK(startup),  NULL);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}

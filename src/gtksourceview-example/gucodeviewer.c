/*
 * gucodeviewer.c
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

#include "gucodeviewer.h"

#include <glib/gi18n.h>

/*  I decided to design it with the GtkBox to pack the widgets
 * instead of GtkGrid or something like this, just becouse I wanted
 * to make it simple and easy to understand for anyone and GtkGrid seems
 * to be something more complicated, I don't know...anyway,
 * be confortable to modify it as you want.
 *
 * P.S.: Once again, sorry about my english.
 */

static void gu_code_viewer_finalize (GObject *object);

G_DEFINE_TYPE (GuCodeViewer, gu_code_viewer, GTK_TYPE_WINDOW)

// callbacks ::

void
gu_code_viewer_open_file (GtkWidget * widget,
              gpointer user_data)
{
  GuCodeViewer * cViewer = GU_CODE_VIEWER (user_data);
  GtkResponseType response;
  GtkWidget * dialog;
  dialog = gtk_file_chooser_dialog_new ("GU - Code Viewer open file diaog",
                                        GTK_WINDOW(cViewer),
                                        GTK_FILE_CHOOSER_ACTION_OPEN,
                                        _("_Open"), GTK_RESPONSE_ACCEPT, _("_Close"), GTK_RESPONSE_CANCEL,
                                        NULL);

  response = gtk_dialog_run (GTK_DIALOG (dialog));
  if (response == GTK_RESPONSE_ACCEPT)
  {
    const gchar * filename;
    gchar * file_content;
    GError * error = NULL;
    GuCodeViewerPrivate * priv = cViewer->priv;
    filename = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER(dialog));

    gboolean open = g_file_get_contents (filename, &file_content,
                                         NULL, &error);
    if (open == FALSE)
    {
      g_print("[WARNING] Error: %s\n", error->message);
      error = NULL;
    }
    else
    {
      gtk_text_buffer_set_text (GTK_TEXT_BUFFER (priv->sBuffer), file_content, -1);
    }
  }
  gtk_widget_destroy (dialog);
}

void
gu_code_viewer_set_langhightlight (GtkWidget * widget, gpointer user_data)
{
  GuCodeViewerPrivate * priv = GU_CODE_VIEWER (user_data)->priv;
  const gchar * mime_type = gtk_button_get_label (GTK_BUTTON(widget));
  priv->lang = gtk_source_language_manager_get_language (GTK_SOURCE_LANGUAGE_MANAGER(priv->lm), mime_type);

  gtk_source_buffer_set_language (GTK_SOURCE_BUFFER (priv->sBuffer), priv->lang);
}

static void
gu_code_viewer_class_init (GuCodeViewerClass *klass)
{
  GObjectClass *g_object_class;

  g_object_class = G_OBJECT_CLASS (klass);

  g_object_class->finalize = gu_code_viewer_finalize;

  g_type_class_add_private ((gpointer)klass, sizeof (GuCodeViewerPrivate));
}

static void
gu_code_viewer_finalize (GObject *object)
{
  GuCodeViewer *self;

  g_return_if_fail (GU_IS_CODE_VIEWER (object));

  self = GU_CODE_VIEWER (object);

  G_OBJECT_CLASS (gu_code_viewer_parent_class)->finalize (object);
}

static void
gu_code_viewer_init (GuCodeViewer *self)
{
  GtkWidget * scrolled;
  GtkWidget * langButton;
  GtkWidget * langLabel;

  self->priv = G_TYPE_INSTANCE_GET_PRIVATE (self, GU_TYPE_CODE_VIEWER, GuCodeViewerPrivate);
  GuCodeViewerPrivate * priv = self->priv;

  // box create ::
  priv->vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  priv->hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);

  priv->OpenButton = gtk_button_new_with_mnemonic (_("_Open"));

  priv->cButton = gtk_button_new_with_label ("c");
  priv->javaButton = gtk_button_new_with_label ("java");
  priv->pyButton = gtk_button_new_with_label ("python");

  // window with horizontal and vertical scroll ::
  scrolled = gtk_scrolled_window_new (NULL, NULL);
  // automatic scrolling ::
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled),
                                  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

  priv->sView = gtk_source_view_new ();
  gtk_container_add (GTK_CONTAINER(scrolled), priv->sView);

  priv->lm = gtk_source_language_manager_new ();
  priv->sBuffer = gtk_source_buffer_new (NULL);
  gtk_source_buffer_set_highlight_syntax (GTK_SOURCE_BUFFER(priv->sBuffer), TRUE);

  gtk_text_view_set_buffer (GTK_TEXT_VIEW (priv->sView), GTK_TEXT_BUFFER(priv->sBuffer));

  gtk_container_add (GTK_CONTAINER(self), priv->vbox);
  gtk_box_pack_start (GTK_BOX(priv->vbox), priv->hbox, TRUE, TRUE, 5);

  gtk_box_pack_start (GTK_BOX(priv->vbox), priv->OpenButton, FALSE, FALSE, 5);
  gtk_box_pack_start (GTK_BOX(priv->vbox), priv->cButton, FALSE, FALSE, 5);
  gtk_box_pack_start (GTK_BOX(priv->vbox), priv->javaButton, FALSE, FALSE, 5);
  gtk_box_pack_start (GTK_BOX(priv->vbox), priv->pyButton, FALSE, FALSE, 5);

  gtk_box_pack_start (GTK_BOX(priv->hbox), scrolled, TRUE, TRUE, 0);

  g_signal_connect (priv->OpenButton, "clicked",
                    G_CALLBACK (gu_code_viewer_open_file), self);
  g_signal_connect (priv->cButton, "clicked",
                    G_CALLBACK (gu_code_viewer_set_langhightlight), self);
  g_signal_connect (priv->javaButton, "clicked",
                    G_CALLBACK (gu_code_viewer_set_langhightlight), self);
  g_signal_connect (priv->pyButton, "clicked",
                    G_CALLBACK (gu_code_viewer_set_langhightlight), self);
  g_signal_connect (self, "destroy",
                    G_CALLBACK (gtk_main_quit), NULL);
}

GtkWidget *
gu_code_viewer_new (void)
{
  return g_object_new (GU_TYPE_CODE_VIEWER,
                       "type", GTK_WINDOW_TOPLEVEL,
                       "default-width", 640, "default-height", 480,
                       "window-position", GTK_WIN_POS_CENTER,
                       NULL);
}

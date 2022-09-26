/*
 * gucodeviewer.h
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

#pragma once

#include <gtk/gtk.h>
#include <glib-object.h>
#include <gtksourceview/gtksource.h>

G_BEGIN_DECLS

#define GU_TYPE_CODE_VIEWER             (gu_code_viewer_get_type ())
#define GU_CODE_VIEWER(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), GU_TYPE_CODE_VIEWER, GuCodeViewer))
#define GU_CODE_VIEWER_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), GU_TYPE_CODE_VIEWER, GuCodeViewerClass))
#define GU_IS_CODE_VIEWER(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GU_TYPE_CODE_VIEWER))
#define GU_IS_CODE_VIEWER_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), GU_TYPE_CODE_VIEWER))
#define GU_CODE_VIEWER_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), GU_TYPE_CODE_VIEWER, GuCodeViewerClass))

typedef struct
{
  GtkWidget * vbox;
  GtkWidget * hbox;

  GtkWidget * open_button;

  GtkWidget * c_button;
  GtkWidget * java_button;
  GtkWidget * py_button;

  GtkWidget * view;
  GtkSourceBuffer * buffer;
  GtkSourceLanguage * lang;
  GtkSourceLanguageManager * lm; // language manager ::
} GuCodeViewerPrivate;

typedef struct
{
  GtkWindow parent;
} GuCodeViewer;

typedef struct
{
  GtkWindowClass parent_class;
} GuCodeViewerClass;


GType gu_code_viewer_get_type (void) G_GNUC_CONST;
GtkWidget *gu_code_viewer_new (void);

// callbacks ::
void gu_code_viewer_open_file           (gpointer user_data);
void gu_code_viewer_set_lang_hightlight (GtkWidget * widget,
                                         gpointer user_data);

G_END_DECLS

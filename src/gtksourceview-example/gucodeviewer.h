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


#ifndef GUCODEVIEWER_H_
#define GUCODEVIEWER_H_

#include <gtk/gtk.h>
#include <glib-object.h>

G_BEGIN_DECLS


#define GU_TYPE_CODE_VIEWER             (gu_code_viewer_get_type ())
#define GU_CODE_VIEWER(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), GU_TYPE_CODE_VIEWER, GuCodeViewer))
#define GU_CODE_VIEWER_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), GU_TYPE_CODE_VIEWER, GuCodeViewerClass))
#define GU_IS_CODE_VIEWER(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GU_TYPE_CODE_VIEWER))
#define GU_IS_CODE_VIEWER_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), GU_TYPE_CODE_VIEWER))
#define GU_CODE_VIEWER_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), GU_TYPE_CODE_VIEWER, GuCodeViewerClass))

typedef struct GuCodeViewer_         GuCodeViewer;
typedef struct GuCodeViewerClass_    GuCodeViewerClass;
typedef struct GuCodeViewerPrivate_  GuCodeViewerPrivate;

struct GuCodeViewer_
{
  GtkWindow parent;
  
  
  GuCodeViewerPrivate * priv;
  
};

struct GuCodeViewerClass_
{
  GtkWindowClass parent_class;
};


GType gu_code_viewer_get_type (void) G_GNUC_CONST;
GtkWidget *gu_code_viewer_new (void);

// callbacks ::
void gu_code_viewer_open_file (GtkWidget * widget,
								gpointer user_data);
void gu_code_viewer_set_langhightlight (GtkWidget * widget,
										gpointer user_data);

G_END_DECLS

#endif /* GUCODEVIEWER_H_ */

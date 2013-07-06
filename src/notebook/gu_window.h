/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * notebook
 * Copyright (C) UserX 2013 <userx.gnu@gmail.com>
 * 
notebook is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * notebook is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _GU_WINDOW_H_
#define _GU_WINDOW_H_

#include <glib-object.h>
#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GU_TYPE_WINDOW             (gu_window_get_type ())
#define GU_WINDOW(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), GU_TYPE_WINDOW, GuWindow))
#define GU_WINDOW_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), GU_TYPE_WINDOW, GuWindowClass))
#define GU_IS_WINDOW(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GU_TYPE_WINDOW))
#define GU_IS_WINDOW_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), GU_TYPE_WINDOW))
#define GU_WINDOW_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), GU_TYPE_WINDOW, GuWindowClass))

typedef struct _GuWindowClass GuWindowClass;
typedef struct _GuWindow GuWindow;
typedef struct _GuWindowPrivate GuWindowPrivate;


struct _GuWindowClass
{
	GtkWindowClass parent_class;
};

struct _GuWindow
{
	GtkWindow parent_instance;

    GuWindowPrivate *priv; 
};

GType gu_window_get_type (void) G_GNUC_CONST;
GtkWidget * gu_window_new (void);

G_END_DECLS

#endif /* _GU_WINDOW_H_ */

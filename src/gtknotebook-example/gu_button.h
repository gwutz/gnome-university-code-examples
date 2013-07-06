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

#ifndef _GU_BUTTON_H_
#define _GU_BUTTON_H_

#include <glib-object.h>
#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GU_TYPE_BUTTON             (gu_button_get_type ())
#define GU_BUTTON(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), GU_TYPE_BUTTON, GuButton))
#define GU_BUTTON_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), GU_TYPE_BUTTON, GuButtonClass))
#define GU_IS_BUTTON(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GU_TYPE_BUTTON))
#define GU_IS_BUTTON_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), GU_TYPE_BUTTON))
#define GU_BUTTON_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), GU_TYPE_BUTTON, GuButtonClass))

typedef struct _GuButtonClass GuButtonClass;
typedef struct _GuButton GuButton;



struct _GuButtonClass
{
	GtkButtonClass parent_class;
};

struct _GuButton
{
	GtkButton parent_instance;

	guint position; 
};

GType gu_button_get_type (void) G_GNUC_CONST;
GtkWidget * gu_button_new (void);


// methods ::
void gu_button_set_position (GtkWidget * self, guint pos);
guint gu_button_get_position (GtkWidget * self);
G_END_DECLS

#endif /* _GU_BUTTON_H_ */

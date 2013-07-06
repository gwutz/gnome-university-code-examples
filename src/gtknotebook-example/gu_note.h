/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * notebook
 * Copyright (C) UserX 2013 <userx.gnu@gmail.com>
 * 
 * GuNote is free software: you can redistribute it and/or modify it
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

#ifndef _GU_NOTE_H_
#define _GU_NOTE_H_

#include <glib-object.h>
#include <gtk/gtk.h>
G_BEGIN_DECLS

#define GU_TYPE_NOTE             (gu_note_get_type ())
#define GU_NOTE(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), GU_TYPE_NOTE, GuNote))
#define GU_NOTE_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), GU_TYPE_NOTE, GuNoteClass))
#define GU_IS_NOTE(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GU_TYPE_NOTE))
#define GU_IS_NOTE_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), GU_TYPE_NOTE))
#define GU_NOTE_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), GU_TYPE_NOTE, GuNoteClass))

typedef struct _GuNoteClass GuNoteClass;
typedef struct _GuNote GuNote;
typedef struct _GuNotePrivate GuNotePrivate;


struct _GuNoteClass
{
	GtkNotebookClass parent_class;
};

struct _GuNote
{
	GtkNotebook parent_instance;

    GuNotePrivate *priv; 
};

// constructor methods ::
GType gu_note_get_type (void) G_GNUC_CONST;
GtkWidget * gu_note_new (void);


// callbacks ::
void gu_note_new_tab_callback (GtkWidget * widget, gpointer user_data);
void gu_note_remove_tab_callback (GtkWidget * widget, gpointer user_data);

// methods ::
void gu_note_refresh(GtkWidget * self);
void gu_note_add_tab (GuNote * self);
void gu_note_rm_tab (GtkWidget * self);

G_END_DECLS

#endif /* _GU_NOTE_H_ */

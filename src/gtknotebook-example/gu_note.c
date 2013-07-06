/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * notebook
 * Copyright (C) UserX 2013 <userx.gnu@gmail.com>
 * 
   GuNote is free software: you can redistribute it and/or modify it
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

#include "gu_note.h"
#include "gu_button.h"

// GuNote's private data structure ::
struct _GuNotePrivate
{
	guint page_counter;
	
};


#define GU_NOTE_GET_PRIVATE(obj)  (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GU_TYPE_NOTE, GuNotePrivate))


G_DEFINE_TYPE (GuNote, gu_note, GTK_TYPE_NOTEBOOK);

// constructor ::
static void
gu_note_init (GuNote * self)
{
	// GuNote's private data ::
    GuNotePrivate * priv = GU_NOTE_GET_PRIVATE(self);
	
	priv->page_counter = 1;

	gu_note_add_tab (self);
	gu_note_add_tab (self);
	gu_note_add_tab (self);
	
}

static void
gu_note_finalize (GObject * object)
{
	

	G_OBJECT_CLASS (gu_note_parent_class)->finalize (object);
}

static void
gu_note_class_init (GuNoteClass * klass)
{
	GObjectClass * object_class = G_OBJECT_CLASS (klass);
	GObjectClass * parent_class = G_OBJECT_CLASS (klass);

	g_type_class_add_private (klass, sizeof (GuNotePrivate));

	object_class->finalize = gu_note_finalize;
}


GtkWidget *
gu_note_new (void)
{
	return GTK_WIDGET(g_object_new(GU_TYPE_NOTE, NULL));
}


// Methods ::
void
gu_note_refresh (GtkWidget * self)
{
	g_return_if_fail (GU_IS_NOTE(self));

	gtk_widget_hide (self);
	gtk_widget_show_all (self);
}

void
gu_note_add_tab (GuNote * self)
{
	g_return_if_fail (GU_IS_NOTE (self));
	GuNotePrivate * priv = GU_NOTE_GET_PRIVATE (GU_NOTE(self));
	
	GtkWidget * image;
	GtkWidget * label;
	GtkWidget * close_button;
	GtkWidget * box;

	GtkWidget * _label;

	image = gtk_image_new_from_stock (GTK_STOCK_CLOSE, GTK_ICON_SIZE_MENU);
	close_button = gu_button_new();
	gu_button_set_position (close_button, (priv->page_counter-1));
	gtk_button_set_image (GTK_BUTTON(close_button), image);

	label = gtk_label_new (g_strdup_printf ("Tab %d", priv->page_counter) );
	box = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 10);
	gtk_box_pack_start (GTK_BOX (box), label, FALSE, FALSE, 5);
	gtk_box_pack_start (GTK_BOX (box), close_button, FALSE, FALSE, 5);
	gtk_widget_show_all(box);
	
	_label = gtk_label_new("[!!] A Simple Label [!!]");

	gtk_notebook_insert_page (GTK_NOTEBOOK (self), _label, box, (priv->page_counter-1) );

	gu_note_refresh (GTK_WIDGET(self));

	priv->page_counter++;

	g_signal_connect(close_button, "clicked", G_CALLBACK(gu_note_remove_tab_callback), self);
}


// callbacks ::
void
gu_note_remove_tab_callback (GtkWidget * widget, gpointer user_data)
{
	guint page_num;

	page_num = gu_button_get_position (widget);
	gtk_notebook_remove_page (GTK_NOTEBOOK(user_data), page_num);
}







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

#include "gu_window.h"
#include "gu_note.h"

struct _GuWindowPrivate
{
	GtkWidget * box;
	GtkWidget * note;
};

#define GU_WINDOW_GET_PRIVATE(o)  (G_TYPE_INSTANCE_GET_PRIVATE ((o), GU_TYPE_WINDOW, GuWindowPrivate))



G_DEFINE_TYPE (GuWindow, gu_window, GTK_TYPE_WINDOW);

static void
gu_window_init (GuWindow * self)
{
    GuWindowPrivate * priv = GU_WINDOW_GET_PRIVATE(self);
	gtk_window_set_default_size(GTK_WINDOW(self), 800, 600);
	priv->box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	priv->note = gu_note_new();

	gtk_box_pack_start(GTK_BOX(priv->box), priv->note, TRUE, TRUE, 10);

	gtk_container_add(GTK_CONTAINER(self), priv->box);

	g_signal_connect(self, "destroy", G_CALLBACK(gtk_main_quit), NULL);
}

static void
gu_window_finalize (GObject *object)
{
	/* TODO: Add deinitalization code here */

	G_OBJECT_CLASS (gu_window_parent_class)->finalize (object);
}

static void
gu_window_class_init (GuWindowClass *klass)
{
	GObjectClass* object_class = G_OBJECT_CLASS (klass);
	GtkWindowClass* parent_class = GTK_WINDOW_CLASS (klass);

	g_type_class_add_private (klass, sizeof (GuWindowPrivate));

	object_class->finalize = gu_window_finalize;
}


GtkWidget *
gu_window_new (void)
{
	return GTK_WIDGET (g_object_new(GU_TYPE_WINDOW, NULL) );
}

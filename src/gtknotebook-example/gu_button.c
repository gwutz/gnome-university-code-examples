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

#include "gu_button.h"

enum
{
	PROP_0,

	PROP_POSITION
};

G_DEFINE_TYPE (GuButton, gu_button, GTK_TYPE_BUTTON);

static void
gu_button_init (GuButton * self)
{
	self->position = 0;
}

static void
gu_button_finalize (GObject *object)
{
	/* Deinitalization code here */

	G_OBJECT_CLASS (gu_button_parent_class)->finalize (object);
}

static void
gu_button_set_property (GObject *object, guint prop_id, const GValue *value, GParamSpec *pspec)
{
	g_return_if_fail (GU_IS_BUTTON (object));

	switch (prop_id)
	{
	case PROP_POSITION:
		GU_BUTTON (object)->position = g_value_get_uint (value);
		break;
	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
		break;
	}
}

static void
gu_button_get_property (GObject *object, guint prop_id, GValue *value, GParamSpec *pspec)
{
	g_return_if_fail (GU_IS_BUTTON (object) );

	switch (prop_id)
	{
	case PROP_POSITION:
		g_value_set_uint (value, GU_BUTTON (object)->position);
		break;
	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
		break;
	}
}

static void
gu_button_class_init (GuButtonClass *klass)
{
	GObjectClass* object_class = G_OBJECT_CLASS (klass);
	GtkButtonClass* parent_class = GTK_BUTTON_CLASS (klass);

	object_class->finalize = gu_button_finalize;
	object_class->set_property = gu_button_set_property;
	object_class->get_property = gu_button_get_property;

	g_object_class_install_property (object_class,
	                                 PROP_POSITION,
	                                 g_param_spec_uint ("position",
	                                                    "Position",
	                                                    "Position of the button",
	                                                    0, /* TODO: Adjust minimum property value */
	                                                    G_MAXUINT, /* TODO: Adjust maximum property value */
	                                                    0,
	                                                    G_PARAM_READABLE | G_PARAM_WRITABLE));
}


GtkWidget *
gu_button_new (void)
{
	return GTK_WIDGET(g_object_new (GU_TYPE_BUTTON, "relief", GTK_RELIEF_NONE, NULL) );
}


void
gu_button_set_position (GtkWidget * self, guint pos)
{
	g_return_if_fail (GU_IS_BUTTON (self));

	g_object_set(G_OBJECT (self), "position", pos, NULL);
}

guint
gu_button_get_position (GtkWidget * self)
{
	guint pos;
	g_object_get (G_OBJECT(self), "position", &pos, NULL);

	return pos;
}
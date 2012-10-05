#include "hsr-icalc.h"

static void
hsr_icalc_init (HsrIcalcIface *iface)
{
	static gboolean initialized = FALSE;

	iface->add = hsr_icalc_add;

	if (!initialized)
	{
		initialized = TRUE;
	}
}

gint
hsr_icalc_add (HsrIcalc *self, gint a, gint b)
{
	g_return_val_if_fail (HSR_ICALC (self), NULL);
	return HSR_ICALC_GET_INTERFACE(self)->add(self, a, b);
}

GType
hsr_icalc_get_type ()
{
	static GType hsr_icalc_type_id = 0;

	if (!hsr_icalc_type_id)
	{
		static const GTypeInfo g_define_type_info =
		{
			sizeof (HsrIcalcIface),
			(GBaseInitFunc) hsr_icalc_init,
			NULL,
			NULL,
			NULL,
			NULL,
			0,
			0,
			NULL
		};

		hsr_icalc_type_id =
			g_type_register_static (G_TYPE_INTERFACE,
						"HsrIcalc",
						&g_define_type_info,
						0);
	}

	return hsr_icalc_type_id;
}

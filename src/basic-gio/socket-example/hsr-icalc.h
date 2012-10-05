#ifndef __HSR_ICALC_H__
#define __HSR_ICALC_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define HSR_TYPE_ICALC					(hsr_icalc_get_type ())
#define HSR_ICALC(obj)					(G_TYPE_CHECK_INSTANCE_CAST ((obj), HSR_TYPE_ICALC, HsrIcalc))
#define HSR_IS_ICALC(obj)				(G_TYPE_CHECK_INSTANCE_TYPE ((obj), HSR_TYPE_ICALC))
#define HSR_ICALC_GET_INTERFACE(obj)	(G_TYPE_INSTANCE_GET_INTERFACE ((obj), HSR_TYPE_ICALC, HsrIcalcIface))

typedef struct _HsrIcalc		HsrIcalc;
typedef struct _HsrIcalcIface	HsrIcalcIface;

struct _HsrIcalcIface
{
	GTypeInterface parent;

	gint (*add) (HsrIcalc *self, gint a, gint b);
};

GType hsr_icalc_get_type (void) G_GNUC_CONST;

gint hsr_icalc_add (HsrIcalc *self, gint a, gint b);

G_END_DECLS

#endif /* __HSR_ICALC_H__ */

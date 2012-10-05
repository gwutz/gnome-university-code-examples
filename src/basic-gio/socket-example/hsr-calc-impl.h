#ifndef __HSR_CALC_IMPL_H__
#define __HSR_CALC_IMPL_H__

#include <glib-object.h>
#include "hsr-icalc.h"

G_BEGIN_DECLS

#define HSR_TYPE_CALC_IMPL				(hsr_calc_impl_get_type ())
#define HSR_CALC_IMPL(obj)				(G_TYPE_CHECK_INSTANCE_CAST ((obj), HSR_TYPE_CALC_IMPL, HsrCalcImpl))
#define HSR_CALC_IMPL_CONST(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), HSR_TYPE_CALC_IMPL, HsrCalcImpl const))
#define HSR_CALC_IMPL_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST ((klass), HSR_TYPE_CALC_IMPL, HsrCalcImplClass))
#define HSR_IS_CALC_IMPL(obj)			(G_TYPE_CHECK_INSTANCE_TYPE ((obj), HSR_TYPE_CALC_IMPL))
#define HSR_IS_CALC_IMPL_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), HSR_TYPE_CALC_IMPL))
#define HSR_CALC_IMPL_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), HSR_TYPE_CALC_IMPL, HsrCalcImplClass))

typedef struct _HsrCalcImpl			HsrCalcImpl;
typedef struct _HsrCalcImplClass	HsrCalcImplClass;

struct _HsrCalcImpl
{
	GObject parent;
};

struct _HsrCalcImplClass
{
	GObjectClass parent_class;
};

GType hsr_calc_impl_get_type (void) G_GNUC_CONST;
HsrCalcImpl *hsr_calc_impl_new (void);


G_END_DECLS

#endif /* __HSR_CALC_IMPL_H__ */

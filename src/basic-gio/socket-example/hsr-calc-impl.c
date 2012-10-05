#include "hsr-calc-impl.h"

gint
hsr_calc_impl_add_real (HsrIcalc *self, gint a, gint b)
{
	return a + b;
}

void
hsr_calc_impl_init_interface (HsrIcalcIface *iface)
{
	iface->add = hsr_calc_impl_add_real;
}

G_DEFINE_TYPE_WITH_CODE (HsrCalcImpl,
                         hsr_calc_impl,
                         G_TYPE_OBJECT,
                         G_IMPLEMENT_INTERFACE(HSR_TYPE_ICALC, hsr_calc_impl_init_interface))

static void
hsr_calc_impl_finalize (GObject *object)
{
	G_OBJECT_CLASS (hsr_calc_impl_parent_class)->finalize (object);
}

static void
hsr_calc_impl_class_init (HsrCalcImplClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);

	object_class->finalize = hsr_calc_impl_finalize;
}

static void
hsr_calc_impl_init (HsrCalcImpl *self)
{

}

HsrCalcImpl *
hsr_calc_impl_new ()
{
	return g_object_new (HSR_TYPE_CALC_IMPL, NULL);
}

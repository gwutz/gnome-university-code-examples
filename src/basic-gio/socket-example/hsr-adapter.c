#include "hsr-adapter.h"

G_DEFINE_TYPE (HsrAdapter, hsr_adapter, G_TYPE_OBJECT)

static void
hsr_adapter_finalize (GObject *object)
{
	G_OBJECT_CLASS (hsr_adapter_parent_class)->finalize (object);
}

static void
hsr_adapter_class_init (HsrAdapterClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);

	object_class->finalize = hsr_adapter_finalize;
}

static void
hsr_adapter_init (HsrAdapter *self)
{
}

HsrAdapter *
hsr_adapter_new ()
{
	return g_object_new (HSR_TYPE_ADAPTER, NULL);
}

void hsr_adapter_handle_request (HsrAdapter *self,
                                 GDataInputStream *gis,
                                 GDataOutputStream *gos)
{
	GError *err = NULL;
	gint16 ergebnis;
	HsrIcalc *server;
	
	server = hsr_calc_impl_new();
	gint32 a = g_data_input_stream_read_int32(gis, NULL, &err);
	if ( err != NULL ) {
		g_error("%s\n", err->message);
		return;
	}
	
	gint32 b = g_data_input_stream_read_int32(gis, NULL, &err);
	if ( err != NULL ) {
		g_error("%s\n", err->message);
		return;
	}
	
	ergebnis = hsr_icalc_add(server, a, b);
	
	g_print("a: %d\nb: %d\nergebnis: %d\n", a, b, ergebnis);
	
	g_data_output_stream_put_int32(gos, ergebnis, NULL, &err);
	if ( err != NULL) {
		g_error("%s\n", err->message);
		return;
	}
}

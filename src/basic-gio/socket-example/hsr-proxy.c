#include "hsr-proxy.h"
#include "hsr-icalc.h"

#define HSR_PROXY_GET_PRIVATE(object)(G_TYPE_INSTANCE_GET_PRIVATE((object), HSR_TYPE_PROXY, HsrProxyPrivate))

struct _HsrProxyPrivate
{
	//for testing purposes
	gint tmp;
};

gint
hsr_proxy_add_real (HsrIcalc *self, gint a, gint b)
{
	GSocketClient *client;
	GSocketConnection *connection = NULL;
	GError *err = NULL;
	
	client = g_socket_client_new();
	connection = g_socket_client_connect_to_host (client,
	                                              (gchar*)"localhost",
	                                              6789,
	                                              NULL,
	                                              &err);
	if ( err != NULL ) {
		g_error("Something went wrong! %s\n", err->message);
		return -1;
	}
	
	GDataInputStream *gis = g_data_input_stream_new(g_io_stream_get_input_stream(G_IO_STREAM(connection)));
    GDataOutputStream *gos = g_data_output_stream_new(g_io_stream_get_output_stream(G_IO_STREAM(connection)));
    
    g_data_output_stream_put_int32(gos, a, NULL, &err);
    if ( err != NULL ) {
    	g_error ( "%s\n", err->message );
    	return 0;
    }
    
    g_data_output_stream_put_int32(gos, b, NULL, &err);
    if ( err != NULL ) {
    	g_error ( "%s\n", err->message );
    	return 0;
    }

    gint32 ergebnis = g_data_input_stream_read_int32(gis, NULL, &err);
    if ( err != NULL ) {
    	g_error ( "%s\n", err->message );
    	return 0;
    }
    return ergebnis;
}

void
hsr_proxy_init_interface(HsrIcalcIface *self) 
{	
	self->add = (gint (*)(HsrIcalc*,gint,gint))hsr_proxy_add_real;
}

G_DEFINE_TYPE_WITH_CODE (HsrProxy,
                         hsr_proxy,
                         G_TYPE_OBJECT,
                         G_IMPLEMENT_INTERFACE( HSR_TYPE_ICALC, hsr_proxy_init_interface))

static void
hsr_proxy_finalize (GObject *object)
{
	G_OBJECT_CLASS (hsr_proxy_parent_class)->finalize (object);
}

static void
hsr_proxy_class_init (HsrProxyClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);

	object_class->finalize = hsr_proxy_finalize;

	g_type_class_add_private (object_class, sizeof (HsrProxyPrivate));
}

static void
hsr_proxy_init (HsrProxy *self)
{
	self->priv = HSR_PROXY_GET_PRIVATE (self);
}

HsrProxy *
hsr_proxy_new ()
{
	return g_object_new (HSR_TYPE_PROXY, NULL);
}

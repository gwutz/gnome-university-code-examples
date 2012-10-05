
#include <glib-object.h>
#include <gio/gio.h>
#include "hsr-adapter.h"

gboolean
connection_established(GSocketService *service,
                       GSocketConnection *connection,
                       GObject *source_object,
                       gpointer user_data) {
    g_print("Connection established\n");
	HsrAdapter *adapter = hsr_adapter_new();
    
    GDataInputStream *gis = g_data_input_stream_new(g_io_stream_get_input_stream(G_IO_STREAM(connection)));
    GDataOutputStream *gos = g_data_output_stream_new(g_io_stream_get_output_stream(G_IO_STREAM(connection)));
    
    hsr_adapter_handle_request(adapter, gis, gos);
    
    return TRUE;
}

int
main (int argc, char *argv[])
{
    GError *error = NULL;
	GSocketService *service;

	g_type_init();
	
	service = g_socket_service_new();
    /* Listening Details */
    g_socket_listener_add_inet_port(G_SOCKET_LISTENER(service),
                                    6789,
                                    NULL,
                                    &error);
    if ( error != NULL ) {
        g_error("%s", error->message);
    }
    
    g_signal_connect (service,
                      "incoming",
                      G_CALLBACK(connection_established),
                      NULL);

    g_socket_service_start(service);
    
    GMainLoop* loop = g_main_loop_new(NULL, FALSE);
    g_main_loop_run(loop);	
	return 0;
}

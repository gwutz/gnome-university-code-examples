
#include <glib-object.h>
#include "hsr-proxy.h"
#include "hsr-icalc.h"
#include <stdlib.h>


int
main (int argc, char *argv[])
{
	g_type_init();
	
	if ( argc < 3 ) {
		g_print("Usage: %s a b\n", argv[0]);
		return 0;
	}
	
	gint32 a = atoi(argv[1]);
	gint32 b = atoi(argv[2]);
	
	HsrIcalc *calc = HSR_ICALC(hsr_proxy_new());
	gint32 ret = hsr_icalc_add(calc, a, b);
	g_print("%d\n", ret);
	
	return 0;
}

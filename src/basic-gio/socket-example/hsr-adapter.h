#ifndef __HSR_ADAPTER_H__
#define __HSR_ADAPTER_H__

#include <glib-object.h>
#include <gio/gio.h>
#include "hsr-calc-impl.h"

G_BEGIN_DECLS

#define HSR_TYPE_ADAPTER			(hsr_adapter_get_type ())
#define HSR_ADAPTER(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), HSR_TYPE_ADAPTER, HsrAdapter))
#define HSR_ADAPTER_CONST(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), HSR_TYPE_ADAPTER, HsrAdapter const))
#define HSR_ADAPTER_CLASS(klass)	(G_TYPE_CHECK_CLASS_CAST ((klass), HSR_TYPE_ADAPTER, HsrAdapterClass))
#define HSR_IS_ADAPTER(obj)			(G_TYPE_CHECK_INSTANCE_TYPE ((obj), HSR_TYPE_ADAPTER))
#define HSR_IS_ADAPTER_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), HSR_TYPE_ADAPTER))
#define HSR_ADAPTER_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), HSR_TYPE_ADAPTER, HsrAdapterClass))

typedef struct _HsrAdapter			HsrAdapter;
typedef struct _HsrAdapterClass		HsrAdapterClass;

struct _HsrAdapter
{
	GObject parent;

};

struct _HsrAdapterClass
{
	GObjectClass parent_class;
};

GType hsr_adapter_get_type (void) G_GNUC_CONST;
HsrAdapter *hsr_adapter_new (void);
void hsr_adapter_handle_request(HsrAdapter *self, GDataInputStream *gis, GDataOutputStream *gos);

G_END_DECLS

#endif /* __HSR_ADAPTER_H__ */

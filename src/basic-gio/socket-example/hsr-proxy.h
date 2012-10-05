#ifndef __HSR_PROXY_H__
#define __HSR_PROXY_H__

#include <glib-object.h>
#include <gio/gio.h>


G_BEGIN_DECLS

#define HSR_TYPE_PROXY				(hsr_proxy_get_type ())
#define HSR_PROXY(obj)				(G_TYPE_CHECK_INSTANCE_CAST ((obj), HSR_TYPE_PROXY, HsrProxy))
#define HSR_PROXY_CONST(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), HSR_TYPE_PROXY, HsrProxy const))
#define HSR_PROXY_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST ((klass), HSR_TYPE_PROXY, HsrProxyClass))
#define HSR_IS_PROXY(obj)			(G_TYPE_CHECK_INSTANCE_TYPE ((obj), HSR_TYPE_PROXY))
#define HSR_IS_PROXY_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), HSR_TYPE_PROXY))
#define HSR_PROXY_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), HSR_TYPE_PROXY, HsrProxyClass))

typedef struct _HsrProxy		HsrProxy;
typedef struct _HsrProxyClass	HsrProxyClass;
typedef struct _HsrProxyPrivate	HsrProxyPrivate;

struct _HsrProxy
{
	GObject parent;

	HsrProxyPrivate *priv;
};

struct _HsrProxyClass
{
	GObjectClass parent_class;
};

GType hsr_proxy_get_type (void) G_GNUC_CONST;
HsrProxy *hsr_proxy_new (void);


G_END_DECLS

#endif /* __HSR_PROXY_H__ */

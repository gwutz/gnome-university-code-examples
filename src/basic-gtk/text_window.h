
#ifndef TEXT_WINDOW_H
#define TEXT_WINDOW_H

#include <glib-object.h>
#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GU_TYPE_TEXTWINDOW (gu_textwindow_get_type())
#define GU_TEXTWINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST ( (obj), GU_TYPE_TEXTWINDOW, GuTextwindow))
#define GU_TEXTWINDOW_CONST(obj) (G_TYPE_CHECK_INSTANCE_CAST ( (obj), GU_TYPE_TEXTWINDOW, GuTextwindow const))
#define GU_TEXTWINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ( (klass), GU_TYPE_TEXTWINDOW, GuTextwindowClass ))
#define GU_IS_TEXTWINDOW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ( (obj), GU_TYPE_TEXTWINDOW ))
#define GU_IS_TEXTWINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ( (klass), GU_TYPE_TEXTWINDOW ))
#define GU_TEXTWINDOW_GET_CLASS (obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GU_TYPE_TEXTWINDOW, GuTextwindowClass))

typedef struct _GuTextwindow GuTextwindow;
typedef struct _GuTextwindowClass GuTextwindowClass;
typedef struct _GuTextwindowPrivate GuTextwindowPrivate;

struct _GuTextwindow {
    GtkWindow parent;

    GuTextwindowPrivate *priv;
};

struct _GuTextwindowClass {
    GtkWindowClass parent_class;


};

GuTextwindow *gu_textwindow_new(void);
GType gu_textwindow_get_type() G_GNUC_CONST;


G_END_DECLS

#endif /* TEXT_WINDOW_H */



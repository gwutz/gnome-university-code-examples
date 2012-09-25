#ifndef SYNC_WINDOW_H
#define SYNC_WINDOW_H

#include <glib-object.h>
#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GU_TYPE_SYNCWINDOW (gu_syncwindow_get_type())
#define GU_SYNCWINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST ( (obj), GU_TYPE_SYNCWINDOW, GuSyncwindow))
#define GU_SYNCWINDOW_CONST(obj) (G_TYPE_CHECK_INSTANCE_CAST ( (obj), GU_TYPE_SYNCWINDOW, GuSyncwindow const))
#define GU_SYNCWINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ( (klass), GU_TYPE_SYNCWINDOW, GuSyncwindowClass ))
#define GU_IS_SYNCWINDOW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ( (obj), GU_TYPE_SYNCWINDOW ))
#define GU_IS_SYNCWINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ( (klass), GU_TYPE_SYNCWINDOW ))
#define GU_SYNCWINDOW_GET_CLASS (obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GU_TYPE_SYNCWINDOW, GuSyncwindowClass))

typedef struct _GuSyncwindow GuSyncwindow;
typedef struct _GuSyncwindowClass GuSyncwindowClass;
typedef struct _GuSyncwindowPrivate GuSyncwindowPrivate;

struct _GuSyncwindow {
    GtkWindow parent;


};

struct _GuSyncwindowClass {
    GtkWindowClass parent_class;


};

GuSyncwindow *gu_syncwindow_new(void);
GType gu_syncwindow_get_type() G_GNUC_CONST;


G_END_DECLS

#endif /* SYNC_WINDOW_H */



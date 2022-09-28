#include "gucodeviewerapp.h"
#include "gucodeviewerappwindow.h"

struct _GuCodeViewerApp
{
  GtkApplication parent;
};

G_DEFINE_TYPE(GuCodeViewerApp, gu_code_viewer_app, GTK_TYPE_APPLICATION)

static void
gu_code_viewer_app_init (GuCodeViewerApp *app)
{
}

static void
gu_code_viewer_app_activate (GApplication *app)
{
  GuCodeViewerAppWindow *win;

  win = gu_code_viewer_app_window_new (GU_CODE_VIEWER_APP (app));
  gtk_window_present (GTK_WINDOW (win));
}

static void
gu_code_viewer_app_open (GApplication  *app,
                         GFile        **files,
                         int            n_files,
                         const char    *hint)
{
  GList *windows;
  GuCodeViewerAppWindow *win;
  int i;

  windows = gtk_application_get_windows (GTK_APPLICATION (app));
  if (windows)
    win = GU_CODE_VIEWER_APP_WINDOW (windows->data);
  else
    win = gu_code_viewer_app_window_new (GU_CODE_VIEWER_APP (app));

  for (i = 0; i < n_files; i++)
    gu_code_viewer_app_window_open (win, files[i]);

  gtk_window_present (GTK_WINDOW (win));
}

static void
gu_code_viewer_app_class_init (GuCodeViewerAppClass *class)
{
  G_APPLICATION_CLASS (class)->activate = gu_code_viewer_app_activate;
  G_APPLICATION_CLASS (class)->open = gu_code_viewer_app_open;
}

GuCodeViewerApp *
gu_code_viewer_app_new (void)
{
  return g_object_new (GU_CODE_VIEWER_APP_TYPE,
                       "application-id", "org.gucodeviewer",
                       "flags", G_APPLICATION_HANDLES_OPEN,
                       NULL);
}

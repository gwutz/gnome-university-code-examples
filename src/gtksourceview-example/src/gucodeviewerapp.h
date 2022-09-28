#pragma once

#include <gtk/gtk.h>

#define GU_CODE_VIEWER_APP_TYPE (gu_code_viewer_app_get_type ())
G_DECLARE_FINAL_TYPE (GuCodeViewerApp, gu_code_viewer_app, GU_CODE_VIEWER, APP, GtkApplication)

GuCodeViewerApp *gu_code_viewer_app_new (void);

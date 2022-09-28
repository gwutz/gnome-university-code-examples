#pragma once

#include "gucodeviewerapp.h"

#define GU_CODE_VIEWER_APP_WINDOW_TYPE (gu_code_viewer_app_window_get_type ())
G_DECLARE_FINAL_TYPE (GuCodeViewerAppWindow, gu_code_viewer_app_window, GU_CODE_VIEWER, APP_WINDOW, GtkApplicationWindow)

GuCodeViewerAppWindow *gu_code_viewer_app_window_new  (GuCodeViewerApp *app);
void                   gu_code_viewer_app_window_open (GuCodeViewerAppWindow *win,
                                                       GFile                 *file);

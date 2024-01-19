#ifndef POPUP_MENU_H
#define POPUP_MENU_H

#include <gtk/gtk.h>

void show_popup_menu(GtkStatusIcon *status_icon);
void hide_popup_menu(void);
void destroy_popup_menu(void);
gboolean is_popup_menu_visible(void);

#endif

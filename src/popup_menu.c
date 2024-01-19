#include <gtk/gtk.h>
#include <string.h>

#include "popup_menu.h"
#include "menu.h"

static void on_selection_done(GtkMenu *menu_widget, gpointer data)
{
}

static void on_item_activate(GtkMenuItem *item, gpointer data)
{
    gchar *mi_name = (gchar *)data;
    menu_item *mi_found = NULL;
    menu *m = shared_menu();

    g_print("%s was clicked!\n", mi_name);

    for (GSList *entry = m->items; entry; entry = g_slist_next(entry)) {
        menu_item *mi = (menu_item *)entry->data;
        if (!strcmp(mi->name, mi_name)) {
            mi_found = mi;
        }
    }

    if (mi_found->active)
        return;

    for (GSList *entry = m->items; entry; entry = g_slist_next(entry)) {
        menu_item *mi = (menu_item *)entry->data;
        mi->active = FALSE;
    }

    mi_found->active = TRUE;
}

void show_popup_menu(GtkStatusIcon *status_icon)
{
    menu *m = shared_menu();
    if (!m->items)
        return;

    GtkWidget *menu_widget = gtk_menu_new();
    g_signal_connect(G_OBJECT(menu_widget), "selection-done", G_CALLBACK(on_selection_done), NULL);

    for (GSList *entry = m->items; entry; entry = g_slist_next(entry)) {
        menu_item *mi          = (menu_item *)entry->data;
        GtkWidget *item_widget = gtk_check_menu_item_new_with_label(mi->description);

        gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(item_widget), mi->active);
        gtk_menu_shell_append(GTK_MENU_SHELL(menu_widget), item_widget);

        g_signal_connect(G_OBJECT(item_widget), "activate", G_CALLBACK(on_item_activate), mi->name);
    }

    gtk_widget_show_all(menu_widget);
    gtk_menu_popup(GTK_MENU(menu_widget), NULL, NULL, gtk_status_icon_position_menu,
                   status_icon, 0, gtk_get_current_event_time());
}

void hide_popup_menu(void)
{
}

void destroy_popup_menu(void)
{
}

gboolean is_popup_menu_visible(void)
{
    return FALSE;
}

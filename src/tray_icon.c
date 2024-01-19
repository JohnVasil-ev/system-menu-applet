#include <gtk/gtk.h>
#include <glib.h>

#include "tray_icon.h"
#include "popup_menu.h"

static GtkStatusIcon *tray_icon = NULL;

static void on_activate(GtkStatusIcon *status_icon, gpointer data)
{
    if (is_popup_menu_visible()) {
        hide_popup_menu();
    }
}

static void on_popup_menu(GtkStatusIcon *status_icon, gpointer data)
{
    if (!is_popup_menu_visible()) {
        show_popup_menu(tray_icon);
    }
}

static gboolean on_button_release(GtkStatusIcon *status_icon, GdkEventButton *event, gpointer data)
{
    if (event->button != 2)
        return FALSE;

    return TRUE;
}

void init_tray_icon(void)
{
    gchar *icon_name = "open-menu-symbolic";
    tray_icon = gtk_status_icon_new_from_icon_name(icon_name);

    gchar *icon_tooltip = "Test tooltip text";
    gtk_status_icon_set_tooltip_text(tray_icon, icon_tooltip);

    g_signal_connect(G_OBJECT(tray_icon), "activate", G_CALLBACK(on_activate), NULL);
    g_signal_connect(G_OBJECT(tray_icon), "popup-menu", G_CALLBACK(on_popup_menu), NULL);
    g_signal_connect(G_OBJECT(tray_icon), "button-press-event", G_CALLBACK(on_button_release), NULL);
}

void destroy_tray_icon(void)
{
    if (tray_icon) {
        gtk_widget_destroy(GTK_WIDGET(tray_icon));
        tray_icon = NULL;
    }
    destroy_popup_menu();
}

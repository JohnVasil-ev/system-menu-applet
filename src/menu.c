#include "menu.h"

menu menu_shared;

menu *shared_menu(void)
{
    return &menu_shared;
}

void init_menu(void)
{
    reset_menu_items();
    menu *m = shared_menu();

    for (int i = 0; i < 3; ++i) {
        menu_item *mi = g_malloc(sizeof(menu_item));

        gchar *number = g_strdup_printf("%d", i);
        gchar *mi_name = g_strconcat(g_strdup("Item "), number, NULL);
        gchar *mi_desc = g_strconcat(g_strdup("Desc "), number, NULL);

        mi->name = mi_name;
        mi->description = mi_desc;
        mi->index = i;
        mi->active = FALSE;
        m->items = g_slist_append(m->items, mi);
    }
    sort_menu_items();
}

void destroy_menu(void)
{
    reset_menu_items();
}

static void destroy_item(gpointer *data)
{
    menu_item *mi = (menu_item *)data;
    g_free(mi->name);
    g_free(mi->description);
    g_free(mi);
}

void reset_menu_items(void)
{
    if (menu_shared.items) {
        g_slist_free_full(menu_shared.items, (GDestroyNotify)destroy_item);
        menu_shared.items = NULL;
    }
}

static gint compare_item_func(gconstpointer a, gconstpointer b)
{
    menu_item *mi_a = (menu_item *)a;
    menu_item *mi_b = (menu_item *)b;
    if (mi_a->index > mi_b->index)
        return 1;
    else if (mi_b->index > mi_a->index)
        return -1;
    else
        return 0;
}

void sort_menu_items(void)
{
    if (menu_shared.items)
        menu_shared.items = g_slist_sort(menu_shared.items, compare_item_func);
}

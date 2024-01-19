#ifndef MENU_H
#define MENU_H

#include <glib.h>

typedef struct {
    GSList *items;
} menu;

typedef struct {
    int index;
    gchar *name;
    gchar *description;
    gboolean active;
} menu_item;

menu *shared_menu(void);

void init_menu(void);
void destroy_menu(void);

void reset_menu_items(void);
void sort_menu_items(void);

#endif

#include <gtk/gtk.h>

#include "tray_icon.h"
#include "menu.h"

int main(int argc, char *argv[]) {
    // Initialize GTK
    gtk_init(&argc, &argv);

    // Initialize program components
    init_tray_icon();
    init_menu();

    gtk_main();

    destroy_menu();
    destroy_tray_icon();

    return EXIT_SUCCESS;
}


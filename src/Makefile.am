bin_PROGRAMS = menu-applet

# Main bin options
menu_applet_SOURCES = \
    main.c \
    menu.c \
    menu.h \
    popup_menu.c \
    popup_menu.h \
    tray_icon.c \
    tray_icon.h

menu_applet_CPPFLAGS = \
    -std=c99 -D_GNU_SOURCE -Wall -Werror -Wno-error=deprecated-declarations \
    $(GLIB_CFLAGS) \
    $(GTK3_CFLAGS) \
    $(XLIB_CFLAGS)

menu_applet_LDADD = \
    $(GLIB_LIBS) \
    $(GTK3_LIBS) \
    $(XLIB_LIBS)

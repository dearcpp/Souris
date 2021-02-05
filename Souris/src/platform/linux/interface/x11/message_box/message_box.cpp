#include "message_box.hpp"

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <stdexcept>
#include <cstring>

SOURIS_PLATFORM_BEGIN_NAMESPACE

void MessageBox(const char *title, const char *message) {
    Display *display = XOpenDisplay(0);

    if (display == 0) {
       throw std::runtime_error("X11 display not found");
       return;
    }

    int screen = DefaultScreen(display);

    Window window = XCreateSimpleWindow(
        display,
        RootWindow(display, screen),
        0, 0, 800, 100, 1,
        BlackPixel(display, screen),
        WhitePixel(display, screen)
    );

    XSelectInput(display, window, ExposureMask | PointerMotionMask | ButtonPressMask | ButtonReleaseMask);
    XMapWindow(display, window);

    XStoreName(display, window, title);

    Atom WM_DELETE_WINDOW = XInternAtom(display, "WM_DELETE_WINDOW", true);
    XSetWMProtocols(display, window, &WM_DELETE_WINDOW, 1);

    XUnmapWindow(display, window);

    XSizeHints hints;

    hints.flags      = PSize | PMinSize | PMaxSize;
    hints.min_width  = hints.max_width  = hints.base_width  = 400;
    hints.min_height = hints.max_height = hints.base_height = 200;

    XSetWMNormalHints(display, window, &hints);
    XMapRaised(display, window);
    XFlush(display);

    XEvent event;

    while (1) {
        XNextEvent(display, &event);
        switch (event.type) {
            case ClientMessage: {
                char *atom = XGetAtomName(display, event.xclient.message_type);
                if(static_cast<Atom>(event.xclient.data.l[0]) == WM_DELETE_WINDOW) {
                    XFree(atom);
                    goto exit;
                }
                XFree(atom);
                break;
            }
        }
    }

exit:
    XDestroyWindow(display, window);
    XCloseDisplay(display);
}

SOURIS_PLATFORM_END_NAMESPACE

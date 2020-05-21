#ifndef T_H
#define T_H


#include <X11/Xlib.h>
#include <X11/Xft/Xft.h>
#include <limits.h>

#include "common.h"
#include "terminal.h"
#include "pty.h"


typedef struct{
    Display* display;
    int screen;
    Visual* visual;
    Colormap colormap;
    Window window;

    XColor background_color;

    XftDraw* xft_draw;
    XftFont* xft_font;

    Terminal* terminal;

    Pty* pty;

    int x;
    int y;
    unsigned int width;
    unsigned int height;
}XTerminal;

static XTerminal xterminal;


int main();

// -----------------------------------------------------------------------
// configuration
// -----------------------------------------------------------------------
char shell[] = "/bin/sh";
unsigned int cols = 80;
unsigned int rows = 24;

// -----------------------------------------------------------------------
// colors
// -----------------------------------------------------------------------
char background_color[] = "#000000";

// -----------------------------------------------------------------------
// keys
// -----------------------------------------------------------------------
typedef struct{
    KeySym keysym;
    unsigned int mod;
    char* string;
} Key;

#define XK_ANY_MOD (UINT_MAX)

static Key terminal_keys[] = {
	{ XK_KP_Enter,      XK_ANY_MOD,     "\r" }
};

#endif
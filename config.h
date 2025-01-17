/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 4; /* border pixel of windows */
static const unsigned int gappx = 20;   /* gaps between windows */
static const unsigned int snap = 32;    /* snap pixel */
static const unsigned int systraypinning =
    0; /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor
          X */
static const unsigned int systrayspacing = 2; /* systray spacing */
static const int systraypinningfailfirst =
    1; /* 1: if pinning fails, display systray on the first monitor, False:
          display systray on the last monitor*/
static const int showsystray = 1;    /* 0 means no systray */
static const int showbar = 1;        /* 0 means no bar */
static const int topbar = 0;         /* 0 means bottom bar */
static const Bool viewontag = False; /* Switch view on tag switch */
static const char *fonts[] = {"ComicShannsMono:size=12"};
static const char dmenufont[] = "monospace:size=14";
static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;

static const char col_gray1[] = "#282a36";
static const char col_gray2[] = "#282a36";
static const char col_gray3[] = "#96b5b4";
static const char col_gray4[] = "#d7d7d7";
static const char col_cyan[] = "#282a36";
static const char col_black[] = "#000000";
static const char col_white[] = "#ffffff";
static const char col_red[] = "#ff5370";
static const char col_darkred[] = "#db1616";
static const char col_yellow[] = "#ffee75";
static const char col_green[] = "#c3e88d";
static const char col_orange[] = "#f07178";
static const char col_purple[] = "#c792ea";
static const char col_pink[] = "#FD9CAC";
static const char col_blue[] = "#89ddff";

static const char *colors[][3] = {
    /*          fg         bg          border   */
    [SchemeNorm] = {col_gray3, col_gray1, col_gray2},
    [SchemeSel] = {col_red, col_cyan, col_darkred},
    [SchemeRed] = {col_red, col_gray1, col_gray2},
    [SchemeYellow] = {col_yellow, col_gray1, col_gray2},
    [SchemeOrange] = {col_orange, col_gray1, col_gray2},
    [SchemeGreen] = {col_green, col_gray1, col_gray2},
    [SchemePurple] = {col_purple, col_gray1, col_gray2},
    [SchemePink] = {col_pink, col_gray1, col_gray2},
    [Schemeblue] = {col_blue, col_gray1, col_gray2},
    [SchemeDarkRed] = {col_darkred, col_gray1, col_gray2},
};
// #include "/home/sampath/.cache/wal/colors-wal-dwm.h"

// static const char *colors[][3]      = {
//	/*               fg         bg         border   */
//	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
//	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
// };
static const unsigned int alphas[][3] = {
    /*               fg      bg        border     */
    [SchemeNorm] = {OPAQUE, baralpha, borderalpha},

    [SchemeSel] = {OPAQUE, baralpha, borderalpha},
};

/* tagging */
static const char *tags[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
/* static const char *tags[] = { "I", "II", "III", "IV", "V", "VI", "VII",
 * "VIII", "IX" }; */
/* static const char *tags[] = { "", "", "", "", "", "",
 * "", "", "" }; */
/* static const char *tags[] = { "Web", "Chat", "Edit", "Meld", "Vb", "Mail",
 * "Video", "Image", "Files" }; */

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     *  use tags mask to point an application to a specific workspace
     */
    /* class                   instance    title      tags      mask  isfloating
       monitor */
    {"TelegramDesktop", NULL, NULL, 1 << 6, 0, 1},
    {"discord", NULL, NULL, 1 << 6, 0, 1},
    {"Signal", NULL, NULL, 1 << 5, 0, 1},
    {"St", NULL, NULL, 2, 0, 1},
    {"Brave-browser", NULL, NULL, 1, 0, 1},
    {"1Password", NULL, NULL, 1 << 2, 0, 1},
    {"Emacs", NULL, NULL, 1 << 3, 0, 1},
};

/* layout(s) */
static const float mfact = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints =
    1; /* 1 means respect size hints in tiled resizals */

#include "layouts.c"

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {"HHH", grid}, {"[M]", monocle},
    {"><>", NULL}, /* no layout function means floating behavior */
    {NULL, NULL},
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

/* commands */
static char dmenumon[2] =
    "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
    "dmenu_run", "-m",      dmenumon, "-fn",    dmenufont, "-nb",     col_gray1,
    "-nf",       col_gray3, "-sb",    col_cyan, "-sf",     col_gray4, NULL};
static const char *filecmd[] = {"thunar", NULL};
static const char *calendar[] = {"gsimplecal", NULL};
static const char *taskmanager[] = {"xfce4-taskmanager", NULL};

#include "selfrestart.c"
#include "shiftview.c"

static Key keys[] = {
    /* modifier                     key        function        argument */
    {MODKEY, XK_p, spawn, {.v = dmenucmd}},
    {MODKEY | ShiftMask, XK_Return, spawn, {.v = filecmd}},
    {MODKEY, XK_b, togglebar, {0}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY, XK_Right, focusstack, {.i = +1}},
    {MODKEY, XK_Left, focusstack, {.i = -1}},
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    /*{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },*/
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY, XK_minus, setgaps, {.i = -1}},
    {MODKEY, XK_equal, setgaps, {.i = +1}},
    {MODKEY | ShiftMask, XK_equal, setgaps, {.i = 0}},
    /*{ MODKEY,                       XK_Return, zoom,           {0} },*/
    /*{ MODKEY,                       XK_Tab,    view,           {0} },*/
    {MODKEY | ShiftMask, XK_q, killclient, {0}},
    {MODKEY, XK_q, killclient, {0}},
    {MODKEY, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY, XK_g, setlayout, {.v = &layouts[1]}},
    {MODKEY, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_f, setlayout, {.v = &layouts[2]}},
    {MODKEY | ControlMask, XK_comma, cyclelayout, {.i = -1}},
    {MODKEY | ControlMask, XK_period, cyclelayout, {.i = +1}},
    {MODKEY, XK_space, cyclelayout, {.i = +1}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_Left, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_Right, tagmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_r, self_restart, {0}},
    {Mod1Mask | ControlMask, XK_Right, shiftview, {.i = 1}},
    {Mod1Mask | ControlMask, XK_Left, shiftview, {.i = -1}},
    {Mod1Mask | ControlMask, XK_Up, shiftview, {.i = 1}},
    {Mod1Mask | ControlMask, XK_Down, shiftview, {.i = -1}},
    {Mod1Mask, XK_Tab, shiftview, {.i = 1}},
    {Mod1Mask | ShiftMask, XK_Tab, shiftview, {.i = -1}},
    {MODKEY, XK_Tab, shiftview, {.i = 1}},
    {MODKEY | ShiftMask, XK_Tab, shiftview, {.i = -1}},

    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8)};

/* IF YOU HAVE A AZERTY KEYBOARD USE THESE CODES
        TAGKEYS(                        XK_ampersand,              0)
        TAGKEYS(                        XK_eacute,                 1)
        TAGKEYS(                        XK_quotedbl,               2)
        TAGKEYS(                        XK_apostrophe,             3)
        TAGKEYS(                        XK_parenleft,              4)
        TAGKEYS(                        XK_section,                5)
        TAGKEYS(                        XK_egrave,                 6)
        TAGKEYS(                        XK_exclam,                 7)
        TAGKEYS(                        XK_ccedilla,               8)
*/

/* THESE ARE THE ORIGINAL QWERTY KEYBOARD CODES
        TAGKEYS(                        XK_1,                      0)
        TAGKEYS(                        XK_2,                      1)
        TAGKEYS(                        XK_3,                      2)
        TAGKEYS(                        XK_4,                      3)
        TAGKEYS(                        XK_5,                      4)
        TAGKEYS(                        XK_6,                      5)
        TAGKEYS(                        XK_7,                      6)
        TAGKEYS(                        XK_8,                      7)
        TAGKEYS(                        XK_9,                      8)
*/

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button1, spawn, {.v = taskmanager}},
    {ClkStatusText, 0, Button2, spawn, {.v = filecmd}},
    {ClkStatusText, 0, Button3, spawn, {.v = calendar}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};

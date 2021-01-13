/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int usealtbar          = 1;        /* 1 means use non-dwm status bar */
static const char *altbarclass      = "Polybar"; /* Alternate bar class name */
static const char *alttrayname      = "tray";    /* Polybar tray instance name */
static const char *altbarcmd        = "autostart.sh"; /* Alternate bar launch command */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  "#8D0C0C" },
};

/* tagging */
static const char *tags[] = { "甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class            instance     title              tags mask switchtotag isfloating  monitor */
    { "2048-qt",        NULL,        NULL,              0,        0,          1,          -1 },
	{ "Audacity",       NULL,        NULL,              1 << 5,   1,          0,          -1 },
	{ "ClickRepair",    NULL,        NULL,              0,        0,          1,          -1 },
	{ "copyq",          NULL,        NULL,              0,        0,          1,          -1 },
	{ "dvdvob2mpg.exe", NULL,        NULL,              0,        0,          1,          -1 },
    { "firefox",        "Places",    NULL,              0,        0,          1,          -1 },
    { "firefox",        "Navigator", NULL,              0,        0,          1,          -1 },
    { "firefox",        "Navigator", "Mozilla Firefox", 0,        0,          0,          -1 },
	{ "Ghb",            NULL,        NULL,              1 << 5,   1,          1,          -1 },  // handbrake
	{ "Gimp",           NULL,        NULL,              1 << 8,   1,          0,          -1 },
	{ "lazarus",        NULL,        NULL,              1 << 5,   1,          1,          -1 },
	{ "mpdcontrol",     NULL,        NULL,              0,        0,          1,          -1 },
	{ "mpv",            NULL,        NULL,              0,        0,          1,          -1 },
	{ "sudoku-Main",    NULL,        NULL,              0,        0,          1,          -1 },
	{ "XnViewMP",       NULL,        NULL,              0,        0,          1,          -1 },
	{ "XTerm",          NULL,        "newsboat",        1 << 3,   0,          0,          -1 },
	{ "XTerm",          NULL,        "nzbget",          1 << 4,   0,          0,          -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
    { NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* commands */
static const char *termcmd[]  = { "kitty", NULL };
// static const char *stcmd[]  = { "st", NULL };
// static const char *xtermcmd[]  = { "launch-xterm.sh", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "xterm", "-title", scratchpadname, "-geometry", "90x34", NULL };
// static const char *roficmd[]  = { "rofi", "-show", "drun", "-theme", "arthur", NULL };
// static const char *poweroffcmd[]  = { "poweroff", NULL };
// static const char *rebootcmd[]  = { "reboot", NULL };
// static const char *trashemptycmd[] = { "zsh", "-c", "trash-empty", NULL };
// static const char *dismountall[] = { "zsh", "-c", "unu", NULL };
// static const char *controlaltdelete[] = { "xterm", "-e", "htop", NULL };
// static const char *conkiescmd[] = { "conkies.sh", NULL };
// static const char *polybarcmd[] = { "/home/kj/.config/polybar/launch.sh", NULL };
// static const char *bashmountcmd[] = { "xterm", "-e", "bashmount", NULL };
// static const char *statsresetattached[] = { "stats-reset.sh", "attached", NULL };
// static const char *statsresetshare[] = { "stats-reset.sh", "share", NULL };
// static const char *statsreset[] = { "stats-reset.sh", NULL };
// static const char *rec64cmd[] = { "rec64", NULL };
// static const char *recordingscmd[] = { "recordings.sh", NULL };
// static const char *thunderbirdcmd[] = { "thunderbird", NULL };
// static const char *emailcmd[] = { "thunderbird", "-compose", NULL };
// static const char *firefoxcmd[] = { "firefox", NULL };
// static const char *gimpcmd[] = { "gimp", NULL };
// static const char *keepassxccmd[] = { "keepassxc", NULL };
// static const char *mpdcontrolcmd[] = { "mpdcontrol", NULL };
// static const char *freememcmd[] = { "freemem.sh", NULL };
// static const char *newsboatcmd[] = { "launch-newsboat.sh", NULL };
// static const char *vimbcmd[] = { "vimb", NULL };
// static const char *playvccmd[] = { "playv.sh", "C", NULL };
// static const char *playvxcmd[] = { "playv.sh", "X", NULL };
// static const char *favscmd[] = { "favs.sh", NULL };
// static const char *nzbgetcmd[] = { "zsh", "-c", "launch-nzbget", NULL };
// static const char *lowermaster[] = { "amixer", "set", "Master", "5%-", "unmute", NULL };
// static const char *raisemaster[] = { "amixer", "set", "Master", "3%+", "unmute", NULL };
// static const char *lowerpcm[] = { "amixer", "-c", "1", "set", "PCM", "5%-", "unmute", NULL };
// static const char *raisepcm[] = { "amixer", "-c", "1", "set", "PCM", "3%+", "unmute", NULL };
// static const char *screenshotcmd[] = { "sh", "-c", "import /tmp/0/screenshot-$(date '+%H%M%S').png", NULL };

#include <X11/XF86keysym.h>
#include "selfrestart.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	// { 0,                            XK_Menu,   spawn,          {.v = roficmd } },
	// { MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	// { MODKEY,                       XK_z,      spawn,          {.v = stcmd } },
	// { MODKEY|Mod1Mask,              XK_z,      spawn,          {.v = xtermcmd } },
	{ ControlMask,                  XK_grave,  togglescratch,  {.v = scratchpadcmd } },

    // launchers
    // { MODKEY,                       XK_Delete, spawn,          {.v = trashemptycmd } },
    // { MODKEY,                       XK_End,    spawn,          {.v = dismountall } },
    // { ControlMask|Mod1Mask,         XK_Delete, spawn,          {.v = controlaltdelete } },
    // { MODKEY,                       XK_F1,     spawn,          {.v = conkiescmd } },
    // { MODKEY,                       XK_F2,     spawn,          {.v = polybarcmd } },
    // { Mod3Mask,                     XK_Tab,    spawn,          {.v = bashmountcmd} },
    // { Mod3Mask,                     XK_F1,     spawn,          {.v = statsresetattached } },
    // { Mod3Mask,                     XK_F2,     spawn,          {.v = statsresetshare } },
    // { Mod3Mask,                     XK_F3,     spawn,          {.v = statsreset } },
    // { Mod3Mask,                     XK_r,      spawn,          {.v = rec64cmd } },
    // { Mod3Mask|ShiftMask,           XK_r,      spawn,          {.v = recordingscmd } },
    // { Mod3Mask,                     XK_f,      spawn,          {.v = firefoxcmd } },
    // { Mod3Mask,                     XK_t,      spawn,          {.v = thunderbirdcmd } },
    // { Mod3Mask|ShiftMask,           XK_t,      spawn,          {.v = emailcmd } },
    // { Mod3Mask,                     XK_g,      spawn,          {.v = gimpcmd } },
    // { Mod3Mask,                     XK_k,      spawn,          {.v = keepassxccmd } },
    // { Mod3Mask,                     XK_m,      spawn,          {.v = mpdcontrolcmd } },
    // { ControlMask|Mod1Mask,         XK_m,      spawn,          {.v = freememcmd } },
    // { Mod3Mask,                     XK_n,      spawn,          {.v = newsboatcmd } },
    // { Mod3Mask,                     XK_v,      spawn,          {.v = vimbcmd } },
    // { Mod3Mask,                     XK_x,      spawn,          {.v = favscmd } },
    // { Mod3Mask|Mod1Mask,            XK_x,      spawn,          {.v = playvccmd } },
    // { Mod3Mask|ControlMask,         XK_x,      spawn,          {.v = playvxcmd } },
    // { Mod3Mask,                     XK_z,      spawn,          {.v = nzbgetcmd } },
    // { 0,                            XK_Print,  spawn,          {.v = screenshotcmd } },

    // dwm
    { MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_o,      rotatestack,    {.i = +1 } },
	{ MODKEY,                       XK_e,      focusstack,     {.i = -1 } },
	// { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	// { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_n,      setmfact,       {.f = -0.01} },
	{ MODKEY,                       XK_i,      setmfact,       {.f = +0.01} },
	{ MODKEY,                       XK_space,  zoom,           {0} },
	{ Mod1Mask,                     XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_f,      togglefloating, {0} },
	{ MODKEY,                       XK_0,      setlayout,      {0} },
	{ MODKEY|ControlMask,           XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_Tab,    cyclelayout,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Tab,    setlayout,      {.v = &layouts[0]} },
	{ MODKEY|Mod1Mask,              XK_Tab,    setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ControlMask,           XK_Tab,    setlayout,      {.v = &layouts[2]} },

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
    // { ControlMask|Mod1Mask,         XK_x,      spawn,          {.v = poweroffcmd } },
    // { ControlMask|Mod1Mask,         XK_r,      spawn,          {.v = rebootcmd } },
    { ControlMask|Mod1Mask,         XK_q,      quit,           {0} },
    { MODKEY|ShiftMask,             XK_r,      self_restart,   {0} },

    // moveresize
	{ MODKEY,                       XK_Down,   moveresize,     {.v = "0x 25y 0w 0h" } },
	{ MODKEY,                       XK_Up,     moveresize,     {.v = "0x -25y 0w 0h" } },
	{ MODKEY,                       XK_Right,  moveresize,     {.v = "25x 0y 0w 0h" } },
	{ MODKEY,                       XK_Left,   moveresize,     {.v = "-25x 0y 0w 0h" } },
	{ MODKEY|ShiftMask,             XK_Down,   moveresize,     {.v = "0x 0y 0w 25h" } },
	{ MODKEY|ShiftMask,             XK_Up,     moveresize,     {.v = "0x 0y 0w -25h" } },
	{ MODKEY|ShiftMask,             XK_Right,  moveresize,     {.v = "0x 0y 25w 0h" } },
	{ MODKEY|ShiftMask,             XK_Left,   moveresize,     {.v = "0x 0y -25w 0h" } },
	{ MODKEY|ControlMask,           XK_Up,     moveresizeedge, {.v = "t"} },
	{ MODKEY|ControlMask,           XK_Down,   moveresizeedge, {.v = "b"} },
	{ MODKEY|ControlMask,           XK_Left,   moveresizeedge, {.v = "l"} },
	{ MODKEY|ControlMask,           XK_Right,  moveresizeedge, {.v = "r"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Up,     moveresizeedge, {.v = "T"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Down,   moveresizeedge, {.v = "B"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Left,   moveresizeedge, {.v = "L"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Right,  moveresizeedge, {.v = "R"} },

    // multimedia

    // { 0,            XF86XK_AudioLowerVolume,   spawn,          {.v = lowermaster } },
    // { 0,            XF86XK_AudioRaiseVolume,   spawn,          {.v = raisemaster } },
    // { MODKEY,       XK_KP_Subtract,            spawn,          {.v = lowermaster } },
    // { MODKEY,       XK_KP_Add,                 spawn,          {.v = raisemaster } },
    // { MODKEY,       XK_KP_Divide,              spawn,          {.v = lowerpcm } },
    // { MODKEY,       XK_KP_Multiply,            spawn,          {.v = raisepcm } },

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
  IPCCOMMAND(  view,                1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggleview,          1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tag,                 1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggletag,           1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tagmon,              1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  focusmon,            1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  focusstack,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  zoom,                1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  incnmaster,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  killclient,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  togglefloating,      1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  setmfact,            1,      {ARG_TYPE_FLOAT}  ),
  IPCCOMMAND(  setlayoutsafe,       1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  quit,                1,      {ARG_TYPE_NONE}   )
};


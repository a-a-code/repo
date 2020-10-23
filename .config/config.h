/* appearance */
static const unsigned int borderpx  = 0;
static const unsigned int snap      = 32;
static const int showbar            = 0;
static const int topbar             = 0;
static const char *fonts[]          = { "LibrationMono:size=10" };
static const char dmenufont[]       = "LibrationMono:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	{ "NULL",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55;
static const int nmaster     = 1;
static const int resizehints = 1;

static const Layout layouts[] = {
	{ "[]=",      tile },
	{ "><>",      NULL },
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ 0,        KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY,   KEY,      tag,            {.ui = 1 << TAG} }, \

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[]  = { "st", NULL };
#define XF86AudioLowerVolume    0x1008ff11
#define XF86AudioMute           0x1008ff12
#define XF86AudioRaiseVolume    0x1008ff13
static Key keys[] = {
	{ MODKEY,                       XK_Return,                  spawn,          {.v = termcmd } },
    { MODKEY,                       XK_space,                   spawn,          SHCMD("vimb") },
	{ MODKEY,                       XK_Tab,                     view,           {0} },
    { MODKEY,                       XK_j,                       focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,                       focusstack,     {.i = -1 } },
    { 0,                            XF86AudioMute,              spawn,          SHCMD("amixer set Master toggle") },
    { 0,                            XF86AudioRaiseVolume,       spawn,          SHCMD("amixer set Master 5%+") },
    { 0,                            XF86AudioLowerVolume,       spawn,          SHCMD("amixer set Master 5%-") },
	TAGKEYS(                        XK_F1,                                      0)
	TAGKEYS(                        XK_F2,                                      1)
	TAGKEYS(                        XK_F3,                                      2)
	TAGKEYS(                        XK_F4,                                      3)
	TAGKEYS(                        XK_F5,                                      4)
	TAGKEYS(                        XK_F6,                                      5)
	TAGKEYS(                        XK_F7,                                      6)
	TAGKEYS(                        XK_F8,                                      7)
	TAGKEYS(                        XK_F9,                                      8)
	{ MODKEY|ShiftMask,             XK_q,                       quit,           {0} },
};

/* button definitions */
static Button buttons[] = {
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


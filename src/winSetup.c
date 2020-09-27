#include <stdlib.h>
#include <ncurses.h>
#include "../libs/wincfg.h"

Wincfg_t *winSetup() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    Wincfg_t *wincfg = malloc(sizeof(Wincfg_t));
    MainWincfg_t *mainWincfg = malloc(sizeof(MainWincfg_t));
    CmdWincfg_t *cmdWincfg = malloc(sizeof(CmdWincfg_t));
    wincfg->mainWincfg = mainWincfg;
    wincfg->cmdWincfg = cmdWincfg;
    getmaxyx(stdscr, wincfg->h, wincfg->w);
    wincfg->mainWincfg->y = 0;
    wincfg->mainWincfg->x = 0;
    wincfg->mainWincfg->h = (wincfg->h/4)*3;
    wincfg->mainWincfg->w = wincfg->w;
    wincfg->cmdWincfg->y = wincfg->mainWincfg->h;
    wincfg->cmdWincfg->x = 0;
    wincfg->cmdWincfg->h = wincfg->h-wincfg->mainWincfg->h;
    wincfg->cmdWincfg->w = wincfg->w;
    wincfg->mainWincfg->mainWin = newwin(wincfg->mainWincfg->h, wincfg->mainWincfg->w, wincfg->mainWincfg->y, wincfg->mainWincfg->x);
    wincfg->cmdWincfg->cmdWin = newwin(wincfg->cmdWincfg->h, wincfg->cmdWincfg->w, wincfg->cmdWincfg->y, wincfg->cmdWincfg->x);

    box(wincfg->mainWincfg->mainWin, 0, 0);
    box(wincfg->cmdWincfg->cmdWin, 0, 0);
    mvwprintw(wincfg->mainWincfg->mainWin, 0, 0, "DIR");
    mvwprintw(wincfg->cmdWincfg->cmdWin, 0, 0, "Shell");
    refresh();
    wrefresh(wincfg->mainWincfg->mainWin);
    wrefresh(wincfg->cmdWincfg->cmdWin);

    return wincfg;
}
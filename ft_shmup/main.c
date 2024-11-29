int specialShotCounter = 0;
int currentScore = 0;
int NUM_ENEMIES = 0;

#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#include "ft_shmup.h"


int main(void) {
    srand(time(NULL));
    initscr();
    raw();
    curs_set(0);
    timeout(10);
    noecho();
    cbreak();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    if (xMax == 0 || yMax == 0) {
        endwin();
        exit(1);
    }

    WINDOW *win = newwin((yMax - 10), (xMax - 10), 5, 5);
    start_color();
    assume_default_colors(COLOR_RED, COLOR_BLACK);
    wborder(win, '{', '}', '*', '*', '#', '#', '#', '#');
    refresh();
	int choice = start_display(win, yMax, xMax);
	check_level(win, xMax, yMax, choice);
    wrefresh(win);
	
    endwin();

    WINDOW *playwin = newwin((yMax - 10), (xMax - 10), 5, 5);
	WINDOW *scorewin = newwin((yMax / 18), xMax - 10 , yMax - 5, 5);
    start_color();
    assume_default_colors(COLOR_RED, COLOR_BLACK);
	wborder(scorewin, '{', '}', '*', '*', '#', '#', '#', '#');
	wrefresh(scorewin);
	
    struct Player p = newplayer(xMax/2 - 2, yMax - 15, xMax, yMax, '@', playwin, 1);
    display(&p);
    wrefresh(playwin);
	nodelay(playwin, TRUE);
    Player enemies[NUM_ENEMIES];
    clock_t lastEnemyShotTimes[NUM_ENEMIES];
	time_t startSpecialShotTimes[NUM_ENEMIES];

    for (int i = 0; i < NUM_ENEMIES; i++) {
        enemies[i] = newplayer(rand() % xMax, rand() % (yMax / 3), xMax, yMax, 'Y', playwin, 1);
        lastEnemyShotTimes[i] = clock();
        display(&enemies[i]);
    }
	int seconds = 0;
	int minutes = 0;
	initTimer();
	init_score(scorewin, yMax, xMax);
	int life = 4;
	startSpecialShotForEnemies(NUM_ENEMIES, startSpecialShotTimes);
    while (1) 
	{
        clear();
		for (int i = 0; i < NUM_ENEMIES; i++) 
		{
			if (enemies[i].alive == 1) {
            	moveEnemy(&enemies[i], xMax, playwin);
          		enemyShootRandomly(&enemies[i], &lastEnemyShotTimes[i], &startSpecialShotTimes[i]);
			
				displayEnemy(&enemies[i], playwin);
			}
			if (rand() % 50 < 1) 
				asteroid(xMax, yMax, playwin);
        	int ch = wgetch(playwin);
			if (ch != ERR)
				if (ch == 'x')
					break; 
			getmv(&p, xMax, yMax, ch, playwin, &enemies[i]);
		}
		life = updateBullets(playwin, yMax, xMax, life, scorewin, p);
		if (life == 0)
		{
			wclear(playwin);
			wrefresh(playwin);
			mvwprintw(win, yMax/2, xMax/2 - (int)strlen("You loose....")/2, "%s", "You loose....");
			wrefresh(playwin);
			napms(1500);
			break;
		}
        napms(16);
		updateBullets(playwin, yMax, xMax, life, scorewin, p);
		updateGameTimer(&seconds, &minutes, scorewin, yMax, xMax);
        display(&p);
        wrefresh(playwin);
    	
	}
    getch();
    endwin();

    return 0;
}


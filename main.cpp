/***********************************************************************
 * Program: Hunt the Wumpus
 * Author: Carson Secrest
 * Description: This program is an adventure game where the player
 *              navigates through a cave system to hunt down the Wumpus.
 *              The player can move to adjacent rooms, shoot arrows to kill
 *              the Wumpus, and avoid hazards such as stalactites and bats.
 * 			    The player wins if they either kill the Wumpus or brind the
 * 				gold to the exit, and loses if they get killed.
 * Input: user input for movement, shooting arrows, entering debug mode,
 *			   and replaying/exiting the game
 * Output: game messages and prompts displayed to the screen
***********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include "game.h"

using namespace std;

void instructions_1() {
	initscr();
	cbreak();
	noecho();

	WINDOW *window = newwin(47, 170, 3, 6);
	box(window, 0, 0);
	refresh();
	mvwprintw(window, 7, 70, "Welcome to Hunt the Wumpus!");
	mvwprintw(window, 10, 30, "Hunt the Wumpus is a game where you navigate through a cave system to hunt down the Wumpus.");
	mvwprintw(window, 11, 30, "The player can move to adjacent rooms, shoot arrows to kill the Wumpus, and avoid hazards such as stalactites and bats.");
	mvwprintw(window, 12, 30, "The player wins if they either kill the Wumpus or bring the gold to the exit, and loses if they get killed.");

	mvwprintw(window, 18, 31, "The controls are:");
	WINDOW *cell = derwin(window, 7, 30, 20, 30);
	mvwprintw(cell, 1, 2, "W -> move up");
	mvwprintw(cell, 2, 2, "A -> move left");
	mvwprintw(cell, 3, 2, "S -> move down");
	mvwprintw(cell, 4, 2, "D -> move right");
	mvwprintw(cell, 5, 2, "F -> shoot arrow");
	mvwprintw(window, 28, 30, "Upon choosing to fire an arrow, you must");
	mvwprintw(window, 29, 30, "then select the direction you want to fire it in.");

	mvwprintw(window, 18, 90, "When you are adjacent to an event, you will be notified");
	mvwprintw(window, 19, 90, "with percepts that look like this:");
	WINDOW *cell2 = derwin(window, 3, 50, 20, 90);
	mvwprintw(cell2, 1, 2, "You smell a terrible stench.");
	mvwprintw(window, 28, 90, "And when you encounter an event, you will be notified");
	mvwprintw(window, 29, 90, "with encounter messages that look like this:");
	WINDOW *cell3 = derwin(window, 3, 50, 30, 90);
	mvwprintw(cell3, 1, 2, "You have encountered the Wumpus!");

	box(cell, 0, 0);
	box(cell2, 0, 0);
	box(cell3, 0, 0);


	mvwprintw(window, 40, 70, "Press any key to continue...");
	wrefresh(window);
	move(0,0);
	getch();
	delwin(window);
	refresh();
	clear();
	refresh();
}

int main()
{
	initscr();
	cbreak();
	noecho();

	// display title
	WINDOW *start_win = newwin(47, 170, 3, 6);
	box(start_win, 0, 0);
	refresh();
	int title_margin = 1;
	mvwprintw(start_win, 1, title_margin, "HHHHHHHHH     HHHHHHHHHUUUUUUUU     UUUUUUUUNNNNNNNN        NNNNNNNNTTTTTTTTTTTTTTTTTTTTTTT         TTTTTTTTTTTTTTTTTTTTTTTHHHHHHHHH     HHHHHHHHHEEEEEEEEEEEEEEEEEEEEEE");
	mvwprintw(start_win, 2, title_margin, "H:::::::H     H:::::::HU::::::U     U::::::UN:::::::N       N::::::NT:::::::::::::::::::::T         T:::::::::::::::::::::TH:::::::H     H:::::::HE::::::::::::::::::::E");
	mvwprintw(start_win, 3, title_margin, "H:::::::H     H:::::::HU::::::U     U::::::UN::::::::N      N::::::NT:::::::::::::::::::::T         T:::::::::::::::::::::TH:::::::H     H:::::::HE::::::::::::::::::::E");
	mvwprintw(start_win, 4, title_margin, "HH::::::H     H::::::HHUU:::::U     U:::::UUN:::::::::N     N::::::NT:::::TT:::::::TT:::::T         T:::::TT:::::::TT:::::THH::::::H     H::::::HHEE::::::EEEEEEEEE::::E");
	mvwprintw(start_win, 5, title_margin, "  H:::::H     H:::::H   U:::::U     U:::::U N::::::::::N    N::::::NTTTTTT  T:::::T  TTTTTT         TTTTTT  T:::::T  TTTTTT  H:::::H     H:::::H    E:::::E       EEEEEE");
	mvwprintw(start_win, 6, title_margin, "  H:::::H     H:::::H   U:::::D     D:::::U N:::::::::::N   N::::::N        T:::::T                         T:::::T          H:::::H     H:::::H    E:::::E             ");
	mvwprintw(start_win, 7, title_margin, "  H::::::HHHHH::::::H   U:::::D     D:::::U N:::::::N::::N  N::::::N        T:::::T                         T:::::T          H::::::HHHHH::::::H    E::::::EEEEEEEEEE   ");
	mvwprintw(start_win, 8, title_margin, "  H:::::::::::::::::H   U:::::D     D:::::U N::::::N N::::N N::::::N        T:::::T                         T:::::T          H:::::::::::::::::H    E:::::::::::::::E   ");
	mvwprintw(start_win, 9, title_margin, "  H:::::::::::::::::H   U:::::D     D:::::U N::::::N  N::::N:::::::N        T:::::T                         T:::::T          H:::::::::::::::::H    E:::::::::::::::E   ");
	mvwprintw(start_win, 10, title_margin, "  H::::::HHHHH::::::H   U:::::D     D:::::U N::::::N   N:::::::::::N        T:::::T                         T:::::T          H::::::HHHHH::::::H    E::::::EEEEEEEEEE   ");
	mvwprintw(start_win, 11, title_margin, "  H:::::H     H:::::H   U:::::D     D:::::U N::::::N    N::::::::::N        T:::::T                         T:::::T          H:::::H     H:::::H    E:::::E             ");
	mvwprintw(start_win, 12, title_margin, "  H:::::H     H:::::H   U::::::U   U::::::U N::::::N     N:::::::::N        T:::::T                         T:::::T          H:::::H     H:::::H    E:::::E       EEEEEE");
	mvwprintw(start_win, 13, title_margin, "HH::::::H     H::::::HH U:::::::UUU:::::::U N::::::N      N::::::::N      TT:::::::TT                     TT:::::::TT      HH::::::H     H::::::HHEE::::::EEEEEEEE:::::E");
	mvwprintw(start_win, 14, title_margin, "H:::::::H     H:::::::H  UU:::::::::::::UU  N::::::N       N:::::::N      T:::::::::T                     T:::::::::T      H:::::::H     H:::::::HE::::::::::::::::::::E");
	mvwprintw(start_win, 15, title_margin, "H:::::::H     H:::::::H    UU:::::::::UU    N::::::N        N::::::N      T:::::::::T                     T:::::::::T      H:::::::H     H:::::::HE::::::::::::::::::::E");
	mvwprintw(start_win, 16, title_margin, "HHHHHHHHH     HHHHHHHHH      UUUUUUUUU      NNNNNNNN         NNNNNNN      TTTTTTTTTTT                     TTTTTTTTTTT      HHHHHHHHH     HHHHHHHHHEEEEEEEEEEEEEEEEEEEEEE");
	title_margin = 5;
	mvwprintw(start_win, 20, title_margin, "WWWWWWWW                           WWWWWWWWUUUUUUUU     UUUUUUUUMMMMMMMM               MMMMMMMMPPPPPPPPPPPPPPPPP   UUUUUUUU     UUUUUUUU   SSSSSSSSSSSSSSS ");
	mvwprintw(start_win, 21, title_margin, "W::::::W                           W::::::WU::::::U     U::::::UM:::::::M             M:::::::MP::::::::::::::::P  U::::::U     U::::::U SS:::::::::::::::S");
	mvwprintw(start_win, 22, title_margin, "W::::::W                           W::::::WU::::::U     U::::::UM::::::::M           M::::::::MP::::::PPPPPP:::::P U::::::U     U::::::US:::::SSSSSS::::::S");
	mvwprintw(start_win, 23, title_margin, "W::::::W                           W::::::WUU:::::U     U:::::UUM:::::::::M         M:::::::::MPP:::::P     P:::::PUU:::::U     U:::::UUS:::::S     SSSSSSS");
	mvwprintw(start_win, 24, title_margin, " W:::::W           WWWWW           W:::::W  U:::::U     U:::::U M::::::::::M       M::::::::::M  P::::P     P:::::P U:::::U     U:::::U S:::::S            ");
	mvwprintw(start_win, 25, title_margin, "  W:::::W         W:::::W         W:::::W   U:::::D     D:::::U M:::::::::::M     M:::::::::::M  P::::P     P:::::P U:::::D     D:::::U S:::::S            ");
	mvwprintw(start_win, 26, title_margin, "   W:::::W       W:::::::W       W:::::W    U:::::D     D:::::U M:::::::M::::M   M::::M:::::::M  P::::PPPPPP:::::P  U:::::D     D:::::U  S::::SSSS         ");
	mvwprintw(start_win, 27, title_margin, "    W:::::W     W:::::::::W     W:::::W     U:::::D     D:::::U M::::::M M::::M M::::M M::::::M  P:::::::::::::PP   U:::::D     D:::::U   SS::::::SSSSS    ");
	mvwprintw(start_win, 28, title_margin, "     W:::::W   W:::::W:::::W   W:::::W      U:::::D     D:::::U M::::::M  M::::M::::M  M::::::M  P::::PPPPPPPPP     U:::::D     D:::::U     SSS::::::::SS  ");
	mvwprintw(start_win, 29, title_margin, "      W:::::W W:::::W W:::::W W:::::W       U:::::D     D:::::U M::::::M   M:::::::M   M::::::M  P::::P             U:::::D     D:::::U        SSSSSS::::S ");
	mvwprintw(start_win, 30, title_margin, "       W:::::W:::::W   W:::::W:::::W        U:::::D     D:::::U M::::::M    M:::::M    M::::::M  P::::P             U:::::D     D:::::U             S:::::S");
	mvwprintw(start_win, 31, title_margin, "        W:::::::::W     W:::::::::W         U::::::U   U::::::U M::::::M     MMMMM     M::::::M  P::::P             U::::::U   U::::::U             S:::::S");
	mvwprintw(start_win, 32, title_margin, "         W:::::::W       W:::::::W          U:::::::UUU:::::::U M::::::M               M::::::MPP::::::PP           U:::::::UUU:::::::U SSSSSSS     S:::::S");
	mvwprintw(start_win, 33, title_margin, "          W:::::W         W:::::W            UU:::::::::::::UU  M::::::M               M::::::MP::::::::P            UU:::::::::::::UU  S::::::SSSSSS:::::S");
	mvwprintw(start_win, 34, title_margin, "           W:::W           W:::W               UU:::::::::UU    M::::::M               M::::::MP::::::::P              UU:::::::::UU    S:::::::::::::::SS ");
	mvwprintw(start_win, 35, title_margin, "            WWW             WWW                  UUUUUUUUU      MMMMMMMM               MMMMMMMMPPPPPPPPPP                UUUUUUUUU       SSSSSSSSSSSSSSS   ");
	wattron(start_win, A_BLINK); // attempt to blink
	mvwprintw(start_win, 40, 70, "Press any key to continue...");
	wattroff(start_win, A_BLINK);
	wrefresh(start_win);
	move(0,0);
	getch();
	delwin(start_win);
	refresh();
	clear();
	refresh();

	instructions_1();

	// set the random seed
	srand(time(NULL));
	
	int wid = 5, len = 5, hig = 3;
	bool debug = true;
	
	Game g;

	// play game
	g.play_game(wid, len, hig, debug);

	move(0,0);
	clear();
	refresh();

	return 0;
}
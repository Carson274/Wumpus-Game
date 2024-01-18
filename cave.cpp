#include <iostream>
#include <ncurses.h>
#include "cave.h"
#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "wumpus.h"
#include "armor.h"
#include "passage.h"
#include "ladder.h"

using namespace std;

Cave::Cave() {
	this->length = 0;
	this->width = 0;
	this->height = 0;
}

Cave::~Cave() {
	// dont forget to delete the events
	for(int i = 0; i < get_length(); ++i) {
		for(int j = 0; j < get_width(); ++j) {
			for(int k = 0; k < get_height(); ++k) {
				if(this->rooms[i][j][k].get_event() != NULL) {
					Event* event = this->rooms[i][j][k].get_event();
					delete event;
					this->rooms[i][j][k].set_event(NULL);
				}
			}
		}
	}
}

void Cave::setup_cave(){
	// setting the length
	this->rooms.resize(get_length());

	// for each row, set the width
	for (size_t i = 0; i < get_length(); ++i)
	{
		rooms[i].resize(get_width());
	}

	// for each room, set the height
	for (int i = 0; i < get_length(); ++i)
	{
		for (int j = 0; j < get_width(); ++j)
		{
			rooms[i][j].resize(get_height());
		}
	}

	// initialize each room object
	for (int i = 0; i < get_length(); ++i)
	{
		for (int j = 0; j < get_width(); ++j)
		{
			for (int k = 0; k < get_height(); ++k)
			{
				rooms[i][j][k] = Room();
			}
		}
	}
}

void Cave::set_length(const int length) {
	this->length = length;
}
void Cave::set_width(const int width) {
	this->width = width;
}
void Cave::set_height(const int height) {
	this->height = height;
}
int Cave::get_length() const {
	return this->length;
}
int Cave::get_width() const {
	return this->width;
}
int Cave::get_height() const {
	return this->height;
}

int* Cave::find_passage(bool first, int z) {
	int *destination = new int[3];

	// iterate forwards
	if(first) {
		for(int i = 0; i < get_length(); ++i) {
			for(int j = 0; j < get_width(); ++j) {
				if(this->rooms[i][j][z].get_event() != NULL) {
					if(this->rooms[i][j][z].get_event_icon() == 'P') {
						destination[0] = i;
						destination[1] = j;
						destination[2] = z;
					}
				}
			}
		}
	} 
	// iterate backwards
	else {
		for(int i = get_length() - 1; i >= 0; --i) {
			for(int j = get_width() - 1; j >= 0; --j) {
				if(this->rooms[i][j][z].get_event() != NULL) {
					if(this->rooms[i][j][z].get_event_icon() == 'P') {
						destination[0] = i;
						destination[1] = j;
						destination[2] = z;
					}
				}
			}
		}
	}
	return destination;
}

void Cave::display_level(WINDOW *win, int level){
	noecho();
	mvwprintw(win, 4, 94, "______ _     _____  ___________   ");
	mvwprintw(win, 5, 90, "    |  ___| |   |  _  ||  _  | ___ \\   _");
	mvwprintw(win, 6, 90, "    | |_  | |   | | | || | | | |_/ /  (_)");
	mvwprintw(win, 7, 90, "    |  _| | |   | | | || | | |    /   ");
	mvwprintw(win, 8, 90, "    | |   | |___\\ \\_/ /\\ \\_/ / |\\ \\    _");
	mvwprintw(win, 9, 90, "    \\_|   \\_____/\\___/  \\___/\\_| \\_|  (_)");
	if(level == 1) {
		mvwprintw(win, 4, 140, " __         __  _____ ");
		mvwprintw(win, 5, 140, "/  |       / / |____ |");
		mvwprintw(win, 6, 140, "`| |      / /      / /");
		mvwprintw(win, 7, 140, " | |     / /       \\ \\");
		mvwprintw(win, 8, 140, "_| |_   / /    .___/ /");
		mvwprintw(win, 9, 140, "\\___/  /_/     \\____/ ");
	} else if(level == 2) {
		mvwprintw(win, 4, 140, " _____       __  _____ ");
		mvwprintw(win, 5, 140, "/ __  \\     / / |____ |");
		mvwprintw(win, 6, 140, "`' / /'    / /      / /");
		mvwprintw(win, 7, 140, "  / /     / /       \\ \\");
		mvwprintw(win, 8, 140, "./ /___  / /    .___/ /");
		mvwprintw(win, 9, 140, "\\_____/ /_/     \\____/ ");
	} else if(level == 3) {
		mvwprintw(win, 4, 140, " _____       __  _____ ");
		mvwprintw(win, 5, 140, "|____ |     / / |____ |");
		mvwprintw(win, 6, 140, "    / /    / /      / /");
		mvwprintw(win, 7, 140, "    \\ \\   / /       \\ \\");
		mvwprintw(win, 8, 140, ".___/ /  / /    .___/ /");
		mvwprintw(win, 9, 140, "\\____/  /_/     \\____/ ");
	}
}

void Cave::display_health(WINDOW *win, int num_lives) {
	noecho();

	// display the health
	if(num_lives == 3) {
		mvwprintw(win, 12, 94, "  _     _____     _______ ____        _____   _______ ");
		mvwprintw(win, 13, 94, " | |   |_ _\\ \\   / / ____/ ___|   _  |___ /  / /___ / ");
		mvwprintw(win, 14, 94, " | |    | | \\ \\ / /|  _| \\___ \\  (_)   |_ \\ / /  |_ \\ ");
		mvwprintw(win, 15, 94, " | |___ | |  \\ V / | |___ ___) |  _   ___) / /  ___) |");
		mvwprintw(win, 16, 94, " |_____|___|  \\_/  |_____|____/  (_) |____/_/  |____/ ");
	} else if(num_lives == 2) {
		mvwprintw(win, 12, 94, "  _     _____     _______ ____        ____     _______ ");
		mvwprintw(win, 13, 94, " | |   |_ _\\ \\   / / ____/ ___|   _  |___ \\   / /___ / ");
		mvwprintw(win, 14, 94, " | |    | | \\ \\ / /|  _| \\___ \\  (_)   __) | / /  |_ \\ ");
		mvwprintw(win, 15, 94, " | |___ | |  \\ V / | |___ ___) |  _   / __/ / /  ___) |");
		mvwprintw(win, 16, 94, " |_____|___|  \\_/  |_____|____/  (_) |_____/_/  |____/ ");
	} else if(num_lives == 1) {
		mvwprintw(win, 12, 94, "  _     _____     _______ ____        _    _______ ");
		mvwprintw(win, 13, 94, " | |   |_ _\\ \\   / / ____/ ___|   _  / |  / /___ / ");
		mvwprintw(win, 14, 94, " | |    | | \\ \\ / /|  _| \\___ \\  (_) | | / /  |_ \\ ");
		mvwprintw(win, 15, 94, " | |___ | |  \\ V / | |___ ___) |  _  | |/ /  ___) |");
		mvwprintw(win, 16, 94, " |_____|___|  \\_/  |_____|____/  (_) |_/_/  |____/ ");
	}
}

void Cave::display_instructions(bool &arrow_controls, WINDOW *win, int level, int num_lives) {
	noecho();
	display_level(win, level);
	display_health(win, num_lives);

	// display the controls
	WINDOW *controls = derwin(win, 12, 40, 34, 128);
	box(controls, 0, 0);
	if(arrow_controls == false) {
		mvwprintw(win, 35, 130, "          -Player Controls-");
		mvwprintw(win, 37, 130, "        w               ^");
		mvwprintw(win, 38, 130, "      a s d           < v >");
		// mvwprintw(win, 40, 130, "        u           up a level");
		// mvwprintw(win, 41, 130, "        j          down a level");
		mvwprintw(win, 43, 130, "        f           fire arrow");
	} else {
		mvwprintw(win, 35, 130, "           -Fire an Arrow-");
		mvwprintw(win, 37, 130, "           Pick a Direction");
		mvwprintw(win, 40, 130, "        w               ^");
		mvwprintw(win, 41, 130, "      a s d           < v >");
	}
	delwin(controls);
}

void Cave::check_for_percepts(WINDOW *win, int x, int y, int z) {
	noecho();
	//check for percepts around player's location
	int i = 0;
	if(x > 0 && this->rooms[x - 1][y][z].get_event() != NULL) {
		this->rooms[x - 1][y][z].play_event_percept(win, i);
		i++;
	} 
	if(x < get_length() - 1 && this->rooms[x + 1][y][z].get_event() != NULL) {
		this->rooms[x + 1][y][z].play_event_percept(win, i);
		i++;
	} 
	if (y > 0 && this->rooms[x][y - 1][z].get_event() != NULL) {
		this->rooms[x][y - 1][z].play_event_percept(win, i);
		i++;
	} 
	if(y < get_width() - 1 && this->rooms[x][y + 1][z].get_event() != NULL) {
		this->rooms[x][y + 1][z].play_event_percept(win, i);
		i++;
	} 
	return;
}

void Cave::print_adventurer(WINDOW *win, int midY, int midX, bool arrow_controls) {
	noecho();
	if(arrow_controls){
		mvwprintw(win, midY - 1, midX, "O_|\\");
		mvwprintw(win, midY, midX, "|\\| |");
		mvwprintw(win, midY + 1, midX - 1, "/ \\|/");

	} else {
		mvwprintw(win, midY - 1, midX, "O");
		mvwprintw(win, midY, midX - 1, "/|\\");
		mvwprintw(win, midY + 1, midX - 1, "/ \\");
	}
	return;
}

void Cave::print_exit(WINDOW *win, int midY, int midX) {
	noecho();

	// create a small window for the exit
	WINDOW *small_win = derwin(win, 3, 9, midY - 1, midX - 4);
	box(small_win, 0, 0);
	start_color();
	init_pair(4, COLOR_RED, COLOR_BLACK);

	// set the EXIT to red
	wattron(small_win, COLOR_PAIR(4));
	mvwprintw(small_win, 1, 2, "EXIT!");
	wattroff(small_win, COLOR_PAIR(4));
	refresh();
	delwin(small_win);
	return;
}

void Cave::print_event(WINDOW *win, int midY, int midX, char icon) {
	noecho();
	start_color();
	init_color(8, 500, 250, 0);
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, 8, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_BLACK);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);

	if(icon == 'L') {
		wattron(win, COLOR_PAIR(2));
		mvwprintw(win, midY-2, midX-4, "|_______|");
		mvwprintw(win, midY-1, midX-4, "|_______|");
		mvwprintw(win, midY, midX-4, "|_______|");
		mvwprintw(win, midY+1, midX-4, "|_______|");
		mvwprintw(win, midY+2, midX-4, "|       |");
		wattroff(win, COLOR_PAIR(2));
	} else if(icon == 'P') {
		wattron(win, COLOR_PAIR(3));
		mvwprintw(win, midY-3, midX-4, "  /-^-\\");
		mvwprintw(win, midY-2, midX-4, " /     \\");
		mvwprintw(win, midY-1, midX-4, "|  ***  |");
		mvwprintw(win, midY, midX-4, "|  ***  |");
		mvwprintw(win, midY+1, midX-4, "|  ***  |");
		mvwprintw(win, midY+2, midX-4, " \\     /");
		mvwprintw(win, midY+3, midX-4, "  \\---/");
		wattroff(win, COLOR_PAIR(3));
	} else if(icon == 'G') {
		wattron(win, COLOR_PAIR(1));
		mvwprintw(win, midY-3, midX-4, "    $");
		mvwprintw(win, midY-2, midX-4, "  /$$$\\");
		mvwprintw(win, midY-1, midX-4, " $  $  $");
		mvwprintw(win, midY, midX-4, "  \\$$$\\");
		mvwprintw(win, midY+1, midX-4, " $  $  $");
		mvwprintw(win, midY+2, midX-4, "  \\$$$/");
		mvwprintw(win, midY+3, midX-4, "    $");
		wattroff(win, COLOR_PAIR(1));
	} else if(icon == 'B') {
		wattron(win, COLOR_PAIR(5));
		mvwprintw(win, midY-2, midX-7, "___  /\\ /\\  ___");
		mvwprintw(win, midY-1, midX-7, "\\_ \\/ o o \\/ _/");
		mvwprintw(win, midY, midX-7, " /_    W    _\\");
		mvwprintw(win, midY+1, midX-7, "  /_  ___  _\\");
		mvwprintw(win, midY+2, midX-7, "   /_/   \\_\\");
		wattroff(win, COLOR_PAIR(5));
	} else if(icon == 'S') {
		mvwprintw(win, midY-2, midX-7, "  \\      \\// /");
		mvwprintw(win, midY-1, midX-7, "   \\ \\/   / /");
		mvwprintw(win, midY, midX-7, "    \\    / /");
		mvwprintw(win, midY+1, midX-7, "     \\  /\\/");
		mvwprintw(win, midY+2, midX-7, "      \\/");
	} else if(icon == 'W') {
		wattron(win, COLOR_PAIR(4));
		mvwprintw(win, midY-2, midX-7, "    _______");
		mvwprintw(win, midY-1, midX-7, "   /  o o  \\");
		mvwprintw(win, midY, midX-7, "  |   vvv   |");
		mvwprintw(win, midY+1, midX-7, "   \\_/   \\_/");
		mvwprintw(win, midY+2, midX-7, "    /\\   /\\");
		wattroff(win, COLOR_PAIR(4));
	} else if(icon == 'A') {
		wattron(win, COLOR_PAIR(6));
		mvwprintw(win, midY-3, midX-7, "  _    _    _");
		mvwprintw(win, midY-2, midX-7, " | \\__/ \\__/ |");
		mvwprintw(win, midY-1, midX-7, " |   _____   |");
		mvwprintw(win, midY, midX-7, " |  |     |  |");
		mvwprintw(win, midY+1, midX-7, "  \\  \\   /  /");
		mvwprintw(win, midY+2, midX-7, "   \\  \\_/  /");
		mvwprintw(win, midY+3, midX-7, "    \\_____/");
		wattroff(win, COLOR_PAIR(6));
	} else {
		mvwprintw(win, midY, midX, "%c", icon);
	}
	return;

// |\___/\___/|
// |  ______  |
// | |      | |
// \  \    /  /
//  \  \__/  /
//   \______/

//    _______
//   /  o o  \
//  |   vvv   |
//   \_/   \_/
//    /\   /\

// \      \// /
//  \ \/   / /
//   \    / /
//    \  /\/
//     \/

// ___  /\ /\  ___
// \_ \/ o o \/ _/
//  /_    W    _\
//   /_  ___  _\
//    /_/   \_\

//  /$$$\\
// $  $  $
//  \\$$$\\
// $  $  $
// \\  $  /
//  $$$$$

//   /-^-\
//  /     \
// |  ***  |
// |  ***  |
// |  ***  |
//  \     /
//   \---/

// |_________|
// |_________|
// |_________|
// |_________|
// |         |

}

void Cave::print_cave(bool &arrow_controls, bool &gold, bool &player_alive, bool &confused, int adventurer_lives, int *adventurer_pos, int *starting_pos, bool debug_mode, bool &armor, bool &teleport, bool &ladder) {
	noecho();
	WINDOW *win = newwin(47, 170, 3, 6);
	box(win, 0, 0);
	// print the cave so far
	int i = adventurer_pos[2]; // current level of the adventurer
	display_instructions(arrow_controls, win, i + 1, adventurer_lives);
	for(int j = 0; j < get_length(); ++j) {
		for(int k = 0; k < get_width(); ++k) {
			WINDOW *cell = derwin(win, 9, 17, j * 9 + 1, k * 17 + 2);
			box(cell, 0, 0);
			int midY = getmaxy(cell) / 2;
			int midX = getmaxx(cell) / 2;
			if(adventurer_pos[0] == j && adventurer_pos[1] == k && adventurer_pos[2] == i){
				print_adventurer(cell, midY, midX, arrow_controls);
			} else if(debug_mode && (starting_pos[0] == j && starting_pos[1] == k && starting_pos[2] == i)) {
				print_exit(cell, midY, midX);
			} else if(rooms[j][k][i].get_event() == NULL) {
				mvwprintw(cell, midY, midX, " ");
			} else if(debug_mode) {
				print_event(cell, midY, midX, this->rooms[j][k][i].get_event_icon());
			} else {
				mvwprintw(cell, midY, midX, " ");
			}
			delwin(cell); // delete the cell window
		}
	}
	// display percerts around player's location
	check_for_events(win, adventurer_pos[0], adventurer_pos[1], adventurer_pos[2], gold, player_alive, confused, armor, teleport, ladder);
	check_for_percepts(win, adventurer_pos[0], adventurer_pos[1], adventurer_pos[2]);
	refresh();
	wrefresh(win);
	delwin(win);
}

void Cave::place_adventurer(int x, int y, int z) {
	// place the adventurer in the cave
	this->rooms[x][y][z].set_has_adventurer(true);
}

void Cave::place_events() {
	// place the events in the cave
	// for each room, 
	int row_idx = -1, col_idx = -1, hei_idx = -1;

	// place single events
	for(int i = 0; i < 3; ++i){
		do {
			row_idx = rand() % get_length();
			col_idx = rand() % get_width();
			hei_idx = rand() % get_height();
		} while(this->rooms[row_idx][col_idx][hei_idx].get_event() != NULL || this->rooms[row_idx][col_idx][hei_idx].get_has_adventurer() == true);

		if(i == 0) {
			this->rooms[row_idx][col_idx][hei_idx].set_event(new Gold());
		} else if(i == 1) {
			this->rooms[row_idx][col_idx][hei_idx].set_event(new Wumpus());
		} else if(i == 2) {
			this->rooms[row_idx][col_idx][hei_idx].set_event(new Armor());
		}
	}

	// place ladders
	for(int i = 0; i < get_height() - 1; ++i) {
		do {
			row_idx = rand() % get_length();
			col_idx = rand() % get_width();
			hei_idx = i;
		} while(this->rooms[row_idx][col_idx][hei_idx].get_event() != NULL || this->rooms[row_idx][col_idx][hei_idx + 1].get_event() != NULL ||  this->rooms[row_idx][col_idx][hei_idx].get_has_adventurer() == true);

		this->rooms[row_idx][col_idx][hei_idx].set_event(new Ladder());
		this->rooms[row_idx][col_idx][hei_idx + 1].set_event(new Ladder());
	}

	// place paired events
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 6; ++j) {
			do {
				row_idx = rand() % get_length();
				col_idx = rand() % get_width();
				hei_idx = i;
			} while(this->rooms[row_idx][col_idx][hei_idx].get_event() != NULL || this->rooms[row_idx][col_idx][hei_idx].get_has_adventurer() == true);
			
			if(j == 0 || j == 1) {
				this->rooms[row_idx][col_idx][hei_idx].set_event(new Stalactites());
			} else if(j == 2 || j == 3) {
				this->rooms[row_idx][col_idx][hei_idx].set_event(new Bats());
			} else if(j == 4 || j == 5) {
				this->rooms[row_idx][col_idx][hei_idx].set_event(new Passage());
			}
		}
	}
}

void Cave::replace_wumpus() {
	// place the wumpus in the cave
	int row_idx = -1, col_idx = -1, hei_idx = -1;
	do {
		row_idx = rand() % get_length();
		col_idx = rand() % get_width();
		hei_idx = rand() % get_height();
	} while(this->rooms[row_idx][col_idx][hei_idx].get_event() != NULL);

	// get the wumpus
	for(int i = 0; i < get_length(); ++i) {
		for(int j = 0; j < get_width(); ++j) {
			for(int k = 0; k < get_height(); ++k) {
				if(this->rooms[i][j][k].get_event() != NULL) {
					if(this->rooms[i][j][k].get_event_icon() == 'W') {
						this->rooms[i][j][k].set_event(NULL);
						this->rooms[row_idx][col_idx][hei_idx].set_event(new Wumpus());
					}
				}
			}
		}
	}
}

bool Cave::find_ladder_below(int x, int y, int z) {
	bool ladder = false;
	// check if there is a ladder below the player
	if(this->rooms[x][y][z - 1].get_event() != NULL) {
		if(this->rooms[x][y][z].get_event_icon() == 'L') {
			ladder = true;
			return ladder;
		}
		else {
			ladder = false;
			return ladder;
		}
	}
	return ladder;
}

void Cave::check_for_events(WINDOW *win, int x, int y, int z, bool &gold, bool &player_alive, bool &confused, bool &armor, bool &teleport, bool &ladder) {
	// check for event at player's location
	if(this->rooms[x][y][z].get_event() != NULL) {
		if(this->rooms[x][y][z].get_event_icon() == 'G') {
			this->rooms[x][y][z].encounter_event(win, gold);
		} else if(this->rooms[x][y][z].get_event_icon() == 'W' || this->rooms[x][y][z].get_event_icon() == 'S') {
			this->rooms[x][y][z].encounter_event(win, player_alive);
		} else if(this->rooms[x][y][z].get_event_icon() == 'B') {
			this->rooms[x][y][z].encounter_event(win, confused);
		} else if(this->rooms[x][y][z].get_event_icon() == 'A') {
			this->rooms[x][y][z].encounter_event(win, armor);
		} else if(this->rooms[x][y][z].get_event_icon() == 'P') {
			this->rooms[x][y][z].encounter_event(win, teleport);
		} else if(this->rooms[x][y][z].get_event_icon() == 'L') {
			this->rooms[x][y][z].encounter_event(win, ladder);
		}
	}
	return;
}

// unsure how to make this less than 15 lines and more efficient
bool Cave::arrow_path(int current_x, int current_y, int current_z, char direction) {
	if(direction == 'w') {
		for(int x = 0; x < 4; ++x){
			if(current_x - 1 < 0 || x == 3) {
				break;
			} 
			else {
				current_x--;
				if(this->rooms[current_x][current_y][current_z].get_event() != NULL) {
					if(this->rooms[current_x][current_y][current_z].get_event_icon() == 'W') {
						return false;
					}
				}
			}
		}
	}
	else if(direction == 'a') {
		for(int y = 0; y < 4; ++y){
			if(current_y - 1 < 0 || y == 3) {
				break;
			} 
			else {
				current_y--;
				if(this->rooms[current_x][current_y][current_z].get_event() != NULL) {
					if(this->rooms[current_x][current_y][current_z].get_event_icon() == 'W') {
						return false;
					}
				}
			}
		}
	}
	else if(direction == 's') {
		for(int x = 0; x < 4; ++x){
			if(current_x + 1 > get_width() - 1 || x == 3) {
				break;
			} 
			else {
				current_x++;
				if(this->rooms[current_x][current_y][current_z].get_event() != NULL) {
					if(this->rooms[current_x][current_y][current_z].get_event_icon() == 'W') {
						return false;
					}
				}
			}
		}
	}
	else if(direction == 'd') {
		for(int y = 0; y < 4; ++y){
			if(current_y + 1 > get_length() - 1 || y == 3) {
				break;
			} 
			else {
				current_y++;
				if(this->rooms[current_x][current_y][current_z].get_event() != NULL) {
					if(this->rooms[current_x][current_y][current_z].get_event_icon() == 'W') {
						return false;
					}
				}
			}
		}
	}
	return true;
}
#include <iostream>
#include <ncurses.h>
#include "game.h"

using namespace std;

Game::Game(){
	this->debug_view = false;
	this->cave = Cave();
	this->adventurer = Adventurer();
	this->starting_position[0] = 0;
	this->starting_position[1] = 0;
	this->starting_position[2] = 0;
	this->wumpus_alive = true;
}

Game::~Game(){
}

void Game::set_debug_view(bool d){
	this->debug_view = d;
	return;
}
bool Game::get_debug_view() const{
	return this->debug_view;
}
void Game::set_wumpus_alive(bool wumpus_alive){
	this->wumpus_alive = wumpus_alive;
}
bool Game::get_wumpus_alive() const{
	return this->wumpus_alive;
}

void Game::debug_prompt(bool& d){
	noecho();
	//get the debug mode or not
	WINDOW *win = newwin(47, 170, 3, 6);
	mvwprintw(win, 22, 65, "Would you like to enter cheat mode?");
	mvwprintw(win, 23, 65, "This makes it so you can see all events");
	mvwprintw(win, 24, 65, "in the cave.");
	mvwprintw(win, 26, 75, "(1-yes, 0-no)");
	box(win, 0, 0);
	wrefresh(win);
	char c = getch();
	clear();
	box(win, 0, 0);

	mvwprintw(win, 24, 65, "                                  ");

	// error checking
	while(c != '1' && c != '0') {
		mvwprintw(win, 23, 65, "Error! You must enter '1' or '0'");
		mvwprintw(win, 26, 65, "Enter cheat mode (1-yes, 0-no): ");
		refresh();
		wrefresh(win);
		noecho();
		c = getch();
	}
	if(c == '1') {
		d = true;
	} else {
		d = false;
	}
	delwin(win);
	return;
}

void Game::set_starting_position(const int x, const int y, const int z){
	this->starting_position[0] = x;
	this->starting_position[1] = y;
	this->starting_position[2] = z;
	return;
}

void Game::randomize_starting_position(){

	// randomize starting position
	int x, y, z;
	x = rand() % this->cave.get_length();
	y = rand() % this->cave.get_width();
	z = rand() % this->cave.get_height();
	set_starting_position(x,y,z);
	this->adventurer.set_position(x,y,z);
	this->cave.place_adventurer(x,y,z);
	return;
}

void Game::set_up(int l, int w, int h, bool b){

	// reset wumpus and adventurer, if applicable
	set_wumpus_alive(true);
	this->adventurer.set_num_lives(1);
	this->adventurer.set_num_arrows(3);
	this->adventurer.set_gold(false);

	// set cave dimensions
	this->cave.set_length(l);
	this->cave.set_width(w);
	this->cave.set_height(h);

	// set debug mode
	this->set_debug_view(b);

	// create cave
	this->cave.setup_cave();

	// place player
	randomize_starting_position();

	// place events
	this->cave.place_events();
}

void Game::display_game(bool &arrow_controls, bool &gold, bool &player_alive, bool &confused, bool &armor, bool &teleport, bool &ladder){
	cout << endl << endl;
	
	// cout << "Arrows remaining: " << this->adventurer.get_num_arrows() << endl;

	this->cave.print_cave(arrow_controls, gold, player_alive, confused, this->adventurer.get_num_lives(), this->adventurer.get_position(), this->starting_position, this->get_debug_view(), armor, teleport, ladder);
}

bool Game::check_win() {
	//check if game over/win
	if(this->adventurer.get_gold() == true && (this->adventurer.get_position()[0] == this->starting_position[0] && this->adventurer.get_position()[1] == this->starting_position[1] && this->adventurer.get_position()[2] == this->starting_position[2])) {
		return true;
	} else if(get_wumpus_alive() == false) {
		return true;
	} 
	return false;
}

void Game::move_up() {
	//move player up
	if(this->adventurer.get_position()[0] == 0) {
		return;
	} else {
		this->adventurer.set_position(this->adventurer.get_position()[0] - 1, this->adventurer.get_position()[1], this->adventurer.get_position()[2]);
	}
	return;
}

void Game::move_down() {
	//move player down
	if(this->adventurer.get_position()[0] == this->cave.get_length() - 1) {
		return;
	} else {
		this->adventurer.set_position(this->adventurer.get_position()[0] + 1, this->adventurer.get_position()[1], this->adventurer.get_position()[2]);
	}
	return;
}

void Game::move_left() {
	//move player left
	if(this->adventurer.get_position()[1] == 0) {
		return;
	} else {
		this->adventurer.set_position(this->adventurer.get_position()[0], this->adventurer.get_position()[1] - 1, this->adventurer.get_position()[2]);
	}
	return;
}

void Game::move_right() {
	//move player right
	if(this->adventurer.get_position()[1] == this->cave.get_width() - 1) {
		return;
	} else {
		this->adventurer.set_position(this->adventurer.get_position()[0], this->adventurer.get_position()[1] + 1, this->adventurer.get_position()[2]);
	}
	return;
}

void Game::move_up_a_level() {
	//move player up a level
	if(this->adventurer.get_position()[2] == this->cave.get_height() - 1) {
		return;
	} else {
		this->adventurer.set_position(this->adventurer.get_position()[0], this->adventurer.get_position()[1], this->adventurer.get_position()[2] + 1);
	}
	return;
}

void Game::move_down_a_level() {
	//move player down a level
	if(this->adventurer.get_position()[2] == 0) {
		return;
	} else {
		this->adventurer.set_position(this->adventurer.get_position()[0], this->adventurer.get_position()[1], this->adventurer.get_position()[2] - 1);
	}
	return;
}

char Game::get_dir(){
	//get direction of arrow:
	char dir;

	bool arrow_controls = true, gold = false, player_alive = true, confused = false, armor = false, teleport = false, ladder = false;

	// display game with arrow controls
	display_game(arrow_controls, gold, player_alive, confused, armor, teleport, ladder);
	
	// cout << "Enter direction: " << endl;
	noecho();
	dir = getch();
	refresh();

	return dir;
}

void Game::wumpus_move(){
	//after a missed arrow, 75% chance that the wumpus is moved to a different room

	//How to get 75%? 
	//Hint: generate a random number from 0-3, if the number is not 0, then move
	int random = rand() % 4;
	if(random != 0) {
		this->cave.replace_wumpus();
	}

	return;
}

void Game::fire_arrow(){
	// The player may fire arrow...
	if(this->adventurer.get_num_arrows() > 0) {
		char dir = get_dir();

		set_wumpus_alive(this->cave.arrow_path(this->adventurer.get_position()[0], this->adventurer.get_position()[1], this->adventurer.get_position()[2], dir));

		this->adventurer.set_num_arrows(this->adventurer.get_num_arrows() - 1);

		// if the wumpus is still alive, move it
		if(get_wumpus_alive() == true) {
			wumpus_move();
		}
	} else {
		cout << "You have no arrows left!" << endl;
	}

	return;

}

void Game::fire_arrow_backwards(){
	// The player may fire arrow...
	if(this->adventurer.get_num_arrows() > 0) {
		char dir = get_dir();

		if(dir == 'w') {
			dir = 's';
		} else if(dir == 'a') {
			dir = 'd';
		} else if(dir == 's') {
			dir = 'w';
		} else if(dir == 'd') {
			dir = 'a';
		}

		set_wumpus_alive(this->cave.arrow_path(this->adventurer.get_position()[0], this->adventurer.get_position()[1], this->adventurer.get_position()[2], dir));

		this->adventurer.set_num_arrows(this->adventurer.get_num_arrows() - 1);

		// if the wumpus is still alive, move it
		if(get_wumpus_alive() == true) {
			wumpus_move();
		}
	} else {
		cout << "You have no arrows left!" << endl;
	}

	return;

}

void Game::move(char c) {
	if (c == 'f'){
		Game::fire_arrow();
	} else if (c == 'v') {
		Game::fire_arrow_backwards();
	}
	switch(c){
		case 'w':
			Game::move_up();
			break;
		case 'a':
			Game::move_left();
			break;
		case 's':
			Game::move_down();
			break;
		case 'd':
			Game::move_right();
			break;
		// case 'u':
		// 	Game::move_up_a_level();
		// 	break;
		// case 'j':
		// 	Game::move_down_a_level();
		// 	break;
	}
	return;
}

void Game::check_confused(char c, int &confused_timer) {
	// Handle player's action: move or fire an arrow
	if(confused_timer == 0) {
		move(c);
	}
	// if the player is at a wall (cannot move in the confused direction), don't lower the confused timer
	else if((c == 's' && this->adventurer.get_position()[0] == 0) || (c == 'w' && this->adventurer.get_position()[0] == this->cave.get_length() - 1) || (c == 'd' && this->adventurer.get_position()[1] == 0) || (c == 'a' && this->adventurer.get_position()[1] == this->cave.get_width() - 1)) {
		if(c == 'w') {
			move('s');
		} else if(c == 'a') {
			move('d');
		} else if(c == 's') {
			move('w');
		} else if(c == 'd') {
			move('a');
		} else if(c == 'u') {
			move('j');
		} else if(c == 'j') {
			move('u');
		} else if (c == 'f') {
			move('v');
		}
	}
	else {
		if(c == 'w') {
			move('s');
		} else if(c == 'a') {
			move('d');
		} else if(c == 's') {
			move('w');
		} else if(c == 'd') {
			move('a');
		} else if(c == 'u') {
			move('j');
		} else if(c == 'j') {
			move('u');
		} else if (c == 'f') {
			move('v');
		}
		confused_timer--;
	}
}

char Game::get_input(){

	//get action, move direction or firing an arrow
	char c;
	noecho();
	c = getch();
	refresh();
	
	return c;
}

void Game::climb_ladder() {

	// if at the top, move down; if at the bottom, move up; else if ladder below, move down; else move up
	if(this->adventurer.get_position()[2] == this->cave.get_height() - 1) {
		move_down_a_level();
	} else if(this->adventurer.get_position()[2] == 0) {
		move_up_a_level();
	} else if(this->cave.find_ladder_below(this->adventurer.get_position()[0], this->adventurer.get_position()[1], this->adventurer.get_position()[2])) {
		move_down_a_level();
	} else {
		move_up_a_level();
	}

	bool arrow_controls = false, gold = false, player_alive = true, confused = false, armor = false, teleport = false, ladder = false;
	display_game(arrow_controls, gold, player_alive, confused, armor, teleport, ladder);
}

void Game::teleport_player() {
	bool first = true;
	int *destination_1 = this->cave.find_passage(first, this->adventurer.get_position()[2]);
	first = false;
	int *destination_2 = this->cave.find_passage(first, this->adventurer.get_position()[2]);
	
	// if the player is on the first passage, teleport them to the second
	if(this->adventurer.get_position()[0] == destination_1[0] && this->adventurer.get_position()[1] == destination_1[1] && this->adventurer.get_position()[2] == destination_1[2]) {
		this->adventurer.set_position(destination_2[0], destination_2[1], destination_2[2]);
	} else {
		this->adventurer.set_position(destination_1[0], destination_1[1], destination_1[2]);
	}

	bool arrow_controls = false, gold = false, player_alive = true, confused = false, armor = false, teleport = false, ladder = false;
	display_game(arrow_controls, gold, player_alive, confused, armor, teleport, ladder);

	delete [] destination_1;
	delete [] destination_2;
	destination_1 = NULL;
	destination_2 = NULL;
	return;
}

bool Game::check_loss(bool &player_alive) {
	if(player_alive == false) {
		this->adventurer.set_num_lives(this->adventurer.get_num_lives() - 1);
		player_alive = true;
	}
	if(this->adventurer.get_num_lives() == 0) {
		return true;
	} else {
		return false;
	}
}

void Game::game_loss(bool &play_again) {
	noecho();
	WINDOW *win = newwin(47, 170, 3, 6);
	box(win, 0, 0);
	int midY = getmaxy(win) / 2;
	int midX = getmaxx(win) / 2;
	mvwprintw(win, midY, midX - 6, "Game Over!");
	mvwprintw(win, midY + 2, midX - 11, "Play again? (y/n)");
	wrefresh(win);
	char c = getch();
	while(c != 'y' && c != 'n') {
		mvwprintw(win, midY, midX - 17, "Error! You must enter 'y' or 'n'");
		mvwprintw(win, midY + 2, midX - 11, "Play again? (y/n)");
		refresh();
		wrefresh(win);
		noecho();
		c = getch();
	}

	if(c == 'n') {
		play_again = false;
	} else {
		play_again = true;
	}
	delwin(win);
	refresh();
}

void Game::game_win(bool &play_again) {
	noecho();
	WINDOW *win = newwin(47, 170, 3, 6);
	box(win, 0, 0);
	int midY = getmaxy(win) / 2;
	int midX = getmaxx(win) / 2;
	mvwprintw(win, midY, midX - 6, "You Win!");
	mvwprintw(win, midY + 2, midX - 11, "Play again? (y/n)");
	wrefresh(win);
	char c = getch();
	while(c != 'y' && c != 'n') {
		mvwprintw(win, midY, midX - 17, "Error! You must enter 'y' or 'n'");
		mvwprintw(win, midY + 2, midX - 11, "Play again? (y/n)");
		refresh();
		wrefresh(win);
		noecho();
		c = getch();
	}

	if(c == 'n') {
		play_again = false;
	} else {
		play_again = true;
	}
	delwin(win);
	refresh();
}

//Note: you need to modify this function
void Game::play_game(int w, int l, int h, bool b){

	bool play_again = true;

	while(play_again == true) {

		debug_prompt(b);

		set_up(w, l, h, b);

		bool gold = false, player_alive = true, confused = false, arrow_controls = false, armor = false, loss = false, teleport = false, ladder = false;
		int confused_timer = 0;

		do {
			// print caves
			display_game(arrow_controls, gold, player_alive, confused, armor, teleport, ladder);

			// check if the player is on a ladder
			if(ladder) {
				climb_ladder();
				ladder = false;
			}

			// check if the player is confused
			if(confused) {
				confused_timer = 5;
				confused = false;
			}

			// check if player has been teleported
			if(teleport) {
				teleport = false;
				teleport_player();
			}

			// get input and move player (if player is alive)
			loss = check_loss(player_alive);
			if(!loss) {
				check_confused(get_input(), confused_timer);
			}

			// if the player has the gold, add it
			this->adventurer.set_gold(gold);

			// check if player has armor
			if(armor) {
				this->adventurer.set_num_lives(3);
				armor = false;
			}
		} while(check_win() == false && !loss);
		if(this->adventurer.get_num_lives() == 0) {
			game_loss(play_again);
		} else {
			game_win(play_again);
		}
	}

	return;
}
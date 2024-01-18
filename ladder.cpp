#include "ladder.h"

#include <iostream>

using namespace std;

Ladder::Ladder() { 
    this->name = "Ladder";
    this->position[0] = 0;
    this->position[1] = 0;
    this->position[2] = 0;
    this->icon = 'L';
    this->percept_message = "You hear creaking.";
    this->encounter_message = "You have encountered the Ladder!";
}

Ladder::~Ladder() {
}

void Ladder::set_position(const int x, const int y, const int z) {
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
}
int* Ladder::get_position() {
    return this->position;
}
char Ladder::get_icon() {
    return this->icon;
}
string Ladder::get_name() {
    return this->name;
}
string Ladder::get_percept_message() {
    return this->percept_message;
}
string Ladder::get_encounter_message() {
    return this->encounter_message;
}

void Ladder::encounter(bool &b) {
    b = true;
}
void Ladder::display_percept_message(WINDOW *win, int i) {
    noecho();
    mvwprintw(win, 27 + i, 100, "You hear creaking.");
    wrefresh(win);
}

void Ladder::display_encounter_message(WINDOW *win) {
    noecho();
    mvwprintw(win, 24, 100, "You have encountered the Ladder!");
    wrefresh(win);
}
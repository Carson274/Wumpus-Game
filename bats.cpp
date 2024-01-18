#include "bats.h"

#include <iostream>

using namespace std;

Bats::Bats() { 
    this->name = "Bats";
    this->position[0] = 0;
    this->position[1] = 0;
    this->position[2] = 0;
    this->icon = 'B';
    this->percept_message = "You hear wings flapping.";
    this->encounter_message = "You have encountered the Bats!";
}

Bats::~Bats() {
}

void Bats::set_position(const int x, const int y, const int z) {
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
}
int* Bats::get_position() {
    return this->position;
}
char Bats::get_icon() {
    return this->icon;
}
string Bats::get_name() {
    return this->name;
}
string Bats::get_percept_message() {
    return this->percept_message;
}
string Bats::get_encounter_message() {
    return this->encounter_message;
}

void Bats::encounter(bool &b) {
    b = true;
}
void Bats::display_percept_message(WINDOW *win, int i) {
    noecho();
    mvwprintw(win, 27 + i, 100, "You hear wings flapping.");
    wrefresh(win);
}

void Bats::display_encounter_message(WINDOW *win) {
    noecho();
    mvwprintw(win, 24, 100, "You have encountered the Bats!");
    mvwprintw(win, 25, 100, "You are you confused for the next 5 turns!");
    wrefresh(win);
}
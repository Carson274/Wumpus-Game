#include "gold.h"

#include <iostream>

using namespace std;

Gold::Gold() {
    this->name = "Gold";
    this->position[0] = 0;
    this->position[1] = 0;
    this->position[2] = 0;
    this->icon = 'G';
    this->percept_message = "You see a glimmer nearby.";
    this->encounter_message = "You have encountered the Gold!";
}

Gold::~Gold() {
}

void Gold::set_position(const int x, const int y, const int z) {
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
}
int* Gold::get_position() {
    return this->position;
}
char Gold::get_icon() {
    return this->icon;
}
string Gold::get_name() {
    return this->name;
}
string Gold::get_percept_message() {
    return this->percept_message;
}
string Gold::get_encounter_message() {
    return this->encounter_message;
}

void Gold::encounter(bool &b) {
    b = true;
}
void Gold::display_percept_message(WINDOW *win, int i) {
    noecho();
    mvwprintw(win, 27 + i, 100, "You see a glimmer nearby.");
    wrefresh(win);
}

void Gold::display_encounter_message(WINDOW *win) {
    noecho();
    mvwprintw(win, 24, 100, "You have encountered the Gold!");
    mvwprintw(win, 25, 100, "Now find the escape!");
    wrefresh(win);
}
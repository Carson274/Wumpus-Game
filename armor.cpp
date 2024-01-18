#include "armor.h"

#include <iostream>

using namespace std;

Armor::Armor() { 
    this->name = "Armor";
    this->position[0] = 0;
    this->position[1] = 0;
    this->position[2] = 0;
    this->icon = 'A';
    this->percept_message = "You feel the power.";
    this->encounter_message = "You have encountered the Armor!";
}

Armor::~Armor() {
}

void Armor::set_position(const int x, const int y, const int z) {
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
}
int* Armor::get_position() {
    return this->position;
}
char Armor::get_icon() {
    return this->icon;
}
string Armor::get_name() {
    return this->name;
}
string Armor::get_percept_message() {
    return this->percept_message;
}
string Armor::get_encounter_message() {
    return this->encounter_message;
}

void Armor::encounter(bool &b) {
    b = true;
}
void Armor::display_percept_message(WINDOW *win, int i) {
    noecho();
    mvwprintw(win, 27 + i, 100, "You feel the power.");
    wrefresh(win);
}

void Armor::display_encounter_message(WINDOW *win) {
    noecho();
    mvwprintw(win, 24, 100, "You have encountered the Armor!");
    mvwprintw(win, 24, 100, "You now have 2 more lives!");
    wrefresh(win);
}
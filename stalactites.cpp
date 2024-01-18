#include "stalactites.h"

#include <iostream>

using namespace std;

Stalactites::Stalactites() {
    this->name = "Stalactites";
    this->position[0] = 0;
    this->position[1] = 0;
    this->position[2] = 0;
    this->icon = 'S';
    this->percept_message = "You hear a faint dripping sound.";
    this->encounter_message = "You have encountered the Stalactites! Watch out!";
}

Stalactites::~Stalactites() {
}

void Stalactites::set_position(const int x, const int y, const int z) {
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
}
int* Stalactites::get_position() {
    return this->position;
}
char Stalactites::get_icon() {
    return this->icon;
}
string Stalactites::get_name() {
    return this->name;
}
string Stalactites::get_percept_message() {
    return this->percept_message;
}
string Stalactites::get_encounter_message() {
    return this->encounter_message;
}

void Stalactites::encounter(bool &b) {
    int random;

    random = rand() % 2;

    if (random == 0) {
        b = true;
    } else {
        b = false;
    }
}
void Stalactites::display_percept_message(WINDOW *win, int i) {
    noecho();
    mvwprintw(win, 27 + i, 100, "You hear a faint dripping sound.");
    wrefresh(win);
}

void Stalactites::display_encounter_message(WINDOW *win) {
    noecho();
    mvwprintw(win, 24, 100, "You have encountered the Stalactites!");
    wrefresh(win);
}
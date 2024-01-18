#include "passage.h"

#include <iostream>

using namespace std;

Passage::Passage() { 
    this->name = "Passage";
    this->position[0] = 0;
    this->position[1] = 0;
    this->position[2] = 0;
    this->icon = 'P';
    this->percept_message = "You feel a breeze.";
    this->encounter_message = "You have encountered a Hidden Passage!";
}

Passage::~Passage() {
}

void Passage::set_position(const int x, const int y, const int z) {
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
}
int* Passage::get_position() {
    return this->position;
}
char Passage::get_icon() {
    return this->icon;
}
string Passage::get_name() {
    return this->name;
}
string Passage::get_percept_message() {
    return this->percept_message;
}
string Passage::get_encounter_message() {
    return this->encounter_message;
}

void Passage::encounter(bool &b) {
    b = true;
}
void Passage::display_percept_message(WINDOW *win, int i) {
    noecho();
    mvwprintw(win, 27 + i, 100, "You feel a breeze.");
    wrefresh(win);
}

void Passage::display_encounter_message(WINDOW *win) {
    noecho();
    mvwprintw(win, 24, 100, "You have encountered a Hidden Passage!");
    mvwprintw(win, 25, 100, "You find yourself at the other end!");
    wrefresh(win);
}
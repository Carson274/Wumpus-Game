#include <iostream>
#include <ncurses.h>
#include "room.h"

using namespace std;

Room::Room() {
	this->event = NULL;
    this->has_adventurer = false;
    this->emptiness = true;
}

Room::~Room() {
    delete this->event;
}

void Room::set_event(Event* event) {
    this->event = event;
}
void Room::set_emptiness(bool emptiness) {
    this->emptiness = emptiness;
}
void Room::set_has_adventurer(bool has_adventurer) {
    this->has_adventurer = has_adventurer;
}
void Room::set_event_position(const int x, const int y, const int z) {
    this->event->set_position(x, y, z);
}
Event* Room::get_event() const {
    return this->event;
}
bool Room::get_emptiness() const {
    return this->emptiness;
}
char Room::get_event_icon() {
    return this->event->get_icon();
}
int* Room::get_event_position() {
    return this->event->get_position();
}
bool Room::get_has_adventurer() const {
    return this->has_adventurer;
}

void Room::encounter_event(WINDOW *win, bool &b) {
    noecho();

    // display encounter message
    this->event->display_encounter_message(win);
    this->event->encounter(b);

    // display result message if stalactite event
    if(this->event->get_icon() == 'S') {
        if(b) {
            mvwprintw(win, 25, 100, "You've managed to dodge a falling stalactite!");
        } else{
            mvwprintw(win, 25, 100, "You've been impaled!");
        }
    }

    // clear event once it's been triggered
    if(this->event->get_icon() != 'P' && this->event->get_icon() != 'L') {
        set_event(NULL);
    }
    wrefresh(win);
    return;
}

void Room::play_event_percept(WINDOW *win, int i) {
    this->event->display_percept_message(win, i);
}

bool Room::is_empty() {
    if(this->event == NULL && this->has_adventurer == false) {
        set_emptiness(true);
    }
    else {
        set_emptiness(false);
    }
    return get_emptiness();
}
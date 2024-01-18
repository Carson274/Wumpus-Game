#include <iostream>
#include "event.h"

using namespace std;

Event::Event() {
    this->name = "<Event Name>";
    this->percept_message = "<Event Percept Message>";
    this->encounter_message = "<Event Encounter Message>";
    this->position[0] = 0;
    this->position[1] = 0;
    this->position[2] = 0;
    this->icon = 'E';
}

Event::~Event() {
}

void Event::set_position(const int x, const int y, const int z) {
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
}
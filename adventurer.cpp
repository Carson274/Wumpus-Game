#include <iostream>
#include "adventurer.h"

using namespace std;

Adventurer::Adventurer() {
	this->num_arrows = 3;
	this->num_lives = 1;
    this->position[0] = 0;
    this->position[1] = 0;
    this->position[2] = 0;
    this->gold = false;
}

Adventurer::~Adventurer() {
}

void Adventurer::set_num_arrows(const int num_arrows) {
    this->num_arrows = num_arrows;
}
void Adventurer::set_num_lives(const int num_lives) {
    this->num_lives = num_lives;
}
void Adventurer::set_position(const int x, const int y, const int z) {
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
}
void Adventurer::set_gold(const bool gold) {
    this->gold = gold;
}
int Adventurer::get_num_arrows() const {
    return this->num_arrows;
}
int Adventurer::get_num_lives() const {
    return this->num_lives;
}
int* Adventurer::get_position() {
    return this->position;
}
bool Adventurer::get_gold() const {
    return this->gold;
}
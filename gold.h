#ifndef GOLD_H
#define GOLD_H 

#include <ncurses.h>
#include "event.h"

class Gold : public Event {
    private:
        
    public:
        Gold();
        ~Gold();

        void set_position(const int, const int, const int);
        int* get_position();
        char get_icon() override;
        string get_name() override;
        string get_encounter_message() override;
        string get_percept_message() override;

        void encounter(bool &);
        void move();

        void display_percept_message(WINDOW *, int);
        void display_encounter_message(WINDOW *);
};

#endif
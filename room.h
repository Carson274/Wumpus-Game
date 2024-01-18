#ifndef ROOM_H
#define ROOM_H 

#include <vector>
#include <iostream>
#include "event.h"
#include "gold.h"
#include "wumpus.h"
#include "bats.h"
#include "stalactites.h"
#include "armor.h"
#include "ladder.h"

using namespace std;

class Room
{
private: 
    Event* event;	//event in the room
    bool has_adventurer;
    bool emptiness;
public:
    /***********************************************************************
     * Function: Room()
     * Description: Default constructor for the Room class. Initializes the room state.
     * Parameters: None
     * Pre-Conditions: None
     * Post-Conditions: Room object is initialized.
    ***********************************************************************/
    Room();

    /***********************************************************************
     * Function: ~Room()
     * Description: Destructor for the Room class. Cleans up any dynamically allocated memory.
     * Parameters: None
     * Pre-Conditions: Room object exists.
     * Post-Conditions: Room object is destroyed and memory is freed.
    ***********************************************************************/
    ~Room();

    /***********************************************************************
     * Function: set_event(Event*)
     * Description: Sets the event in the room.
     * Parameters: Event* - A pointer to the event to set.
     * Pre-Conditions: Room object exists.
     * Post-Conditions: Event is set in the room.
    ***********************************************************************/
    void set_event(Event*);

    /***********************************************************************
     * Function: set_emptiness(bool)
     * Description: Sets the emptiness status of the room.
     * Parameters: bool - The emptiness status to set.
     * Pre-Conditions: Room object exists.
     * Post-Conditions: Emptiness status of the room is set.
    ***********************************************************************/
    void set_emptiness(bool);

    /***********************************************************************
     * Function: set_has_adventurer(bool)
     * Description: Sets the adventurer status of the room.
     * Parameters: bool - The adventurer status to set.
     * Pre-Conditions: Room object exists.
     * Post-Conditions: Adventurer status of the room is set.
    ***********************************************************************/
    void set_has_adventurer(bool);

    /***********************************************************************
     * Function: set_event_position(const int, const int, const int)
     * Description: Sets the position of the event in the room.
     * Parameters: const int - The x-coordinate of the event's position.
     *             const int - The y-coordinate of the event's position.
     *             const int - The z-coordinate of the event's position.
     * Pre-Conditions: Room object exists.
     * Post-Conditions: Position of the event in the room is set.
    ***********************************************************************/
    void set_event_position(const int, const int, const int);

    /***********************************************************************
     * Function: get_event() const
     * Description: Returns the event in the room.
     * Parameters: None
     * Pre-Conditions: Room object exists.
     * Post-Conditions: Event in the room is returned.
    ***********************************************************************/
    Event* get_event() const;	// get the event in the room

    /***********************************************************************
     * Function: get_emptiness() const
     * Description: Returns the emptiness status of the room.
     * Parameters: None
     * Pre-Conditions: Room object exists.
     * Post-Conditions: Emptiness status of the room is returned.
    ***********************************************************************/
    bool get_emptiness() const;

    /***********************************************************************
     * Function: get_event_icon()
     * Description: Returns the icon of the event in the room.
     * Parameters: None
     * Pre-Conditions: Room object exists.
     * Post-Conditions: Icon of the event in the room is returned.
    ***********************************************************************/
    char get_event_icon();

    /***********************************************************************
     * Function: get_event_position()
     * Description: Returns the position of the event in the room.
     * Parameters: None
     * Pre-Conditions: Room object exists.
     * Post-Conditions: Position of the event in the room is returned.
    ***********************************************************************/
    int* get_event_position();

    /***********************************************************************
     * Function: get_has_adventurer() const
     * Description: Returns the adventurer status of the room.
     * Parameters: None
     * Pre-Conditions: Room object exists.
     * Post-Conditions: Adventurer status of the room is returned.
    ***********************************************************************/
    bool get_has_adventurer() const;

    /***********************************************************************
     * Function: encounter_event(WINDOW *, bool &)
     * Description: Encounters the event in the room.
     * Parameters: WINDOW* - The window to display the encounter in.
     *             bool& - A reference to a boolean variable to store the result of the encounter.
     * Pre-Conditions: Room object exists.
     * Post-Conditions: Event is encountered and result is stored in the boolean variable.
    ***********************************************************************/
    void encounter_event(WINDOW *, bool &);

    /***********************************************************************
     * Function: play_event_percept(WINDOW *, int)
     * Description: Plays the percept of the event in the room.
     * Parameters: WINDOW* - The window to display the percept in.
     *             int - The intensity of the percept.
     * Pre-Conditions: Room object exists.
     * Post-Conditions: Percept of the event is played in the window.
    ***********************************************************************/
    void play_event_percept(WINDOW *, int);

    /***********************************************************************
     * Function: is_empty()
     * Description: Checks if the room is empty.
     * Parameters: None
     * Pre-Conditions: Room object exists.
     * Post-Conditions: Returns true if the room is empty, false otherwise.
    ***********************************************************************/
    bool is_empty();

};

#endif
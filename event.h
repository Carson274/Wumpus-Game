#ifndef EVENT_H
#define EVENT_H 

#include <vector>
#include <iostream>
#include <ncurses.h>

using namespace std;

class Event
{
protected:
    string name;
    string percept_message;
    string encounter_message;
    int position[3];
    char icon;
public:

    /***********************************************************************
     * Function: Event()
     * Description: Default constructor for the Event class. Initializes the event state.
     * Parameters: None
     * Pre-Conditions: None
     * Post-Conditions: Event object is initialized.
    ***********************************************************************/
	Event();

    /***********************************************************************
     * Function: ~Event()
     * Description: Destructor for the Event class. Cleans up any dynamically allocated memory.
     * Parameters: None
     * Pre-Conditions: Event object exists.
     * Post-Conditions: Event object is destroyed and memory is freed.
    ***********************************************************************/
    ~Event();

    /***********************************************************************
     * Function: set_position(const int, const int, const int)
     * Description: Sets the position of the event.
     * Parameters: const int - The x-coordinate of the event's position.
     *             const int - The y-coordinate of the event's position.
     *             const int - The z-coordinate of the event's position.
     * Pre-Conditions: Event object exists.
     * Post-Conditions: Position of the event is set.
    ***********************************************************************/
    virtual void set_position(const int, const int, const int) = 0;

    /***********************************************************************
     * Function: get_name()
     * Description: Returns the name of the event.
     * Parameters: None
     * Pre-Conditions: Event object exists.
     * Post-Conditions: Name of the event is returned.
    ***********************************************************************/
    virtual string get_name() = 0;

    /***********************************************************************
     * Function: get_encounter_message()
     * Description: Returns the encounter message of the event.
     * Parameters: None
     * Pre-Conditions: Event object exists.
     * Post-Conditions: Encounter message of the event is returned.
    ***********************************************************************/
    virtual string get_encounter_message() = 0;

    /***********************************************************************
     * Function: get_percept_message()
     * Description: Returns the percept message of the event.
     * Parameters: None
     * Pre-Conditions: Event object exists.
     * Post-Conditions: Percept message of the event is returned.
    ***********************************************************************/
    virtual string get_percept_message() = 0;

    /***********************************************************************
     * Function: encounter(bool &)
     * Description: Virtual function for encountering the event.
     * Parameters: bool& - A reference to a boolean variable to store the result of the encounter.
     * Pre-Conditions: Event object exists.
     * Post-Conditions: Result of the encounter is stored in the boolean variable.
    ***********************************************************************/
    virtual void encounter(bool &) = 0;

    /***********************************************************************
     * Function: get_position()
     * Description: Virtual function for getting the position of the event.
     * Parameters: None
     * Pre-Conditions: Event object exists.
     * Post-Conditions: Position of the event is returned.
    ***********************************************************************/
    virtual int* get_position() = 0;

    /***********************************************************************
     * Function: get_icon()
     * Description: Virtual function for getting the icon of the event.
     * Parameters: None
     * Pre-Conditions: Event object exists.
     * Post-Conditions: Icon of the event is returned.
    ***********************************************************************/
    virtual char get_icon() = 0;

    /***********************************************************************
     * Function: display_percept_message(WINDOW *, int)
     * Description: Virtual function for displaying the percept message of the event.
     * Parameters: WINDOW* - The window to display the percept in.
     *             int - The intensity of the percept.
     * Pre-Conditions: Event object exists.
     * Post-Conditions: Percept message of the event is displayed in the window.
    ***********************************************************************/
    virtual void display_percept_message(WINDOW *, int) = 0;

    /***********************************************************************
     * Function: display_encounter_message(WINDOW *)
     * Description: Virtual function for displaying the encounter message of the event.
     * Parameters: WINDOW* - The window to display the encounter in.
     * Pre-Conditions: Event object exists.
     * Post-Conditions: Encounter message of the event is displayed in the window.
    ***********************************************************************/
        virtual void display_encounter_message(WINDOW *) = 0;

};

#endif
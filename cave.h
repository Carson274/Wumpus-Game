#ifndef CAVE_H
#define CAVE_H 

#include <vector>
#include <iostream>
#include "room.h"

using namespace std;

class Cave 
{
private:
    int length;
    int width;
    int height;
    vector<vector<vector<Room > > > rooms;
public:

    /***********************************************************************
     * Function: Cave()
     * Description: Default constructor for the Cave class. Initializes the cave state.
     * Parameters: None
     * Pre-Conditions: None
     * Post-Conditions: Cave object is initialized.
    ***********************************************************************/
    Cave();

    /***********************************************************************
     * Function: ~Cave()
     * Description: Destructor for the Cave class. Cleans up any dynamically allocated memory.
     * Parameters: None
     * Pre-Conditions: Cave object exists.
     * Post-Conditions: Cave object is destroyed and memory is freed.
    ***********************************************************************/
    ~Cave();

    /***********************************************************************
     * Function: setup_cave()
     * Description: Sets up the cave for the game.
     * Parameters: None
     * Pre-Conditions: Cave object exists.
     * Post-Conditions: Cave is set up for the game.
    ***********************************************************************/
    void setup_cave();

    /***********************************************************************
     * Function: find_passage(bool, int)
     * Description: Finds a passage in the cave.
     * Parameters: bool - A flag to indicate if the passage should be hidden or not.
     *             int - The level of the cave to find the passage in.
     * Pre-Conditions: Cave object exists.
     * Post-Conditions: Returns the coordinates of the passage.
    ***********************************************************************/
    int* find_passage(bool, int);
    
    /***********************************************************************
     * Function: display_level(WINDOW *, int)
     * Description: Displays the specified level of the cave.
     * Parameters: WINDOW* - The window to display the level in.
     *             int - The level of the cave to display.
     * Pre-Conditions: Cave object exists.
     * Post-Conditions: Specified level of the cave is displayed in the window.
    ***********************************************************************/
    void display_level(WINDOW *, int);

    /***********************************************************************
     * Function: display_health(WINDOW *, int)
     * Description: Displays the health of the player.
     * Parameters: WINDOW* - The window to display the health in.
     *             int - The health of the player.
     * Pre-Conditions: Cave object exists.
     * Post-Conditions: Player's health is displayed in the window.
    ***********************************************************************/
    void display_health(WINDOW *, int);

    /***********************************************************************
     * Function: display_instructions(bool &, WINDOW *, int, int)
     * Description: Displays the game instructions.
     * Parameters: bool& - A reference to a boolean variable to store the user's choice to view the instructions.
     *             WINDOW* - The window to display the instructions in.
     *             int - The width of the window.
     *             int - The height of the window.
     * Pre-Conditions: Cave object exists.
     * Post-Conditions: Game instructions are displayed in the window.
    ***********************************************************************/
    void display_instructions(bool &, WINDOW *, int, int);

    /***********************************************************************
     * Function: check_for_percepts(WINDOW *, int, int, int)
     * Description: Checks for percepts in the cave.
     * Parameters: WINDOW* - The window to display the percepts in.
     *             int - The x-coordinate of the player's position.
     *             int - The y-coordinate of the player's position.
     *             int - The z-coordinate of the player's position.
     * Pre-Conditions: Cave object exists.
     * Post-Conditions: Percepts are checked for and displayed in the window.
    ***********************************************************************/
    void check_for_percepts(WINDOW *, int, int, int);

    /***********************************************************************
     * Function: print_adventurer(WINDOW *, int, int, bool)
     * Description: Prints the adventurer in the cave.
     * Parameters: WINDOW* - The window to print the adventurer in.
     *             int - The x-coordinate of the adventurer's position.
     *             int - The y-coordinate of the adventurer's position.
     *             bool - A flag to indicate if the adventurer should be visible or not.
     * Pre-Conditions: Cave object exists.
     * Post-Conditions: Adventurer is printed in the window.
    ***********************************************************************/
    void print_adventurer(WINDOW *, int, int, bool);

    /***********************************************************************
     * Function: print_exit(WINDOW *, int, int)
     * Description: Prints the exit in the cave.
     * Parameters: WINDOW* - The window to print the exit in.
     *             int - The x-coordinate of the exit's position.
     *             int - The y-coordinate of the exit's position.
     * Pre-Conditions: Cave object exists.
     * Post-Conditions: Exit is printed in the window.
    ***********************************************************************/
    void print_exit(WINDOW *, int, int);

    /***********************************************************************
     * Function: print_event(WINDOW *, int, int, char)
     * Description: Prints an event in the cave.
     * Parameters: WINDOW* - The window to print the event in.
     *             int - The x-coordinate of the event's position.
     *             int - The y-coordinate of the event's position.
     *             char - The symbol of the event to print.
     * Pre-Conditions: Cave object exists.
     * Post-Conditions: Event is printed in the window.
    ***********************************************************************/
    void print_event(WINDOW *, int, int, char);

    /***********************************************************************
     * Function: print_cave(bool &, bool &, bool &, bool &, int, int *, int *, bool, bool &, bool &, bool &)
     * Description: Prints the cave.
     * Parameters: Multiple parameters to control the printing of the cave.
     * Pre-Conditions: Cave object exists.
     * Post-Conditions: Cave is printed.
    ***********************************************************************/
    void print_cave(bool &, bool &, bool &, bool &, int, int *, int *, bool, bool &, bool &, bool &);

    /***********************************************************************
     * Function: place_adventurer(int, int, int)
     * Description: Places the adventurer in the cave.
     * Parameters: int - The x-coordinate of the adventurer's position.
     *             int - The y-coordinate of the adventurer's position.
     *             int - The z-coordinate of the adventurer's position.
     * Pre-Conditions: Cave object exists.
     * Post-Conditions: Adventurer is placed in the cave.
    ***********************************************************************/
    void place_adventurer(int, int, int);

    /***********************************************************************
     * Function: place_events()
     * Description: Places the events in the cave.
     * Parameters: None
     * Pre-Conditions: Cave object exists.
     * Post-Conditions: Events are placed in the cave.
    ***********************************************************************/
    void place_events();

    /***********************************************************************
     * Function: replace_wumpus()
     * Description: Replaces the Wumpus in the cave.
     * Parameters: None
     * Pre-Conditions: Cave object exists.
     * Post-Conditions: Wumpus is replaced in the cave.
    ***********************************************************************/
    void replace_wumpus();

    /***********************************************************************
     * Function: find_ladder_below(int, int, int)
     * Description: Finds a ladder below the specified position in the cave.
     * Parameters: int - The x-coordinate of the position.
     *             int - The y-coordinate of the position.
     *             int - The z-coordinate of the position.
     * Pre-Conditions: Cave object exists.
     * Post-Conditions: Returns true if a ladder is found below the specified position, false otherwise.
    ***********************************************************************/
    bool find_ladder_below(int, int, int);


    /***********************************************************************
     * Function: check_for_events(WINDOW *, int, int, int, bool &, bool &, bool &, bool &, bool &, bool &)
     * Description: Checks for events in the cave.
     * Parameters: WINDOW* - The window to display the events in.
     *             int - The x-coordinate of the player's position.
     *             int - The y-coordinate of the player's position.
     *             int - The z-coordinate of the player's position.
     *             Multiple bool& - References to boolean variables to store the events.
     * Pre-Conditions: Cave object exists.
     * Post-Conditions: Events are checked for and displayed in the window.
    ***********************************************************************/
    void check_for_events(WINDOW *, int, int, int, bool &, bool &, bool &, bool &, bool &, bool &);

    /***********************************************************************
     * Function: arrow_path(int, int, int, char)
     * Description: Determines the path of the arrow in the cave.
     * Parameters: int - The x-coordinate of the arrow's starting position.
     *             int - The y-coordinate of the arrow's starting position.
     *             int - The z-coordinate of the arrow's starting position.
     *             char - The direction of the arrow.
     * Pre-Conditions: Cave object exists.
     * Post-Conditions: Returns true if the arrow hits the Wumpus, false otherwise.
    ***********************************************************************/
    bool arrow_path(int, int, int, char);

    /***********************************************************************
     * Function: set_length(const int)
     * Description: Sets the length of the cave.
     * Parameters: const int - The length to set.
     * Pre-Conditions: Cave object exists.
     * Post-Conditions: Length of the cave is set.
    ***********************************************************************/
    void set_length(const int);

    /***********************************************************************
     * Function: set_width(const int)
     * Description: Sets the width of the cave.
     * Parameters: const int - The width to set.
     * Pre-Conditions: Cave object exists.
     * Post-Conditions: Width of the cave is set.
    ***********************************************************************/
    void set_width(const int);

    /***********************************************************************
     * Function: set_height(const int)
     * Description: Sets the height of the cave.
     * Parameters: const int - The height to set.
     * Pre-Conditions: Cave object exists.
     * Post-Conditions: Height of the cave is set.
    ***********************************************************************/
    void set_height(const int);

    /***********************************************************************
     * Function: get_length() const
     * Description: Returns the length of the cave.
     * Parameters: None
     * Pre-Conditions: Cave object exists.
     * Post-Conditions: Length of the cave is returned.
    ***********************************************************************/
    int get_length() const;

    /***********************************************************************
     * Function: get_width() const
     * Description: Returns the width of the cave.
     * Parameters: None
     * Pre-Conditions: Cave object exists.
     * Post-Conditions: Width of the cave is returned.
    ***********************************************************************/
    int get_width() const;

    /***********************************************************************
     * Function: get_height() const
     * Description: Returns the height of the cave.
     * Parameters: None
     * Pre-Conditions: Cave object exists.
     * Post-Conditions: Height of the cave is returned.
    ***********************************************************************/
    int get_height() const;

};

#endif
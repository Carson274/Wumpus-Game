#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream>
#include <ncurses.h>
#include "cave.h"
#include "adventurer.h"

using namespace std;

//Game interface 
class Game
{
private:

	bool debug_view;	//debug mode or not
	Cave cave;
	Adventurer adventurer;
	int starting_position[3];
	bool wumpus_alive;

public:
	/***********************************************************************
	 * Function: Game()
	 * Description: Default constructor for the Game class. Initializes the game state.
	 * Parameters: None
	 * Pre-Conditions: None
	 * Post-Conditions: Game object is initialized.
	 ***********************************************************************/
	Game();

	/***********************************************************************
	 * Function: ~Game()
	 * Description: Destructor for the Game class. Cleans up any dynamically allocated memory.
	 * Parameters: None
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: Game object is destroyed and memory is freed.
	 ***********************************************************************/
	~Game();

	/***********************************************************************
	 * Function: set_debug_view()
	 * Description: Sets the debug_view variable to the passed in value.
	 * Parameters: const bool
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: debug_view is set to the passed in value.
	 ***********************************************************************/
	void set_debug_view(const bool);

	/***********************************************************************
	 * Function: get_debug_view()
	 * Description: Returns the value of debug_view.
	 * Parameters: None
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: debug_view is returned.
	 ***********************************************************************/
	bool get_debug_view() const;

	/***********************************************************************
	 * Function: set_wumpus_alive()
	 * Description: Sets the wumpus_alive variable to the passed in value.
	 * Parameters: const bool
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: wumpus_alive is set to the passed in value.
	 ***********************************************************************/
	void set_wumpus_alive(const bool);

	/***********************************************************************
	 * Function: get_wumpus_alive()
	 * Description: Returns the value of wumpus_alive.
	 * Parameters: None
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: wumpus_alive is returned.
	 ***********************************************************************/
	bool get_wumpus_alive() const;

	/***********************************************************************
	 * Function: debug_prompt(bool&)
	 * Description: Prompts the user to enter the debug mode or not.
	 * Parameters: bool& - A reference to a boolean variable to store the user's choice.
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: User's choice is stored in the passed variable.
	***********************************************************************/
	void debug_prompt(bool&); //get the debug mode or not
	
	/***********************************************************************
	 * Function: randomize_starting_position()
	 * Description: Randomizes the starting position of the adventurer.
	 * Parameters: None
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: starting_position is randomized.
	 ***********************************************************************/
	void randomize_starting_position();

	/***********************************************************************
	 * Function: debug_prompt(bool&)
	 * Description: Prompts the user to enter the debug mode or not.
	 * Parameters: bool& - A reference to a boolean variable to store the user's choice.
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: User's choice is stored in the passed variable.
	***********************************************************************/
	void set_starting_position(const int, const int, const int);

	/***********************************************************************
	 * Function: set_up(int, int, int, bool)
	 * Description: Sets up the game with the given parameters.
	 * Parameters: int - The length of the game area.
	 *             int - The width of the game area.
	 *             int - The height of the game area.
	 *             bool - The debug mode.
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: Game is set up with the given parameters.
	***********************************************************************/
	void set_up(int, int, int, bool);

	/***********************************************************************
	 * Function: display_game(bool &, bool &, bool &, bool &, bool &, bool &, bool &)
	 * Description: Displays the current state of the game.
	 * Parameters: bool& - A reference to a boolean variable to store the state of the game.
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: Current state of the game is displayed.
	***********************************************************************/
	void display_game(bool &, bool &, bool &, bool &, bool &, bool &, bool &);

	/***********************************************************************
	 * Function: check_win()
	 * Description: Checks if the player has won the game.
	 * Parameters: None
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: Returns true if the player has won, false otherwise.
	***********************************************************************/
	bool check_win();

	/***********************************************************************
	 * Function: get_dir()
	 * Description: Gets the direction of the player's movement.
	 * Parameters: None
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: Returns the direction of the player's movement.
	***********************************************************************/
	char get_dir();

	/***********************************************************************
	 * Function: wumpus_move()
	 * Description: Moves the Wumpus in the game.
	 * Parameters: None
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: Wumpus is moved.
	***********************************************************************/
	void wumpus_move();

	/***********************************************************************
	 * Function: fire_arrow()
	 * Description: Fires an arrow in the game.
	 * Parameters: None
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: Arrow is fired.
	***********************************************************************/
	void fire_arrow();

	/***********************************************************************
	 * Function: fire_arrow_backwards()
	 * Description: Fires an arrow backwards in the game.
	 * Parameters: None
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: Arrow is fired backwards.
	***********************************************************************/
	void fire_arrow_backwards();

	/***********************************************************************
	 * Function: move_up()
	 * Description: Moves the player up in the game.
	 * Parameters: None
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: Player is moved up.
	***********************************************************************/
	void move_up();

	/***********************************************************************
	 * Function: move_down()
	 * Description: Moves the player down in the game.
	 * Parameters: None
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: Player is moved down.
	***********************************************************************/
	void move_down();

	/***********************************************************************
	 * Function: move_left()
	 * Description: Moves the player left in the game.
	 * Parameters: None
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: Player is moved left.
	***********************************************************************/
	void move_left();

	/***********************************************************************
	 * Function: move_right()
	 * Description: Moves the player right in the game.
	 * Parameters: None
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: Player is moved right.
	***********************************************************************/
	void move_right();

	/***********************************************************************
	 * Function: move_up_a_level()
	 * Description: Moves the player up a level in the game.
	 * Parameters: None
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: Player is moved up a level.
	***********************************************************************/
	void move_up_a_level();

	/***********************************************************************
	 * Function: move_down_a_level()
	 * Description: Moves the player down a level in the game.
	 * Parameters: None
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: Player is moved down a level.
	***********************************************************************/
	void move_down_a_level();

	/***********************************************************************
	 * Function: move(char)
	 * Description: Moves the player in the direction specified by the parameter.
	 * Parameters: char - The direction to move the player.
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: Player is moved in the specified direction.
	***********************************************************************/
	void move(char);

	/***********************************************************************
	 * Function: check_confused(char, int&)
	 * Description: Checks if the player is confused and modifies the direction of movement if necessary.
	 * Parameters: char - The original direction of movement.
	 *             int& - A reference to an integer to store the modified direction of movement.
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: If the player is confused, the direction of movement is modified.
	***********************************************************************/
	void check_confused(char, int&);

	/***********************************************************************
	 * Function: get_input()
	 * Description: Gets the user's input for the game.
	 * Parameters: None
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: Returns the user's input.
	***********************************************************************/
	char get_input();

	/***********************************************************************
	 * Function: climb_ladder()
	 * Description: Simulates the player climbing a ladder in the game.
	 * Parameters: None
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: Player's position is updated to simulate climbing a ladder.
	***********************************************************************/
	void climb_ladder();

	/***********************************************************************
	 * Function: teleport_player()
	 * Description: Teleports the player to a random location in the game.
	 * Parameters: None
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: Player's position is updated to a random location.
	***********************************************************************/
	void teleport_player();

	/***********************************************************************
	 * Function: check_loss(bool &)
	 * Description: Checks if the player has lost the game.
	 * Parameters: bool& - A reference to a boolean variable to store the result.
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: If the player has lost, the passed variable is set to true.
	***********************************************************************/
	bool check_loss(bool &);

	/***********************************************************************
	 * Function: game_loss(bool &)
	 * Description: Handles the game loss scenario.
	 * Parameters: bool& - A reference to a boolean variable to indicate if the game is over.
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: If the player has lost, the game over scenario is handled.
	***********************************************************************/
	void game_loss(bool &);

	/***********************************************************************
	 * Function: game_win(bool &)
	 * Description: Handles the game win scenario.
	 * Parameters: bool& - A reference to a boolean variable to indicate if the game is over.
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: If the player has won, the game over scenario is handled.
	***********************************************************************/
	void game_win(bool &);

	/***********************************************************************
	 * Function: play_game(int, int, int, bool)
	 * Description: Starts the game with the given parameters.
	 * Parameters: int - The length of the game area.
	 *             int - The width of the game area.
	 *             int - The height of the game area.
	 *             bool - The debug mode.
	 * Pre-Conditions: Game object exists.
	 * Post-Conditions: Game is started with the given parameters.
	***********************************************************************/
	void play_game(int, int, int, bool);

};


#endif
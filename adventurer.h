#ifndef ADVENTURER_H
#define ADVENTURER_H 

#include <vector>
#include <iostream>

using namespace std;

class Adventurer {
private:
    int num_arrows;
    int num_lives;
    int position[3];
    bool gold;
public:

    /***********************************************************************
     * Function: Adventurer()
     * Description: Default constructor for the Adventurer class. Initializes the adventurer state.
     * Parameters: None
     * Pre-Conditions: None
     * Post-Conditions: Adventurer object is initialized.
    ***********************************************************************/
    Adventurer();

    /***********************************************************************
     * Function: ~Adventurer()
     * Description: Destructor for the Adventurer class. Cleans up any dynamically allocated memory.
     * Parameters: None
     * Pre-Conditions: Adventurer object exists.
     * Post-Conditions: Adventurer object is destroyed and memory is freed.
    ***********************************************************************/
    ~Adventurer();

    /***********************************************************************
     * Function: setup_cave()
     * Description: Sets up the cave for the adventurer.
     * Parameters: None
     * Pre-Conditions: Adventurer object exists.
     * Post-Conditions: Cave is set up for the adventurer.
    ***********************************************************************/
    void setup_cave();

    /***********************************************************************
     * Function: set_num_arrows(const int)
     * Description: Sets the number of arrows for the adventurer.
     * Parameters: const int - The number of arrows to set.
     * Pre-Conditions: Adventurer object exists.
     * Post-Conditions: Number of arrows for the adventurer is set.
    ***********************************************************************/
    void set_num_arrows(const int);

    /***********************************************************************
     * Function: set_num_lives(const int)
     * Description: Sets the number of lives for the adventurer.
     * Parameters: const int - The number of lives to set.
     * Pre-Conditions: Adventurer object exists.
     * Post-Conditions: Number of lives for the adventurer is set.
    ***********************************************************************/
    void set_num_lives(const int);

    /***********************************************************************
     * Function: set_position(const int, const int, const int)
     * Description: Sets the position of the adventurer in the cave.
     * Parameters: const int - The x-coordinate of the position.
     *             const int - The y-coordinate of the position.
     *             const int - The z-coordinate of the position.
     * Pre-Conditions: Adventurer object exists.
     * Post-Conditions: Position of the adventurer is set.
    ***********************************************************************/
    void set_position(const int, const int, const int);

    /***********************************************************************
     * Function: set_gold(const bool)
     * Description: Sets the gold status for the adventurer.
     * Parameters: const bool - The gold status to set.
     * Pre-Conditions: Adventurer object exists.
     * Post-Conditions: Gold status for the adventurer is set.
    ***********************************************************************/
    void set_gold(const bool);

    /***********************************************************************
     * Function: get_num_arrows() const
     * Description: Returns the number of arrows the adventurer has.
     * Parameters: None
     * Pre-Conditions: Adventurer object exists.
     * Post-Conditions: Number of arrows the adventurer has is returned.
    ***********************************************************************/
    int get_num_arrows() const;

    /***********************************************************************
     * Function: get_num_lives() const
     * Description: Returns the number of lives the adventurer has.
     * Parameters: None
     * Pre-Conditions: Adventurer object exists.
     * Post-Conditions: Number of lives the adventurer has is returned.
    ***********************************************************************/
    int get_num_lives() const;

    /***********************************************************************
     * Function: get_position()
     * Description: Returns the position of the adventurer in the cave.
     * Parameters: None
     * Pre-Conditions: Adventurer object exists.
     * Post-Conditions: Position of the adventurer is returned.
    ***********************************************************************/
    int* get_position();
    
    /***********************************************************************
     * Function: get_gold() const
     * Description: Returns the gold status of the adventurer.
     * Parameters: None
     * Pre-Conditions: Adventurer object exists.
     * Post-Conditions: Gold status of the adventurer is returned.
    ***********************************************************************/
    bool get_gold() const;

};



#endif
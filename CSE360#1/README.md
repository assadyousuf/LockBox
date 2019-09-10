name:Assad Yousuf
Student ID:1212371223

Overview:This program simulates a house with an owner and acceptable keys passed into the command line arguments. The door only opens with an acceptable key inserted into the door. A list of who is inside the house is also kept by the program. A special key callde FIRE_FIGHTER_ACESS is always set up to be able to open the door.  

Implementation:The program starts off by taking in an input and returning and int that marks the action to be peformed. The appropiate case is found and the action is taken if the critera are passed. There are several functions written that help aid in peforming these actions. wordCounter() counts the number of words in the input and makes sure its a valid input. removeFromInsideHouse() Loops through the vector containing the people inside the house and removes the appropriate person. printWhoIsInside() prints the vector list containing the people inside the house. validKey() checks to see if the key passed in is valid. checkIfInside() returns a boolen indicating if a person is inside or not. The whole program is encompassed in a while loop that is only broken if the command to quit the program is entered.

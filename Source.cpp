#include<iostream>
using namespace std; 

// Class to represent playing a game of TicTacToe
class Game {
public:

	// declare fucnction to print out starting script when first playing a game
	void starting_script() {
		// Prints out the starting information for the game
		// cout << "This is a TicTacToe game!" << endl;
		// cout << "Player Number " << player_number << " is now playing." << endl;
		// cout << "Please enter a number you would like to replace with an " << player_symbol << endl;
	}
};

// Class to represent a TicTacToe game board
class Board {
public:
	// Create a character array to hold the 9 available spots of the board
	char board_spots[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	// Create the player value variables
	int player_number = 1;
	char player_symbol = 'X';
	char input_value = '|';

	// Create character arrays of acceptable input characters
	// and already in use characters
	char acceptable_chars[13] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 'q', 'Q', 'p', 'P'};
	char in_use[10] = { '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'};

	// declare function to display tictactoe board
	// function takes an array as a parameter that will be used to fill
	// in the user inputted spots
	void show_board() {
		cout << board_spots[0] << "|" << board_spots[1] << "|" << board_spots[2] << "\n";
		cout << "-" << "-" << "-" << "-" << "-" << "\n";
		cout << board_spots[3] << "|" << board_spots[4] << "|" << board_spots[5] << "\n";
		cout << "-" << "-" << "-" << "-" << "-" << "\n";
		cout << board_spots[6] << "|" << board_spots[7] << "|" << board_spots[8] << "\n";
	}

	// declare function to validate that a user input is an acceptable character
	// and if the input is a spot number, the spot number does not
	// already have a player symbol in it
	void validate_input() {
		// Validate that the input character is an acceptable character

		// Validate that the input character is not already in use
	}

	// declare function to update board_spots
	void update_board_spots(char input_value) {
		for (int i = 0; i < 9; i++) {
			if (board_spots[i] == input_value) {
				board_spots[i] = player_symbol;
			}
		}
	}
};

int main() {
	// create a char that can be used as the user input variable
	char input_value = '|';

	// Create a board object
	Board object1;
	object1.show_board();

	// Get the spot the user would like to place their symbol in
	// validate that the input value is a space on the board
	cin >> input_value;

	// Update the board with the player's symbol
	object1.update_board_spots(input_value);
	object1.show_board();
	return 0;

}
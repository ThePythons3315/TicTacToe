#include<iostream>
using namespace std;

// Class to represent a TicTacToe game board
class Board {
public:
	// Create a character array to hold the 9 available spots of the board
	char board_spots[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	// Declare function to display tictactoe board
	// function takes an array as a parameter that will be used to fill
	// in the user inputted spots
	void show_board() {
		cout << board_spots[0] << "|" << board_spots[1] << "|" << board_spots[2] << "\n";
		cout << "-" << "-" << "-" << "-" << "-" << "\n";
		cout << board_spots[3] << "|" << board_spots[4] << "|" << board_spots[5] << "\n";
		cout << "-" << "-" << "-" << "-" << "-" << "\n";
		cout << board_spots[6] << "|" << board_spots[7] << "|" << board_spots[8] << "\n";
	}

	// Declare function to update board spots with player symbol
	void update_board_spots(char input_value, char symbol) {
		for (int i = 0; i < 9; i++) {
			if (board_spots[i] == input_value) {
				board_spots[i] = symbol;// Place the player symbol in the board spot
			}
		}
	}

	//resets the game you select 'play again'
	void reset_board() {
		for (char i = '1'; i < ':'; i++) {
			board_spots[i - 49] = i;// Use char math to reset all spots in board to numbers 1-9
		}
	}
};

// Class to represent playing a game of TicTacToe
class Game {
public:

	// Create the player value variables
	int player = 1;
	char player_symbol = 'X';
	char input = '|';

	// Create arrays to help with input validation
	char acceptable_chars[13] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 'q', 'Q', 'p', 'P' };
	char in_use[9] = { '*', '*', '*', '*', '*', '*', '*', '*', '*' };

	// Create an object of the board class
	Board obj1;

	//Game script
	void run_game() {

		// Opening statement for the game
		cout << "Welcome to Tic Tac Toe" << endl;

		// loop as long as the game has not finished
		while (isFinished() == false) {

			// Show the board on the screen
			obj1.show_board();

			// Get the user input and update the characters in use array
			do {
				cout << "Player " << player_symbol << " enter move (1-9): ";
				cin >> input;
			} while (validate_input(input) == false);
			update_in_use_array(input);

			// Update the board spots with new player symbols
			obj1.update_board_spots(input, player_symbol);

			// Switch the current player's number and symbol to the next player's number and symbol
			update_player();

		}//end while
	}

	void update_player() {
		// If player 1 just went, switch to player 2 and vice versa
		if (player_symbol == 'X') {
			player = 2;
			player_symbol = 'O';
		}
		else {
			player = 1;
			player_symbol = 'X';
		}
	}

	bool isFinished() {
		//if a player gets three X's or O's across top row they win
		if ((obj1.board_spots[0] == obj1.board_spots[1]) && (obj1.board_spots[1] == obj1.board_spots[2])) {
			obj1.show_board();
			//if the winning board spot is = to X(player1) it will print that player one has won
			//if not it will print player 2 has won
			if (obj1.board_spots[0] == 'X')
				cout << "Player 1 has won.\n";
			else
				cout << "Player 2 has won.\n";
			return true;
		}
		//if a player gets three X's or O's from top left corner dianonally to the right they win
		else if ((obj1.board_spots[0] == obj1.board_spots[4]) && (obj1.board_spots[4] == obj1.board_spots[8])) {
			obj1.show_board();
			if (obj1.board_spots[0] == 'X')
				cout << "Player 1 has won.\n";
			else
				cout << "Player 2 has won.\n";
			return true;
		}
		//if a player gets three X's or O's from top right corner dianonally to the left they win
		else if ((obj1.board_spots[2] == obj1.board_spots[4]) && (obj1.board_spots[4] == obj1.board_spots[6])) {
			obj1.show_board();
			if (obj1.board_spots[0] == 'X')
				cout << "Player 1 has won.\n";
			else
				cout << "Player 2 has won.\n";
			return true;
		}
		//if a player gets three X's or O'sacross the middle row they win the game
		else if ((obj1.board_spots[3] == obj1.board_spots[4]) && (obj1.board_spots[4] == obj1.board_spots[5])) {
			obj1.show_board();
			if (obj1.board_spots[0] == 'X')
				cout << "Player 1 has won.\n";
			else
				cout << "Player 2 has won.\n";
			return true;
		}
		//if a player gets three X's or O's across bottom row they win
		else if ((obj1.board_spots[6] == obj1.board_spots[7]) && (obj1.board_spots[7] == obj1.board_spots[8])) {
			obj1.show_board();
			if (obj1.board_spots[0] == 'X')
				cout << "Player 1 has won.\n";
			else
				cout << "Player 2 has won.\n";
			return true;
		}
		//if a player gets three X's O's down the left column they win
		else if ((obj1.board_spots[0] == obj1.board_spots[3]) && (obj1.board_spots[3] == obj1.board_spots[6])) {
			obj1.show_board();
			if (obj1.board_spots[0] == 'X')
				cout << "Player 1 has won.\n";
			else
				cout << "Player 2 has won.\n";
			return true;
		}
		//if a player  gets three X's or O's down the right column they win
		else if ((obj1.board_spots[2] == obj1.board_spots[5]) && (obj1.board_spots[5] == obj1.board_spots[8])) {
			obj1.show_board();
			if (obj1.board_spots[0] == 'X')
				cout << "Player 1 has won.\n";
			else
				cout << "Player 2 has won.\n";
			return true;
		}
		//if a player  gets three X's or O's down the middle column they win
		else if ((obj1.board_spots[1] == obj1.board_spots[4]) && (obj1.board_spots[4] == obj1.board_spots[7])) {
			obj1.show_board();
			if (obj1.board_spots[0] == 'X')
				cout << "Player 1 has won.\n";
			else
				cout << "Player 2 has won.\n";
			return true;
		}
		else if (check_draw())
		{
			obj1.show_board();
			cout << "There was a draw. You are both winners!!" << endl;
		}
		else
			return false;
		//this will determine if the game is finished all checks will be considered. 
	}

	// Function to determine if game is a draw
	bool check_draw() {
		int count = 0;

		for (int i = 0; i < 9; i++) {
			if (obj1.board_spots[i] >= 49 && obj1.board_spots[i] <= 57) {
				count += 1;
			}
		}
		if (count == 0) {
			return true;
		}
		return false;
	}


	// declare function to validate that a user input is an acceptable character
	// and if the input is a spot number, the spot number does not
	// already have a player symbol in it
	bool validate_input(char input_value) {
		// bool variable to be returned true if input character is validated
		bool input_acceptable = false;
		bool input_not_in_use = true;

		// Validate that the input character is an acceptable character
		for (int i = 0; i < 12; i++) {
			// input is an acceptable character if it is in the
			// acceptable_chars array
			if (input_value == acceptable_chars[i]) {
				input_acceptable = true;
			}
		}

		// Validate that the input character is not already in use
		for (int i = 0; i < 9; i++) {
			// input is acceptable if the character is not in the
			// in_use array, if it is turn the variable to false
			if (input_value == in_use[i]) {
				input_not_in_use = false;
			}
		}

		// if character is not in use and is an acceptable character
		// return true, otherwise return false
		if (input_acceptable == true && input_not_in_use == true) {
			return true;
		}
		return false;
	}

	void update_in_use_array(char input_value) {
		// Add the used input_value into the in_use array at the 
		// first spot available
		for (int i = 0; i < 9; i++) {
			if (in_use[i] == '*') {
				in_use[i] = input_value;
				break;
			}
		}
	}

	void reset_is_use_array() {
		// Reset the in_use array to not include any in use spot numbers
		for (int i = 0; i < 9; i++) {
			in_use[i] = '*';
		}
	}

};


int main() {
	Game object;
	object.run_game();
	return 0;
}
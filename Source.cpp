#include<iostream>
#include <string>
using namespace std;

// Class to represent a TicTacToe game board
class Board {
public:
	// Create a character array to hold the 9 available spots of the board
	char board_spots[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	// Displays the game board
	void show_board() {
		cout << board_spots[0] << "|" << board_spots[1] << "|" << board_spots[2] << "\n";
		cout << "-" << "-" << "-" << "-" << "-" << "\n";
		cout << board_spots[3] << "|" << board_spots[4] << "|" << board_spots[5] << "\n";
		cout << "-" << "-" << "-" << "-" << "-" << "\n";
		cout << board_spots[6] << "|" << board_spots[7] << "|" << board_spots[8] << "\n";
	}

	// Updates game board with player's symbols
	void update_board_spots(char input_value, char symbol) {
		for (int i = 0; i < 9; i++) {
			if (board_spots[i] == input_value) {
				board_spots[i] = symbol;// Place the player symbol in the board spot
			}
		}
	}

	// Resets the game board to original layout
	void reset_board() {
		for (char i = '1'; i < ':'; i++) {
			board_spots[i - 49] = i;// Use char math to reset all spots in board to numbers 1-9
		}
	}
};

// Class to represent playing a game of TicTacToe
class Game {
public:
	// Create variables associated with the players
	int player = 1;
	char player_symbol = 'X';
	string input = "";

	// Create variables to track start of a new game
	// or if a game has been quit
	bool new_game = true;
	bool quit_game = false;

	// Create arrays to help with input validation
	char acceptable_chars[13] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 'q', 'Q', 'p', 'P'};
	char in_use[9] = { '*', '*', '*', '*', '*', '*', '*', '*', '*' };

	// Create an object of the board class
	Board obj1;

	// Game script, actually runs the game
	void run_game() {
		// loop as long as the game has not finished
		while (isFinished() == false) {

			// If this is a new game, print out opening statement
			if (new_game == true) {
				cout << "Welcome to Tic Tac Toe" << endl;
				new_game = false;//Set new_game to false, game has started
			}

			obj1.show_board();//Show the board on the screen

			// Get user input for playing the game
			do {
				cout << "Player " << player_symbol << " enter move (1-9): ";
				getline(cin, input);
			} while (validate_input(input) == false);//Ask for characters until user enters correct one
			update_in_use_array(input[0]);//Update the characters in the in_use array

			obj1.update_board_spots(input[0], player_symbol);//Update board spots with new player symbols

			update_player();//Switch the current player's number and symbol to the next player's number and symbol

			// Quit the game if user entered 'q' or 'Q'
			if (input[0] == 'q' || input[0] == 'Q') {
				cout << "You have chosen to terminate the game. Thanks for playing!" << endl;
				quit_game = true;//Set quit variable to true so game will terminate
				break;
			}
			// Restart the game if user entered 'p' or 'P'
			else if (input[0] == 'p' || input[0] == 'P') {
				restart_game();//Reset all game/board features
			}

		}//end while
		restart_game();//Reset game/board in case the user wants to play again
	}

	// If player 1 just went, switch to player 2 and vice versa
	void update_player() {
		if (player_symbol == 'X') {
			player = 2;
			player_symbol = 'O';
		}
		else {
			player = 1;
			player_symbol = 'X';
		}
	}

	// Checks all win / draw conditions and returns true if game ended, false to keep playing
	bool isFinished() {
		//if a player gets three X's or O's across top row they win
		if ((obj1.board_spots[0] == obj1.board_spots[1]) && (obj1.board_spots[1] == obj1.board_spots[2])) {
			show_winner(obj1.board_spots[0]);
			return true;
		}
		//if a player gets three X's or O's across the middle row they win the game
		else if ((obj1.board_spots[3] == obj1.board_spots[4]) && (obj1.board_spots[4] == obj1.board_spots[5])) {
			show_winner(obj1.board_spots[3]);
			return true;
		}
		//if a player gets three X's or O's across bottom row they win
		else if ((obj1.board_spots[6] == obj1.board_spots[7]) && (obj1.board_spots[7] == obj1.board_spots[8])) {
			show_winner(obj1.board_spots[6]);
			return true;
		}
		//if a player gets three X's or O's down the left column they win
		else if ((obj1.board_spots[0] == obj1.board_spots[3]) && (obj1.board_spots[3] == obj1.board_spots[6])) {
			show_winner(obj1.board_spots[0]);
			return true;
		}
		//if a player  gets three X's or O's down the right column they win
		else if ((obj1.board_spots[2] == obj1.board_spots[5]) && (obj1.board_spots[5] == obj1.board_spots[8])) {
			show_winner(obj1.board_spots[2]);
			return true;
		}
		//if a player  gets three X's or O's down the middle column they win
		else if ((obj1.board_spots[1] == obj1.board_spots[4]) && (obj1.board_spots[4] == obj1.board_spots[7])) {
			show_winner(obj1.board_spots[1]);
			return true;
		}
		//if a player gets three X's or O's from top left corner dianonally to the right they win
		else if ((obj1.board_spots[0] == obj1.board_spots[4]) && (obj1.board_spots[4] == obj1.board_spots[8])) {
			show_winner(obj1.board_spots[0]);
			return true;
		}
		//if a player gets three X's or O's from top right corner dianonally to the left they win
		else if ((obj1.board_spots[2] == obj1.board_spots[4]) && (obj1.board_spots[4] == obj1.board_spots[6])) {
			show_winner(obj1.board_spots[2]);
			return true;
		}
		// Checks for a draw
		else if (check_draw())
		{
			obj1.show_board();
			cout << "There was a draw. You are both winners!!" << endl;
			return true;
		}
		else
			return false;//Game is not finished, continue playing game
	}

	// Determine if game ended in draw
	bool check_draw() {
		int count = 0;

		// If there is at least one ascii number in the array, return false
		// meaning there is not draw
		for (int i = 0; i < 9; i++) {
			if (obj1.board_spots[i] >= 49 && obj1.board_spots[i] <= 57) {
				count += 1;
			}
		}
		// Only 'X' and 'O' on board, game ends in draw
		if (count == 0) {
			return true;
		}
		return false;
	}

	// Validate that user input is an acceptable character
	// and if the input is a spot number, the spot number does not
	// already have a player symbol in it
	bool validate_input(string input_value) {
		// Bool variablea to be returned true if input character is validated
		bool one_character_only = false;
		bool input_acceptable = false;
		bool input_not_in_use = true;

		// If the input is not more than one character, set variable to true
		if (input_value.length() == 1) {
			one_character_only = true;
		}

		// Validate that the input character is an acceptable character
		for (int i = 0; i < 13; i++) {
			// Input is an acceptable character if it is in the
			// acceptable_chars array
			if (input_value[0] == acceptable_chars[i]) {
				input_acceptable = true;
			}
		}

		// Validate that the input character is not already in use
		for (int i = 0; i < 9; i++) {
			// Input is acceptable if the character is not in the
			// in_use array, if it is turn the variable to false
			if (input_value[0] == in_use[i]) {
				input_not_in_use = false;
			}
		}

		// If character is not in use, is an acceptable character
		// and is only a single character, then return true, otherwise return false
		if (input_acceptable == true && input_not_in_use == true && one_character_only == true) {
			return true;
		}
		return false;
	}

	// Adds the spot number that was just taken to the in_use array
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

	// Resets the in_use array to orginal state
	void reset_in_use_array() {
		// Reset the in_use array to not include any in use spot numbers
		for (int i = 0; i < 9; i++) {
			in_use[i] = '*';
		}
	}

	// Prints the winner of the game to the console
	void show_winner(char player_symbol) {
		obj1.show_board();
		if (player_symbol == 'X')
			cout << "Player 1 has won.\n";
		else
			cout << "Player 2 has won.\n";
	}

	// Resets the player information to original state
	void reset_player() {
		player = 1;
		player_symbol = 'X';
	}

	// Calls all reset functions and resets board/game to original state
	void restart_game() {
		obj1.reset_board();//Reset board
		reset_in_use_array();//Reset in use characters
		reset_player();//Reset the player back to player 1
		new_game = true;//Turn new game variable to true
	}
};


int main() {
	// Create variables to allow user to play game multiple times
	string input = "";
	bool play_again;

	// Create game object
	Game object;

	// Loop that allows the game to be played multiple times
	do {
		
		play_again = false;//Sets play_again to false to prevent infinite loop of playing again

		object.run_game();//Function call that actually plays the game

		// If the user quit mid game, this prevents the user from being given the 
		// option to play again
		if (object.quit_game == true) {
			break;
		}

		// Gets input from the user to see if they would like to play again
		// will only be asked if the game ended in a win/draw
		cout << "\nWould you like to play again? Enter 'p' or 'P' to play again." << endl;
		cout << "Enter anything else to quit.\n" << endl;
		getline(cin, input);

		// The user wanted to play again if they entered a p, anything else prints 
		// a terminate message
		if ((input == "p" || input == "P")) {
			play_again = true;
		}
		else {
			cout << "You have chosen to terminate the game. Thanks for playing!" << endl;
		}

	} while (play_again == true);//Plays another game if play_again is set to true
	
	return 0;
}
#include<iostream>
using namespace std; 


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
	// q/Q = quit   p/P = Play
	char acceptable_chars[13] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 'q', 'Q', 'p', 'P' };


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
	}

	//Updates the player from X->O & O->X
	void update_player(int p) {
		if (p == 1) {
			player_number = 1;
			player_symbol = 'X';
		}
		else {
			player_number = 2;
			player_symbol = 'O';
		}
	}
	//returns the player
	char getplayer() {
		return player_symbol;
	}

	// declare function to update board_spots : This could also serve as the check 
	bool update_board_spots(char input_value) {
		if (input_value == 'q' || input_value == 'Q') {//checks to see if the 
			isFinished();
		}
		else if (isFinished() == true && input_value=='p'|| input_value=='p') {
			reset();
		}
		else {
			for (int i = 0; i < 9; i++) {
				if (board_spots[i] == input_value) {
					if (input_value == 'X'|| input_value == 'x') {//checks to see if they picked the same spot as someone else 
						cout << "you can't choose someone elses spot, pick a number!" << endl;
						return false;
					}
					else if (input_value == 'O'|| input_value=='o') {//checks to see if they picked the same spot as someone else
						cout << "you can't choose someone elses spot, pick a number!" << endl;
						return false;
					}
					else {
						board_spots[i] = player_symbol;
						return true;
					}
				}
			}//end for loop //cycle through to player selection and input their symbol
		}
		
	}

	//resets the game you select 'play again'
	void reset() {
		for (char i = '1'; i < ':'; i++) {
			board_spots[i - 49] = i;
		}
	}

	bool isFinished() {
		//if player one gets three X's across top row they win
		if ((board_spots[0] == 'X') && (board_spots[1] == 'X') && (board_spots[2] == 'X')) {
			cout << "Player 1 has won.\n";
			return true;
		}
		//if player one gets three X's from top left corner dianonally to the right they win
		else if ((board_spots[0] == 'X') && (board_spots[4] == 'X') && (board_spots[8] == 'X')) {
			cout << "Player 1 has won.\n";
			return true;
		}
		//if player one gets three X's from top right corner dianonally to the left they win
		else if ((board_spots[2] == 'X') && (board_spots[4] == 'X') && (board_spots[6] == 'X')) {
			cout << "Player 1 has won.\n";
			return true;
		}
		//if player one gets three O's across top row they win
		else if ((board_spots[0] == 'O') && (board_spots[1] == 'O') && (board_spots[2] == 'O')) {
			cout << "Player 2 has won.\n";
			return true;
		}
		//if player one gets three O's from top left corner dianonally to the right they win
		else if ((board_spots[0] == 'O') && (board_spots[4] == 'O') && (board_spots[8] == 'O')) {
			cout << "Player 2 has won.\n";
			return true;
		}
		//if player one gets three O's from top right corner dianonally to the left they win
		else if ((board_spots[2] == 'O') && (board_spots[4] == 'O') && (board_spots[6] == 'O')) {
			cout << "Player 2 has won.\n";
			return true;
		}

		else
			return false;
		
		//this will determine if the game is finished all checks will be considered. 
	}
};

// Class to represent playing a game of TicTacToe
class Game {
public:
	Board obj1;
	int player = 1;
	char input = '|';
	//Game script
	void starting_script() {

		cout << "Welcome to Tick Tac Toe"<<endl;
		//whole game will loop as long as it is not done. 
		while (obj1.isFinished() == false) {
			obj1.show_board();
			
		jump://this is for when the check happens
			cout << "Player " << obj1.getplayer()<< " enter move (1-9): ";
			cin >> input;
			if (obj1.update_board_spots(input) == false) {
				goto jump;
			}
			//------------at the end of each loop these need to be updated-----
			player = -player;
			obj1.update_player(player);
			//if (obj1.isFinished() == true) {

			//}

		}//end while
	}//end void starting script

};


int main() {
	// create a char that can be used as the user input variable
	/*char input_value = '|';

	// Create a board object
	Board object1;
	object1.show_board();

	// Get the spot the user would like to place their symbol in
	// validate that the input value is a space on the board
	cin >> input_value;

	// Update the board with the player's symbol
	object1.update_board_spots(input_value);
	object1.show_board();
	*/
	Game object;

	object.starting_script();

	return 0;

}

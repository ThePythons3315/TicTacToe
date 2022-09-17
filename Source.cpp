#include<iostream>
using namespace std; 



class Board {
public:



	char space1 = '*';
	char space2 = '*';
	char space3 = '*';
	char space4 = '*';
	char space5 = '*';
	char space6 = '*';
	char space7 = '*';
	char space8 = '*';
	char space9 = '*';

	void charInputCheck() {

		//here we will check to see if the char input is valid and does not over write what is already there. 

	}

	void numInputCheck() {

		//here we will check to see if the number is valid and does not over write what is already here 

	}

	Board() {

		cout << space1 << "|" << space2 << "|" << space3 << endl;
		cout << "_|_|_" << endl;
		cout << space4 << "|" << space5 << "|" << space6 << endl;
		cout << "_|_|_" << endl;
		cout << space7 << "|" << space8 << "|" << space9 << endl;
		cout << " | | " << endl;

	}

	Board(char, int, int) {

		//This will be user input and put things where they need to be in the board. 
	}

	bool isFinished() {

		//here is where we would be checking to see if the game is over. 
		return true;
	}

	void gameReset() {

		//reset all base values to way they were before 
	}

};

int main() {
	Board* game{};

	char inputL;
	int inputN;
	int toggle = 1;

	while (game->isFinished() == false) {
		Board();
	jump1:

		cout << "Input which row:       (A, B, C)" << endl;
		cin >> inputL;
		game->charInputCheck();//This should check and send back to "jump1" if it is invalid


	jump2:
		cout << "Input which column:     (1, 2, 3)" << endl;
		cin >> inputN;
		game->numInputCheck();//This should check and send back to jump2 if it is invalid

		Board(inputL, inputN, toggle);
		toggle = -toggle;

	}	//game is ended



	return 0;

}
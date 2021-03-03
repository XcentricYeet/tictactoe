#include <iostream>
#include <stdio.h>

void printBoard(char board[]);
bool checkWin(char board[], char ID);
void localGame();
int AI(char board[], char ID, char playerID);
void AIGame();

int main() {
	int style=0;
	std::cout << "Would you like to play against another player (1) or against an AI (2)?" << std::endl;
	std::cin >> style;

	try {
		if(style==1) {
			localGame();
		} else if(style==2) {
			AIGame();
		} else {
			std::cout << "Error... Please make sure to choose either 1 or 2!" << std::endl;
		}
	} catch (...) {
		std::cout << "Error... Please make sure you entered an integer value!" << std::endl;
	}
}

void printBoard(char board[]) {
	std::cout << "\n       ||       ||       \n   " << board[0] << "   ||   " << board[1] << "   ||   " << board[2] << "\n       ||       ||       \n-------------------------\n-------------------------\n       ||       ||       \n   " << board[3] << "   ||   " << board[4] << "   ||   " << board[5] << "   \n       ||       ||       \n-------------------------\n-------------------------\n       ||       ||       \n   " << board[6] << "   ||   " << board[7] << "   ||   " << board[8] << "   \n       ||       ||       \n" << std::endl;
}

bool checkWin(char board[], char ID) {
	if((board[0]==ID && board[1]==ID && board[2]==ID) || (board[3]==ID && board[4]==ID && board[5]==ID) || (board[6]==ID && board[7]==ID && board[8]==ID) || (board[0]==ID && board[3]==ID && board[6]==ID) || (board[1]==ID && board[4]==ID && board[7]==ID) || (board[2]==ID && board[5]==ID && board[8]==ID) || (board[0]==ID && board[4]==ID && board[8]==ID) || (board[2]==ID && board[4]==ID && board[6]==ID)) {
		return true;
	}
	return false;
}

void localGame() {
	char board[9] = "        ";
	board[8] = ' ';
	char ID = 'x';
	int i=0;
	bool win = false;
	while(i<9) {
		printBoard(board);
		int move;
		std::cout << "player " << ID << "'s turn\nenter a number(1-9)" << std::endl;
		std::cin >> move;

		try {
			if(move>=1 && move<=9) {
				if(board[move-1]!= ' ') {
					std::cout << "That spot is occupied!" << std::endl;
				} else {
					board[move-1] = ID;
					if(checkWin(board, ID)) {
						win=true;
						break;
					}
					if(ID == 'x') {
						ID = 'y';
					} else {
						ID = 'x';
					}
					i++;
				}
			} else {
				std::cout << "That number does not correlate to a space on the board" << std::endl;
			}
		} catch (...) {
			std::cout << "Error... Please make sure you entered an integer value!" << std::endl;
		}
	}

	std::cout << "Printing finalized board..." << std::endl;
	printBoard(board);
	if(!win){
		std::cout << "This game resulted in a tie! Nobody wins!";
	} else {
		std::cout << "Player " << ID << " has won the game!";
	}
}

int AI(char board[], char ID, char playerID) {
	if((board[0]==' ' && (board[1]==ID||board[1]==playerID) && (board[2]==ID || board[2]==playerID)) || (board[0]==' ' && (board[4]==ID || board[4]==playerID) && (board[8]==ID || board[8]==playerID)) || (board[0]==' ' && (board[3]==ID || board[3]==playerID) && (board[6]==ID || board[6]==playerID))) {
		return 1;
	}
}

void AIGame() {
	char board[9] = "        ";
	board[8] = ' ';
	char ID = 'x';
	char playerID = ' ';
	int i=0;
	bool win = false;

	std::cout << "Would you rather be x or o?" << std::endl;
	std::cin >> playerID;

	try {
		if(playerID!='x' && playerID!='o') {
			std::cout << "Error... Please make sure to choose a valid option" << std::endl;
			return;
		}
	} catch(...) {
		std::cout << "Error... Please make sure to choose a valid option" << std::endl;
		return;
	}

	while(i<9) {
		printBoard(board);
		int move=0;
		std::cout << "player " << ID << "'s turn\nenter a number(1-9)" << std::endl;
		if(ID==playerID) {
			std::cin >> move;
		} else {
			move = AI(board, ID, playerID);
		}

		try {
			if(move>=1 && move<=9) {
				if(board[move-1]!= ' ') {
					std::cout << "That spot is occupied!" << std::endl;
				} else {
					board[move-1] = ID;
					if(checkWin(board, ID)) {
						win=true;
						break;
					}
					if(ID == 'x') {
						ID = 'y';
					} else {
						ID = 'x';
					}
					i++;
				}
			} else {
				std::cout << "That number does not correlate to a space on the board" << std::endl;
			}
		} catch (...) {
			std::cout << "Error... Please make sure you entered an integer value!" << std::endl;
		}
	}

	std::cout << "Printing finalized board..." << std::endl;
	printBoard(board);
	if(!win){
		std::cout << "This game resulted in a tie! Nobody wins!";
	} else if(ID==playerID) {
		std::cout << "You won the game!";
	} else {
		std::cout << "The AI won the game!";
	}
}

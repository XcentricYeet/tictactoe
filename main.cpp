#include <iostream>
#include <stdio.h>

void printBoard(char board[]); //prints out the gameboard
bool checkWin(char board[], char ID); //checks if a player has won
void localGame(); //game with 2 players
int AI(char board[], char ID, char playerID); //basic AI for tictactoe, fairly easy to beat
void AIGame(); //game against an AI

/*
* Main function
* Choose what gamemode to play
* plays the game
*/
int main() {
	int style=0;
	//chooses gamemode
	std::cout << "Would you like to play against another player (1) or against an AI (2)?" << std::endl;
	std::cin >> style;
	//plays game
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

/*
* prints out the game board, looks like:
*       ||       ||       
*	||       ||
*	||       ||
*-------------------------
*-------------------------
*       ||       ||       
*	||       ||
*	||       ||
*-------------------------
*-------------------------
*       ||       ||       
*	||       ||
*	||       ||	   
*/
void printBoard(char board[]) {
	std::cout << "\n       ||       ||       \n   " << board[0] << "   ||   " << board[1] << "   ||   " << board[2] << "\n       ||       ||       \n-------------------------\n-------------------------\n       ||       ||       \n   " << board[3] << "   ||   " << board[4] << "   ||   " << board[5] << "   \n       ||       ||       \n-------------------------\n-------------------------\n       ||       ||       \n   " << board[6] << "   ||   " << board[7] << "   ||   " << board[8] << "   \n       ||       ||       \n" << std::endl;
}

/*
* checks if a player has won by manually checking each box
*/
bool checkWin(char board[], char ID) {
	if((board[0]==ID && board[1]==ID && board[2]==ID) || (board[3]==ID && board[4]==ID && board[5]==ID) || (board[6]==ID && board[7]==ID && board[8]==ID) || (board[0]==ID && board[3]==ID && board[6]==ID) || (board[1]==ID && board[4]==ID && board[7]==ID) || (board[2]==ID && board[5]==ID && board[8]==ID) || (board[0]==ID && board[4]==ID && board[8]==ID) || (board[2]==ID && board[4]==ID && board[6]==ID)) {
		return true;
	}
	return false;
}

/*
* plays a game with two players
*/
void localGame() {
	char board[9] = "        ";
	board[8] = ' ';
	char ID = 'x';
	int i=0;
	bool win = false;
	while(i<9) {
		printBoard(board);
		//gets the player's move
		int move;
		std::cout << "player " << ID << "'s turn\nenter a number(1-9)" << std::endl;
		std::cin >> move;
		//makes the move
		try {
			if(move>=1 && move<=9) { //checks to see if the move is an actual space on the board
				if(board[move-1]!= ' ') { //checks if the move is available
					std::cout << "That spot is occupied!" << std::endl;
				} else {
					board[move-1] = ID; //makes the move
					if(checkWin(board, ID)) { //checks if someone wins after this move is played
						win=true;
						break;
					}
					if(ID == 'x') { //switches the turn
						ID = 'o';
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
	//prints the results
	std::cout << "Printing finalized board..." << std::endl;
	printBoard(board);
	if(!win){ //checks for a tie
		std::cout << "This game resulted in a tie! Nobody wins!";
	} else { //if there is no tie, then the last ID used won the game based on the checkWin function
		std::cout << "Player " << ID << " has won the game!";
	}
}

/*
* basic AI for tictactoe
* checks for a possible win/loss this turn in order to complete the win or try to prevent a loss
* moves to the middle spot (5) if available
* if this spot is not available, it plays at the first available spot
*/
int AI(char board[], char ID, char playerID) {
	if((board[0]==' ' && board[1]==ID && board[2]==ID) || (board[0]==' ' && board[1]==playerID && board[2]==playerID) || (board[0]==' ' && board[4]==ID && board[8]==ID) || (board[0]==' ' && board[4]==playerID && board[8]==playerID) || (board[0]==' ' && board[3]==ID && board[6]==ID) || (board[0]==' ' && board[3]==playerID && board[6]==playerID)) {
		return 1;
	} else if ((board[0]==ID && board[1]==' ' && board[2]==ID) || (board[0]==playerID && board[1]==' ' && board[2]==playerID) || (board[1]==' ' && board[4]==ID && board[7]==ID) || (board[1]==' ' && board[4]==playerID && board[7]==playerID)) {
		return 2;
	} else if(((board[2]==' ' && board[1]==ID && board[0]==ID) || (board[2]==' ' && board[1]==playerID && board[0]==playerID) || (board[2]==' ' && board[4]==ID && board[6]==ID) || (board[0]==' ' && board[4]==playerID && board[6]==playerID) || (board[2]==' ' && board[5]==ID && board[8]==ID) || (board[2]==' ' && board[5]==playerID && board[8]==playerID))) {
		return 3;
	} else if((board[3]==' ' && board[4]==ID && board[5]==ID) || (board[3]==' ' && board[4]==playerID && board[5]==playerID) || (board[0]==ID && board[3]==' ' && board[6]==ID) || (board[0]==playerID && board[3]==' ' && board[6]==playerID)) {
		return 4;
	} else if(board[4]==' ') {
		return 5;
	} else if((board[5]==' ' && board[4]==ID && board[3]==ID) || (board[5]==' ' && board[4]==playerID && board[3]==playerID) || (board[5]==' ' && board[2]==ID && board[8]==ID) || (board[5]==' ' && board[2]==playerID && board[8]==playerID)) {
		return 6;
	} else if((board[6]==' ' && board[7]==ID && board[8]==ID) || (board[6]==' ' && board[7]==playerID && board[8]==playerID) || (board[6]==' ' && board[4]==ID && board[2]==ID) || (board[6]==' ' && board[4]==playerID && board[2]==playerID) || (board[6]==' ' && board[3]==ID && board[2]==ID) || (board[6]==' ' && board[3]==playerID && board[2]==playerID)) {
		return 7;
	} else if((board[7]==' ' && board[6]==ID && board[8]==ID) || (board[7]==' ' && board[6]==playerID && board[8]==playerID) || (board[7]==' ' && board[4]==ID && board[1]==ID) || (board[7]==' ' && board[4]==playerID && board[1]==playerID)) {
		return 8;
	} else if((board[8]==' ' && board[7]==ID && board[6]==ID) || (board[8]==' ' && board[7]==playerID && board[6]==playerID) || (board[8]==' ' && board[5]==ID && board[2]==ID) || (board[8]==' ' && board[5]==playerID && board[2]==playerID) || (board[8]==' ' && board[4]==ID && board[0]==ID) || (board[8]==' ' && board[4]==playerID && board[0]==playerID)) {
		return 9;
	} else {
		for(int i=0; i<9; i++) {
			if(board[i]==' ') {
				return i+1;
			}
		}
	}
	return 0;
}

/*
* plays a game against an AI
*/
void AIGame() {
	char board[9] = "        ";
	board[8] = ' ';
	char ID = 'x';
	char playerID = ' ';
	int i=0;
	bool win = false;
	//collects the playerID
	std::cout << "Would you rather be x or o?" << std::endl;
	std::cin >> playerID;
	//checks to make sure the playerID is an available ID
	try {
		if(playerID!='x' && playerID!='o') {
			std::cout << "Error... Please make sure to choose a valid option" << std::endl;
			return;
		}
	} catch(...) {
		std::cout << "Error... Please make sure to choose a valid option" << std::endl;
		return;
	}
	//plays the game
	while(i<9) {
		//collects the move
		printBoard(board);
		int move=0;
		std::cout << "player " << ID << "'s turn\nenter a number(1-9)" << std::endl;
		if(ID==playerID) { //checks for if its the player's turn or the AI's
			std::cin >> move;
		} else {
			move = AI(board, ID, playerID);
		}
		//makes the move
		try {
			if(move>=1 && move<=9) { //checks to see if the move is an actual spot on the board
				if(board[move-1]!= ' ') { //checks if the move is available
					std::cout << "That spot is occupied!" << std::endl;
				} else { //makes the move
					board[move-1] = ID;
					if(checkWin(board, ID)) { //checks for if someone won
						win=true;
						break;
					}
					if(ID == 'x') { //switches the ID
						ID = 'o';
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
	//prints results
	std::cout << "Printing finalized board..." << std::endl;
	printBoard(board);
	if(!win){ //checks for a tie
		std::cout << "This game resulted in a tie! Nobody wins!";
	} else if(ID==playerID) { //checks if the player won the game
		std::cout << "You won the game!";
	} else { //checks if the AI won the game
		std::cout << "The AI won the game!";
	}
}

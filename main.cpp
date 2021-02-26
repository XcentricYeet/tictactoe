#include <iostream>
#include <stdio.h>

void printBoard(char board[]);
void checkWin();

int main() {
	char board[9] = "        ";
	board[8] = ' ';
	char ID = 'x';
	int i=0;
	while(i<9) {
		printBoard(board);
		int move;
		std::cout << "player " << ID << "'s turn\nenter a number(1-9)" << std::endl;
		std::cin >> move;
		if(move>=1 && move<=9) {
			if(board[move-1]!= ' ') {
				std::cout << "That spot is occupied!" << std::endl;
			} else {
				board[move-1] = ID;
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
	}
}

void printBoard(char board[]) {
	std::cout << "       ||       ||       \n   " << board[0] << "   ||   " << board[1] << "   ||   " << board[2] << "\n       ||       ||       \n-------------------------\n-------------------------\n       ||       ||       \n   " << board[3] << "   ||   " << board[4] << "   ||   " << board[5] << "   \n       ||       ||       \n-------------------------\n-------------------------\n       ||       ||       \n   " << board[6] << "   ||   " << board[7] << "   ||   " << board[8] << "   \n       ||       ||       " << std::endl;
}

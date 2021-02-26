#include <iostream>
#include <stdio.h>

void printBoard(char board[]);

int main() {
	char board[9] = "        ";
	char ID = 'x';
	printBoard(board);
}

void printBoard(char board[]) {
	std::cout << "       ||       ||       \n   " << board[0] << "   ||   " << board[1] << "   ||   " << board[2] << "\n       ||       ||       \n-------------------------\n-------------------------\n       ||       ||       \n   " << board[3] << "   ||   " << board[4] << "   ||   " << board[5] << "   \n       ||       ||       \n-------------------------\n-------------------------\n       ||       ||       \n   " << board[6] << "   ||   " << board[7] << "   ||   " << board[8] << "   \n       ||       ||       " << std::endl;
}

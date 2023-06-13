/*
* Name: Bobby Parsons
* Date: 9/1/21
* Email: rfparsons@dmacc.edu
* 
* Description: Program to play a game of tic-tac-toe against another human
*/

#include <array>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<vector<int>> moveList = { {}, {} };

    array<char, 2> mark = { 'X','O' };
    array<char, 9> board = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
    int move = 0;
    const int MAXMOVES = 9;

    for (int turn = 0; turn < MAXMOVES; turn++) {
        // draw the board
        cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
        cout << " -----------" << endl;
        cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
        cout << " -----------" << endl;
        cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
        // get the next move
        cout << endl << "Player " << (turn % 2) + 1 << " select a cell (1 - 9):" << endl;
        cin >> move;
        if (board[move - 1] != ' ') {
            cout << "Sorry but that cell is taken! You lose the game." << endl;
            turn = MAXMOVES;
        }
        else { board[move - 1] = mark[turn % 2]; }

        moveList[turn % 2].push_back(move);
    }
    cout << "Game Over" << endl;

    cout << "Review of player 1 moves: " << endl;
    for (int i = 0; i < moveList[0].size(); i++) {
        cout << moveList[0][i];
        if (i == moveList[0].size() - 1) {
            cout << endl;
        }
        else {
            cout << ", ";
        }
    }

    cout << "Review of player 2 moves: " << endl;
    for (int i = 0; i < moveList[1].size(); i++) {
        cout << moveList[1][i];
        if (i == moveList[1].size() - 1) {
            cout << endl;
        }
        else {
            cout << ", ";
        }
    }

    return 0;
}
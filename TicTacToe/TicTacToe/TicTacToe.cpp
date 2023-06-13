/*
* Name: Bobby Parsons
* Date: 9/1/21
* Email: rfparsons@dmacc.edu
* 
* Description: Program to play a game of tic-tac-toe against another human
*/

#include <iostream>
using namespace std;

int main() {

    char mark[] = { 'X','O' };
    char board[] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
    int move = 0;
    int winner = 0;
    const int MAXMOVES = 9;

    for (int turn = 0; turn < MAXMOVES; turn++) {

        //draw the board
        cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
        cout << " -----------" << endl;
        cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
        cout << " -----------" << endl;
        cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;

        // get next move
        cout << endl << "Player " << (turn % 2) + 1 << " select cell (1 - 9)" << endl;
        cin >> move;

        if (board[move - 1] != ' ') {
            cout << "Sorry but that cell is taken! You lose the game." << endl;
            winner = (-1 * ((turn % 2) - 1)) + 1; //sets the other player as the winner
            turn = MAXMOVES;
        }
        else
        {
            board[move - 1] = mark[turn % 2];
        }

        //Added code to check for a winner:
        //only run the following code after the 3rd turn
        if (turn >= 2) {
            // check the verticals
            for (int i = 0; i < 3; i++) {
                if (board[i] == board[i + 3] && board[i + 3] == board[i + 6] && board[i] != ' ') {
                    turn = MAXMOVES;
                    if (board[i] == 'X') {
                        winner = 1;
                    }
                    else {
                        winner = 2;
                    }
                }
            }

            // check the horizontals
            for (int i = 0; i < 7; i+=3) {
                if (board[i] == board[i + 1] && board[i + 1] == board[i + 2] && board[i] != ' ') {
                    turn = MAXMOVES;
                    if (board[i] == 'X') {
                        winner = 1;
                    }
                    else {
                        winner = 2;
                    }
                }
            }

            //check the diagonals
            if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ') {
                turn = MAXMOVES;
                if (board[0] == 'X') {
                    winner = 1;
                }
                else {
                    winner = 2;
                }
            }
            if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ') {
                turn = MAXMOVES;
                if (board[2] == 'X') {
                    winner = 1;
                }
                else {
                    winner = 2;
                }
            }
        }
    }

    if (winner != 0) {
        cout << "Player " << winner << " wins!" << endl;
    }
    else {
        cout << "Tie game!" << endl;
    }

    cout << "Game Over." << endl;
    return 0;

}

/*
* Testing:
   |   |
 -----------
   |   |
 -----------
   |   |

Player 1 select cell (1 - 9)
1
 X |   |
 -----------
   |   |
 -----------
   |   |

Player 2 select cell (1 - 9)
6
 X |   |
 -----------
   |   | O
 -----------
   |   |

Player 1 select cell (1 - 9)
2
 X | X |
 -----------
   |   | O
 -----------
   |   |

Player 2 select cell (1 - 9)
7
 X | X |
 -----------
   |   | O
 -----------
 O |   |

Player 1 select cell (1 - 9)
3
Player 1 wins!
Game Over.
----------------------------
   |   |
 -----------
   |   |
 -----------
   |   |

Player 1 select cell (1 - 9)
1
 X |   |
 -----------
   |   |
 -----------
   |   |

Player 2 select cell (1 - 9)
2
 X | O |
 -----------
   |   |
 -----------
   |   |

Player 1 select cell (1 - 9)
3
 X | O | X
 -----------
   |   |
 -----------
   |   |

Player 2 select cell (1 - 9)
5
 X | O | X
 -----------
   | O |
 -----------
   |   |

Player 1 select cell (1 - 9)
4
 X | O | X
 -----------
 X | O |
 -----------
   |   |

Player 2 select cell (1 - 9)
8
Player 2 wins!
Game Over.
----------------------------
   |   |
 -----------
   |   |
 -----------
   |   |

Player 1 select cell (1 - 9)
1
 X |   |
 -----------
   |   |
 -----------
   |   |

Player 2 select cell (1 - 9)
2
 X | O |
 -----------
   |   |
 -----------
   |   |

Player 1 select cell (1 - 9)
5
 X | O |
 -----------
   | X |
 -----------
   |   |

Player 2 select cell (1 - 9)
3
 X | O | O
 -----------
   | X |
 -----------
   |   |

Player 1 select cell (1 - 9)
9
Player 1 wins!
Game Over.
----------------------------
   |   |
 -----------
   |   |
 -----------
   |   |

Player 1 select cell (1 - 9)
1
 X |   |
 -----------
   |   |
 -----------
   |   |

Player 2 select cell (1 - 9)
3
 X |   | O
 -----------
   |   |
 -----------
   |   |

Player 1 select cell (1 - 9)
2
 X | X | O
 -----------
   |   |
 -----------
   |   |

Player 2 select cell (1 - 9)
5
 X | X | O
 -----------
   | O |
 -----------
   |   |

Player 1 select cell (1 - 9)
4
 X | X | O
 -----------
 X | O |
 -----------
   |   |

Player 2 select cell (1 - 9)
7
Player 2 wins!
Game Over.
*/
/*Name : Fish Wars Group
Date : 9/28/2021
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;


int decideRoundWinner(string player_move, string computer_move, int player_bonus, int computer_bonus) {
    int winner = 0;

    // TODO: Winner logic

    return winner;
}

void assignCards(vector<string> &player_hand, vector<string> &computer_hand, vector<string> &deck) {
    int card;
    int fullDeckSize = deck.size();

    for (int i = 0; i < fullDeckSize; i++) {
        card = rand() % deck.size();

        if (i % 2 == 0) { //switches between dealing to the player and to the computer
            player_hand.push_back(deck[card]);
        }
        else {
            computer_hand.push_back(deck[card]);
        }

        deck.erase(deck.begin() + card); // deletes the element at position "card"
    }
}


int main() {
    bool playAgain = true;

    while (playAgain != false) {
        // Setup
        //vector<string> player_hand = { "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0" };
        //vector<string> computer_hand = { "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0" };
        vector<string> player_hand = {  };
        vector<string> computer_hand = {  };
        vector<string> cards = { "1", "1", "1", "2", "2", "2", "3", "3", "3", "4", "4", "5", "5", "6", "6", "7", "7", "8", "8", "9", "9", "10", "10", "peace", "peace", "shark" };

        assignCards(player_hand, computer_hand, cards);

        int player_score = 0;
        int player_bonus = 0;

        int computer_score = 0;
        int computer_bonus = 0;

        int player_move;
        int computer_move;

        // Round start
        for (int i = 0; i < 13; i++) {
            // Get location of user move
            for (int j = 0; j < player_hand.size(); j++) {
                cout << j + 1 << ". " << player_hand.at(j) << "   ";
            }
            cout << endl << "Enter the number of card you want to play: ";
            cin >> player_move;
            player_move -= 1;

            // Get location of computer move
            computer_move = rand() % (computer_hand.size() - 1);

            // Decide winner
            int round_winner = decideRoundWinner(player_hand.at(player_move), computer_hand.at(computer_move), player_bonus, computer_bonus);

            // Update score and display result
            if (round_winner == 0) {
                // tie
                //TODO: determine if battle bonus needs to be set to 0
                cout << "Tie!\n" << endl;
                cout << "Player score: " << player_score << " Computer Score: " << computer_score << "\n" << endl;
            }
            else if (round_winner == 1) {
                // Player wins
                player_score += 1;
                player_bonus += 1;
                cout << "Player wins this round!\n" << endl;
                cout << "Player score: " << player_score << " Computer Score: " << computer_score << "\n" << endl;

            }
            else {
                // Computer wins
                computer_score += 1;
                computer_bonus += 1;
                cout << "Computer wins this round!\n" << endl;
                cout << "Player score: " << player_score << " Computer Score: " << computer_score << "\n" << endl;
            }

            //remove cards from hands
            player_hand.erase(player_hand.begin() + player_move, player_hand.begin() + player_move + 1);
            computer_hand.erase(computer_hand.begin() + computer_move, computer_hand.begin() +computer_move + 1);

        }

        // Replay the game?
        string choice;
        cout << "Would you like to play again? (y for yes, n for no): ";
        cin >> choice;
        if (choice == "n") {
            playAgain = false;
        }
    }

    return 0;
}
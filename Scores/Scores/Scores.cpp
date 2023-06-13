/*
* Name: Bobby Parsons
* Date: 10/9/21
* Email: rfparsons@dmacc.edu
*
* Description: Uses a dynamically-allocated array to collect scores and display
* the record of a sports team
* 
* Dynamically allocated arrays are useful to save on memory and allow a little
* more flexibility than standard arrays. However, with the availibility of the 
* vector class, it doesn't seem strictly necessary to use in modern C++ 
* programming. On the other hand, if resources are tight or the whole standard
* library is unavailable, dynamic arrays are a great tool to know.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int* teamScores;
    int* opponentScores;
    int games;
    int wins = 0;
    int losses = 0;
    int ties = 0;
    int diff = 0;
    int biggestWin;
    int biggestDiff = INT_MIN; // hopefully you don't lose by more than 2.1 billion points every game

    double record;

    cout << "How many games were played? ";
    cin >> games;

    teamScores = new int[games];
    opponentScores = new int[games];

    for (int i = 0; i < games; i++) {
        cout << "Enter team's score for game " << i + 1 << ": ";
        cin >> teamScores[i];
        cout << "Enter opponent's score for game " << i + 1 << ": ";
        cin >> opponentScores[i];

        diff += teamScores[i] - opponentScores[i]; // calculate point differential

        if (biggestDiff < teamScores[i] - opponentScores[i]) {
            biggestDiff = teamScores[i] - opponentScores[i];

            biggestWin = i;
        }

        if (teamScores[i] > opponentScores[i]) {
            wins++;
        }
        else if (teamScores[i] < opponentScores[i]) {
            losses++;
        }
        else {
            ties++;
        }
    }

    // count ties as half a win
    record = (wins + (ties / 2.0)) / games;

    cout << "Your team went " << wins << "-" << losses;

    // only show a number of ties if there is one
    if (ties > 0) {
        cout << "-" << ties;
    }

    cout << " (" << fixed << setprecision(3) << record;
    cout << ") with a point differential of " << diff << "." << endl;

    if (record != 0.0) { // don't display this if they lost every game
        cout << "Your biggest win was game " << biggestWin + 1;
        cout << " where the score was " << teamScores[biggestWin] << "-" << opponentScores[biggestWin] << endl;
    }

    delete [] teamScores;
    delete [] opponentScores;

    return 0;
}

/*
How many games were played? 6
Enter team's score for game 1: 12
Enter opponent's score for game 1: 5
Enter team's score for game 2: 21
Enter opponent's score for game 2: 22
Enter team's score for game 3: 23
Enter opponent's score for game 3: 23
Enter team's score for game 4: 5
Enter opponent's score for game 4: 4
Enter team's score for game 5: 9
Enter opponent's score for game 5: 3
Enter team's score for game 6: 7
Enter opponent's score for game 6: 2
Your team went 4-1-1 (0.750) with a point differential of 18.
Your biggest win was game 1 where the score was 12-5
*/
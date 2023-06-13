/*
* Name: Bobby Parsons
* Date: 10/15/21
* Email: rfparsons@dmacc.edu
*
* Description: Improperly accesses memory through a pointer and overwrites it
*/

#include <iostream>

using namespace std;

int main()
{
    char* badArr = new char;
    char name[5] = { 'B','O','B','B','Y'}; //have to do this manually so the null terminator isn't there

    *badArr = 'B';

    cout << "Value of badArr: ";
    cout << badArr[0] << endl;

    cout << "Next kilobyte of memory:" << endl;

    for (int i = 1; i < 1025; i++) {
        cout << badArr[i] << " "; //references values in a non-existant array
    }

    cout << endl;

    cout << "Overwriting it with my name: " << endl;

    for (int i = 1; i < 1025; i++) {
        badArr[i] = name[i % 5];
    }

    cout << "Reading it back:" << endl;

    for (int i = 1; i < 1025; i++) {
        cout << badArr[i] << " ";
    }

    cout << endl;

    return 0; // if it hasn't crashed!
}

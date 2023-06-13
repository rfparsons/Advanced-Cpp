/*
* Name: Bobby Parsons
* Date: 10/23/21
* Email: rfparsons@dmacc.edu
*
* Description: Demonstrates a "max" function made with a template
*/

#include <iostream>
#include "util.h"

using namespace std;

int main()
{
    int num1 = 1;
    int num2 = 2;
    char char1 = 'a';
    char char2 = 'A';
    double dub1 = 10.127;
    double dub2 = 10.1099;

    cout << max(num1, num2) << endl;
    cout << max(char1, char2) << endl;
    cout << max(dub1, dub2) << endl;
}


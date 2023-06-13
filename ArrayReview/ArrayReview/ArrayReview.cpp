/*
* Name: Bobby Parsons
* Date: 9/10/21
* Email: rfparsons@dmacc.edu
*
* Description: Simple program reviewing c++ style arrays
*/

#include <iostream>
#include <array>

using namespace std;

const int SIZE = 9;

int main() {
	array<double, SIZE> arr;

	for (int i = 0; i < SIZE; i++) {
		cout << "Enter double #" << i + 1 << ": ";
		cin >> arr[i];
	}

	cout << "First double: " << arr[0] << endl;
	cout << "Middle double: " << arr[SIZE / 2] << endl;
	cout << "Last double: " << arr[SIZE - 1] << endl;
}
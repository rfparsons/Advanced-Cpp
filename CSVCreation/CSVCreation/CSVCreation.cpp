/*
* Name: Bobby Parsons
* Date: 9/24/21
* Email: frparsons@dmacc.edu
* 
* Takes an order and outputs it to a CSV
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	string sku;
	int quantity;
	double price;

	ofstream fout;

	fout.open("order.csv", ios::app);
	while (sku != "q") {
		cout << "SKU (q to quit): ";
		cin >> sku;
		if (sku != "q") {
			cout << "Quantity: ";
			cin >> quantity;
			cout << "Unit Price: ";
			cin >> price;

			fout << sku << "," << quantity << "," << fixed << setprecision(2) << price << endl;
		}
	}

	fout.close();
}

/*
SKU (q to quit): KS944RUR
Quantity: 2
Unit Price: 9.99
SKU (q to quit): AT222RUR
Quantity: 1
Unit Price: 1.00
SKU (q to quit): q

File:
KS944RUR,2,9.99
AT222RUR,1,1.00
*/
/*
* Name: Bobby Parsons
* Date: 9/12/21
* Email: rfparsons@dmacc.edu
*
* Description: CLI tool to take food orders and manage stock of a food truck
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <array>

using namespace std;

enum menu { BURGER, HOT_DOG, CHILI, FRIES, SODA, BURGER_BUNS, HOT_DOG_BUNS, ADD_CHILI = 5, END_ORDER = -1, CHECK_STOCK = 39, RESTOCK = 49, END_DAY = 98 };

const int MENU_ITEMS = 7;

const int MAX_STOCK[MENU_ITEMS] = {200, 200, 500, 75, 200, 75, 75};
//MAX_STOCK[BURGER] = 200;
//MAX_STOCK[HOT_DOG] = 200;
//MAX_STOCK[CHILI] = 500;
//MAX_STOCK[FRIES] = 75;
//MAX_STOCK[SODA] = 200;
//MAX_STOCK[BURGER_BUNS] = 75;
//MAX_STOCK[HOT_DOG_BUNS] = 75;

const string ITEM_NAMES[MENU_ITEMS] = { "Hamburger patties", "Hot dogs", "Ounces of chili", "Fry baskets", "Cans of soda", "Hamburger buns", "Hot dog buns"};
//ITEM_NAMES[BURGER] = "Hamburger patties";
//ITEM_NAMES[HOT_DOG] = "Hot dogs";
//ITEM_NAMES[CHILI] = "Ounces of chili";
//ITEM_NAMES[FRIES] = "Fry baskets";
//ITEM_NAMES[SODA] = "Cans of soda";
//ITEM_NAMES[BURGER_BUNS] = "Hamburger buns";
//ITEM_NAMES[HOT_DOG_BUNS] = "Hot dog buns";

const double BURGER_PRICE = 5;
const double HOT_DOG_PRICE = 5;
const double CHILI_PRICE = 4;
const double FRIES_PRICE = 7;
const double SODA_PRICE = 2;
const double ADD_CHILI_PRICE = 2;

const int CHILI_BOWL_AMOUNT = 12;
const int ADD_CHILI_AMOUNT = 4;

// prompt asked for items to no longer be sold when stock is "near zero", not sure where that should be
const int OUT_OF_STOCK_LIMIT = 3;

const double TAX = 0.05;

void enterStock(array<int, MENU_ITEMS> &stock);
void printStock(array<int, MENU_ITEMS>& stock);

int main() {
	bool finishedDay = false;
	bool finishedOrder = false;
	bool validInput = false;
	int selection;
	int ordersMade = 0;
	double subtotal;
	double total;
	double stockPercent;
	double dayTotal = 0;

	array<int, MENU_ITEMS> stock = { -1, -1, -1, -1, -1, -1, -1 };

	enterStock(stock);

	while (!finishedDay) {
		finishedOrder = false;
		subtotal = 0;
		while (!finishedOrder) {
			if (stock[BURGER] > OUT_OF_STOCK_LIMIT && stock[BURGER_BUNS] > OUT_OF_STOCK_LIMIT) {
				cout << "1. Hamburger" << endl;
			}
			if (stock[HOT_DOG] > OUT_OF_STOCK_LIMIT && stock[HOT_DOG_BUNS] > OUT_OF_STOCK_LIMIT) {
				cout << "2. Hot dog" << endl;
			}
			if (stock[CHILI] > CHILI_BOWL_AMOUNT) {
				cout << "3. Bowl of chili" << endl;
			}
			if (stock[FRIES] > OUT_OF_STOCK_LIMIT) {
				cout << "4. Basket of fries" << endl;
			}
			if (stock[SODA] > OUT_OF_STOCK_LIMIT) {
				cout << "5. Can of soda" << endl;
			}
			if (stock[CHILI] > ADD_CHILI_AMOUNT) {
				cout << "6. Add chili to hamburger, hot dog, or fries" << endl;
			}
			cout << endl;
			cout << "Enter \"0\" to end the order." << endl;
			cout << "Enter \"40\" to check the current stock." << endl;
			cout << "Enter \"50\" to enter new stock." << endl;
			cout << "Enter \"99\" if it's the end of the day." << endl;
			cin >> selection;

			switch (selection - 1) {
			case BURGER:
				if (stock[BURGER] > OUT_OF_STOCK_LIMIT && stock[BURGER_BUNS] > OUT_OF_STOCK_LIMIT) {
					stock[BURGER]--;
					stock[BURGER_BUNS]--;
					subtotal += BURGER_PRICE;
				}
				else {
					cout << "Out of stock!" << endl;
				}
				break;
			case HOT_DOG:
				if (stock[HOT_DOG] > OUT_OF_STOCK_LIMIT && stock[HOT_DOG_BUNS] > OUT_OF_STOCK_LIMIT) {
					stock[HOT_DOG]--;
					stock[HOT_DOG_BUNS]--;
					subtotal += HOT_DOG_PRICE;
				}
				else {
					cout << "Out of stock!" << endl;
				}
				break;
			case CHILI:
				if (stock[CHILI] > CHILI_BOWL_AMOUNT) {
					stock[CHILI] -= CHILI_BOWL_AMOUNT;
					subtotal += CHILI_PRICE;
				}
				else {
					cout << "Out of stock!" << endl;
				}
				break;
			case FRIES:
				if (stock[FRIES] > OUT_OF_STOCK_LIMIT) {
					stock[FRIES]--;
					subtotal += FRIES_PRICE;
				}
				else {
					cout << "Out of stock!" << endl;
				}
				break;
			case SODA:
				if (stock[SODA] > OUT_OF_STOCK_LIMIT) {
					stock[SODA]--;
					subtotal += SODA_PRICE;
				}
				else {
					cout << "Out of stock!" << endl;
				}
				break;
			case ADD_CHILI:
				if (stock[CHILI] > ADD_CHILI_AMOUNT) {
					stock[CHILI] -= ADD_CHILI_AMOUNT;
					subtotal += ADD_CHILI_PRICE;
				}
				else {
					cout << "Out of stock!" << endl;
				}
				break;
			case END_ORDER:
				total = subtotal + subtotal * TAX;
				dayTotal += total;
				ordersMade++;

				cout << "Subtotal: $" << fixed << setprecision(2) << subtotal << endl;
				cout << "Total: $" << fixed << setprecision(2) << total << endl;

				finishedOrder = true;

				cout << "Press Enter to continue";
				cin.ignore();
				cin.ignore(); // two ignores because the first one just ignores the existing contents of the buffer
				// and not getch() in case I move over to a Linux machine
				break;
			case CHECK_STOCK: // Added feature: Can check stock in the middle of a day
				printStock(stock);
				cout << "Press Enter to continue";
				cin.ignore();
				cin.ignore();
				break;
			case RESTOCK: // Added feature: Can restock in the middle of a day
				enterStock(stock);
				break;
			case END_DAY:
				finishedOrder = true;
				finishedDay = true;
				break;
			default:
				cout << "Invalid option!" << endl;
				//cin.clear(); //clear buffer to avoid a loop if a non-integer is entered
			}
		}
		for (int i = 0; i < MENU_ITEMS; i++) {
			stockPercent = (stock[i] * 1.0) / MAX_STOCK[i];
			if (stockPercent < 0.20) {
				cout << "Running low on " << ITEM_NAMES[i] << "!" << endl;
			}
		}
	}

	// Added feature: Readout of total for the day as well as orders taken
	cout << "Total amount made today: $" << fixed << setprecision(2) << dayTotal << endl;
	cout << "Total orders taken today: " << ordersMade << endl;
	printStock(stock);

	return 0;
}

void enterStock(array<int, MENU_ITEMS>& stock)
{
	bool validInput = false;
	int entry;

	for (int i = 0; i < MENU_ITEMS; i++) {
		while (!validInput) {
			if (stock[i] > 0)
			{
				cout << "Enter stock of " << ITEM_NAMES[i] << ": (current amount: " << stock[i] << ") ";
			}
			else {
				cout << "Enter stock of " << ITEM_NAMES[i] << ": ";
			}
			cin >> entry;

			if (entry <= MAX_STOCK[i] && entry >= 0) {
				validInput = true;
				stock[i] = entry;
			}
			else {
				cout << "Invalid amount of stock! Please enter a number between 0 and " << MAX_STOCK[i] << endl;
				//cin.clear(); //clear buffer to avoid a loop if a non-integer is entered
				//cin.ignore(INT_MAX, '\n');
			}
		}

		validInput = false;
	}
}

void printStock(array<int, MENU_ITEMS>& stock)
{
	for (int i = 0; i < MENU_ITEMS; i++) {
		cout << setfill('.');
		cout << setw(20) << left << ITEM_NAMES[i] << setw(3) << right << stock[i] << endl;
	}
}

/*
* Note: The menu has been removed after some inputs for readability.
* The menu is shown when it changes (such as when an item is removed)
Enter stock of Hamburger patties: 20
Enter stock of Hot dogs: 20
Enter stock of Ounces of chili: 20
Enter stock of Fry baskets: 20
Enter stock of Cans of soda: 20
Enter stock of Hamburger buns: 20
Enter stock of Hot dog buns: 20
1. Hamburger
2. Hot dog
3. Bowl of chili
4. Basket of fries
5. Can of soda
6. Add chili to hamburger, hot dog, or fries

Enter "0" to end the order.
Enter "40" to check the current stock.
Enter "50" to enter new stock.
Enter "99" if it's the end of the day.
1
1. Hamburger
2. Hot dog
3. Bowl of chili
4. Basket of fries
5. Can of soda
6. Add chili to hamburger, hot dog, or fries

Enter "0" to end the order.
Enter "40" to check the current stock.
Enter "50" to enter new stock.
Enter "99" if it's the end of the day.
3
1. Hamburger
2. Hot dog
4. Basket of fries
5. Can of soda
6. Add chili to hamburger, hot dog, or fries

Enter "0" to end the order.
Enter "40" to check the current stock.
Enter "50" to enter new stock.
Enter "99" if it's the end of the day.
4
0
Subtotal: $16.00
Total: $16.80
Press Enter to continue
Running low on Hamburger patties!
Running low on Hot dogs!
Running low on Ounces of chili!
Running low on Cans of soda!
40
Hamburger patties....19
Hot dogs.............20
Ounces of chili.......8
Fry baskets..........19
Cans of soda.........20
Hamburger buns.......19
Hot dog buns.........20
Press Enter to continue
50
Enter stock of Hamburger patties: (current amount: 19) 20
Enter stock of Hot dogs: (current amount: 20) 20
Enter stock of Ounces of chili: (current amount: 8) 20
Enter stock of Fry baskets: (current amount: 19) 20
Enter stock of Cans of soda: (current amount: 20) 20
Enter stock of Hamburger buns: (current amount: 19) 20
Enter stock of Hot dog buns: (current amount: 20) 20
1. Hamburger
2. Hot dog
3. Bowl of chili
4. Basket of fries
5. Can of soda
6. Add chili to hamburger, hot dog, or fries

Enter "0" to end the order.
Enter "40" to check the current stock.
Enter "50" to enter new stock.
Enter "99" if it's the end of the day.
2
6
5
0
Subtotal: $9.00
Total: $9.45
Press Enter to continue
Running low on Hamburger patties!
Running low on Hot dogs!
Running low on Ounces of chili!
Running low on Cans of soda!
99
Running low on Hamburger patties!
Running low on Hot dogs!
Running low on Ounces of chili!
Running low on Cans of soda!
Total amount made today: $26.25
Total orders taken today: 2
Hamburger patties....20
Hot dogs.............19
Ounces of chili......16
Fry baskets..........20
Cans of soda.........19
Hamburger buns.......20
Hot dog buns.........19
*/
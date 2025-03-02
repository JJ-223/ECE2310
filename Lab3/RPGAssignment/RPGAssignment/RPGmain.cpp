#include "RPG.h"
#include <iostream>
#include <string>
using namespace::std;

int main() {
	RPG player1;
	cout << "Player1 (Default Constructor) Details: \n";
	player1.printAll();
	cout << endl;

	string skills[] = { "water", "fire" };
	RPG player2("Icecream", 95, 15, 7, "mage", skills);
	cout << "Player2 (Overloaded Constructor) Details: \n";
	player2.printAll();
	cout << endl;
	
	cout << "Testing accessor functions: \n" << endl;
	player2.updateHealth(80);
	cout << "Player2 after updates: \n" << endl;
	cout << "Player2.isAlive: ";

	if (player2.isAlive())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	player2.printAll();
	cout << endl;

	return 0;
}
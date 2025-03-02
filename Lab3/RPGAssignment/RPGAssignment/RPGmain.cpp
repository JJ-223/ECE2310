#include "RPG.h"
#include <iostream>
#include <string>
using namespace::std;

int main() {
	RPG player1;
	cout << "Player1 (Default Constructor) Details: \n";
	player1.printAll();
	cout << endl;

	RPG player2("Icecream", 95, 15, 7, "mage");
	cout << "Player2 (Overloaded Constructor) Details: \n";
	player2.printAll();
	cout << endl;
	
	cout << "Testing accessor functions: \n" << endl;
	player2.updateHealth(80);
	cout << "Player2 after updates: \n" << endl;
	cout << player2.isAlive() << endl;
	player2.printAll();
	cout << endl;

	return 0;
}
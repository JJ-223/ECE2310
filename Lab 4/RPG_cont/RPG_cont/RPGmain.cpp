#include "RPG.h"
#include <iostream>
#include <string>
using namespace::std;

void displayStats(RPG player1, RPG player2) {
	printf("%s health: %i  /  %s health: %i\n", player1.getName().c_str(),
		player1.getHealth(), player2.getName().c_str(), player2.getHealth());
}

void displayEnd(RPG player1, RPG player2) {
	if (player1.isAlive())
		printf("%s defeated %s! Good game!\n", player1.getName().c_str(), player2.getName().c_str());
	else
		printf("%s defeated %s! Good game!\n", player2.getName().c_str(), player1.getName().c_str());
}

void gameLoop(RPG* player1, RPG* player2) {
	while (player1->isAlive() && player2->isAlive()) {
		displayStats(*player1, *player2);
		printf("%s's turn\n", player1->getName().c_str());
		player1->useSkill(player2);
		
		if (!player1->isAlive() || !player2->isAlive()) {
			printf("\n**********************************\n");
			displayStats(*player1, *player2);
			displayEnd(*player1, *player2);
			break;
		}
		printf("--------------------------------------\n");

		displayStats(*player1, *player2);
		printf("%s's turn\n", player2->getName().c_str());
		player2->useSkill(player1);

		if (!player1->isAlive() || !player2->isAlive()) {
			printf("\n**********************************\n");
			displayStats(*player1, *player2);
			displayEnd(*player1, *player2);
			break;
		}
		printf("--------------------------------------\n");
	}
}

int main() {
	string skills[] = { " ", " " };
	RPG p1 = RPG("Wiz", 70, 45, 15, "mage", skills);
	RPG p2 = RPG();

	gameLoop(&p1, &p2);
	//displayEnd(p1, p2);
	return 0;
}
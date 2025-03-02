#include "RPG.h"
#include <string>
#include <iostream>
using namespace::std;

RPG::RPG() {
	name = "NPC";
	health = 100;
	strength = 10;
	defense = 10;
	type = "warrior";
	skills[0] = "slash";
	skills[1] = "parry";
}

RPG::RPG(string name, int health, int strength, int defense, string type, string skills[SKILL_SIZE]) {
	this->name = name;
	this->health = health;
	this->strength = strength;
	this->defense = defense;
	this->type = type;
	skills = new string[SKILL_SIZE];

	setSkills();
}

void RPG::setSkills() {
	if (type == "mage") {
		skills[0] = "fire";
		skills[1] = "thunder";
	}
	else if (type == "thief") {
		skills[0] = "pilfer";
		skills[1] = "jab";
	}
	else if (type == "archer") {
		skills[0] = "parry";
		skills[1] = "crossbow_attack";
	}
	else {
		skills[0] = "slash";
		skills[1] = "parry";
	}
	
}

/*void RPG::printAction(string, RPG) {
	printf("%s used %s on %s\n", name.c_str(), skills.c_str(), opponent.getName().c_str());
}*/

void RPG::updateHealth(int new_health){
	health = new_health;
}

/*void RPG::attack(RPG*) {

}*/

/*void RPG::useSkill(RPG*) {

}*/

bool RPG::isAlive() const {
	if (health > 0)
		return true;
	else
		return false;
}

string RPG::getName() const {
	return name;
}

int RPG::getHealth() const {
	return health;
}

int RPG::getStrength() const {
	return strength;
}

int RPG::getDefense() const {
	return defense;
}

void RPG::printAll() const {
	cout << "Name: " << name << endl;
	cout << "Health: " << health << endl;
	cout << "Strength: " << strength << endl;
	cout << "Defense: " << defense << endl;
	cout << "Type: " << name << endl;
	cout << "Skill #1: " << skills[0] << endl;
	cout << "Skill #2: " << skills[1] << endl;
}

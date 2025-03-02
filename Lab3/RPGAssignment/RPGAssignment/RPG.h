#pragma once

#ifndef RPG_H
#define RPG_H

#include <iostream>
#include <string>
using namespace::std;

const int SKILL_SIZE = 2;

class RPG
{
public:
	RPG();
	RPG(string name, int health, int strength, int defense, string type, string skills[SKILL_SIZE]);

	void setSkills();
	void printAction(string, RPG);
	void updateHealth(int);
	//void attack(RPG*);
	//void useSkill(RPG*);

	bool isAlive() const;
	string getName() const;
	int getHealth() const;
	int getStrength() const;
	int getDefense() const;
    
	void printAll() const;
private:
	string name;
	int health;
	int strength;
	int defense;
	string type; //warrior, mage, thief, archer
	string skills[SKILL_SIZE];
};
#endif

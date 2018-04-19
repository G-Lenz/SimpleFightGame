/******************************************************************************
 * Program name: character.hpp
 * Author: George Lenz
 * Date: 2/18/2018
 * Description: Header file for character class
******************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <cstdlib>
#include <time.h>
#include <string>
#include <iostream>
using namespace std;
class Character
{
protected:

int attackMax;
int defenseMax;
int armor;
int strength;
std::string name;
struct display
{
    std::string line1;
    std::string line2;
    std::string line3;
    std::string line4;
    std::string line5;
};

display picture;
public:

Character()
{
    attackMax = 0;
    defenseMax = 0;
    armor = 0;
    strength= 0;
    name = "";
    picture.line1 = "";
    picture.line2 = "";
    picture.line3 = "";
    picture.line4 = "";
    picture.line5 = "";
}

Character(int aMax, int dMax, int armor1, int strength1)
{
    this->attackMax = aMax;
    this->defenseMax = dMax;
    this->armor = armor1;
    this->strength = strength1;
}
//Character(const Character);
//Charcter& operator=(Character);
~Character(){};
int getAttackMax()
{
    return attackMax;
}
int getdefenseMax()
{
    return defenseMax;
}
int getArmor()
{
    return armor;
}
int getStrength()
{
    return strength;
}
std::string getName()
{
    return name;

}
void setName(std::string aName)
{
    this->name = aName;
}
void setStrength(int num)
{
    strength = num;
}

display getDisplay()
{
    return picture;
}

void printCharacters(Character* right)
{
    cout << endl << (this->getDisplay()).line1;
    cout << "            " << right->getDisplay().line1 << endl;
    cout << (this->getDisplay()).line2 << "            ";
    cout << right->getDisplay().line2 << endl;
    cout << this->getDisplay().line3 << "     vs     ";
    cout << right->getDisplay().line3 << endl;
    cout << this->getDisplay().line4 << "            ";
    cout << right->getDisplay().line4 << endl;
    cout << this->getDisplay().line5 << "            ";
    cout << right->getDisplay().line5 << endl;
 
};
virtual int attack() = 0;
virtual void defend(int) = 0;
int roll(int anAttack)
{
    return 1 + rand() % anAttack;
}
//assignment operator overload
Character& operator=(const Character* right)
{
    this->attackMax = right->attackMax;
    this->defenseMax = right->defenseMax;
    this->armor = right->armor;
    this->strength = right->strength;
    this->name = right->name;
}
};

#endif

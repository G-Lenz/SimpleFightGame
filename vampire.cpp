/**********************************************************
 * Program Name: vampire.cpp
 * Author: George Lenz
 * Date 2/18/2018
 * Description: Implementation for vampire class
 * *******************************************************/
#include "vampire.hpp"
#include "character.hpp"
#include <string>
#include <iostream>
using namespace std;

int Vampire::attack()
{
    int die1 = 1 + rand() % attackMax;
    int totAttack = 0;
    totAttack = die1;
    return totAttack;
}

void Vampire::defend(int anAttack)
{   int die1 = 1 + rand() % defenseMax;
    int charm = 1+ rand() % 2;
    
    int defense = die1;
    int damage = 0;
    
    switch(charm)
    {
        case 1: 
        {
             damage = 0;
             cout << "Vampire has charmed the opponent;"
                  << " No damage is dealt." << endl << endl;
             return;
        }
        break;
    
        case 2:
        {
            damage = anAttack - defense - armor;
        }
        break;
    }
 
    if(this->strength - damage <= 0)
    {
        cout << "THE VAMPIRE HAS BEEN KILLED" << endl;
    }
    damage = anAttack - defense - armor;
    if (damage < 0)
    {
        damage = 0;
        cout << "DAMAGE DEALT: " << damage << endl;
        return;
    }
    else
    {
        this->strength = this->strength - damage;
        if(this->strength < 0)
        {
            this->strength = 0;
        }
        cout << "DAMAGE DEALT: " << damage << endl;
     }
} 
    



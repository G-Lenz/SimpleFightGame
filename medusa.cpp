/**********************************************************
 * Program Name: medusa.cpp
 * Author: George Lenz
 * Date 2/18/2018
 * Description: Implementation for medusa class
 * *******************************************************/
#include "medusa.hpp"
#include "character.hpp"
#include <string>
#include <iostream>
using namespace std;

int Medusa::attack()
{
    int die1 = 1 + rand() % attackMax;
    int die2 = 1 + rand() % attackMax;
    int totAttack = die1 + die2;
    if (totAttack == 12)
    {
        totAttack = 100;
        cout << "Medusa used glare, your Character has bee turned to stone!" 
             << endl;
        return totAttack;
    }
    else
    {
        return die1 + die2;
    }
}

void Medusa::defend(int anAttack)
{   int die1 = 1 + rand() % defenseMax;
    int defense = die1;
    int damage = 0;

    damage = anAttack - defense - armor;

    if(this->strength - damage <= 0)
    {
        cout << "MEDUSA HAS BEEN KILLED" << endl;
    }

    if (damage < 0)
    {
        damage = 0;
        cout << "DAMAGE DEALT: " << damage << endl;
        return;
    }
    else
    {
        this->strength = this->strength - damage;
        if(this->strength <= 0)
        {
            this->strength = 0;
            
        }
        cout << "DAMAGE DEALT: " << damage << endl;
    }
        
}
 
    

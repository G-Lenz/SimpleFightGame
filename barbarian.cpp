/**********************************************************
 * Program Name: barbarian.cpp
 * Author: George Lenz
 * Date 2/18/2018
 * Description: Implementation for barbarian class
 * *******************************************************/
#include "barbarian.hpp"
#include "character.hpp"
#include <string>
#include <iostream>
using namespace std;

int Barbarian::attack()
{
    int die1 = 1 + rand() % attackMax;
    int die2 = 1 + rand() % attackMax;
    int totAttack = 0;
    totAttack = die1 + die2;
    return totAttack;
}

void Barbarian::defend(int anAttack)
{   int die1 = 1 + rand() % defenseMax;
    int die2 = 1 + rand() % defenseMax;
    int defense = die1 + die2;
    int damage = 0;
   
    damage = anAttack - defense - armor;
 
    if(this->strength - damage <= 0)
    {
      
        cout << "BARBARIAN HAS BEEN KILLED" << endl;
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
    

/**********************************************************
 * Program Name: harrypotter.cpp
 * Author: George Lenz
 * Date 2/18/2018
 * Description: Implementation for harrypotter class
 * *******************************************************/
#include "harrypotter.hpp"
#include "character.hpp"
#include <string>
#include <iostream>
using namespace std;

int HarryPotter::attack()
{
    int die1 = 1 + rand() % attackMax;
    int die2 = 1 + rand() % attackMax;
    int totAttack = 0;
    totAttack = die1 + die2;
    return totAttack;
}

void HarryPotter::defend(int anAttack)
{   int die1 = 1 + rand() % defenseMax;
    int die2 = 1 + rand() % defenseMax;
    int defense = die1 + die2;
    int damage = 0;
   
    damage = anAttack - defense - armor;
 
    if(this->strength - damage <= 0 && this->life == 2)
    {
        cout << "HARRY POTTER HAS BEEN KILLED" << endl << endl;
    }
    else
    {
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
        cout << "DAMAGE DEALT: " << damage << endl;
        if(this->strength < 0 && this->life == 2)
        {
            this->strength = 0;
        }
        if(this->strength <=0 && this->life == 1)
        {
            cout << "HARRY POTTER HAS RESSURECTED." << endl << endl;
            this->strength = 20;
            life++;
        }
    }
} 
    

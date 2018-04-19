/**********************************************************
 * Program Name: bluemen.cpp
 * Author: George Lenz
 * Date 2/18/2018
 * Description: Implementation for bluemen class
 * *******************************************************/
#include "bluemen.hpp"
#include "character.hpp"
#include <string>
#include <iostream>
using namespace std;

int BlueMen::attack()
{
    int die1 = 1 + rand() % attackMax;
    int die2 = 1 + rand() % attackMax;
    int totAttack = 0;
    totAttack = die1 + die2;
    return totAttack;
}

void BlueMen::defend(int anAttack)
{   int die1 = 1 + rand() % defenseMax;
    int die2 = 1 + rand() % defenseMax;
    int die3 = 1 + rand() % defenseMax;
    int defense = 0;
    int damage = 0;
    if(this->strength <= 4)
    {
        defense = die1;
    }
    else if(this->strength <= 8)
    {
        defense = die1 + die2;
    }
    else
    {
        defense = die1 + die2 + die3;
    } 
   
   
    damage = anAttack - defense - armor;
 
    if(this->strength - damage <= 0)
    {
        cout << "THE BLUEMEN HAVE BEEN KILLED" << endl << endl;
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
        cout << "DAMAGE DEALT: " << damage << endl;
        if(this->strength < 0)
        {
            this->strength = 0;
        }
 
    }
} 
    

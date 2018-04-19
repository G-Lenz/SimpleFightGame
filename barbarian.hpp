/***************************************************
 * Program Name: barbarian.hpp
 * Author: George Lenz
 * Date: 2/18/1018
 * Description: Headder file for barbarian class.
 * ************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "character.hpp"
#include <string>
using namespace std;

class Barbarian : public Character
{
private:

   

public: 

    Barbarian(string aName) : Character(6, 6, 0, 12)
    {
        name = aName;
        picture.line1 = " \\|/      ";
        picture.line2 = "|\\ /|     ";
        picture.line3 = "|O O|     ";
        picture.line4 = "| > |     ";
        picture.line5 = "|[-]|     ";
    }

    ~Barbarian(){};

    virtual int attack();
    virtual void defend(int);

};
#endif




/***************************************************
 * Program Name: vampire.hpp
 * Author: George Lenz
 * Date: 2/18/1018
 * Description: Headder file for vampire class.
 * ************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "character.hpp"
#include <string>
using namespace std;

class Vampire : public Character
{
private:

    

public: 

    Vampire(string aName) : Character(12, 6, 1, 18)
    {
        name = aName;
        picture.line1 = "  MMM      ";
        picture.line2 = " |\\ /|     ";
        picture.line3 = "  O O      ";
        picture.line4 = "(  >  )    ";
        picture.line5 = " \\V V/     ";
    }

    ~Vampire(){};

    virtual int attack();
    virtual void defend(int);

};
#endif




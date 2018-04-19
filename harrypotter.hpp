/***************************************************
 * Program Name: harrypotter.hpp
 * Author: George Lenz
 * Date: 2/18/1018
 * Description: Header file for harrypotter class.
 * ************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "character.hpp"
#include <string>
using namespace std;

class HarryPotter : public Character
{
private:

int life;   

public: 

    HarryPotter(string aName) : Character(6, 6, 0, 10)
    {
        name = aName;
        life = 1;
        picture.line1 = "mmm       ";
        picture.line2 = "_*_       ";
        picture.line3 = "O-O       ";
        picture.line4 = " >        ";
        picture.line5 = "\\-/       ";
    }

    ~HarryPotter(){};

    virtual int attack();
    virtual void defend(int);

};
#endif




/***************************************************
 * Program Name: meudsa.hpp
 * Author: George Lenz
 * Date: 2/18/1018
 * Description: Header file for medusa class.
 * ************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "character.hpp"
#include <string>
using namespace std;

class Medusa : public Character
{
private:

   

public: 

    Medusa(string aName) : Character(6, 6, 3, 8)
    {
        name = aName;
        picture.line1 ="SSSSSSSSS ";
        picture.line2 ="SSSO OSSS ";
        picture.line3 =" SS \" SS  ";
        picture.line4 =" SS\\0/SS  ";
        picture.line5 ="  S   S   ";
    }

    ~Medusa(){};

    virtual int attack();
    virtual void defend(int);

};
#endif




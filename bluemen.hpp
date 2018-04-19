/***************************************************
 * Program Name: blueMen.hpp
 * Author: George Lenz
 * Date: 2/18/1018
 * Description: Header file for blueMen class.
 * ************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "character.hpp"
#include <string>
using namespace std;

class BlueMen : public Character
{
private:

    

public: 

    BlueMen(string aName) : Character(10, 6, 3, 12)
    {
        name = aName;
        picture.line1 ="(^ ^)(oVo)";
        picture.line2 =" (_)  (_) ";
        picture.line3 ="          ";
        picture.line4 ="(o 0)(@ @)";
        picture.line5 =" (_)  (_) ";
    }

    ~BlueMen(){};

    virtual int attack();
    virtual void defend(int);

};
#endif




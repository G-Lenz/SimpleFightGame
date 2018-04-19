/*********************************************************************************************
 * Program Name: main.cpp
 * Author: George Lenz
 * Date 2/18/2018
 * Description: Roll based team fighting game.
 * ******************************************************************************************/

#include "queuenode.hpp"
#include "character.hpp"
#include "barbarian.hpp"
#include "medusa.hpp"
#include "vampire.hpp"
#include "bluemen.hpp"
#include "harrypotter.hpp"
#include "validate.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int main()
{
    srand(time(NULL));
    int round = 1;
    int menuChoice = 0;
    int charChoice = 0;
    int numFighters =0;
    int fighterCount = 1;
    int score1 = 0;
    int score2 = 0;
    std::string aName;

    system("clear");    
    do
    { 
        QueueNode p1Queue;
        QueueNode p2Queue;
        QueueNode losers;
 
        //Menu
        cout << "*****************" << endl;
        cout << "**FIGHTING GAME**" << endl;  
        cout << "*****************" << endl << endl;

        cout << "1. Play Game" << endl;
        cout << "2. EXIT" << endl << endl;

        cout << "Select an option: ";
        validate(&menuChoice, 1, 2);
        system("clear");

        if(menuChoice == 1)
        { 
            cout << "Please enter the number of " 
                 << "fighters for each side(max: 10)\n\n";
            cout << "Number of fighters: ";
            validate(&numFighters, 1, 10);
            system("clear");

            for(int i=0; i<numFighters; i++)
            {
                //Player 1 character selection
                cout << "Player 1: CHOOSE FIGHTER " << fighterCount
                     << endl << endl;
                cout << "1. Vampire\n";
                cout << "2. Barbarian\n";
                cout << "3. Blue Men\n";
                cout << "4. Medusa\n";
                cout << "5. Harry Potter\n";
                cout << "\nSelection: ";
                validate(&charChoice, 1, 5);
            
            //add character to list and allow user to change the name
            switch(charChoice)
            {
                
                case 1:
                {
                    cout << "What would you like to name this Vampire: "
                         << endl;
                    cin >> aName;
                    p1Queue.addBack(new Vampire(aName));
                }  
                break;
                case 2:
                {
                    cout << "What would you like to name this Barbarian: "
                         << endl;
                    cin >> aName;
                    p1Queue.addBack(new Barbarian(aName));
                }     
                break;   
                case 3:
                {
                    cout << "What would you like to name these Blue men:  " 
                         << endl;
                    cin >> aName;
                    p1Queue.addBack(new BlueMen(aName));
                }     
                break;   
                case 4:
                {
                    cout << "What would you like to name this Medusa: " 
                         << endl;
                    cin >> aName;
                    p1Queue.addBack(new Medusa(aName));
                }     
                break;   
                case 5:
                {
                    cout << "What would you like to name this Harry Potter: " 
                         << endl;
                    cin >> aName;
                    p1Queue.addBack(new HarryPotter(aName));
                }     
                break;
            }
            fighterCount += 1;
        }  
            fighterCount = 1;
            system("clear");

            //Player 2 character selection
            for (int i = 0; i<numFighters; i++)
            {
                //menu
                cout << "Player 2: CHOOSE FIGHTER " << fighterCount
                    << endl << endl;
                cout << "1. Vampire\n";
                cout << "2. Barbarian\n";
                cout << "3. Blue Men\n";
                cout << "4. Medusa\n";
                cout << "5. Harry Potter\n";
                cout << "\nselection: ";
                validate(&charChoice, 1, 5);

                //Player 2 add character to list and change name
                switch(charChoice)
                {
                    case 1:
                    {
                    cout << "What would you like to name this Vampire: "
                         << endl;
                    cin >> aName;
                    p2Queue.addBack(new Vampire(aName));
                    }  
                    break;
                    case 2:
                    {
                    cout << "What would you like to name this Barbarian: " 
                         << endl;
                    cin >> aName;
                    p2Queue.addBack(new Barbarian(aName));
                    }     
                    break;   
                    case 3:
                    {
                    cout << "What would you like to name these Blue Men: "
                         << endl;
                    cin >> aName;
                    p2Queue.addBack(new BlueMen(aName));
                    }     
                    break;   
                    case 4:
                    {
                    cout << "What would you like to name this Medusa" 
                         << endl;
                    cin >> aName;
                    p2Queue.addBack(new Medusa(aName));
                    }     
                    break;   
                    case 5:
                    {
                    cout << "What would you like to name this Harry Potter: "
                         << endl;
                    cin >> aName;
                    p2Queue.addBack(new HarryPotter(aName));
                    }        
                    break;
                }
                fighterCount += 1;
            }
            fighterCount = 1;
            system("clear");
            cin.ignore();


            //Loop while characters on either team
            while(p1Queue.getFront() != nullptr &&
                  p2Queue.getFront() != nullptr) 
            {      
 
               //Display Fight Card
                cout << "Round " << round << endl;
                cout << "P1: " << p1Queue.getFront()->getName()  
                         << "  vs  " 
                         << "P2: " << p2Queue.getFront()->getName()
                        << endl << endl;
                cout << "Health: " << p1Queue.getFront()->getStrength()
                     << "            "  << "Health: "
                     << p2Queue.getFront()->getStrength() << endl;

                p1Queue.getFront()->printCharacters(p2Queue.getFront());
                cout << endl;
                cout << "Player 2 press ENTER to attack...";
                cin.ignore();
                system("clear");
     
                //Checks if current characters are dead
                while(p1Queue.getFront()->getStrength() > 0
                      && p2Queue.getFront()->getStrength() > 0)
                {   
                //Header Info
                cout << "Round " << round << endl << endl;
                cout << "Player 2 " << "attacking "
                     << "Player 1" << endl<<endl;
 
                    //Player 2 attack player 1 and display information
                    p1Queue.getFront()->defend(p2Queue.getFront()->attack());
                    cout << endl;
                    std::cout << "P1: " <<   p1Queue.getFront()->getName() 
                              << "  vs  " << "P2: "
                              <<  p2Queue.getFront()->getName() << endl << endl;
                    std::cout << "Health: " << p1Queue.getFront()->getStrength()
                              << "              "
                              << "Health: " << p2Queue.getFront()->getStrength()
                              << endl << endl;
                    p1Queue.getFront()->printCharacters(p2Queue.getFront());
                    cout << endl;

                    //check if player 1 was killed
                    if(p1Queue.getFront()->getStrength() <= 0)
                    {
                        break;
                    }
             
              
                    cout << "Player 1 press enter to attack...";
                    cin.ignore();
                    system("clear"); 
                    
                    //Player 1 attacking player 2 Header
                    cout << "ROUND " << round << endl << endl;
                    cout << "Player 1 " << " attacking " 
                         << "Player 2 " << endl << endl;
        
                    //Player 1 attack Player 2 display info
                    p2Queue.getFront()->defend(p1Queue.getFront()->attack());

                    cout << endl;
                    std::cout << "P1: " <<   p1Queue.getFront()->getName() 
                              << "  vs  " << "P2: "
                              <<  p2Queue.getFront()->getName() << endl << endl;
                    std::cout << "Health: " << p1Queue.getFront()->getStrength()
                              << "              "
                              << "Health: " << p2Queue.getFront()->getStrength()
                              << endl << endl;
                    p1Queue.getFront()->printCharacters(p2Queue.getFront());
                    cout << endl;
                    if(p2Queue.getFront()->getStrength() <=0)
                    {
                        break;
                    }
 
                    cout << "Player 2 press enter to attack...";
                    cin.ignore();
                    system("clear");
            
  
                }
                //find round winner and display
                //move winner to back and loser to loser queue
                if(p1Queue.getFront()->getStrength() <= 0)
                {
                    cout << p2Queue.getFront()->getName() 
                         << " WINS!" << endl << endl;
                    
                    p1Queue.removeFront(losers);
                    p2Queue.getFront()->setStrength
                                      (
                                          p2Queue.getFront()->getStrength() +
                                         (p2Queue.getFront()->getStrength() / 2)
                                      );
                    p2Queue.returnWinner();
                    score2 +=1;
                }
                else if(p2Queue.getFront()->getStrength() <=0)
                {
                    cout << p1Queue.getFront()->getName() 
                         <<"  WINS!" << endl << endl;
                    p2Queue.removeFront(losers);
                    p1Queue.getFront()->setStrength
                                      (
                                          p1Queue.getFront()->getStrength() +
                                         (p1Queue.getFront()->getStrength() / 2)
                                      );
                    p1Queue.returnWinner();
                    score1+=1;
                } 
                
                //Prompt for next round or end match
                if(p1Queue.getFront() != nullptr &&
                   p2Queue.getFront() != nullptr)
                {    
                    cout << "Press Enter to bring up next fighters...";
                }
                else
                {
                    cout << "Press ENTER to see total score.";
                }
                cin.ignore();
                system("clear");
                round++;
            }  
            //Player 1 Winner Display
            if(p1Queue.getFront() == nullptr)
            {
                system("clear");
                cout << "PLAYER 2 WINS!!" << endl << endl;
                cout << "Total Kills: " << endl;
                cout << "Player 1: " << score1 <<endl;
                cout << "Player 2: " << score2 <<endl <<endl;
                cout << "DECEASED:" << endl;
                losers.printQueue();
                cout << endl << "press ENTER to return to main menu...";
                cin.ignore();
                system("clear");
                    
            }
            //Player 2 Winner display
            else if(p2Queue.getFront() == nullptr)
            {
                system("clear");
                cout << "PLAYER 1 WINS!!!" << endl << endl;
                 cout << "Total Kills: " << endl;
                cout << "Player 1: " << score1 <<endl;
                cout << "Player 2: " << score2 <<endl <<endl;
                cout << "DECEASED: " << endl;
                losers.printQueue();
                cout << endl;
                cout <<  "press ENTER to return to main menu...";
                cin.ignore();
                system("clear");
                
            }

        score1 = 0;
        score2 = 0;
        round = 1;
        
                    
        }
    }while(menuChoice!=2); //continue while user doesn't quit
    
    return 0;
}

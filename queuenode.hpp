/****************************************************************************
 * Program Name: queueNode.hpp
 * Author: George Lenz
 * Date: 2/25/2018
 * Description: header file for queueNode class
 * *************************************************************************/

#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP
#include "character.hpp"

class QueueNode
{

private:

    struct Node
    {
        Node* next;
        Character* val;
        Node(Character* val1)
        {
        val = val1;
        next = nullptr;
        
        }
    };
    
    Node* head;


public:

    QueueNode()
    {
        head = nullptr;
    }
    ~QueueNode()
    {
        Node* current = head; 
        while(current!= nullptr)
        {
            Node* temp = current->next;
            delete current->val;
            delete current;
            current = temp;
            
        }
        
    };
    bool isEmpty();
    void addBack(Character*);
    void removeFront(QueueNode& losers);
    Character* getFront();
    void printQueue();
    void returnWinner();
    void add(Node*);
    Character& operator=(const Character*);
};

#endif


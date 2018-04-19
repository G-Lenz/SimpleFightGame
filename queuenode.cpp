/***************************************************************************
 * Progam Name: queuenode.cpp
 * Author: George Lenz
 * Date: 2/25/2018
 * Desciption: Implementation file for queuenode class
 * ************************************************************************/
#include "queuenode.hpp"
#include <iostream>
#include "character.hpp"

//Check if queue is empty
bool QueueNode::isEmpty()
{
    if(head == nullptr)
    {
       return true;
    }
    else
    {
        return false;
    }
}

//add item to end of queue
void QueueNode::addBack(Character* aVal)
{
    if(this->isEmpty())
    {
        head = new Node(aVal);
        head->next = nullptr;
    }
    else if(head->next == nullptr)
    {
        head->next = new Node(aVal);
        head->next->next = nullptr;
    }
    else
    {
        Node* nextNode = head; 
        while(nextNode->next != nullptr)
        {
            nextNode = nextNode->next; 
        }
        nextNode->next = new Node(aVal);
        nextNode = nextNode->next;
        nextNode->next = nullptr;
    }
}

//add node to another list
void QueueNode::add(Node* aNode)
{
     if(this->isEmpty())
    {
        head = aNode;
        head->next = nullptr;
    }
    else if(head->next == nullptr)
    {
        head->next = aNode;
        head->next->next = nullptr;
    }
    else
    {
        Node* nextNode = head; 
        while(nextNode->next != nullptr)
        {
            nextNode = nextNode->next; 
        }
        nextNode->next = aNode;
        nextNode = nextNode->next;
        nextNode->next = nullptr;
    }
  
}

//remove item from front of list and add to passed list
void QueueNode::removeFront(QueueNode& losers)
{
    Node* temp;
    if(this->isEmpty())
    {
        return;
    }
  
    else if(head->next == nullptr)
    {   
        temp = head;
        temp->next = nullptr;
        losers.add(temp);
        head = nullptr;
      
    }


    else
    {
        temp = head;
        head = head->next;
        temp->next = nullptr;
        losers.add(temp);
 
        
        
    }
}

//get Front item in list
Character* QueueNode::getFront()
{
    if(this->isEmpty())
    {
        return nullptr;
    }
    else
    {
        return head->val;
    } 
}
 

//puts front of list to the back
void QueueNode::returnWinner()
{
    if(this->isEmpty())
    {
        return;
    }
    else if(head->next ==nullptr)
    {
        return;
    }
    else
    {
        Node* nextNode = head;
        Node* temp;
    
        while(nextNode->next!=nullptr)
        {
            nextNode = nextNode->next;
        }

        temp = head;
        head = head->next;
        nextNode->next = temp;
        nextNode->next->next = nullptr;
        
        
            
    }

}

//outputs list
void QueueNode::printQueue()
{
    if(this->isEmpty())
    {
        cout << "Nobody Dead" << endl;
        return;
    }
    else
    {
        Node* temp = head;
        while(temp != nullptr)
        {
            cout << temp->val->getName() << endl;
            temp = temp->next;
        }
        
    }
}
        




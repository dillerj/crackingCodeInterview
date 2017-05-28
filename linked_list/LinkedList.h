//*******************************************************************
//  LinkedList.h
//  LinkedList_Project
//
//  Created by Karlina Beringer on June 12, 2014.
//  Edited by Jed Diller 5/27/17
//  This header file contains the LinkedList class declarations.
//*******************************************************************

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
using namespace std;

//*******************************************************************
// Node structs contain data and a pointer to the next node.
// In this project, it will represent a song/artist combination.
//*******************************************************************
struct Node
{
    int value;
    Node *next; // pointer to next node
};

//*******************************************************************
// LinkedList is a list of singly-linked nodes.
// In this project, it will represent a song playlist.
//*******************************************************************
class LinkedList
{
    private:
    // Head of the list contains no song data, 
    // but points to the song playlist.
    Node *head;
    int listLength;
    
    public:
    // Default Constructor creates the head node.
    LinkedList();
    
    // Add new node to end of list
    // If no nodes initialized yet, create one and point head to it
    void addNodeToEnd(int value);
    void removeNodeFromEnd();
    void deleteAllNodes();

    // Inserts node with value into list
    // position is 0-listLength
    bool insertNode( int value, int position );
    
    // Setter removes a node by its given position.
    bool removeNode(int position );


    // AddBeginning
    // PopTop
    // Add end
    // DeleteEnd

    int getListLength();

    // Prints each node in the list in consecutive order,
    // starting at the head and ending at the tail.
    // Prints list data to the console.
    void printList();
    
    // Destructor de-allocates memory used by the list.
    ~LinkedList();
};

#endif // LINKEDLIST_H
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
struct node
{
    int data;
    node *next; // pointer to next node
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
    node *head;
    int listLength;
    
    public:
    // Default Constructor creates the head node.
    LinkedList();
    
    // Setter adds a node to the list at a given position.
    // Takes a node and list position as parameters.
    // Position must be between 1 and the number of data nodes.
    // Returns true if the operation is successful.
    bool insertNode( node *newNode, int position );
    
    // Setter removes a node by its given position.
    // Returns true if the operation is successful.
    bool removeNode( int position );

    // Prints each node in the list in consecutive order,
    // starting at the head and ending at the tail.
    // Prints list data to the console.
    void printList();
    
    // Destructor de-allocates memory used by the list.
    ~LinkedList();
};

#endif // LINKEDLIST_H
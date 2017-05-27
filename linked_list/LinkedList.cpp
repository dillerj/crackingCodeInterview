//*******************************************************************
//  LinkedList.cpp
//  LinkedList_Project
//
//  Created by Karlina Beringer on June 12, 2014.
//  Edited by Jed Diller 5/27/17
//  This source file contains the LinkedList class definitions.
//*******************************************************************

#include "LinkedList.h"

// Default Constructor creates the head node.
LinkedList::LinkedList()
{
    head = new node;
    head -> data = 0;
    head -> next = NULL;
    listLength = 0;
}

// Setter adds a node to the list at a given position.
// Takes a node and list position as parameters.
// Position must be between 1 and the number of data nodes.
// Returns true if the operation is successful.
bool LinkedList::insertNode( node * newNode, int position )
{
    // Sanity check for desired position 
    if ((position <= 0) || (position > listLength+1))
    {
        cout << "Error: the given position is out of range\n";
        return false;
    }

    // If there is no node attached to head, add link new node to head 
    if (head -> next == NULL) 
    {
        head -> next = newNode;
        listLength++;
        return true;
    } 

    // Find the end of the linked list
    int count = 0;
    node * p = head;
    node * q = head;
    while (q)
    { 
        // Insert in the middle of list if the position is right
        if (count == position)
        {
            p -> next = newNode;
            newNode -> next = q;
            listLength++;
            return true;
        }
        p = q;
        q = p -> next;
        count++;
    }

    // Insert at the end of the list if position is right
    if (count == position)
    {
        p -> next = newNode;
        newNode -> next = q;
        listLength++;
        return true;
    }

    cout << "nError: node was not added to list.n";
    return false;
}

// Setter removes a node by its given position.
// Returns true if the operation is successful.
bool LinkedList::removeNode( int position )
{
    if ((position <= 0) || (position > listLength + 1))
    {
        cout << "nError: the given position is out of range.n";
        return false;
    }
    if (head -> next == NULL)
    {
       cout << "nError: there is nothing to remove.n";
       return false;
    }
    int count = 0;
    node * p = head;
    node * q = head;
    while (q) 
    {
        if (count == position)
        {
            p -> next = q -> next;
            delete q;
            listLength--;
            return true;
        }
        p = q;
        q = p -> next;
        count++;
    }
    cout << "nError: nothing was removed from the list.n";
    return false;
}

// Prints each node in the list in consecutive order,
// starting at the head and ending at the tail.
// Prints the data to the console.
void LinkedList::printList()
{
    int count=0;
    node * p = head;
    node * q = head;
    cout << "Linked List:\n";
    while (q)
    {
        p = q;

        cout << "\npos : " << count << endl;
        cout << "data: " << p -> data << endl;
        q = p -> next;
        count++;
    }
}

// Destructor de-allocates memory used by the list.
LinkedList::~LinkedList() 
{
    node * p = head;
    node * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
        if (q) delete p;
    }
}


/******************************************************
 *                  Main Testing 
 ******************************************************/
int main()
{
    // STEP 1: Create some unlinked song nodes.
    
    node * A = new node;
    A -> data = 1;
    cout << "Created node\n";
    
    node * B = new node;
    B -> data = 2;
    
    node * C = new node;
    C -> data = 3;
    
    node * D = new node;
    D -> data = 4;
    
    node * E = new node;
    E -> data = 5;
    
    node * F = new node;
    F -> data = 6;
    
    // // STEP 2: Build a list of three song nodes by appending to end of list.
    cout << "Instantiating list\n";
    LinkedList myList;
    cout << "Done making list\n";
    myList.insertNode(A, 1);
    myList.insertNode(B, 2);
    myList.insertNode(C, 3);
    myList.insertNode(D, 4);
    myList.printList();
    
    // STEP 3: Insert a node into middle of list.
    myList.insertNode(E, 2);
    myList.printList();
    
    // STEP 4: Insert node at the front of list.
    myList.insertNode(F,1);
    myList.printList();
    
    // STEP 5: Remove the last node from the list.
    myList.removeNode(6);
    myList.printList();
    
    // STEP 6: Remove the first node from the list.
    myList.removeNode(1);
    myList.printList();
    
    // STEP 7: Remove a node from the middle of the list.
    myList.removeNode(3);
    myList.printList();
    
    return 0;
}



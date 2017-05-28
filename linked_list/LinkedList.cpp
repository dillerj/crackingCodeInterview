/*******************************************************************
 * Author: Jed Diller
 * LinkedList.cpp
 * Linked List Class
 *******************************************************************/

#include "LinkedList.h"

/* 
 * Constructor
 */
LinkedList::LinkedList()
{
    head = NULL;
    listLength = 0;
}

/*
 * Add new Node to end of list
 */ 
void LinkedList::addNodeToEnd(int value)
{
    if (head != NULL) {
        // Start at head and traverse until end
        Node * p_curr = head; 
        Node * p_next = head; 
        while (p_next != NULL)
        {
            p_curr = p_next;            // save current pointer
            p_next = p_next -> next;    // keep traversing list
        }

        // Found end, so now add new element
        p_next = new Node;
        p_curr -> next = p_next; 
        p_next -> next = NULL;
        p_next -> value = value;
        printf("created node at: %p\n", (void *)p_next); 
 
    } else {
        // Create first node and point head to it
        head = new Node;
        head -> value = value; 
        head -> next = NULL;
        printf("created node at head: %p\n", (void *)head); 
    } 

    listLength++;
    return;
}

/* 
 * Remove last Node from end of list
 */
void LinkedList::removeNodeFromEnd()
{
    
    // Start at head and traverse until end
    Node * p_curr = head; 
    Node * p_next = head; 

    // Check for empty list s
    if (head == NULL)
    {
        cout << "List is already empty\n";
        return;
    }
    
    // Check for deleting node head points to
    if (head->next == NULL)
    {
        printf("deleting node at head: %p\n", (void *)head); 
        delete head; // delete node at head
        head = NULL; // set head null
        listLength--;            
        return;  
    } 

    // Iterate through until end
    while (p_next->next != NULL)
    {
        p_curr = p_next;
        p_next = p_next-> next;    // keep traversing list
    }

    // Found end, so now remove element
    printf("deleting node at: %p\n", (void *)p_next); 
    delete p_next;
    p_curr -> next = NULL;
    listLength--;

    return;
}

void LinkedList::deleteAllNodes()
{
    while(head != NULL)
    {
        removeNodeFromEnd();
    }
    return;
}

/*
 * Setter adds a Node to the list at a given position.
 * Returns true if the operation is successful.
 */
bool LinkedList::insertNode( int value, int position )
{
    // Sanity check for desired position 
    // Positions are indexed 0-N
    // To place one at the end, position = listLength
    if ((position < 0) || (position > listLength))
    {
        cout << "Error: the given position is out of range\n";
        return false;
    }

    // If position is first value, change head
    if (position == 0)
    {
        Node * p_afterInsert = head->next;
        head = new Node;
        head->next  = p_afterInsert;
        head->value = value;
        listLength++;
        return true;
    }

    // No Node at head yet, create it, position is 0
    // Add to end if position = length
    if (position == listLength) 
    {
        addNodeToEnd(value);
        return true;
    } 

    // Find the desired poisiton in linked list
    int curr_pos = 0;
    Node * p_last = head;
    Node * p_curr = head;
    
    while (curr_pos < position)
    { 
        p_last = p_curr;
        p_curr = p_curr -> next;
        curr_pos++;
    }

    // Insert Node
    p_last -> next = new Node;
    // Set new node values
    p_last -> next -> next = p_curr; // set new pointer to point to next position
    p_last -> next -> value = value;
    listLength++;
    return true;
}


bool LinkedList::removeNode( int position )
{
    // To place one at the end, position = listLength
    if ((position < 0) || (position > listLength))
    {
        cout << "Error: the given position is out of range\n";
        return false;
    }

    // Special check if at front of list (head involved)
    // If position is first value, change head
    if (position == 0)
    {
        Node * save = head->next;
        delete head;
        head = save;
        listLength--;
        return true;
    }

    // No Node at head yet, create it, position is 0
    // Add to end if position = length
    if (position == listLength) 
    {
        removeNodeFromEnd();
        return true;
    }

    // Find the desired positon in linked list
    int curr_pos = 0;
    Node * p_last = head;
    Node * p_curr = head;
    
    while (curr_pos < position)
    { 
        p_last = p_curr;
        p_curr = p_curr -> next;
        curr_pos++;
    }

    // Get next pointer and deleted node
    p_last -> next = p_curr->next;
    delete p_curr;
    listLength--;
    return true;;
}


int LinkedList::getListLength()
{
    return listLength;
}

void LinkedList::printList()
{
    cout << "Linked List:\n";
    cout << "head: " << head << "\n";

    int count=0;
    Node * p_curr = head;
    if (head==NULL) {
        cout << "Empty list, head is NULL:\n";

    } else {
        while (p_curr != NULL)
        {
            cout << "pos : " << count << " data: " << p_curr->value;
            printf(" next: %p\n", (void *)p_curr->next);
            p_curr = p_curr -> next;
            count++;
        }
    }
}

// Destructor de-allocates memory used by the list.
LinkedList::~LinkedList() 
{
    deleteAllNodes();
}

/******************************************************
 *                  Main Testing 
 ******************************************************/
int main()
{
    LinkedList ll;
    cout << "Done making list\n";
    ll.addNodeToEnd(1);
    ll.addNodeToEnd(2);
    ll.addNodeToEnd(3);
    ll.addNodeToEnd(4);
    cout << "List length: " << ll.getListLength() << "\n";
    ll.printList();

    cout << "\nRemoving 1 node:\n";
    ll.removeNodeFromEnd();
    cout << "List length: " << ll.getListLength() << "\n";
    ll.printList();


    cout << "\nInserting node at 1:\n";
    // values 9 at posiiton 1
    ll.insertNode(9,1);
    ll.printList();

    cout << "\nInserting node at 0:\n";
    // values 11 at posiiton 0
    ll.insertNode(11,0);
    ll.printList();

    cout << "\nRemoving node at 3:\n";
    ll.removeNode(3);
    ll.printList();

    cout << "\nRemoving node at 0:\n";
    ll.removeNode(0);
    ll.printList();

    cout << "\nDeleteing rest of nodes:\n";
    ll.deleteAllNodes();
    cout << "List length: " << ll.getListLength() << "\n";
    ll.printList();
    
    return 0;
}



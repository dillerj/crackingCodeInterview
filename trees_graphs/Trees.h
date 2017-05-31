/*******************************************************************
 *  Jed Diller
 *  Trees.h
 *  This header file contains the Trees class declarations.
 *******************************************************************/

#ifndef TREES_H
#define TREES_H

#include <iostream>
#include <string>
using namespace std;

/*******************************************************************
 * Node Structures
 *******************************************************************/

// Node with dynamic amount of children
struct Node
{
    int value;
    Node * children; // should be **? 
};

// Binary Node
struct BinNode
{
    int value;
    Node *left;
    Node *right; 
};

/*******************************************************************
 * Tree class declration
 *******************************************************************/
class BinTree
{
    private:
        BinNode *head;
        int numNodes;
    
    public:
        BinTree();
        BinNode *getNode(int value);
        bool insertNode( int value);
        bool removeNode(int value);
        void deleteAllNodes();
        void printTree();
        ~BinTree();
};

#endif // TREES_H
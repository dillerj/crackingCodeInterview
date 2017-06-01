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
#include <iomanip>

/*******************************************************************
 * Node Structures
 *******************************************************************/

// Node with dynamic amount of children
// struct Node
// {
//     int value;
//     Node * children; // should be **? 
// };

// Binary Node
struct node
{
    int value;
    node *left;
    node *right; 
};

// Bin Node Specific functions 
node* createNode(int value);        
void deleteNode(node *p_node);
void visit( node *p_node, bool valOnly);

/*******************************************************************
 * Tree class declration
 *******************************************************************/
class BinTree
{
    public:
        BinTree();
        ~BinTree();
        
        void addNode(int value);
        void traverseInOrder();
        void traversePreOrder();
        void traversePostOrder();
        void deleteTree();
        int getNumNodes();
        void printTree();
        bool search(int value);
        
    private:
        node *head;
        int numNodes;
        
        void addNode(node *p_node, int value);
        void traverseInOrder( node *p_node );
        void traversePreOrder( node *p_node );
        void traversePostOrder( node *p_node );
        void deleteTree(node *p_node);
        void printTree(node* p);
        node* search(node *p_node, int value);
};

#endif // TREES_H
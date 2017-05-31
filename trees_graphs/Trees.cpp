/*
 * Jed Diller
 * Interview Prep
 * Tree class
 */

/*******************************************************************
 * Author: Jed Diller
 * Trees.cpp
 * Linked List Class
 *******************************************************************/

#include "Trees.h"

/* 
 * Constructor
 */
BinTree::BinTree()
{
    head = NULL;
    numNodes = 0;
}

void BinTree::addNode( BinNode * p_node, int value)
{
    // Adds node in the right place for a binary tree
    if (p_node == NULL)
    {
        p_node = createNode(value);
    } else {
        // Compare to values in node
        if (value < p_node->value)
        {
            // Value < current node value, go left
            addNode(p_node->left);
        } else {
            // Value >= current node value, go right
            addNode(p_node->right);
        }
    }
    return;
}

BinNode* BinTree::createNode(int value)
{
    BinNode * p_node = new BinNode;
    p_node->value = value;
    p_node->left  = NULL;
    p_node->right = NULL;
    return p_node;
}

void BinTree::deleteNodes(BinNode * p_node)
{
    // Delete current node and nodes below recusively 
    // Delete left, then right, then current
    if (p_node != NULL)
    {
        deleteNode(p_node->left);
        deleteNode(p_node->right);
        deleteNode(p_node);
    }
}

void BinTree::deleteNode(BinNode * p_node)
{
    // Recursively delete all node under selected node?
    delete node_p;
    return;
}

void BinTree::visit( BinNode * p_node)
{
    // print out node?
    printf("p_node: %p\n", (void *)p_node); 
    printf("value : %i\n", p_node->value); 
    printf("left  : %p\n", (void *)p_node->left); 
    printf("right : %p\n", (void *)p_node->right); 
}

void BinTree::traverseInOrder( BinNode * p_node )
{
    // In order is left, current, right
    if (p_node != NULL)
    {
        traverseInOrder(p_node->left);
        visit(p_node);
        traverseInOrder(p_node->right);
    }
    return;
}

void BinTree::traversePreOrder( BinNode * p_node )
{
    // Pre order is current, left, right
    if (p_node != NULL)
    {
        visit(p_node);
        traversePreOrder(p_node->left);
        traversePreOrder(p_node->right);
    }
    return;
}

void BinTree::traversePostOrder( BinNode * p_node )
{
    // Pre order is current, left, right
    if (p_node != NULL)
    {
        traversePostOrder(p_node->left);
        traversePostOrder(p_node->right);
        visit(p_node);
    }
    return;
}

int BinTree::getNumNodes()
{
    return numNodes;
}

void BinTree::printTree()
{
    return;
}

// Destructor de-allocates memory used by the list.
BinTree::~BinTree() 
{
    return;
}

/******************************************************
 *                  Main Testing 
 ******************************************************/
int main()
{
    BinTree btree;
    cout << "Created binary tree object\n";
        
    return 0;
}



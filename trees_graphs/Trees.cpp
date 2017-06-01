/*******************************************************************
 * Author: Jed Diller
 * Trees.cpp
 * Linked List Class
 *******************************************************************/

#include "Trees.h"


/*******************************************************************
 * Functions
 *******************************************************************/

node* createNode(int value)
{
    node *p_node = new node;
    p_node->value = value;
    p_node->left  = NULL;
    p_node->right = NULL;
    return p_node;
}

void deleteNode(node *p_node)
{
    // Recursively delete all node under selected node?
    delete p_node;
    return;
}

void visit( node *p_node)
{
    if (p_node == NULL)
    {
        cout << "Visit, failed, pointer to node is NULL\n";
        return;
    }
    // print out node?
    printf("p_node: %p\n", (void *)p_node); 
    printf("value : %i\n", p_node->value); 
    printf("left  : %p\n", (void *)p_node->left); 
    printf("right : %p\n", (void *)p_node->right); 
}


/*******************************************************************
 * Class Definitions 
 *******************************************************************/

BinTree::BinTree()
{
    head = NULL;
    numNodes = 0;
}

void BinTree::addNode(int value)
{
    // Adds node in the right place for a binary tree
    if (head == NULL)
    {
        cout << "Head is empty, creating node\n";
        head = createNode(value);   
    } else {
        addNode(head, value);        
    }
    return;
}

void BinTree::addNode(node *p_node, int value)
{    
    // Regular case
    if (p_node == NULL)
    {
        p_node = createNode(value);
        printf("created node at: %p\n", (void *)p_node); 
    } else {
        // Compare to values in node
        if (value < p_node->value)
        {
            // Value < current node value, go left
            addNode(p_node->left, value);
            printf("added left node at: %p\n", (void *)p_node); 
        } else {
            // Value >= current node value, go right
            addNode(p_node->right, value);
            printf("added right node at: %p\n", (void *)p_node); 
        }
    }
    numNodes++;
    return;
}


void BinTree::deleteTree()
{
    deleteTree(head);
}

void BinTree::deleteTree(node *p_node)
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


void BinTree::traverseInOrder(node *p_node)
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

void BinTree::traversePreOrder( node *p_node )
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

void BinTree::traversePostOrder( node *p_node )
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
    if (head == NULL)
    {
        cout << "Tree is empty\n";
    } else {
        printTree(head,0);
    }
    return;
}

void BinTree::printTree(node* p, int indent=0)
{
    // print post order
    if(p != NULL) {
        if(p->left) 
            printTree(p->left, indent+4);
        if(p->right) 
            printTree(p->right, indent+4);
        if (indent) {
            cout << std::setw(indent) << ' ';
        }
        cout<< p->value << "\n ";
    }
}

// Destructor de-allocates memory used by the list.
BinTree::~BinTree() 
{
    deleteTree();
    return;
}

/******************************************************
 *                  Main Testing 
 ******************************************************/
int main()
{
    cout << "Creating node:\n";
    node * p_test = createNode(10);
    visit(p_test);

    cout << "\nCreated binary tree object\n";
    BinTree btree;

    cout << "Adding nodes:\n";
    btree.addNode(8);
    btree.addNode(1);
    btree.addNode(4);
    btree.addNode(10);
    btree.addNode(7);
    
    cout << "Printing Tree()\n";
    btree.printTree();

    // cout << "Traversing tree\n";
    // btree.traverseInOrder(p_head);

    return 0;
}



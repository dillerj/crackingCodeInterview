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

void visit( node *p_node, bool valOnly=true)
{
    if (p_node == NULL)
    {
        cout << "Visited node is NULL\n";
        return;
    }

    if (valOnly)
        printf("value : %i\n", p_node->value); 
    else {
        printf("p_node: %p\n", (void *)p_node); 
        printf("value : %i\n", p_node->value); 
        printf("left  : %p\n", (void *)p_node->left); 
        printf("right : %p\n", (void *)p_node->right); 
    }
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
        numNodes++;
    } else {
        addNode(head, value);        
    }
    return;
}

void BinTree::addNode(node *p_node, int value)
{    
    // Compare to values in node
    if (value < p_node->value)
    {
        // Value < current node value, go left
        // Check to see if we can keep going left
        if (p_node->left != NULL)
        {    
            addNode(p_node->left, value);
        } else {
            // create left node
            p_node->left = createNode(value);
            numNodes++; 
        }
    
    } else {
        // Value >= current node value, go right
        if (p_node->right != NULL)
        {    
            addNode(p_node->right, value);
        } else {
            // create left node
            p_node->right = createNode(value); 
            numNodes++;
        }       
    }
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
        printTree(head);
    }
    return;
}

void BinTree::printTree(node* p)
{
    // print pre order
    if(p != NULL) {
        cout<< p->value << "\n";
        if(p->left) {
            cout << "<-L\n";
            printTree(p->left);
        }
        if(p->right) {
            cout << "R->\n";
            printTree(p->right);
        }
    }
}


bool BinTree::search(int value)
{
    node *p_search = search(head, value);

    if (p_search == NULL){
        cout << "Failed to find value: " << value << "\n";
        return false;
    } else {
        printf("Found value: %i at p_search: %p\n", value, (void *)p_search);
        return true;
    }
}

node *BinTree::search(node *p_node, int value)
{
    if(p_node != NULL)
    {
        if(value == p_node->value)
        {
            return p_node;
        }

        if(value < p_node->value) {
            return search(p_node->left, value);
        } else {
            return search(p_node->right, value);
        }
    
    } else {
        return NULL; 
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
    visit(p_test,false);

    cout << "\nCreated binary tree object\n";
    BinTree btree;

    cout << "Adding nodes:\n";
    btree.addNode(8);
    btree.addNode(1);
    btree.addNode(4);
    btree.addNode(10);
    btree.addNode(7);
    
    cout <<"Number of nodes: " << btree.getNumNodes() << "\n"; 

    cout << "\nPrinting Tree()\n";
    btree.printTree();

    cout << "\nSearch Tree\n";
    btree.search(1);
    btree.search(100);
    
    // cout << "Traversing tree\n";
    // btree.traverseInOrder(p_head);

    return 0;
}



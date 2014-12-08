#ifndef AVLNODE_H
#define AVLNODE_H

#include "node.h"

// An AVLTree Node
class AVLNode
{
public: // Member Variables
    AVLNode *left, *right;
    Node* data;
    int height;

public: // Constructor || Destructor
    AVLNode();
    AVLNode(Node* data);
    ~AVLNode();
public: // Member Functions
    friend class AVLTree;
};


#endif // AVLNODE_H

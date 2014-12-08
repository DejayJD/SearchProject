#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include "node.h"
#include "avlnode.h"

using namespace std;

// AVLTree class that will be inside the avlcontainer class
class AVLTree
{
private: // Member Variables
    AVLNode *root;
public : // Constructor || Destructor
    AVLTree();
    ~AVLTree();
public : // Member Functions
    void insert(Node* data);
    bool contains(string& data);
    Node* search(string& data);
private: // Member Functions
    void _insert(AVLNode*& node, Node*& data);
    int height(AVLNode *t);
    void rotateWithLeftChild(AVLNode*& k1);
    void rotateWithRightChild(AVLNode*& k1);
    void doubleWithLeftChild(AVLNode*& k3);
    void doubleWithRightChild(AVLNode*& k3);
    int max(int left, int right);
    bool _contains(string& data, AVLNode*& node);
    Node* _search(string& data, AVLNode*& node);
};

#endif // AVLTREE_H

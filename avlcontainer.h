#ifndef AVLCONTAINER_H
#define AVLCONTAINER_H
#include "avltree.h"
#include "node.h"
#include "indexinterface.h"


// This class is an avltree data structure that will implement
// the reverse index obtained from the persistent index.
// This class will is a child class of IndexInterface so the
// user can choose between hashtable and avltree
class avlContainer: public IndexInterface
{
public: // Constructor
    avlContainer();

public: // Member Variables
    void insert(string, int, int);
    void insert(string, int);
    Node& search(string);
    bool contains(string);
    void clearIndex();
    ~avlContainer();

private:
    AVLTree tree;

};

#endif // AVLCONTAINER_H

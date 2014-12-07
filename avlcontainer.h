#ifndef AVLCONTAINER_H
#define AVLCONTAINER_H
#include "avltree.h"
#include "node.h"
#include "indexinterface.h"

class avlContainer: public IndexInterface
{
public:
    avlContainer();
    void insert(string, int);
    Node& search(string);
    bool contains(string);
    void clearIndex();
    ~avlContainer();

private:
    AVLTree tree;

};

#endif // AVLCONTAINER_H

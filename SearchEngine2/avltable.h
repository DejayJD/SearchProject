#ifndef AVLTABLE_H
#define AVLTABLE_H
#include <string>
#include <iostream>
#include "avltree.h"
#include "node.h"

using namespace std;
class avlTable
{
public:
    avlTable();
    int hashFunction(string);
    bool hasElement(int);
    void insert(int);
    AVLTree<Node*>* getAVLTree(int);
    void createAVLTree(int);

private:
    static int const tableSize = 26;
    AVLTree<Node*>** table;
};

#endif // AVLTABLE_H

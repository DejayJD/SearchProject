#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <iostream>
#include "avltable.h"

using namespace std;
class hashTable
{
public:
    hashTable();
    int hashFunction(string, unsigned int);
    void insert(int);
    bool hasElement(int);
    avlTable* getAVLTable(int);
    void createTable(int);

private:
    static int const tableSize = 100000;
    avlTable** table;
};

#endif // HASHTABLE_H

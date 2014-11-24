#ifndef CONTAINER_H
#define CONTAINER_H
#include "avltable.h"
#include "avltree.h"
#include "hashtable.h"


class Container
{
public:
    Container();
    void insert(string, int);   //insert word with the id
    Node* search(string);       //search for the word
    bool contains(string);

    int getwordcount() {
        return wordcount;
    }
    int getinsertcount() {
        return insertcount;
    }

private:
    hashTable index;
    int wordcount; //delete later
    int insertcount; //delete later
};

#endif // CONTAINER_H

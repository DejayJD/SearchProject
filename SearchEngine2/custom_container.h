#ifndef CUSTOM_CONTAINER_H
#define CUSTOM_CONTAINER_H

#include "avltable.h"
#include <avltree.h>
#include "hashtable.h"


class custom_container
{
public:
    custom_container();
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

#endif // CUSTOM_CONTAINER_H
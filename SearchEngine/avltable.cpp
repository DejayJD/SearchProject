#include "avltable.h"

avlTable::avlTable()
{
    table = new AVLTree<Node*>*[tableSize];
    for(int i = 0; i < tableSize; i++) {
        table[i] = nullptr;
    }
}

int avlTable::hashFunction(string word) {
    int first = word[0];
    return first % tableSize;
}

bool avlTable::hasElement(int key) {
    if(table[key] == nullptr)
        return false;
    else
        return true;
}

void avlTable::insert(int key) {
    if(!hasElement(key))
        table[key] = new AVLTree<Node*>();
}

AVLTree<Node*>* avlTable::getAVLTree(int key) {
    if(!hasElement(key)){
        cerr << "Tree does not exist" << endl;
        return nullptr;
    }
    else
        return table[key];
}
void avlTable::createAVLTree(int key) {
    if(table[key] != nullptr)
        cerr << "Tree already exists" << endl;
    else
        table[key] = new AVLTree<Node*>();
}

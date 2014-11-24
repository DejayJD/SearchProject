#include "container.h"

Container::Container()
{
    wordcount = 0;  //take out later
    insertcount = 0;    //take out later
}

void Container::insert(string word, int id) {

    int hTableKey = index.hashFunction(word, 0);    //get first hashkey with seed 0
    if(!index.hasElement(hTableKey))        //if the table for this word does not exist
        index.createTable(hTableKey);   //create table
    int aTableKey = index.getAVLTable(hTableKey)->hashFunction(word);   //second hash
    if(!index.getAVLTable(hTableKey)->hasElement(aTableKey))    //if table for this word does not exists
        index.getAVLTable(hTableKey)->createAVLTree(aTableKey); //create tree for this section

    if(index.getAVLTable(hTableKey)->getAVLTree(aTableKey)->contains(word)) //if word exists
    {
        index.getAVLTable(hTableKey)->getAVLTree(aTableKey)->search(word)->insertId(id);    //add id to node for word
    }
    else {
        Node* temp = new Node(word, id);    //create the node
        index.getAVLTable(hTableKey)->getAVLTree(aTableKey)->insert(temp);  //add word to tree
        wordcount++;
    }
    insertcount++;
}
Node* Container::search(string word) {
    int hTableKey = index.hashFunction(word, 0);
    if(!index.hasElement(hTableKey)) {  //make sure that table for that key exists
        cerr << "Word does not exist in tree" << endl;
    }

    int aTableKey = index.getAVLTable(hTableKey)->hashFunction(word);
    if(!index.getAVLTable(hTableKey)->hasElement(aTableKey))    //make sure that table for that key exists
        cerr << "Word does not exist in tree" << endl;
    if(index.getAVLTable(hTableKey)->getAVLTree(aTableKey)->contains(word)) {   //check if word exists in tree
        return index.getAVLTable(hTableKey)->getAVLTree(aTableKey)->search(word);   //search for word
    }
    else {      //if word doesn't exists
        cerr << "Word does not exist in tree" << endl;
        return nullptr;
    }
}

bool Container::contains(string word) {
    int hTableKey = index.hashFunction(word, 0);
    if(!index.hasElement(hTableKey)) {  //make sure that table for that key exists
        return false;
    }
    int aTableKey = index.getAVLTable(hTableKey)->hashFunction(word);
    if(!index.getAVLTable(hTableKey)->hasElement(aTableKey))    //make sure that table for that key exists
        return false;
    if(index.getAVLTable(hTableKey)->getAVLTree(aTableKey)->contains(word)) {   //check if word exists in tree
        return true;
    }
    else {      //if word doesn't exists
        return false;
    }
}


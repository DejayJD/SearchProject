#ifndef CONTAINER_H
#define CONTAINER_H

#include "avltree.h"
#include <unordered_map>
#include <string>
#include "node.h"
#include "indexinterface.h"

using namespace std;
class Container: protected IndexInterface
{
public:
    Container();
    void insert(string, int);   //insert word with the id
    Node& search(string);       //search for the word
    bool contains(string);
    void clearIndex();

    int getwordcount()
    {
        return wordcount;
    }
    int getinsertcount()
    {
        return insertcount;
    }
    unordered_map <string, Node> &getHash();

private:
    unordered_map <string, Node> hash;
    int wordcount; //delete later
    int insertcount; //delete later
};

#endif // CONTAINER_H

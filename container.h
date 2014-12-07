#ifndef CONTAINER_H
#define CONTAINER_H

#include "indexinterface.h"
#include "avltree.h"
#include <unordered_map>
#include <string>
#include "node.h"

using namespace std;
class Container : public IndexInterface
{
public:
    Container();
    void insert(string, int);   //insert word with the id
    void insert(string, int, int); // insert word with id and frequency
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

    unordered_map <string, Node> hash;

private:

    int wordcount; //delete later
    int insertcount; //delete later
};

#endif // CONTAINER_H

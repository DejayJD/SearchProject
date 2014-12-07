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
public: // Constructor || Destructor
    Container();
    ~Container();
public: // Member Function
    // insert string as key, and id to unordered map
    void insert(string, int);
    // insert string as key, (id and frequency) => for FrequencyNode
    void insert(string, int, int);

    // search function
    Node& search(string);

    // checks if the container contains the word
    bool contains(string);

    // clears container
    void clearIndex();

    int getwordcount()
    {
        return wordcount;
    }
    int getinsertcount()
    {
        return insertcount;
    }

    unordered_map <string, Node> hash;

public: // Setter || Getter
    unordered_map <string, Node> &getHash();


private:
    int wordcount; //delete later
    int insertcount; //delete later
};

#endif // CONTAINER_H

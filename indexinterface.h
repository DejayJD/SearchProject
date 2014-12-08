#ifndef INDEXINTERFACE_H
#define INDEXINTERFACE_H

#include <iostream>
#include "node.h"

using namespace std;

// IndexInterface is an abstract class that will allow
// polymorphism to happen. In the searchEngine case,
// IndexInterface allows the user to use either AVLTree
// or HashTable for as their index data structure since
// both of them are sub classes of IndexInterface
class IndexInterface
{
public: // Constructor || Destructor
    IndexInterface();
    virtual ~IndexInterface();
public: // Member Functions
    virtual Node& search(string&) = 0;
    virtual void insert(string&, int) = 0;
    virtual void insert(string&, int, int) = 0;
    virtual bool contains(string&) = 0;
    virtual void clearIndex() = 0;

};

#endif // INDEXINTERFACE_H

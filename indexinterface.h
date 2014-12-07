#ifndef INDEXINTERFACE_H
#define INDEXINTERFACE_H

#include <iostream>
#include "node.h"

using namespace std;

class IndexInterface
{
public:
    IndexInterface();
    virtual ~IndexInterface();
    virtual Node& search(string) = 0;
    virtual void insert(string, int) = 0;
    virtual void insert(string, int, int) = 0;
    virtual bool contains(string) = 0;
    virtual void clearIndex() = 0;

};

#endif // INDEXINTERFACE_H

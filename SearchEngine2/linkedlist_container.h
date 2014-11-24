#ifndef LINKEDLIST_CONTAINER_H
#define LINKEDLIST_CONTAINER_H

#include <LinkedList.h>
#include <node.h>

class linkedlist_container
{
private:

public:
    LinkedList <Node*> list;
    linkedlist_container();
    void insert(Node*&);

};

#endif // LINKEDLIST_CONTAINER_H

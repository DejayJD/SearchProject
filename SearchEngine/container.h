#ifndef CONTAINER_H
#define CONTAINER_H
#include <vector>
#include <string>
#include <node.h>
#include <avltree.h>

using namespace std;


class Container
{

private: // Member Variables
    AVLTree <Node*> avl;
public: // Constructor
    Container()
    {

    }

public: // Member Functions
    void insertNewWord(string& word)
    {
        avl.insert(new Node(word));
    }

    void insertNewWord(string& word, int id)
    {
        avl.insert(new Node(word, id));
    }

    bool contains(string& word)
    {
        return avl.contains(word);
    }

    Node*& search(string& word)
    {
        return avl.search(word);
    }
    void insertId()
    {
    }
    AVLTree <Node*> &getContainer()
    {
        return avl;
    }
};

#endif // CONTAINER_H

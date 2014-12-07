#ifndef INDEXER_H
#define INDEXER_H
#include "container.h"
#include "indexinterface.h"
#include "avlcontainer.h"
#include <fstream>
#include <vector>

class Indexer
{
public: // Constructor || Destructor
    Indexer();
    Indexer(Container&);
    Indexer(Container& container, ifstream& read);

public: // Member Functions
    void clearIndex(Container& container);
    void addWord(string, int);  //before we do this, figure out the id stuff
    void createSmallIndex(Container& container);   //outputs miniaturized index
    void buildIndex(Container&);  //checks if there is a small index and builds from that
    void buildIndex(IndexInterface* ii);
    void store();

private: // Member Variables
    Container container;
    IndexInterface* indexInterface;


 };
#endif // INDEXER_H

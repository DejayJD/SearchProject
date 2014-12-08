#ifndef INDEXER_H
#define INDEXER_H
#include "container.h"
#include "indexinterface.h"
#include "avlcontainer.h"
#include <fstream>
#include <vector>
#include <string>

// Indexer class is used to create the persistent index and
// rebuild the IndexInterface (depending on the user's choice)
using namespace std;
class Indexer
{
public: // Constructor || Destructor
    Indexer();
    Indexer(Container&);
    Indexer(Container& container, ifstream& read);

public: // Member Functions
    void clearIndex(Container& container);
    void clearIndex(IndexInterface* i);
    void addWord(string&, int);
    // createSmallIndex Builds persistent index
    void createSmallIndex(Container& container);
    // buildIndex rebuilds index to the data structure in Memory
    void buildIndex(Container&);
    void buildIndex(IndexInterface* ii);
    void store();

private: // Member Variables
    Container container;
    IndexInterface* indexInterface;
 };
#endif // INDEXER_H

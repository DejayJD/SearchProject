#ifndef INDEXER_H
#define INDEXER_H
#include "container.h"
#include <fstream>
#include <vector>

class Indexer
{
public:
    Indexer();
    Indexer(Container&);
    Indexer(Container& container, ifstream& read);
    void clearIndex(Container& container);
    void addWord(string, int);  //before we do this, figure out the id stuff
    void createSmallIndex(Container& container);   //outputs miniaturized index
    void buildIndex(Container&);  //checks if there is a small index and builds from that
    void store();

private:
    Container container;

 };
#endif // INDEXER_H

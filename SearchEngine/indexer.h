#ifndef INDEXER_H
#define INDEXER_H
#include "container.h"
#include <fstream>

class Indexer
{
public:
    Indexer();
    void clearIndex();
    void addWord(string, int);  //before we do this, figure out the id stuff
    void createSmallIndex();    //outputs miniaturized index
    void buildIndex();  //checks if there is a small index and builds from that

private:
    Container container;
};

#endif // INDEXER_H

#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include "parser.h"
#include "indexer.h"

class SearchEngine
{
private: // Member Variables
    ifstream read;
    Container container;

    Page* page;
    Parser* p;
    Indexer* i;

    unordered_map <int, Page*> pages;

public: // Constructor || Destructor
    SearchEngine();
    ~SearchEngine();
public: // Member Functions
    void readXML();
    void store();
    void store(string);
    void search(string);
    void buildIndex();
    void buildPages();
    void searchPage(int);
};

#endif // SEARCHENGINE_H

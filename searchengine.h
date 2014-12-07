#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include "parser.h"
#include "indexer.h"
#include "indexinterface.h"
#include "avlcontainer.h"

class SearchEngine
{
private: // Member Variables
    ifstream read;
    Container container;

    Page* page;
    Parser* p;
    Indexer* i;

    IndexInterface* indexInterface;

    unordered_map <int, Page*> pages;
    vector<FrequencyNode> arr;

public: // Constructor || Destructor
    SearchEngine();
    ~SearchEngine();
    void search2(string);

private: // Member Functions
    void quickSort(vector <FrequencyNode> &arr, int left, int right);


public: // Member Functions
    void readXML();
    void store();
    void store(string);
    void search(string);
    void rebuildIndex();
    void printIndex();
//    void buildPages();
    void buildPageTable(string file);
    void searchPage(int);
    void clearIndex();
    void displayPage(int i);
    void clearSearch();
    void avlTree();
    void hashTable();
};

#endif // SEARCHENGINE_H

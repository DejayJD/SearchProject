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
    vector<FrequencyNode> arr;

public: // Constructor || Destructor
    SearchEngine();
    ~SearchEngine();

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
};

#endif // SEARCHENGINE_H

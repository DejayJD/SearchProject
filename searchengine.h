#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include "parser.h"
#include "indexer.h"
#include "query.h"
#include <cmath>
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
    Query q;

    IndexInterface* indexInterface;

    unordered_map <int, Page*> pages;
    vector<FrequencyNode> arr;
    vector<QNode> qnodes;

public: // Constructor || Destructor
    SearchEngine();
    ~SearchEngine();

private: // Member Functions
    void quickSort(vector <FrequencyNode> &arr, int left, int right);
    void quickSort(vector <QNode> &arr, int left, int right);
    int getNumberDocsinWord(string);


public: // Member Functions
    Container &getContainer();
    void readXML();
    void store();
    void store(string);
    void search(string);
    void search2(string); //
    void rebuildIndex();
    void printIndex();
    void buildPageTable(string file);
    void searchPage(int);
    void clearIndex();
    void displayPage(int i);
    void clearSearch();
    Page* searchGetPage(int id);
    vector <QNode> searchEngine(string word);
    void getQuery(string query, int list);
    void sort();
    bool printSearchResult();
    void getPageRank(int);
    void displayUsername(string username);
    void avlTree();//
    void hashTable();//
};

#endif // SEARCHENGINE_H

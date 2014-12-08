#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include "parser.h"
#include "indexer.h"
#include "query.h"
#include <cmath>
#include "indexinterface.h"
#include "avlcontainer.h"

using namespace std;

// SearchEngine is the driver class that operates the Parser,
// Indexer, and Query processor. It also sorts the QNodes given
// by the Query processor based on tfidf and outputs it to the user.
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
    bool avlTree();//
    bool hashTable();//
};

#endif // SEARCHENGINE_H

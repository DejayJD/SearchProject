#ifndef QUERY_H
#define QUERY_H
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>

#include "porter2stemmer.h"

#include "container.h"
#include "qnode.h"
#include "page.h"
#include "indexinterface.h"
#include "avlcontainer.h"

using namespace std;

// Query class accepts queries from users and parses them
// It will determine which pages are most relevant to the user
// through all the keywords. It will return a vector of QNodes
// of relevant pages to be further sorted in the searchEngine
class Query
{
private:
    int totalPages;
    Container container;
    IndexInterface* indexInterFace;
    unordered_map <int, Page*> pages;

    vector <QNode> getContainerInfo(string in);
    vector <QNode> getContainerInfo2(string in);
    vector <QNode> queryAnd(vector <QNode>, vector<QNode>);
    vector <QNode> queryOr(vector <QNode>, vector<QNode>);
    vector <QNode> queryNot(vector <QNode>, vector<QNode>);
    vector <QNode> queryGt(vector <QNode>, int);
    vector <QNode> queryLt(vector <QNode>, int);

    Page* searchGetPage(int id);

public:
    Query();
    ~Query();
    void printResults(int, vector<QNode>); //print number of results by the integer
    vector <QNode> processQueries(string query, IndexInterface* container, unordered_map <int, Page*> &pages, int totalPages);
    void clear();

};

#endif // QUERY_H

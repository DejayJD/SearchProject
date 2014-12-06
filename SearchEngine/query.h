#ifndef QUERY_H
#define QUERY_H
#include <iostream>


class Query
{
private:
    vector<int> qresults;
public:
    Query();
    ~Query();
    void printResults(int); //print number of results by the integer
    void processQueries(string* lstrings, string* rstrings);
    vector<int> queryAnd(vector<int>, vector<int>);
    vector<int> queryOr(vector<int>, vector<int>);
    vector<int> queryNot(vector<int>, vector<int>);
    vector<int> queryGt(vector<int>, vector<int>);
    vector<int> queryLt(vector<int>, vector<int>);
};

#endif // QUERY_H

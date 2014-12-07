#ifndef QUERY_H
#define QUERY_H
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
struct qnode
{
    qnode(int id, int freq, string date)
    {
        this->date=date;
        this->id=id;
        this->freq=freq;
    }
    string date;
    int id;
    int freq;
};

class Query
{
private:
    vector<int> qresults;
public:
    Query();
    ~Query();
    void printResults(int, vector<qnode>); //print number of results by the integer
    void processQueries(string, int);
    vector<qnode> getContainerInfo(string in);
    vector<qnode> queryAnd(vector<qnode>, vector<qnode>);
    vector<qnode> queryOr(vector<qnode>, vector<qnode>);
    vector<qnode> queryNot(vector<qnode>, vector<qnode>);
    vector<qnode> queryGt(vector<qnode>, string);
    vector<qnode> queryLt(vector<qnode>, string);
};

#endif // QUERY_H

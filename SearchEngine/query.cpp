#include "query.h"

Query::Query()
{

}

Query::~Query()
{
    qresults.clear();
}

//Prints out the results of the query
void Query::printResults(int num)
{
    for (int i=0; i<num; i++) //Go through the vector and print it out
    {
        if (num<qresults.size())
            cout << qresults[i] << endl;
        else
            break;
    }
    qresults.clear(); //Reset the array for another query
    return;
}

void processQueries()
{
    //TODO: Parse input, put it into left and right side string vectors as well as command vectors
    vector<string> lstrings;
    vector<string> rstrings;
    vector<string> commands;
    vector<int> idL;
    vector<int> idR;
    //TODO: Get ids from AVL (presorted by frequency) and put them into vectors, then run the different tests;
    //TODO: Call functions according to commands, passing in the results
    int lpos, rpos;

    //clear up the temporary strings
    lstrings.clear();
    rstrings.clear();
}


//TODO: Operations
vector<int> queryAnd(vector<int> left, vector<int> right)
{

}

vector<int> queryOr(vector<int> left, vector<int> right)
{

}

vector<int> queryNot(vector<int> left, vector<int> right)
{

}

vector<int> queryGt(vector<int> left, vector<int> right)
{

}

vector<int> queryLt(vector<int> left, vector<int> right)
{

}

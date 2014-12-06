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

void processQueries(string query)
{
    //TODO: Parse input, put it into left and right side string vectors as well as command vectors
    //From Query: Word, Query Command
    //From Container: Frequency, Date, and IDs
    vector<string> lstrings;
    vector<string> rstrings;
    vector<string> commands;
    vector<int> idL;
    vector<int> idR;
    vector<int> lfreq;
    vector<int> rfreq;
    vector<int> ldate;
    vector<int> rdate;
    string temp;
    //TODO: Get ids from AVL (presorted by frequency) and put them into vectors, then run the different tests;
    //TODO: Call functions according to commands, passing in the results
    stringstream stream;
    stream << query;
    bool rightside;
    while (sstream.peek != "\n")
    {
        stream >> temp;
        commands.push_back(temp);
        stream >> temp;
        if (temp == "NOT"||temp == "AND"||temp=="OR"||temp=="DATEGT"||temp=="DATELT")
        {
            commands.push_back();
            rightside=true;
        }
        else
        {
            if (rightside==false)
                lstrings.push_back(temp);
            else
                rstrings.push_back(temp);
        }
    }

    //clear up the temporary strings
    lstrings.clear();
    rstrings.clear();
    commands.clear();
    lfreq.clear();
    rfreq.clear();
    ldate.clear();
    rdate.clear();
    idL.clear();
    idR.clear();
}


//TODO: Operations
void queryAnd(vector<int> left, vector<int> right)
{
    for (int i=0; i<left.size(); i++)
    {
        for (int j=0; j<right.size(); j++)
        {
            if (right[j]==left[i])
            {
                qresults.push_back(left[i]); //If the queries are equal, push them into the results vector
            }
        }
    }
}

void queryOr(vector<int> left, vector<int> right)
{
    //TODO: Ouput by frequency
}

void queryNot(vector<int> left, vector<int> right)
{
    //TODO: Remove all ids from left that exist in right, then put left into vector
    for (int i=0; i<left.size(); i++)
    {
        for (int j=0; j<right.size(); j++)
        {
            if (right[j]==left[i])
            {
                left.erase(left.begin()+i); //If the queries are equal, push them into the results vector
                idL.erase(idL.begin()+i);
                ldate.erase(ldate.erase()+i);
            }
        }
    }
    for (int i=0; i<left.size(); i++)
    {
        qresults.push_back(left[i]);
    }
}

void queryGt(vector<int> dates, int date)
{
    //Take out all dates before number
    for (int i=0; i<qresults.size(); i++)
    {
        if ()
    }
}

void queryLt(int date)
{
    //Take out all dates after the number
}

#include "query.h"

Query::Query()
{

}

Query::~Query()
{
    qresults.clear();
}

//TODO: Get container stuff:
vector<qnode> Query::getContainerInfo(string in)
{
    vector<qnode> newVec;
    qnode input(1000, 5, "2013/25/21"); // id-freq-date
    qnode input2(1001, 2, "2013/22/15");
    qnode input3(2113, 10, "2001/20/11");
    qnode input4(2113, 10, "2002/20/11");
    if (in<"Hello")
    {
        newVec.push_back(input);
        newVec.push_back(input2);
    }
    else
    {
        newVec.push_back(input);
        newVec.push_back(input3);
    }
    return newVec;
}

//Prints out the results of the query
void Query::printResults(int num, vector<qnode> qresults)
{
    if (qresults.size()==0)
    {
        cout << "No results were found :(" << endl;
    }
    for (int i=0; i<num; i++) //Go through the vector and print it out
    {
        if (i<qresults.size())
            cout << qresults[i].id << endl;
        else
            break;
    }
    //qresults.clear(); //Reset the array for another query
    return;
}

//FINISHED: Command operations (AND/OR/NOT/DATELT/DATEGT)
vector<qnode> Query::queryAnd(vector<qnode> left, vector<qnode> right)
{
    vector<qnode> newVec;
    for (int i=0; i<left.size(); i++)
    {
        for (int j=0; j<right.size(); j++)
        {
            if (right[j].id==left[i].id)
            {
                newVec.push_back(left[i]);
            }
        }
    }
    return newVec;
}

vector<qnode> Query::queryOr(vector<qnode> left, vector<qnode> right)
{
    vector<qnode> newVec;
    for (int i=0; i<left.size(); i++)
    {
        newVec.push_back(left[i]);
    }
    for (int i=0; i<right.size(); i++)
    {
       bool contains;
       for (int j=0; j<newVec.size(); j++)
       {
            if (newVec[j].id==right[i].id)
            {
                contains = true;
            }
       }
       if (contains==false)
           newVec.push_back(right[i]);
       contains = false;
    }
    return newVec;
}

vector<qnode> Query::queryNot(vector<qnode> left, vector<qnode> right)
{
    vector<qnode> newVec;
    for (int i=0; i<left.size(); i++)
    {
        newVec.push_back(left[i]);
        for (int j=0; j<right.size(); j++)
        {
            if (right[j].id==left[i].id)
            {
                newVec.pop_back();
            }
        }
    }
    return newVec;
}

vector<qnode> Query::queryGt(vector<qnode> data, string date)
{
    vector<qnode> newVec;
    for (int i=0; i<data.size(); i++)
    {
        newVec.push_back(data[i]);
        if (date < data[i].date)
        {
            newVec.pop_back();
        }
    }
    return newVec;
}

vector<qnode> Query::queryLt(vector<qnode> data, string date)
{
    vector<qnode> newVec;
    for (int i=0; i<data.size(); i++)
    {
        newVec.push_back(data[i]);
        if (date > data[i].date)
        {
            newVec.pop_back();
        }
    }
    return newVec;
}


void Query::processQueries(string query, int numresults)
{
    stringstream stream(query);
    string temp;
    //From Query: Word, Query Command
    //From Container: Frequency, Date, and IDs
    vector<string> strings;
    bool commands[4] = {false, false, false, false};
    stream >> temp; //Get first command
    if (temp=="AND")
    {
        commands[0] = true;
    }
    else
    {
        if (temp=="OR")
        {
            commands[0] = false;
        }
        else
        {
            cerr << "Invalid Query Input: Make sure you are using correct Query commands" << endl;
            cerr << "Usage: And/Or ... Not(optional) ... DateGt(optional) ... DateLt(optional) ..." << endl;
            return;
        }
    }
    while (stream >> temp)
    {
        strings.push_back(temp);
    }
    vector<qnode> persistentVec=getContainerInfo(strings[0]);
    int counter;
    for (int i=1; i<strings.size()-1; i++)
    {
        if (strings[i]=="NOT"||strings[i]=="DATEGT"||strings[i]=="DATELT")
        {
            if (strings[i]=="NOT")
            {
                commands[1]=true;
            }
            if (strings[i]=="DATEGT")
            {
                commands[2]=true;
            }
            if (strings[i]=="DATELT")
            {
                commands[3]=true;
            }
            counter = i;
            break;
        }
        else
        {
            vector<qnode> right=getContainerInfo(strings[i]);

            if (commands[0]==true)
            {
                persistentVec=queryAnd(persistentVec,right);
            }
            else
            {
                persistentVec=queryOr(persistentVec,right);
            }
        }
    }

    if (commands[1]==true)
    {
        for (int i=counter+1; i<strings.size(); i++)
        {
            if (strings[i]=="DATEGT"||strings[i]=="DATELT")
            {
                if (strings[i]=="DATEGT")
                {
                    commands[2]=true;
                }
                if (strings[i]=="DATELT")
                {
                    commands[3]=true;
                }
                counter = i;
                break;
            }
            vector<qnode> right=getContainerInfo(strings[i]);
            persistentVec=queryNot(persistentVec, right);
        }
    }
    if (commands[2]==true)
    {
        persistentVec=queryGt(persistentVec, strings[counter+1]);
        counter+=2;
    }
    if (commands[3]==true)
    {
        persistentVec=queryLt(persistentVec, strings[counter+1]);
        counter+=2;
    }
    printResults(numresults, persistentVec);
}

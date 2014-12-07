#include "query.h"

Query::Query()
{
    cout << "Query Created!" << endl;
}

Query::~Query()
{
    //qresults.clear();
}

//TODO: Get container stuff:
vector <QNode> Query::getContainerInfo(string in)
{
    transform(in.begin(), in.end(), in.begin(), ::tolower);
    Porter2Stemmer::stem(in);

    vector<QNode> newVec;
    typedef unordered_map <int, FrequencyNode> map;
    map temp = container.search(in).getIds();
    int n = container.search(in).getCount();
    for(map::const_iterator it = temp.begin(); it != temp.end(); it++)
    {
        int id = it -> first;
        QNode temp(id, it->second.getFrequency(), searchGetPage(id)->getDate());
        temp.setTfidf(temp.getfreq()*log10(totalPages/n));
        //cout << temp.getTfidf() << " ";
        newVec.push_back(temp);
    }
    return newVec;
}

vector <QNode> Query::getContainerInfo2(string in)
{
    transform(in.begin(), in.end(), in.begin(), ::tolower);
    Porter2Stemmer::stem(in);

    vector<QNode> newVec;
    typedef unordered_map <int, FrequencyNode> map;
    map temp = indexInterFace->search(in).getIds();
    int n = indexInterFace->search(in).getCount();
    for(map::const_iterator it = temp.begin(); it != temp.end(); it++)
    {
        int id = it -> first;
        QNode temp(id, it->second.getFrequency(), searchGetPage(id)->getDate());
        temp.setTfidf(temp.getfreq()*log10(totalPages/n));
        //cout << temp.getTfidf() << " ";
        newVec.push_back(temp);
    }
    return newVec;
}

//Prints out the results of the query
void Query::printResults(int num, vector <QNode> qresults)
{
    cout << endl;
    if (qresults.size()==0)
    {
        cout << "No results were found :(" << endl;
    }
    for (int i=0; i<num; i++) //Go through the vector and print it out
    {
        if (i<qresults.size())
            cout << "Titles : " << searchGetPage(qresults[i].id)->getTitle() << endl;
        else
            break;
    }
    //qresults.clear(); //Reset the array for another
    cout << endl;
    return;
}

//FINISHED: Command operations (AND/OR/NOT/DATELT/DATEGT)
vector<QNode> Query::queryAnd(vector<QNode> left, vector<QNode> right)
{
    vector<QNode> newVec;
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

vector<QNode> Query::queryOr(vector<QNode> left, vector<QNode> right)
{
    vector<QNode> newVec;
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

vector<QNode> Query::queryNot(vector<QNode> left, vector<QNode> right)
{
    vector<QNode> newVec;
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

vector<QNode> Query::queryGt(vector<QNode> data, int date)
{
    vector<QNode> newVec;
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

vector<QNode> Query::queryLt(vector<QNode> data, int date)
{
    vector<QNode> newVec;
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


vector <QNode> Query::processQueries(string query, int numresults, Container& container,
                                     unordered_map <int, Page*> &pages, int totalPages)
{
    cout << "Processing query : " << query << endl;
    this->totalPages = totalPages;
    this->container = container;
    this->pages = pages;
    stringstream stream(query);
    string temp;
    //From Query: Word, Query Command
    //From Container: Frequency, Date, and IDs
    vector<string> strings;
    vector<QNode> persistentVec;
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
            if (stream.peek()==-1)
            {
                persistentVec=getContainerInfo2(temp);
                return persistentVec;
            }
            else
            {
                throw "Invalid Query Input: Make sure you are using correct Query commands\nUsage: AND/OR ... NOT(optional) ... DATEGT(optional) ... DATELT(optional) ...";
            }
        }
    }
    while (stream >> temp)
    {
        strings.push_back(temp);
    }
    persistentVec=getContainerInfo2(strings[0]);

    int counter;
    for (int i=1; i<strings.size(); i++)
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
            vector<QNode> right=getContainerInfo2(strings[i]);

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
            vector<QNode> right=getContainerInfo2(strings[i]);
            persistentVec=queryNot(persistentVec, right);
        }
    }
    if (commands[2]==true)
    {
        char del = '/';
        strings[counter+1].erase(remove(strings[counter+1].begin(), strings[counter+1].end(), del), strings[counter+1].end());
        int idate = stoi(strings[counter+1]);

        persistentVec=queryGt(persistentVec, idate);

        counter+=2;
    }
    if (commands[3]==true)
    {
        char del = '/';
        strings[counter+1].erase(remove(strings[counter+1].begin(), strings[counter+1].end(), del), strings[counter+1].end());
        int idate = stoi(strings[counter+1]);
        persistentVec=queryLt(persistentVec, idate);
        counter+=2;
    }
    //printResults(numresults, persistentVec);
    //cout << persistentVec.size();
    if(persistentVec.size() == 0)
        throw "No Results";
    return persistentVec;
}

Page* Query::searchGetPage(int id)
{
    unordered_map <int, Page*>::const_iterator got = pages.find(id);

    if (got == pages.end())
    {
        cout << "cannot found word!" << endl;
        return nullptr;
    }
    else
        return got->second;
}
void clear()
{

}
vector <QNode> Query::processQueries(string query, IndexInterface* container,
                                     unordered_map <int, Page*> &pages, int totalPages)
{
    cout << "Processing query : " << query << endl;
    this->totalPages = totalPages;
    this->indexInterFace = container;
    this->pages = pages;
    stringstream stream(query);
    string temp;
    //From Query: Word, Query Command
    //From Container: Frequency, Date, and IDs
    vector<string> strings;
    vector<QNode> persistentVec;
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
            if (stream.peek()==-1)
            {
                persistentVec=getContainerInfo2(temp);
                if(persistentVec.size() == 0)
                {
                    throw "not found";
                }
                return persistentVec;
            }
            else
            {
                throw "Invalid Query Input: Make sure you are using correct Query commands\nUsage: AND/OR ... NOT(optional) ... DATEGT(optional) ... DATELT(optional) ...";
            }
        }
    }
    while (stream >> temp)
    {
        strings.push_back(temp);
    }
    persistentVec=getContainerInfo2(strings[0]);

    int counter;
    for (int i=1; i<strings.size(); i++)
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
            vector<QNode> right=getContainerInfo2(strings[i]);

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
            vector<QNode> right=getContainerInfo2(strings[i]);
            persistentVec=queryNot(persistentVec, right);
        }
    }
    if (commands[2]==true)
    {
        char del = '/';
        strings[counter+1].erase(remove(strings[counter+1].begin(), strings[counter+1].end(), del), strings[counter+1].end());
        int idate = stoi(strings[counter+1]);

        persistentVec=queryGt(persistentVec, idate);

        counter+=2;
    }
    if (commands[3]==true)
    {
        char del = '/';
        strings[counter+1].erase(remove(strings[counter+1].begin(), strings[counter+1].end(), del), strings[counter+1].end());
        int idate = stoi(strings[counter+1]);
        persistentVec=queryLt(persistentVec, idate);
        counter+=2;
    }
    //printResults(numresults, persistentVec);
    //cout << persistentVec.size();
    if(persistentVec.size() == 0)
        throw "No Results";
    return persistentVec;
}

#include "searchengine.h"

SearchEngine::SearchEngine()
{

    cout << "Search Engine Starts!" << endl;

    p = new Parser(container);
    cout << "Parser Created" << endl;

    i = new Indexer(container);
    cout << "Indexer Created" << endl;

    p->setupStopwords();
    cout << "setup Stopwords" << endl;

}

SearchEngine::~SearchEngine()
{
    delete p;
    delete i;
}

void SearchEngine::readXML()
{
    p->readThrough();
}

void SearchEngine::store()
{
    p->openFile("WikiDumpPart1.xml");
    cout << "File Opened" << endl;
//    p.readThrough();

    readXML();

    p->closeFile();
    cout << "File Closed" << endl;
    cout << "There are " << p->count << " pages parsed!" << endl;
}

void SearchEngine::store(string file)
{
    cout << "storing xml pages in \"" << file << "\"..." << endl;
    p->openFile(file);
    cout << "File \"" << file << "\" Opened" << endl;
    cout << "Reading \"" << file << "\"" << endl;
    p->readThrough(container);
    cout << "Done Reading" << endl;
    p->closeFile();
    cout << "File \"" << file << "\" Closed" << endl;
    cout << "There are " << p->count << " pages parsed!" << endl;
}

void SearchEngine::search(string word)
{
    if (arr.empty())
    {
        cout << "Searching for \"" << word << "\"" << endl;
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        Porter2Stemmer::stem(word);
        if(container.contains(word))
        {
            cout << "Pages containing \"" << word << "\" are titled :" << endl;
            typedef unordered_map <int, FrequencyNode> MyMap;
            MyMap temp = container.search(word).getIds();
            for(MyMap::const_iterator it = temp.begin(); it != temp.end(); it++)
            {
                int key = it -> first;
                //cout << (it->second) << ", ";
                //searchPage(key);
                FrequencyNode node = it -> second;
                arr.push_back(node);
            }
            cout << "sorting in frequency..." << endl;
            quickSort(arr, 0, arr.size()-1);

            int max = 10;
            if (arr.size() > max)
            {
                cout << "TOP " << max << " pages:" << endl;
                for (int i = 0; i < max; i++)
                {
                    cout << i+1 << ". with frequency = " << arr[i].getFrequency() << ", ";
                    searchPage(arr[i].getId());
                }
            }
            else
            {
                cout << "TOP " << arr.size() << " page(s):" << endl;
                for (int i = 0; i < arr.size(); i++)
                {
                    cout << i+1 << ". with frequency = " << arr[i].getFrequency() << ", ";
                    searchPage(arr[i].getId());
                }
            }
        }
        else
        {
            cout << word << " isn't in Container!" << endl;
        }
    }
    else
    {
        cout << "Please Clear Search Results first! <se.clearSearch()>" << endl;
    }

}

void SearchEngine::rebuildIndex()
{
    //i->buildIndex(container);
    i->buildIndex(indexInterface);
}

void SearchEngine::printIndex()
{
    i->createSmallIndex(container);
}

void SearchEngine::buildPageTable(string file)
{
    cout << "building pageTable from \"" << file << "\"" << endl;
    p->openFile(file);
    p->buildPageTable();
    p->closeFile();
}

void SearchEngine::searchPage(int id)
{
    unordered_map <int, Page*>::const_iterator got = p->pages.find(id);

    if (got == p->pages.end())
    {
        cout << "cannot found word!" << endl;
    }
    else
        cout << "Title : " << got->second->getTitle() << endl;
}

void SearchEngine::quickSort(vector <FrequencyNode> &arr, int left, int right)
{
    int i = left, j = right;
    FrequencyNode tmp;
    FrequencyNode pivot = arr[(left + right) / 2];
    /* partition */
    while (i <= j)
    {
        while (arr[i] > pivot)
        {
            i++;
        }
        while (arr[j] < pivot)
        {
            j--;
        }
        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

void SearchEngine::quickSort(vector <QNode> &arr, int left, int right)
{
    //cout << "quicksort! ";
    int i = left, j = right;
    QNode tmp;
    QNode pivot = arr[(left + right) / 2];
    /* partition */
    while (i <= j)
    {
        while (arr[i] > pivot)
        {
            i++;
        }
        while (arr[j] < pivot)
        {
            j--;
        }
        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

void SearchEngine::clearIndex()
{
    cout << "clearing Index!" << endl;
    i->clearIndex(container);
    cout << "clearing pageTable!" << endl;
    p->pages.clear();
    p->resetTotalPages();
}

void SearchEngine::displayPage(int rank)
{
    cout << "Displaying rank " << rank <<"..." << endl;
    if(!arr.empty())
    {
        if(rank <= arr.size())
        {
            int i = rank-1;
            cout << "arr["<< i << "]:" << endl;
            unordered_map <int, Page*>::const_iterator got = p->pages.find(arr[i].getId());


            cout << endl;
            if (got == p->pages.end())
            {
                cout << "cannot found word!" << endl;
            }
            else
            {
                cout << "TITLE : " << got->second->getTitle() << endl;
                cout << "Date : "<< got->second->getDate() << endl;
                if (got->second->getUsername().size() > 0)
                {
                    cout << "Username : " << got->second->getUsername() << endl;
                }
                cout << "TEXT : " << endl;
                cout << endl;
                cout << got->second->getText() << endl;
            }
        }
        else
        {
            cout << "Rank is out of bounds! display rank <1-" << arr.size() << ">" << endl;
        }
    }
    else
    {
        cout << "Please input search value first! <se.search(string)>" << endl;
    }
}

void SearchEngine::clearSearch()
{
    cout << "Clearing Search Results!" << endl;
    arr.clear();
}
Container &SearchEngine::getContainer()
{
    return container;
}

Page* SearchEngine::searchGetPage(int id)
{
    unordered_map <int, Page*>::const_iterator got = p->pages.find(id);

    if (got == p->pages.end())
    {
        cout << "cannot found word!" << endl;
        return nullptr;
    }
    else
        return got->second;
}

void SearchEngine::getQuery(string query, int list)
{
    try
    {
        qnodes = q.processQueries(query, indexInterface, p->pages, p->getTotalPages());
        //qnodes = q.processQueries(query, list, container, p->pages, p->getTotalPages());
    }
    catch(const char* msg)
    {
        throw msg;
    }

    //cout << qnodes.size();
}

void SearchEngine::sort()
{
    cout << "Sorting..." << endl;
    //cout << qnodes.size() << endl;
    quickSort(qnodes, 0, qnodes.size()-1);
}

bool SearchEngine::printSearchResult()
{
    cout << "Printing Search Results!" << endl;
    int max = 10;

    if (qnodes.size() > max)
    {
        cout << "TOP " << max << " pages out of " << qnodes.size() << " pages" << endl;
        for (int i = 0; i < max; i++)
        {
            cout << i+1 << ". With tfidf = " << qnodes[i].getTfidf() << ", ";
            searchPage(qnodes[i].getId());
        }
    }
    else
    {
        cout << "TOP " << qnodes.size() << " page(s):" << endl;
        for (int i = 0; i < qnodes.size(); i++)
        {
            cout << i+1 << ". With tfidf = " << qnodes[i].getTfidf() << ", ";
            searchPage(qnodes[i].getId());
        }
    }
    return true;
}

void SearchEngine::getPageRank(int rank)
{
    cout << "Displaying rank " << rank << "..." << endl;
    if(!qnodes.empty())
    {
        if(rank <= qnodes.size())
        {
            int i = rank-1;
            cout << "qnodes["<< i << "]:" << endl;
            unordered_map <int, Page*>::const_iterator got = p->pages.find(qnodes[i].getId());

            cout << endl;
            if (got == p->pages.end())
            {
                cout << "cannot found word!" << endl;
            }
            else
            {
                cout << "TITLE : " << got->second->getTitle() << endl;
                cout << "Date : "<< got->second->getDate() << endl;
                if (got->second->getUsername().size() > 0)
                {
                    cout << "Username : " << got->second->getUsername() << endl;
                }
                cout << "TEXT : " << endl;
                cout << endl;
                cout << got->second->getText() << endl;
            }
        }
        else
        {
            cout << "Rank is out of bounds! display rank <1-" << qnodes.size() << ">" << endl;
        }
    }
    else
    {
        cout << "Please input search value first!" << endl;
    }
}

void SearchEngine::displayUsername(string username)
{
    int count = 0;
    cout << "Displaying available pages written by " << username << endl;
    if(!qnodes.empty())
    {

        for(int i = 0; i < qnodes.size(); i++)
        {
            if(username == searchGetPage(qnodes[i].getId())->getUsername())
            {
                cout << i+1 << ". " << searchGetPage(qnodes[i].getId())->getTitle() << endl;
                count += 1;
            }
        }
        cout << endl;
    }
    if (count == 0)
    {
        cout << "no such username!" << endl;
    }
    else
    {
        cout << "there are " << count << " pages written by " << username << "!" << endl;
    }
}
void SearchEngine::hashTable() {
    indexInterface = new Container();
}

void SearchEngine::avlTree()
{
    indexInterface = new avlContainer();
}

void SearchEngine::search2(string word)
{
    if (arr.empty())
    {
        cout << "Searching for \"" << word << "\"" << endl;
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        Porter2Stemmer::stem(word);
        if(indexInterface->contains(word))
        {
            cout << "Pages containing \"" << word << "\" are titled :" << endl;
            typedef unordered_map<int,FrequencyNode> MyMap;
            MyMap temp = indexInterface->search(word).getIds();
            for(MyMap::const_iterator it = temp.begin(); it != temp.end(); it++)
            {
                int key = it -> first;
                //cout << (it->second) << ", ";
                //searchPage(key);
                FrequencyNode node = it -> second;
                arr.push_back(node);
            }
            cout << "sorting in frequency..." << endl;
            quickSort(arr, 0, arr.size()-1);

            int max = 10;
            if (arr.size() > max)
            {
                cout << "TOP " << max << " pages:" << endl;
                for (int i = 0; i < max; i++)
                {
                    cout << i+1 << ". with frequency = " << arr[i].getFrequency() << ", ";
                    searchPage(arr[i].getId());
                }
            }
            else
            {
                cout << "TOP " << arr.size() << " page(s):" << endl;
                for (int i = 0; i < arr.size(); i++)
                {
                    cout << i+1 << ". with frequency = " << arr[i].getFrequency() << ", ";
                    searchPage(arr[i].getId());
                }
            }
        }
        else
        {
            cout << word << " isn't in Container!" << endl;
        }
    }
    else
    {
        cout << "" << endl;
    }

}

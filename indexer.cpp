#include "indexer.h"

Indexer::Indexer()
{
}

Indexer::Indexer(Container& container)
{
    this->container = container;
}

Indexer::Indexer(Container& container, ifstream& read)
{
    this->container = container;
   // this->read = read;
}

void Indexer::clearIndex()
{
    container.clearIndex();
    return;
}

void Indexer::addWord(string word, int pageID)
{

}
void Indexer::buildIndex()
{
    ifstream fin;
    fin.open("miniIndex.xml");
    if(!fin.is_open())
    {
        cout << "File does not exits. Creating new index" << endl;
    }
    else
    {
        cout << "fin is open!" << endl;
    }

    fin.close();
}
void Indexer::createSmallIndex(Container& container)
{
    ofstream fout("miniIndex.xml");
    if (fout.is_open())
    {
        for (auto it = container.hash.begin(); it != container.hash.end(); ++it)
        {
            fout << it->second << endl;
        }

    }
    fout.close();
}

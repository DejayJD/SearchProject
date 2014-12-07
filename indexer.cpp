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

void Indexer::clearIndex(Container& container)
{
    container.clearIndex();
    return;
}

void Indexer::addWord(string word, int pageID)
{

}
void Indexer::buildIndex(Container& container)
{
    ifstream fin;
    fin.open("miniIndex.xml");
    if(!fin.is_open())
    {
        cout << "File does not exits. Creating new index" << endl;
    }
    else
    {
        cout << "Reindexing from miniIndex to Container..." << endl;
        string word;
        string sid;
        while (!fin.eof())
        {            
            fin >> word;
            if (fin.eof()) break;
            fin >> sid;
            while (sid != "!")
            {
               string delimiter = ",";

                size_t pos = 0;
                string token;
                while ((pos = sid.find(delimiter)) != string::npos)
                {
                    token = sid.substr(0, pos);
                    sid.erase(0, pos + delimiter.length());
                }
                int id = stoi(token);
                int frequency = stoi(sid);
                container.insert(word, id, frequency);

                fin >> sid;
            }
        }

    }

    fin.close();
}

void Indexer::buildIndex(IndexInterface* ii)
{
    indexInterface = ii;
    ifstream fin;
    fin.open("miniIndex.xml");
    if(!fin.is_open())
    {
        cout << "File does not exits. Creating new index" << endl;
    }
    else
    {
        cout << "Reindexing from miniIndex to Container..." << endl;
        string word;
        string sid;
        while (!fin.eof())
        {
            fin >> word;
            if (fin.eof()) break;
            fin >> sid;
            while (sid != "!")
            {
               string delimiter = ",";

                size_t pos = 0;
                string token;
                while ((pos = sid.find(delimiter)) != string::npos)
                {
                    token = sid.substr(0, pos);
                    sid.erase(0, pos + delimiter.length());
                }
                int id = stoi(token);
                int frequency = stoi(sid);
                ii->insert(word, id, frequency);
                fin >> sid;
            }
        }
    }

    fin.close();
}

void Indexer::createSmallIndex(Container& container)
{
    ofstream fout("miniIndex.xml");
    cout << "Printing index out to miniIndex.xml..." << endl;
    if (fout.is_open())
    {
        for (auto it = container.hash.begin(); it != container.hash.end(); ++it)
        {
            fout << it->second << endl;
        }

    }
    fout.close();
}

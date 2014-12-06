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
    cout << "Storing xml pages in " << file << endl;
    p->openFile(file);
    cout << "File " << file << " Opened" << endl;
    cout << "Reading " << file << endl;
    p->readThrough();
    cout << "Done Reading" << endl;
    p->closeFile();
    cout << "File " << file << " Closed" << endl;
    cout << "There are " << p->count << " pages parsed!" << endl;
}

void SearchEngine::search(string word)
{
    cout << "Search the indes for: " << p->getContainer().search(word).getWord() << endl;
    cout << "Pages containing \"" << word << "\" are titled :" << endl;
    typedef unordered_map<int,int> MyMap;
    MyMap temp = p->getContainer().search(word).getIds();
    for(MyMap::const_iterator it = temp.begin(); it != temp.end(); it++)
    {
        int key = it -> first;
        //cout << (it->second) << ", ";
        searchPage(key);
    }
    cout << endl;
}

void SearchEngine::buildIndex()
{
    //i->createSmallIndex(p->getContainer());
    p->openFile("WikiDumpPart3.xml");
    p->buildPages();
    p->closeFile();
}


void SearchEngine::buildPages()
{
    ofstream fout("pages.xml");
    if (fout.is_open())
    {
        for (auto it = p->pages.begin(); it != p->pages.end(); ++it)
        {
            fout << "<page>" << endl;
            fout << "<id>" << it->first << "</id>" << endl;
            fout << " : " << it->second->getTitle() << ", " << it->second->getText() << endl;
        }

    }
    fout.close();
}

void SearchEngine::searchPage(int id)
{
    unordered_map <int, Page*>::const_iterator got = p->pages.find(id);

    if (got == p->pages.end())
    {
        cout << "not found" << endl;
    }
    else
        cout << "title : " << got->second->getTitle() << endl;
}

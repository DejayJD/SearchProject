#ifndef PARSER_H
#define PARSER_H

#include "page.h"

#include "container.h"
#include "avlcontainer.h"
#include "indexinterface.h"
#include "porter2stemmer.h"

#include <bitset>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>

#include <cstring>

using namespace std;

// Parser is a custom xml parser that reads xml pages while gathering
// information of interest and storing them to page objects. The parser
// also gets each word of the text and stores them in a temporary container
// which is then used to create the persistent index by the indexer.
// It also parses through the xml file and creates a dictionary (hashtable)
// of all the xml pages that has been parsed which can be accessed with ids
// of each page.
class Parser
{
private: // Member Variables
    char const* delims = " \t[],-'/\\!%&=()<>?{}|._\n:;#~*+@^•—¡¿”“";
    ifstream read;
    vector <string> stopwords;
    vector <string> words;
    string buffer;
    set<string> wordSet;
    Page* page;
    Container container;

    int totalPages;

    IndexInterface* indexInterface;

    unordered_map <string, string> stemWords;

    //unordered_map <int, Page*> pages;

public: // Member Variables
    int count;
    unordered_map <int, Page*> pages;

public: // Constructor || Destructor
    Parser();
    Parser(Container&);
    Parser(Container&, ifstream&);

public: // Setters || Getters
    int getTotalPages();
    string& getTitle();
    string& getText();
    set <string> &getWordSet();
    vector <string> &getWords();
    void resetTotalPages();

public: // Member Functions
    // 1st Method Parsing
    bool ReadConfig(char*);
    // Reads and inserts stopwords to the set for comparing during parsing
    bool setupStopwords();
    // opens and close files for i/o
    void openFile(char* file);
    void openFile(string file);
    void closeFile();

    // prints title and text
    void printPage();

    // Reads in information between <page> and </page> in an xml file.
    // and inserts it into a newly created Page object
    bool readPage();

    // Reads through the entire xml file
    void readThrough();
    void readThrough(Container& container);
    void readThrough(IndexInterface* indexInterface);

    // Page
    void store();
    void store(Container& container);
    void store(IndexInterface* i);
    Container &getContainer();
    void buildPageTable();

private: // Member Functions
    string readContent(ifstream& read, string tag);
    string readText(ifstream& read);
    bool invalidChar (char c);
    void stripUnicode(string & str);
    void stem(string&);


private: // Templated Function
    template<typename C>
    void custom_strpbrk(string const& s, char const* delims, C& ret)
    {
        char const* p = s.c_str();
        char const* q = strpbrk(p+1, delims);
        for( ; q != NULL; q = strpbrk(p, delims) )
        {
            string data = typename C::value_type(p, q);
            transform(data.begin(), data.end(), data.begin(), ::tolower);
            stem(data);
            if (data.size() > 2 && data.size() < 30 && wordSet.count(data) == 0)
            {
                container.insert(data, page->getId());
            }
            p = q + 1;
        }
    }
    template<typename C>
    void custom_strpbrk(string const& s, char const* delims, C& ret, Container& container)
    {
        int count = 0;
        char const* p = s.c_str();
        char const* q = strpbrk(p+1, delims);
        for( ; q != NULL; q = strpbrk(p, delims) )
        {
            string data = typename C::value_type(p, q);
            transform(data.begin(), data.end(), data.begin(), ::tolower);
            stem(data);
            if (data.size() > 2 && data.size() < 30 && wordSet.count(data) == 0)
            {
                count += 1;
                container.insert(data, page->getId());
            }
            p = q + 1;
        }
        page->setWordCount(count);
        //cout << page->getWordCount() << endl;
    }
    template<typename C>
    void custom_strpbrk(string const& s, char const* delims, C& ret, IndexInterface* container)
    {
        int count = 0;
        char const* p = s.c_str();
        char const* q = strpbrk(p+1, delims);
        for( ; q != NULL; q = strpbrk(p, delims) )
        {
            string data = typename C::value_type(p, q);
            transform(data.begin(), data.end(), data.begin(), ::tolower);
            stem(data);
            if (data.size() > 2 && data.size() < 30 && wordSet.count(data) == 0)
            {
                count += 1;
                container->insert(data, page->getId());
            }
            p = q + 1;
        }
        page->setWordCount(count);
        //cout << page->getWordCount() << endl;
    }
};

#endif // PARSER_H

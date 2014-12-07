#ifndef PARSER_H
#define PARSER_H

#include "avltree.h"
#include "page.h"

#include "container.h"
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


class Parser
{
private: // Member Variables
    char const* delims = " \t[],-'/\\!%&=()<>?{}|._\n:;#~*+@^•—¡¿”“";
    ifstream read;
    vector <string> stopwords;
    vector <string> words;
    string buffer;
    set<string> wordSet;
    AVLTree <string> avl;

    Page* page;
    Container container;

    int totalPages;

    unordered_map <string, string> stemWords;

    //unordered_map <int, Page*> pages;

public: // Member Variables
    int count;
    unordered_map <int, Page*> pages;

public: // Constructor || Destructor
    Parser();
    Parser(Container&);
    Parser(Container&, ifstream&);

public: // Member Functions
    bool ReadConfig(char*);
    bool setupStopwords();
    void printPage();
    void openFile(char* file);
    void openFile(string file);
    void closeFile();
    bool readPage();
    void readThrough();
    void readThrough(Container& container);
    string& getTitle();
    string& getText();
    set <string> &getWordSet();
    vector <string> &getWords();

    void store();
    void store(Container& container);
    Container &getContainer();

    void buildPageTable();

private:
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
};

#endif // PARSER_H
#ifndef PARSER_H
#define PARSER_H

#include <avltree.h>
#include <page.h>

#include <container.h>
#include <custom_container.h>
//#include <stemmer.h>

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
    custom_container cc;
public: // Member Variables
    int count;

public: // Constructor || Destructor
    Parser();

public: // Member Functions
    bool ReadConfig(char*);
    bool setupStopwords();
    void printPage();
    void openFile(char* file);
    void closeFile();
    bool readPage();
    void readThrough();
    string& getTitle();
    string& getText();
    set <string> &getWordSet();
    vector <string> &getWords();

    void store();
    Container &getContainer();
    custom_container &getCustom_Container();

private:
    string readContent(ifstream& read, string tag);
    string readText(ifstream& read);
    bool invalidChar (char c);
    void stripUnicode(string & str);


public: // Templated Function
    template<typename C>
    void custom_strpbrk(string const& s, char const* delims, C& ret)
    {
        C output;

        char const* p = s.c_str();
        char const* q = strpbrk(p+1, delims);
        for( ; q != NULL; q = strpbrk(p, delims) )
        {
            string data = typename C::value_type(p, q);
            //data.erase(remove_if(data.begin(), data.end(), ::isspace ), data.end());
            transform(data.begin(), data.end(), data.begin(), ::tolower);
            //cout << typename C::value_type(p, q) << endl;
            if (wordSet.count(data) == 0 && data.size() > 2)
            {
                //words.push_back(data);
                //if(container.contains(data))
//                if (cc.contains(data))
//                {
//                    cout << "container contains " << data << "! Inserting id: " << page->getId() << endl;
//                    //container.search(data)->insertId(page->getId());
//                    cc.search(data)->insertId(page->getId());
//                }
//                else
//                {
//                    cout << "container doesn't contain " << data << "! Creating new Node " << data << " with id :" << page->getId() << endl;
//                    //container.insertNewWord(data, page->getId());
//                    cc.insert(data, page->getId());
//                    //count += 1;
//                    //cout << "number of words inside cc : " << count << endl;
//                }
                //cout << "inserting " << data << " and id: " << page->getId() << endl;
                cc.insert(data, page->getId());
            }

            p = q + 1;
        }
        //output.swap(ret);
    }
};

#endif // PARSER_H

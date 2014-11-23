#ifndef PARSER_H
#define PARSER_H

#include <avltree.h>
#include <page.h>

//#include <pugixml.hpp>
#include <container.h>
//#include <boost/algorithm/string.hpp>
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
    ifstream read;
    vector <string> stopwords;
    string buffer;
    set<string> wordSet;
    AVLTree <string> avl;

    Page* page;
    Container container;

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

    void store();


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
          transform(data.begin(), data.end(), data.begin(), ::tolower);
        if (wordSet.count(data) == 0)
        {
              //cout << data << " isn't' a stopword" << endl;
              //output.push_back(data);
              //avl.insert(data);
//            char* word = new char[data.size()];
//            strcat(word, data.c_str());
//            data[stem(word, 0, data.size() - 1) + 1] = 0;
//            delete word;
              if (container.contains(data))
              {
                  //cout << "OOPS " << data << " already exists!" << endl;
                  container.search(data)->insertId(page->getId());
                  //cout << "insert id : " << page->getId() << "to " << data << endl;
              }
              else
              {
                  container.insertNewWord(data, page->getId());
                  //cout << "insert : " << data << endl;
                  //container.search(data)->insertId(page->getId());
                  //cout << "insert id : " << page->getId() << " to " << data << endl;
              }
        }
        //else
            //cout << "deleting stopword " << data << " from string" << endl;
        p = q + 1;
      }

      //output.swap(ret);
    }
};

#endif // PARSER_H

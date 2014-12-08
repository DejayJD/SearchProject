#ifndef PAGE_H
#define PAGE_H

#include <string>

using namespace std;

// Page class stores every information of interest
// that is relevant and related to the page in the xml that has
// been parsed by the parser class. Page objects will be
// accessed if there is a need to get information of pages in
// the searchEngine
class Page
{
private: // Member Variables
    string title;
    string text;
    string username;
    int date;
    int id;
    int wordCount;
public: // Constructor || Destructor
    Page();
    ~Page();
public: // Setters || Getters
    string &getTitle();
    string &getText();
    string &getUsername();
    int getDate();
    int getId();
    int getWordCount();
    void setTitle(string&);
    void setTitle(string);
    void setUsername(string);    
    void setText(string&);
    void setText(string text);
    void setDate(int);
    void setId(int id);
    void setWordCount(int wordCount);
};

#endif // PAGE_H

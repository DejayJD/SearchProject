#ifndef PAGE_H
#define PAGE_H

#include <string>

using namespace std;

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

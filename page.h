#ifndef PAGE_H
#define PAGE_H

#include <string>

using namespace std;

class Page
{
private:
    string title;
    string text;
    string username;
    string date;
    int id;
public:
    Page();
    string &getTitle();
    string &getText();
    string &getUsername();
    string &getDate();
    int getId();
    void setTitle(string&);
    void setTitle(string);
    void setUsername(string);
    void setDate(string);
    void setText(string&);
    void setText(string text);
    void setId(int id);
};

#endif // PAGE_H

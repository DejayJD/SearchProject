#ifndef PAGE_H
#define PAGE_H

#include <string>

using namespace std;

class Page
{
private:
    string title;
    string text;
    int id;
public:
    Page();
    string &getTitle();
    string &getText();
    int getId();
    void setTitle(string&);
    void setTitle(string);
    void setText(string&);
    void setText(string text);
    void setId(int id);
};

#endif // PAGE_H

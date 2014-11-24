#include "page.h"

Page::Page()
{
}

string &Page::getTitle()
{
    return title;
}
string &Page::getText()
{
    return text;
}
int Page::getId()
{
    return id;
}

void Page::setTitle(string& title)
{
    this->title = title;
}

void Page::setTitle(string title)
{
    this->title = title;
}


void Page::setText(string& text)
{
    this->text = text;
}
void Page::setText(string text)
{
    this->text = text;
}
void Page::setId(int id)
{
    this->id = id;
}

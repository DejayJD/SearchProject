#include "page.h"

Page::Page()
{
    id = 0;
}

string &Page::getTitle()
{
    return title;
}
string &Page::getUsername()
{
    return username;
}

string &Page::getDate()
{
    return date;
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

void Page::setUsername(string username)
{
    this->username = username;
}

void Page::setDate(string date)
{
    this->date = date;
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

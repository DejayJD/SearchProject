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

string &Page::getText()
{
    return text;
}

int Page::getDate()
{
    return date;
}

int Page::getId()
{
    return id;
}

int Page::getWordCount()
{
    return wordCount;
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

void Page::setText(string& text)
{
    this->text = text;
}
void Page::setText(string text)
{
    this->text = text;
}

void Page::setDate(int date)
{
    this->date = date;
}

void Page::setId(int id)
{
    this->id = id;
}

void Page::setWordCount(int wordCount)
{
    this->wordCount = wordCount;
}

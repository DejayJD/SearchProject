#include "parser.h"

Parser::Parser()
{
}

Parser::Parser(Container& container)
{
    this->container = container;
}

Parser::Parser(Container& container, ifstream& read)
{
    this->container = container;
    //this->read = read;
}

bool Parser::readPage()
{
    char c;
    string buffer;
    string tag;

    if (read.is_open())
    {
        while (tag != "/page")
        {
            c = read.get();
            if(c == '<')
            {
                c = read.get();
                while (c != '>')
                {
                    tag.push_back(c);
                    c = read.get();
                }
                //cout << buffer << endl;

                // READS ONE PAGE
                if (tag == "page")
                {
                    //cout << "in page!" << endl;
                    page = new Page();
                    while (buffer != "/page")
                    {
                        while(c != '<')
                        {
                            c = read.get();
                        }
                        if (c == '<')
                        {
                            c = read.get();
                            while (c != '>')
                            {
                                buffer.push_back(c);
                                c = read.get();
                            }

                            if (buffer == "title")
                            {
                                page->setTitle(readContent(read, "title"));
                                //cout << "title : " << page->getTitle() << endl;
                            }
                            if (buffer == "username")
                            {
                                page->setUsername(readContent(read, "username"));
                                //cout << "username : " << page->getUsername() << endl;
                            }
                            if (buffer == "timestamp")
                            {
                                page->setDate(readContent(read, "date"));
                                //cout << "date : " << page->getDate() << endl;
                            }
                            if (buffer == "id")
                            {
                                if (page->getId() == 0)
                                {
                                    page->setId(stoi(readContent(read, "id")));
                                }
                                //cout << "id : " << page->getId() << endl;
                            }

                            if (buffer.find("text") != std::string::npos && !(buffer.find("/text") != std::string::npos))
                            {
                                page->setText((readText(read)));
                            }
                            if (buffer == "/page")
                            {
                                tag = buffer;
                                buffer.clear();
                                break;
                            }
                            buffer.clear();
                        }

                    }

                }
            }
            if (tag == "/page")
            {
                tag.clear();
                break;
            }
            tag.clear();
            if (read.eof()) break;
        }
    }
    return true;
}

bool Parser::setupStopwords()
{
    read.open("stopwords.txt");
    if(read.is_open())
    {
        while(!read.eof())
        {
            getline(read, buffer);
            stopwords.push_back(buffer);
        }
    }
    read.close();
    wordSet = set<string>(stopwords.begin(), stopwords.end());
}

string Parser::readContent(ifstream& read, string tag)
{
    string text;
    getline(read, text, '<');
    return text;
}

string Parser::readText(ifstream& read)
{
    string text;
    string word;
    char c;
    c = read.get();
    while (c != '<')
    {
        if(c > 127 || c < 0)
        {
            while (c > 127 || c < 0)
            {
                c = read.get();
            }
        }

        if(c == '[')
        {
            c = read.get();
            if (c == '[')
            {
                while (c != ']')
                {
                    c = read.get();
                }
                c = read.get();
            }
            else
            {
                break;
            }
            c = read.get();
        }

        if(c == '{')
        {
            c = read.get();
            if (c == '{')
            {
                while (c != '}')
                {
                    c = read.get();
                }
                c = read.get();
            }
            else
            {
                break;
            }
            c = read.get();
        }
//        if (c == '&')
//        {
//            c = read.get();
//            if (c == 'g' || c == 'l' || c == 'q' || c == 'a')
//            {
//                while (c != ';')
//                {
//                    c = read.get();
//                }
//                c = read.get();
//            }
//            else
//            {
//                break;
//            }
//            c = read.get();
//        }
        text.push_back(c);
        c = read.get();

    }
    return text;
}

void Parser::printPage()
{
    cout << "title is : " << page->getTitle() << endl;
    cout << "text is : " << page->getText() << endl;
}

void Parser::openFile(char* file)
{
        read.open(file);
}

void Parser::openFile(string file)
{
        read.open(file);
}

void Parser::closeFile()
{
    read.close();
}
void Parser::readThrough()
{
    count = 0;
    while(!read.eof())
    {
        count += 1;

        readPage();
        //pages.emplace(page->getId(), page);

        store();
    }

}
string& Parser::getTitle()
{
    return page->getTitle();
}

string& Parser::getText()
{
    return page->getText();
}
set <string> &Parser::getWordSet()
{
    return wordSet;
}

void Parser::store()
{
    custom_strpbrk(page->getText(), delims, words);
}

vector <string> &Parser::getWords()
{
    return words;
}
Container &Parser::getContainer()
{
    return container;
}

void Parser::buildPages()
{
    count = 0;
    while(!read.eof())
    {
        count += 1;

        readPage();
        pages.emplace(page->getId(), page);
    }
}


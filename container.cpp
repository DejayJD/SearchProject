#include "container.h"

Container::Container()
{
    wordcount = 0;  //take out later
    insertcount = 0;    //take out later
}

Container::~Container()
{

}

void Container::insert(string word, int id)
{
    if(contains(word))
    {
        search(word).insertId(id);
    }
    else
    {
        Node temp(word, id);
        hash.emplace(word, temp);
    }
}

void Container::insert(string word, int id, int frequency)
{
    if(contains(word))
    {
        search(word).insertId(id, frequency);
    }
    else
    {
        Node temp(word, id, frequency);
        hash.emplace(word, temp);
    }
}

Node& Container::search(string word) {
    auto search = hash.find(word);

    if ( search != hash.end() )
      return (search->second);
    else
      cerr << "Not found" << endl;
}
bool Container::contains(string word) {
    auto search = hash.find(word);

    if ( search != hash.end() )
      return true;
    else
      return false;
}

void Container::clearIndex()
{
    hash.clear();
}

unordered_map <string, Node> &Container::getHash()
{
    return hash;
}

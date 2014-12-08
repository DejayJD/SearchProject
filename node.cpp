#include "node.h"

Node::Node()
{

}

Node::Node(string &word)
{
    this->word = word;
}

Node::Node(string& word, int id)
{
    this->word = word;
    this->ids.emplace(id, FrequencyNode(id));
    incCount();
}

Node::Node(string& word, int id, int frequency)
{
    this->word = word;
    this->ids.emplace(id, FrequencyNode(id, frequency));
    incCount();
}

Node::~Node()
{

}

unordered_map<int, FrequencyNode> &Node::getIds()
{
    return ids;
}

string &Node::getWord()
{
    return word;
}

void Node::setWord(string word)
{
    this->word = word;
}

void Node::insertId(int id)
{
    if(exists(id))
    {
        unordered_map <int, FrequencyNode>::iterator got = ids.find(id);
        if (got == ids.end())
        {
            cout << "not found" << endl;
        }
        else
        {
            got->second.incFrequency();
        }

    }
    else
    {
        ids.emplace(id, FrequencyNode(id));
        incCount();
    }
}

void Node::insertId(int id, int frequency)
{
    ids.emplace(id, FrequencyNode(id, frequency));
    incCount();
}

bool Node::exists(int id)
{
    auto search = ids.find(id);
    if (search != ids.end())
        return true;
    else
        return false;
}

int Node::getCount()
{
    return ids.size();
}

void Node::incCount()
{
    count += 1;
}

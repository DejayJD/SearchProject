#ifndef NODE_H
#define NODE_H
#include "LinkedList.h"
#include <vector>
#include <unordered_map>

using namespace std;
class Node
{
private:
    string word;
    //vector <int> ids;
    unordered_map<int, int> ids;
public:
    Node(){}
    Node(string &word)
    {
        this->word = word;
    }

    Node(string& word, int id)
    {
        this->word = word;
        this->ids.emplace(id, id);
    }

    unordered_map<int, int> &getIds()
    {
        return ids;
    }

    string &getWord()
    {
        return word;
    }

    void insertId(int id)
    {
        if(exists(id))
        {
            return;
        }
        ids.emplace(id, id);
    }

    bool exists(int id)
    {
        auto search = ids.find(id);
        if (search != ids.end())
            return true;
        else
            return false;
    }

    friend ostream& operator<<(ostream& out, Node& node)
    {
        out << node.word;
        for (auto it = node.getIds().begin(); it != node.getIds().end(); ++it)
        {
            out << ", " << it->second;
        }
        return out;
    }
};

#endif // NODE_H

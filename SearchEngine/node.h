#ifndef NODE_H
#define NODE_H
#include <LinkedList.h>

using namespace std;
class Node
{
private:
    string word;
    LinkedList <int> ids;
public:
    Node(){}
    Node(string &word)
    {
        this->word = word;
    }

    Node(string& word, int id)
    {
        this->word = word;
        this->ids.insert(id);
    }

    LinkedList <int> &getIds()
    {
        return ids;
    }

    string &getWord()
    {
        return word;
    }

    void insertId(int id)
    {
        ids.insert(id);
    }

    friend ostream& operator<<(ostream& out, const Node& node)
    {
        out << node.word;
        return out;
    }
};

#endif // NODE_H

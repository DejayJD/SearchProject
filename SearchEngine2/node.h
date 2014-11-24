#ifndef NODE_H
#define NODE_H
#include <LinkedList.h>

using namespace std;
class Node
{
private:
    string word;
    int frequency;
    LinkedList <int> ids;
public:
    Node(){}
    Node(string &word)
    {
        this->word = word;
        frequency = 0;
    }

    Node(string& word, int id)
    {
        this->word = word;
        this->ids.insert(id);
        frequency = 1;
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
        frequency = 1;
    }

    friend ostream& operator<<(ostream& out, const Node& node)
    {
        out << node.word;
        return out;
    }

    void incrementFrequency()
    {
        frequency += 1;
    }

    bool searchId(int id)
    {
        return ids.contains(id);
    }

    //bool operator >()
};

#endif // NODE_H

#ifndef NODE_H
#define NODE_H
#include "frequencynode.h"
#include <vector>
#include <unordered_map>


using namespace std;
class Node
{
private: // Member Variables
    string word;
    unordered_map<int, FrequencyNode> ids;
public: // Constructor || Destructor
    Node();
    Node(string &word);
    Node(string& word, int id);
    Node(string& word, int id, int frequency);
    ~Node();
public: // Member Functions
    unordered_map<int, FrequencyNode> &getIds();
    string &getWord();
    void setWord(string word);
    void insertId(int id);
    void insertId(int id, int frequency);
    bool exists(int id);
    friend ostream& operator<<(ostream& out, Node& node)
    {
        out << node.word;
        for (auto it = node.getIds().begin(); it != node.getIds().end(); ++it)
        {
            out << " " << it->second;
        }
        out << " !";
        return out;
    }
};

#endif // NODE_H

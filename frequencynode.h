#ifndef FREQUENCYNODE_H
#define FREQUENCYNODE_H

#include <iostream>

using namespace std;

class FrequencyNode
{
private: // Member Variables
    int id;
    int frequency;
public: // Constructor || Destructor
    FrequencyNode();
    FrequencyNode(int id);
    FrequencyNode(int id, int frequency);
    ~FrequencyNode();

public: // Member Functions
    int getId();
    int getFrequency() const;
    void incFrequency();
    void setId(int);
    friend ostream& operator<<(ostream& out, FrequencyNode node)
    {
        out << node.id << "," << node.frequency;
        return out;
    }
    inline bool operator<(const FrequencyNode& rhs)
    {
        return this->getFrequency() < rhs.getFrequency();
    }
    inline bool operator>(const FrequencyNode& rhs)
    {
        return this->getFrequency() > rhs.getFrequency();
    }
};

#endif // FREQUENCYNODE_H

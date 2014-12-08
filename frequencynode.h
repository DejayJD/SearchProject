#ifndef FREQUENCYNODE_H
#define FREQUENCYNODE_H

#include <iostream>

using namespace std;

// This class is used to store and rebuild the inverse index with
// frequency value still attached to it
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
    void incFrequency();
    void setId(int);

public: // Getter || Setter
    int getId();
    int getFrequency() const;

public: // Operator Overload
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

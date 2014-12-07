#include "frequencynode.h"

FrequencyNode::FrequencyNode()
{
    id = 0;
    frequency = 0;
}

FrequencyNode::FrequencyNode(int id)
{
    this->id = id;
    frequency = 1;
}

FrequencyNode::FrequencyNode(int id, int frequency)
{
    this->id = id;
    this->frequency = frequency;
}

FrequencyNode::~FrequencyNode()
{

}

int FrequencyNode::getId()
{
    return id;
}

int FrequencyNode::getFrequency() const
{
    return frequency;
}

void FrequencyNode::incFrequency()
{
    frequency += 1;
}

void FrequencyNode::setId(int id)
{
    this->id = id;
}

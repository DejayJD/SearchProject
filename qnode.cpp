#include "qnode.h"

QNode::QNode()
{
}

QNode::QNode(int id, int freq, int date)
{
    this->date = date;
    this->id = id;
    this->freq = freq;
}

QNode::~QNode()
{

}

int QNode::getId()
{
    return id;
}

int QNode::getfreq() const
{
    return freq;
}
int QNode::getDate()
{
    return date;
}

double QNode::getTfidf() const
{
    return tfidf;
}

void QNode::setTfidf(double tfidf)
{
    this->tfidf = tfidf;
}

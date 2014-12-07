#ifndef QNODE_H
#define QNODE_H

class QNode
{
private: // Member Variables
    int date;
    int id;
    int freq;
    double tfidf;
public: // Constructor || Destructor
    QNode();
    QNode(int id, int freq, int date);
    ~QNode();
public: // Accessors
    int getId();
    int getfreq() const;
    int getDate();
    double getTfidf() const;
    void setTfidf(double);

    friend class Query;
    inline bool operator<(const QNode& rhs)
    {
        return this->getTfidf() < rhs.getTfidf();
    }
    inline bool operator>(const QNode& rhs)
    {
        return this->getTfidf() > rhs.getTfidf();
    }

};

#endif // QNODE_H

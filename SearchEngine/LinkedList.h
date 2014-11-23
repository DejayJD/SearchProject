#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>
using namespace std;

template <class T> class LinkedList
{
private:
    class Node
    {
    public: // Member Variables
        T data;
        Node * next;
        Node * prev;


    public: // Constructor || Destructor
        Node(T data1, Node * next1 = nullptr)
        {
            data = data1;
            next = next1;
        }
        ~Node()
        {
            delete next;
            next = nullptr;
        }

    public: // Member Functions
        void operator++(int)
        {
            this = this->next;
        }
        void operator--(int)
        {
            this = this->prev;
        }
    };

private: // Member Variables
    // List head & tail pointer
    Node * head, *tail;
    // position pointer for incrementing over the list
    Node *position;
    int length = 0;

public: // Constructor || Destructor
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        length = 0;
        position = head;
    }
    ~LinkedList()
    {
        delete head;
        head = nullptr;
    }

public : // Member Functions

    //inserts data to the head of the list
    void insertHead(T data)
    {
        Node *nodePtr = new Node(data);
        // invoked when list is empty
        if (head == nullptr)
        {
            head = nodePtr;
            tail = head;
            tail->next = nullptr;
            position = head;
        }
        // invoked when list not empty
        else
        {
            Node *temp = head;
            nodePtr->next = temp;
            temp->prev = nodePtr;
            nodePtr->prev = nullptr;
            head = nodePtr;
        }
        length += 1;
    }

    // inserts a data to the back of the list
    void insert(T data)
    {
        Node *nodePtr = new Node(data);
        // invoked when list is empty
        if (head == nullptr)
        {
            head = nodePtr;
            tail = head;
            tail->next = nullptr;
            position = head;
        }
        // invoked when list not empty
        else
        {
            Node *cur = head;
            while (cur->next != nullptr)
            {
                //cur->next->prev = cur;
                cur = cur->next;
            }
            cur->next = nodePtr;
            cur->next->prev = cur;
            cur = cur->next;
            tail = cur;
            tail->next = nullptr;
        }
        length += 1;
    }

    // removes a data from the linkedlist
    void remove(T data)
    {
        Node *nodePtr;
        Node *previousNodePtr;

        // If the list is empty, do nothing.
        if (!head)  return;

        // Determine if the first node is the one to delete.
        if ((head->data == data) && (length == 1))
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            length = 0;
        }
        else if (head->data == data)
        {
            head = head->next;
            previousNodePtr = head->prev;
            head->prev = nullptr;
            //delete previousNodePtr;
            length -= 1;
        }
        else
        {
             // Initialize nodePtr to the head of the list.
            nodePtr = head;

             // Skip nodes whose data member is not equal.
            while (nodePtr != nullptr && nodePtr->data != data)
            {
                previousNodePtr = nodePtr;
                nodePtr = nodePtr->next;
            }
             // Link the previous node to the node after
             // nodePtr, then delete nodePtr.
            if ((nodePtr) && (nodePtr == tail))
            {
                previousNodePtr->next = nodePtr->next;
                tail = previousNodePtr;
                delete nodePtr;
                length -= 1;
            }
            else if (nodePtr)
            {
                previousNodePtr->next = nodePtr->next;
                delete nodePtr;
                length -= 1;
            }
        }
    }

    // prints out the data in the whole list to the console
    void displayList()
    {
        Node *nodePtr = head; // Start at head of list
        while (nodePtr != tail)
        {
         // Print the data in the current node
            std::cout << nodePtr->data << std::endl;
         // Move on to the next node
            nodePtr = nodePtr->next;
        }
        cout << nodePtr->data << endl;
    }

    // searches through the list and returns the matching value
    T& search(T& data)
    {
        if (length == 0) // if the list doesn't have any entries
        {
            //return;
        }
        for (Node* nodePtr = head; nodePtr != tail; nodePtr++)
        {
            if(nodePtr->data == data)
                return nodePtr->data;
        }
    }

    // moves position to next unless it's tail
    void moveToNext()
    {
        if (position != tail)
        {
            position = position->next;
        }
    }

    // returns the next value while incrementing position
    T& getNext()
    {
        if (position != tail)
        {
            position = position->next;
            return position->data;
        }
    }

    // returns current position value
    T& getCurrent()
    {
        return position->data;
    }

    int getLength()
    {
        return length;
    }

    // resets position to initial state (head)
    void resetPosition()
    {
        position = head;
    }

    //gets the last element of the list
    T& getLast()
    {
        return tail->data;
    }
};
#endif // LINKEDLIST_H

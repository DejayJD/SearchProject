#include "linkedlist_container.h"

linkedlist_container::linkedlist_container()
{
}

void linkedlist_container::insert(Node *& node)
{
    if (list.empty())
    {
        list.insert(node);
    }
    else
    {
        if(node->getWord() == list.getCurrent()->getWord())
        {
            list.getCurrent()->insertId(node->getIds().getCurrent());
        }
        else
        {
            list._insert(node);

        }
    }
}

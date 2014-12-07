#include "avlcontainer.h"

avlContainer::avlContainer() : IndexInterface()
{
}

void avlContainer::insert(string word, int id) {
    Node* temp = &search(word);
    if(temp == nullptr) {
        delete temp;
        temp = new Node(word, id);
        tree.insert(temp);
    }
    else {
        temp->insertId(id);
    }
}

Node& avlContainer::search(string word) {
    Node* temp = tree.search(word);
    if(temp == nullptr) {
        return *temp;
    }
    else
        return *temp;
}

bool avlContainer::contains(string word) {
    Node* temp = &(search(word));
    if(temp == nullptr) return false;
    return true;
}

void avlContainer::clearIndex() {
    tree.~AVLTree();
    cout << "Index cleared." << endl;
}

avlContainer::~avlContainer() {

}

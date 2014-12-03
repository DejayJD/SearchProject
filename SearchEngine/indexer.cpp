#include "indexer.h"

Indexer::Indexer()
{
}

void Indexer::clearIndex() {
    container.clearIndex();
    return;
}

void Indexer::addWord(string word, int pageID) {

}
void Indexer::buildIndex() {
    ifstream fin("miniIndex.txt");
    if(!fin.is_open()) {
        cout << "File does not exits. Creating new index" << endl;
    }
}
void Indexer::createSmallIndex() {
    ofstream fout("miniIndex.txt");
}


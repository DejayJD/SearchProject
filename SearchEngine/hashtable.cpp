#include "hashtable.h"

hashTable::hashTable()
{
    table = new avlTable*[tableSize];
    for(int i = 0; i < tableSize; i++) {
        table[i] = nullptr;
    }

}
int hashTable::hashFunction(string word, unsigned int seed = 0) {
    const char* cword = word.c_str();
    unsigned hash = seed;
    while(*cword) {
        hash = hash * 101 + *cword++;
    }
    return hash % tableSize;
}

bool hashTable::hasElement(int element) {
    if(table[element] == nullptr)
        return false;
    else
        return true;
}

avlTable* hashTable::getAVLTable(int key) {
    if(!hasElement(key)) {
        cerr << "Table does not exist" << endl;
    }
    return table[key];
}

void hashTable::createTable(int key) {
    table[key] = new avlTable();
}

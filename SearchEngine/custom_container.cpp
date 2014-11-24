#include "custom_container.h"


custom_container::custom_container()
{
    wordcount = 0;  //take out later
    insertcount = 0;    //take out later
    //unordered_map<string, int> hash1(1000000);


}

void custom_container::insert(string word, int id) {
    if(contains(word)) {
        search(word).insertId(id);
    }
    else {
        Node temp(word, id);
        hash.emplace(word, temp);
    }

}
Node& custom_container::search(string word) {
    auto search = hash.find(word);

    if ( search != hash.end() )
      return (search->second);
    else
      cerr << "Not found" << endl;
}
bool custom_container::contains(string word) {
    auto search = hash.find(word);

    if ( search != hash.end() )
      return true;
    else
      return false;
}

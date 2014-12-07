#include <iostream>
#include <chrono>
#include "searchengine.h"
//#include "stemmer.h"
//#include "stem.h"
using namespace std;

int main(int argc, char** argv)
{
    SearchEngine se;
    se.hashTable();
//    string file = "WikiDumpPart3.xml";
    string file = "WikiBooks.xml";

    unsigned int totalMilliseconds = 0;
    //Parse time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

//    //se.store(); // stores initial page (hardcode.xml)
//    se.store(file);
    se.buildPageTable(file); // builds the Page Hash Table
    se.rebuildIndex();      // builds index from inverted index

    end = std::chrono::system_clock::now();
    unsigned int milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    totalMilliseconds += milliseconds;
    cout << "Parsing " << " Time: " << milliseconds << " milliseconds" << std::endl;

//    se.printIndex();
//    string sword = "Running";

//    se.search(sword);
    se.search2("fontenot");

//    string file2 = "xml.xml";
//    se.store(file2);

//    se.search("fontenot");

//    se.clearIndex();

//    se.search("fontenot");

    return 0;
}

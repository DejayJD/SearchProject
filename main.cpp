#include <iostream>
#include <chrono>
#include "searchengine.h"
//#include "stemmer.h"
//#include "stem.h"
using namespace std;

int main(int argc, char** argv)
{
    SearchEngine se;
//    string file = "WikiDumpPart3.xml";
    string file = "enwikibooks-20141026-pages-meta-current.xml";

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
    string sword = "Running";

    se.search(sword);
//    se.search("fontenot");

//    string file2 = "xml.xml";
//    se.store(file2);

//    se.search("fontenot");

//    se.clearIndex();

//    se.search("fontenot");

    se.displayPage(1);
    se.displayPage(2);
    se.clearSearch();
    se.displayPage(2);

    se.search("comedy");
    se.displayPage(5);
    return 0;
}
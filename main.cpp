#include <iostream>
//#include <parser.h>
#include <chrono>
#include "searchengine.h"
//#include "node.h"
//#include <avltree.h>
//#include <custom_container.h>

#define FILE_NUMBER 100;

using namespace std;

int main(int argc, char** argv)
{
    SearchEngine se;
    string file = "WikiDumpPart3.xml";

    unsigned int totalMilliseconds = 0;
    //Parse time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    //se.store(); // stores initial page (hardcode.xml)
    se.store(file);
    se.buildIndex();

    end = std::chrono::system_clock::now();
    unsigned int milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    totalMilliseconds += milliseconds;
    cout << "Parsing " << " Time: " << milliseconds << " milliseconds" << std::endl;

    //se.store();

    se.search("textbook");




//    se.search("textbook");

//    start = std::chrono::system_clock::now();
//    se.buildIndex();
//    end = std::chrono::system_clock::now();
//    milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
//    totalMilliseconds += milliseconds;
//    cout << "Parsing page only " << " Time: " << milliseconds << " milliseconds" << std::endl;

    cout << "Building Pages" << endl;
    se.buildPages();


    return 0;
}

#include <iostream>
#include <parser.h>
#include <chrono>
using namespace std;

int main(int argc, char** argv)
{
    Parser p;
    cout << "Parser Created" << endl;
    p.setupStopwords();
    cout << "setupWords" << endl;
    //p.openFile(argv[5]);
    p.openFile("WikiDump/WikiDumpPart1.xml");
    cout << "File Opened" << endl;


    unsigned int totalMilliseconds = 0;
    //Parse time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    p.readThrough();


    end = std::chrono::system_clock::now();
    unsigned int milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    totalMilliseconds += milliseconds;
    std::cout << "Parsing " << " Time: " << milliseconds << " milliseconds" << std::endl;

    p.readThrough();

    p.closeFile();
    cout << "File Closed" << endl;
//    cout << "There are " << p.count << " pages parsed!" << endl;
//    p.printPage();


    return 0;
}

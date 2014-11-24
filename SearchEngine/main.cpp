#include <iostream>
#include <parser.h>
#include <chrono>
#include "node.h"
//#include <custom_container.h>

#define FILE_NUMBER 100;

using namespace std;

int main(int argc, char** argv)
{
    Container con;
    Parser p;
    cout << "Parser Created" << endl;
    p.setupStopwords();
    cout << "setupWords" << endl;
    //p.openFile(argv[5]);
    p.openFile("WikiDumpPart1.xml");
    cout << "File Opened" << endl;


    unsigned int totalMilliseconds = 0;
    //Parse time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    p.readThrough();

    end = std::chrono::system_clock::now();
    unsigned int milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    totalMilliseconds += milliseconds;
    cout << "Parsing " << " Time: " << milliseconds << " milliseconds" << std::endl;

    p.closeFile();
    cout << "File Closed" << endl;
    cout << "There are " << p.count << " pages parsed!" << endl;

    string word = "textbook";
    cout << "Search the indes for: " << p.getCustom_Container().search(word).getWord() << endl;
    cout << "Page Ids containing " << word << " are:" << endl;
    typedef unordered_map<int,int> MyMap;
    MyMap temp = p.getCustom_Container().search(word).getIds();
    for(MyMap::const_iterator it = temp.begin(); it != temp.end(); it++) {
        int key = it -> first;
        cout <<"ids: " << (it->second) << endl;
    }

    cout << "Parsing " << " Time: " << milliseconds << " milliseconds" << std::endl;




//    for (int i = 0; i < p.getWords().size(); i++)
//    {
//        cout << p.getWords().at(i) << endl;
//    }

//    cout << "pages that contains david has ids: " << endl;
//    p.getContainer().search("david")->getIds().displayList();

//    cout << "pages that contains organic has ids: " << endl;
//    p.getContainer().search("organic")->getIds().displayList();

//    cout << "pages that contains light has ids: " << endl;
//    p.getContainer().search("light")->getIds().displayList();

//    string s = "dōshi&quot;&gt;どうし";
//    for (int i = 0; i < s.size(); i++)
//    {
//        char c = s[i];
//        cout << (int)c << endl;
//    }

//    string word = "word";
//    Node temp(word, 90);
//    temp.insertId(22);
//    temp.insertId(75);
//    temp.insertId(11);


    return 0;
}

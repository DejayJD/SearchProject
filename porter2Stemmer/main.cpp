/**
 * @file main.cpp
 * @author Sean Massung
 * @date September 2012
 *
 * An example using the Porter2Stemmer namespace.
 *
 * Words are read from the file diffs.txt
 *  (from http://snowball.tartarus.org/algorithms/english/diffs.txt)
 *  and compared against the correct output.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "porter2stemmer.h"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[])
{
    cout << "Starting" << endl;
    for (int i=0; i<2000000; i++)
    {
        string toStem="running";
        Porter2Stemmer::stem(toStem);
    }
    cout << "Done" << endl;
    return 0;
}

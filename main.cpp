#include <iostream>
#include <chrono>
#include "searchengine.h"
//#include "stemmer.h"
//#include "stem.h"
//#include "query.h"
using namespace std;

int main(int argc, char** argv)
{
    SearchEngine se;
//    string file = "enwikibooks-20141026-pages-meta-current.xml";

//    se.buildPageTable(file); // builds the Page Hash Table
//    se.rebuildIndex();      // builds index from inverted index

    int choice;
    do
    {
        cout << "Choose between 3 Modes!" << endl;
        cout << "1. Maintenance Mode" << endl
                << "2. Interactive Mode" << endl
                   << "3. Stress Test Mode" << endl;
        cout << "-1. to exit!" << endl;


        cin >> choice;
        cin.ignore();

        if (choice == 1) // Maintenance Mode
        {
            cout << "Starting Maintenance Mode!" << endl;
            int mChoice;
            do
            {
                cout << "What would you like to do?" << endl;
                cout << "1. Clear Index" << endl;
                cout << "2. Add Page(s)" << endl;
                cout << "3. Print Index" << endl;
                cout << "-1. to exit" << endl;

                cin >> mChoice;
                if(mChoice == 1) {
                    se.clearIndex();
                }
                else if(mChoice == 2) {
                    cout << "What is the name of the file to store to?" << endl;
                    string fileString;
                    cin >> fileString;
                    se.store(fileString);
                }
                else if(mChoice == 3) {
                    se.printIndex();
                }
                else if (mChoice == -1)
                {
                    cout << "Leaving Maintanance Mode..." << endl;
                }
                else
                {
                    cout << "Choose between <1-3>" << endl;
                }
            }   while (mChoice != -1);




        }
        else if (choice == 2) // Interactive Mode
        {
            cout << "Starting Interactive Mode!" << endl;

            cout << "AVLTree of HashTable as Data Structure?" << endl;
            cout << "1. AVLTree" << endl
                    << "2. HashTable" << endl;
            int pick = 0;
            while (pick != 1 || pick != 2)
            {
                cin >> pick;
                cin.ignore();

                if(pick == 1)
                {
                    se.avlTree();
                    cout << "AVLTree is constructed!" << endl;
                    break;
                }
                else if (pick == 2)
                {
                    se.hashTable();
                    cout << "HashTable is constructed!" << endl;
                    break;
                }
                else
                {
                    cout << "Please pick between <1-2>!" << endl;
                }
            }


            //se.clearIndex();
            string file = "Wikibooks.xml";

            se.buildPageTable(file); // builds the Page Hash Table
            se.rebuildIndex();      // builds index from inverted index
            string query;
            int rank;
            do
            {
                cout << "Enter Thine Query: \"<AND/OR> <q1> (NOT) <q2> (DATELT/DATEGT date1 DATEGT date2)" << endl;
                getline(cin, query);
                if(query == "exitprogram") break;


                try
                {
                    se.getQuery(query, 10);
                    se.sort();
                    se.printSearchResult();
                    do
                    {
                        cout << "Which document would you want to see? Input 0 if not interested..." << endl;
                        cin >> rank;
                        cin.ignore();
                        if (rank == 0) break;
                        else if (rank == -1)
                        {
                            string username;
                            cout << "Secret Feature! What username?" << endl;
                            getline(cin, username);
                            se.displayUsername(username);
                        }
                        se.getPageRank(rank);

                    }   while (rank != 0);
                }
                catch(const char* msg)
                {
                    cerr << msg << endl;
                }
            }   while (query != "exitprogram");

        }
        else if (choice == 3) // Stress Test Mode
        {
            cout << "Starting Stress Test Mode!" << endl;

        }
        else if (choice == -1)
        {
            cout << "Closing Search Engine..." << endl;
        }
        else
        {
            cout << "Please choose between <1-3>" << endl;
        }
    }   while(choice != -1);


    return 0;
}

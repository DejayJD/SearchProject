#include <iostream>
#include <chrono>
#include "searchengine.h"

using namespace std;

int main(int argc, char** argv)
{
    SearchEngine se;

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
                cout << "2. Store" << endl;
                cout << "3. Print Index" << endl;
                cout << "4. Search a word in the temporary Data Structure" << endl;
                cout << "-1. to exit" << endl;

                cin >> mChoice;
                if(mChoice == 1) {
                    se.clearIndex();
                }
                else if(mChoice == 2) {
                    cout << "What is the name of the file to store?" << endl;
                    string fileString;
                    cin >> fileString;
                    se.store(fileString);
                }
                else if(mChoice == 3) {
                    se.printIndex();
                }
                else if(mChoice ==4)
                {
                    cout << "word to search" << endl;
                    string word;
                    cin >> word;
                    se.search(word);
                }
                else if (mChoice == -1)
                {
                    cout << "Leaving Maintenance Mode..." << endl;
                    break;
                }
                else
                {
                    cout << "Choose between <1-4>" << endl;
                }
            }   while (mChoice != -1);




        }
        else if (choice == 2) // Interactive Mode
        {
            cout << "Starting Interactive Mode!" << endl;
            //se.clearIndex();

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

            // THIS WILL BE THE XML PAGES THAT CAN BE ACCESSED
            string file = "WikiBooks.xml";

            // builds the Page HashTable
            se.buildPageTable(file);
            // builds index from inverted index
            se.rebuildIndex();
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
            string filename;
            cout << "Starting Stress Test Mode!\nEnter Thine Filename: ";
            cin >> filename;
            ifstream fin(filename.c_str());
            chrono::time_point<chrono::system_clock> start, end;
            start = chrono::system_clock::now();
            while (!fin.eof())
            {
                cout << "Reading file" << endl;
                string temp;
                fin >> temp;
                if (temp=="LoadAVL") //DONE
                {
                    cout << "Loading index into AVL structure: " << endl;
                    se.avlTree();
                    cout << "AVLTree is constructed!" << endl;
                }
                if (temp=="LoadHash") //DONE
                {
                    cout << "Loading index into Hash: " << temp << endl;
                    se.hashTable();
                    cout << "AVLTree is constructed!" << endl;
                }
                if (temp=="BuildIndex") //DONE
                {
                    fin >> temp;
                    se.buildPageTable(temp); // builds the Page Hash Table
                    se.rebuildIndex();      // builds index from inverted index
                    cout << "Index is built" << endl;
                }
                if (temp=="AddFile") //DONE
                {
                    fin >> temp;
                    se.store(temp);
                    cout << "Added index: " << temp << endl;
                }
                if (temp=="ClearIndex")//DONE
                {
                    se.clearIndex();
                    cout << "Cleared index" << endl;
                }
                if (temp=="Query") //DONE
                {
                    fin.ignore();
                    getline(fin, temp);
                    se.getQuery(temp, 10);
                    se.sort();
                    se.printSearchResult();
                }
                if (temp=="FindPage") //DONE
                {
                    fin >> temp;
                    cout << "Finding page with rank: " << endl;
                    se.getPageRank(stoi(temp));
                }
                if (temp=="PrintIndex") // Done
                {
                    se.printIndex();
                }
            }
            end = chrono::system_clock::now();
            chrono::duration<double> elapsed_seconds = end - start;
            cout << "Stress Test time result: " << elapsed_seconds.count() << endl;

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

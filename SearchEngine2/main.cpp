#include <iostream>
#include <parser.h>
#include <chrono>
//#include <custom_container.h>
#include <linkedlist_container.h>

using namespace std;

void quickSort(vector <string> &arr, int left, int right)
{
    cout << "flag " << endl;
    int i = left, j = right;
    string tmp;
    string pivot = arr[(left + right) / 2];
    /* partition */
    while (i <= j)
    {
        while ((arr[i].length() < pivot.length()) || ((arr[i].length() == pivot.length()) && arr[i].compare(pivot) < 0))
        {
            i++;
        }
        while ((arr[j].length() > pivot.length()) || ((arr[j].length() == pivot.length()) && arr[j].compare(pivot) > 0))
        {
            j--;
        }
        if (i <= j)
        {
            cout << "flag " << endl;
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }

    }
    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}


int main(int argc, char** argv)
{
//    Container con;
    Parser p;
    cout << "Parser Created" << endl;
    p.setupStopwords();
    //p.openFile(argv[5]);
    p.openFile("WikiDumpPart1.xml");
    cout << "File Opened" << endl;


    unsigned int totalMilliseconds = 0;
    //Parse time
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    p.readThrough();

    p.closeFile();
    cout << "File Closed" << endl;
    cout << "There are " << p.count << " pages parsed!" << endl;

//    for (int i = 100; i < 200; i++)
//    {
//        cout << p.getWords().at(i) << endl;
//        //cout << p.nodes.at(i) << endl;
//    }
//    cout << p.getWords().size() << endl;

    cout << "sorting..." << endl;
    quickSort(p.getWords(), 0, p.getWords().size());

    cout << "done sorting!" << endl;

//    for (int i = 0; i < 200; i++)
//    {
//        cout << p.getWords().at(i) << endl;
//        //cout << p.nodes.at(i) << endl;
//    }

    //cout << p.nodes.size() << endl;
//    for (int i = 130000; i < 130100; i++)
//    {
//        cout << p.getWords().at(i) << endl;
//    }

    linkedlist_container lc;
    cout << "created container class" << endl;
    cout << "inserting words to container class..." << endl;
    for (int i = 0; i < p.getWords().size(); i++)
    {
        Node* temp = new Node(p.getWords().at(i), 1);
        lc.insert(temp);
        cout << "word " << i+1 << endl;
    }
    cout << "done inserting!" << endl;

    end = std::chrono::system_clock::now();
    unsigned int milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    totalMilliseconds += milliseconds;
    cout << "Parsing " << " Time: " << milliseconds << " milliseconds" << std::endl;

    //lc.list.displayList();
//    string s = "s";
//    string b = "s";
//    string c = "a";
//    Node* n = new Node(s, 1);
//    Node* z = new Node(s, 2);
//    Node* a = new Node(b, 4);
//    Node* q = new Node(c, 10);
//    lc.insert(n);
//    lc.insert(n);
//    lc.insert(z);
//    lc.insert(a);
//    lc.insert(q);
//    lc.list.getCurrent()->getIds().displayList();



    return 0;
}

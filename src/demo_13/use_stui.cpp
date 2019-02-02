// use_stui.cpp -- using a class with private inheritance
// compile with studenti.cpp
#include <iostream>
#include "demo_13/studenti.h"

using std::cin;
using std::cout;
using std::endl;

void set(Studenti & sa, int n);

const int pupils = 3;
const int quizzes = 5;

int use_stui_test()
{
    Studenti ada[pupils] = 
        {Studenti(quizzes), Studenti(quizzes), Studenti(quizzes)};

    int i;
    for (i = 0; i < pupils; i++)
        set(ada[i], quizzes);
    cout << "\nStudent List:\n";
    for (i = 0; i < pupils; ++i)
        cout << ada[i].Name() << endl;
    cout << "\nResults:";
    for (i = 0; i < pupils; i++)
    {
        cout << endl << ada[i];
        cout << "average: " << ada[i].Average() << endl;
    }
    cout << "Done.\n";
    // cin.get();
    return 0;
}

void set(Studenti & sa, int n)
{
    cout << "Please enter the student's name: ";
    getline(cin, sa);
    cout << "Please enter " << n << " quiz scores:\n";
    for (int i = 0; i < n; i++)
        cin >> sa[i];
    while (cin.get() != '\n')
        continue; 
}

#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

string getCurrentDate()
{
    time_t t = time(0); // get time now
    tm *now = localtime(&t);
    string date = to_string(now->tm_mday) + " - " + to_string(now->tm_mon) + " - " + to_string(now->tm_yday);
    return date;
}

void add(string title)
{
    string desc;
    ofstream logStore;
    logStore.open("../site-data/logs.csv", ios_base::app); // to open file in append mode

    cout << "Enter description (markdown links and images allowed): \n";
    getline(cin, desc);

    string divider = " | ";

    logStore << getCurrentDate() << divider << title << divider << desc << "\n";
    cout << title << " added successfully \n";
}
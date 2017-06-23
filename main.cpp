/*
    Primzahlenrechner 2.0
    C++ 2012
    Durchschnittszeit für Primzahlen von 1 - 50000:
    6.145s

    ToDo:
        - Zeit
        - Multitasking
*/


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool calcPrim(unsigned long long var);

int main()
{
    unsigned long long start, end, cur;
    unsigned long long count = 0;
    bool ifPrim;
    string filename;

    cout << "Startzahl:" << endl;
    cin >> start;
    cur = start;

    cout << "Endzahl:" << endl;
    cin >> end;

    cout << "Dateiname: ";
    cin >> filename;

    ofstream txtfile (filename.c_str());

    do
    {
        ifPrim = calcPrim(cur);

        if(ifPrim == true && cur != 1)
        {
            txtfile << cur << endl;
            cout << cur << endl;
            count++;
            cur++;
        }
        else
        {
            cur++;
        }
    }
    while(cur <= end);

    txtfile.close();

    cout << "Primzahlen gefunden: " << count << endl;
    cout << "Bereich: " << start << " - " << end << endl;
    cout << "Datei \"" << filename << "\" wurde erfolgreich erstellt" << endl;

    cout << endl;
    cout << "[ENTER] zum Beenden druecken..." << endl;

    cin.ignore();
    cin.get();

    return 0;
}

bool calcPrim(unsigned long long var)
{
    unsigned long long mod;

    for(int i = 2; i <= var; i++)
    {
        mod = var % i;

        if(mod == 0 && i != var)
        {
            return 0;
        }
    }

    return 1;
}

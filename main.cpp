/*
    Primzahlenrechner 2.0
    C++ 2012
    Durchschnittszeit für Primzahlen von 1 - 50000:
    6.145s
*/


#include <iostream>
using namespace std;

bool calcPrim(int var);

long long main()
{
    int start, end, cur;
    int count = 0;
    bool ifPrim;

    cout << "Startzahl:" << endl;
    cin >> start;
    cur = start;

    cout << "Endzahl:" << endl;
    cin >> end;

    do
    {
        ifPrim = calcPrim(cur);

        if(ifPrim == true && cur != 1)
        {
            count++;
            cout << cur << endl;
            cur++;
        }
        else
        {
            cur++;
        }
    }
    while(cur <= end);

    cout << "Primzahlen gefunden: " << count << endl;
    cout << "Bereich: " << start << " - " << end << endl;
    cout << "Es wurden keine Aufzeichnungnen erstellt." << endl;

    return 0;
}

bool calcPrim(int var)
{
    int mod;

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

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{

    Wektor W(1,1,1);
    Macierz M;
    cout << "Wprowadzenie macierzy(>>)" << endl;
    for (int i = 0; i < ROZMIAR; i++) {
        cin >> M[i];
    }

    cout << endl << " Start programu " << endl << endl;
    cout << "Dzialanie wektora(<<) i konstruktor domyslny" << endl;
    cout << W << endl << "//////////////" << endl;
    cout << "Dzialanie macierzy(<<)" << endl;
    cout << M << endl;
    cout << "Dzialanie operacji na macierzach:" << endl;
    cout << "Odejmowanie" << endl;
    cout << M[1] - M[2] << endl;
    cout << "Dodawanie" << endl;
    cout << M[0] + M[2] << endl;
    cout << "Mnozenie" << endl;
    cout << M[1] * M[2] << endl;
    cout << "Dzielenie przez skalar" << endl;
    cout << M[1] / 2 << endl;
}

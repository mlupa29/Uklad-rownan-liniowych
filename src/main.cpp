#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



using namespace std;



int main()
{

    UkladRownanLiniowych ukl;
    cin >> ukl;
    cout << ukl << endl;
    ukl.oblicz();
    ukl.blad();

}

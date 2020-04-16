#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <cmath>
#include "Macierz.hh"
#include "Wektor.hh"


class UkladRownanLiniowych {
    Macierz M;
    Wektor W;
    Wektor wynik;
public:
    Macierz get_M()const { return M; }
    Wektor get_W()const { return W; }
    Macierz& set_M() { return M; }
    Wektor& set_W() { return W; }
    void oblicz();
    void blad();

};



std::istream& operator >> (std::istream& Strm, UkladRownanLiniowych& UklRown);



std::ostream& operator << (std::ostream& Strm,
    const UkladRownanLiniowych& UklRown
    );


#endif

#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include <iostream>
#include "Wektor.hh"
#include <algorithm>

class Macierz {

    Wektor Tab[ROZMIAR];
  
public:
    Macierz();
    Wektor operator[] (int i) const;
    Wektor& operator[] (int i);

    double Wyznacznik() const;
    void Transpozycja(Macierz & Mc);

   /* const Macierz  operator + (const Macierz & W) const;
    const Macierz  operator - (const Macierz & W) const;
    const Macierz  operator * (const Macierz & W) const;
   */
    Wektor  operator * (const Wektor& W);
};

std::istream& operator >> (std::istream & Strm, Macierz & Mac);

std::ostream& operator << (std::ostream & Strm, const Macierz & Mac);


#endif

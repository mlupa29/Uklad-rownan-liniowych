#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include <iostream>
#include "Wektor.hh"


class Macierz {

    Wektor Tab[ROZMIAR];
  
public:
    Macierz();
    Wektor operator[] (int i) const;
    Wektor& operator[] (int i);

};

std::istream& operator >> (std::istream & Strm, Macierz & Mac);

std::ostream& operator << (std::ostream & Strm, const Macierz & Mac);


#endif

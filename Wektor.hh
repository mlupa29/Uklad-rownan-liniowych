#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */

class Wektor {
    double Tab[ROZMIAR];

public:
    double operator[] (int i) const;
    double& operator[] (int i);

    Wektor operator +(Wektor W);
    Wektor operator -(Wektor W);
    double operator *(Wektor W);
    Wektor operator /(double skalar);
    Wektor operator *(double skalar);

};


std::istream& operator >> (std::istream& Strm, Wektor& Wek);


std::ostream& operator << (std::ostream& Strm, const Wektor& Wek);

#endif

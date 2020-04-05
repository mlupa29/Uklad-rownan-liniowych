#include "Wektor.hh"


Wektor::Wektor()
{
    Tab[0] = 0;
    Tab[1] = 0;
    Tab[2] = 0;
}

Wektor::Wektor(double x, double y, double z)
{
    Tab[0] = x;
    Tab[1] = y;
    Tab[2] = z;
}


Wektor Wektor::operator +(Wektor W)
{
    Wektor Wynik;
    for (int i = 0; i < ROZMIAR; i++)
        Wynik[i] = Tab[i] + W[i];
    return Wynik;
}
Wektor Wektor::operator -(Wektor W)
{
    Wektor Wynik;
    for (int i = 0; i < ROZMIAR; i++)
        Wynik[i] = Tab[i] - W[i];
    return Wynik;
}
double Wektor::operator *(Wektor W)
{
    double Wynik = 0;
    for (int i = 0; i < ROZMIAR; i++)
        Wynik += Tab[i] * W[i];
    return Wynik;
}

Wektor Wektor::operator /(double skalar)
{
    //Nie wiem czy nie zaagresywne bo konczy dzialanie calego programu???
    if (skalar == 0)
    {
        std::cerr << "skalar musi byc rozny !=0";
        std::exit(EXIT_FAILURE);
    }
    else {
        Wektor Wynik;
        for (int i = 0; i < ROZMIAR; i++)
            Wynik[i] = Tab[i] / skalar;
        return Wynik;
    }
}

Wektor Wektor::operator *(double skalar)
{
    Wektor Wynik;
    for (int i = 0; i < ROZMIAR; i++)
        Wynik[i] = Tab[i] * skalar;
    return Wynik;
}

double Wektor::operator[] (int i) const
{
    return Tab[i];
}

double & Wektor::operator[] (int i)
{
    return Tab[i];
}

std::istream & operator >> (std::istream & Strm, Wektor & Wek)
{
    for (int i = 0; i < ROZMIAR; i++)
        Strm >> Wek[i];

    return Strm;
}

std::ostream & operator << (std::ostream & Strm, const Wektor & Wek)
{
    for (int i = 0; i < ROZMIAR; i++)
        Strm << Wek[i] << " ";

    return Strm;
}

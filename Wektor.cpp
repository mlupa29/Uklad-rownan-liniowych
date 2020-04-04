#include "Wektor.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
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
    Wektor Wynik;
    for (int i = 0; i < ROZMIAR; i++)
        Wynik[i] = Tab[i] / skalar;
    return Wynik;
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

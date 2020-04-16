#include "Macierz.hh"

Macierz::Macierz()
{
	
}

Wektor Macierz::operator[] (int i) const
{
    return Tab[i];
}
Wektor & Macierz::operator[] (int i)
{
    return Tab[i];
}


//Algorytm Wyznacznika Metody Gaussa
double Macierz::Wyznacznik() const
{
    Macierz kop = *this;
    int p = 0;
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = i + 1; j < ROZMIAR; j++)
        {
            if (kop[i][i] == 0)
            {
                p++;
                std::swap(kop[i], kop[j]);
            }
        }
        if (kop[i][i] == 0)
            return 0;
        for (int j = i + 1; j < ROZMIAR; j++)
        {
            kop[j] = kop[j] - kop[i] * kop[j][i] / kop[i][i];
        }
    }
    double wyznacznik = 1;
    for (int i = 0; i < ROZMIAR; i++)
    {
        wyznacznik *= kop[i][i];
    }
    if (p % 2 == 0)
    {
        return wyznacznik;
    }
    return -wyznacznik;
}


//kopiowanie domyslne przez kompilator
void Macierz::Transpozycja(Macierz & Mc) {
    Macierz P;
    P = Mc;
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            (Mc[j])[i] = (P[i])[j];
        }
    }
}

//Macierz * Wertor
Wektor  Macierz::operator * (const Wektor& W)
{
    Transpozycja(*this);
    Wektor wynik;
    for (int i = 0; i < ROZMIAR; i++)
        wynik[i] = Tab[i] * W;

    return wynik;

}

//Okazaly sie niepotrzebne dla Gaussa
/*
Macierz const Macierz::operator+(const Macierz & W)const {
    Macierz S;
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            (S[j])[i] = (Tab[j])[i] + (W[i])[j];

        }
    }
    return S;
}

Macierz const Macierz::operator-(const Macierz & W)const {
    Macierz S;
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            (S[j])[i] = (Tab[j])[i] - (W[i])[j];

        }
    }
    return S;
}


Macierz const Macierz::operator*(const Macierz & W)const {
    Macierz S;
    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = 0; j < ROZMIAR; j++) {
            double s = 0;
            for (int k = 0; k < ROZMIAR; k++) s += (Tab[i])[k] * (W[k])[j];
            (S[j])[i] = s;

        }
    }
    return S;
}
*/
std::istream & operator >> (std::istream & Strm, Macierz & Mac)
{
    for (int i = 0; i < ROZMIAR; i++)
        Strm >> Mac[i];

    return Strm;
}

std::ostream & operator << (std::ostream & Strm, const Macierz & Mac)
{
    for (int i = 0; i < ROZMIAR; i++)
        Strm << Mac[i] << std::endl;

    return Strm;
}

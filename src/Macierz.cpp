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

double Macierz::Wyznacznik() const
{
    double sp_sum = 0;
    double sm_sum = 0;
    sp_sum = (Tab[0])[0] * (Tab[1])[1] * (Tab[2])[2] + (Tab[0])[1] * (Tab[1])[2] * (Tab[2])[0] + (Tab[0])[2] * (Tab[1])[0] * (Tab[2])[1];
    sm_sum = (Tab[2])[0] * (Tab[1])[1] * (Tab[0])[2] + (Tab[2])[1] * (Tab[1])[2] * (Tab[0])[0] + (Tab[2])[2] * (Tab[1])[0] * (Tab[0])[1];
    return sp_sum - sm_sum;
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

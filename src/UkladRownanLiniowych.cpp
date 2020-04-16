#include "UkladRownanLiniowych.hh"

//wychodza zera dla zestawu przykladowego ale to chyba wina przyblizen kompilatora
void UkladRownanLiniowych::blad()
{
    Wektor W_blad = M * wynik - W;
    std::cout << "wektor bledu" << W_blad << std::endl;
    std::cout << "dlugosc wektor bledu" << sqrt(W_blad * W_blad) << std::endl;
}
void UkladRownanLiniowych::oblicz()
{
    Macierz kop = M;
    double wyzn = kop.Wyznacznik();
    if (wyzn == 0)
    {
        for (int i = 0; i < ROZMIAR; i++)
        {
            kop = M;
            kop[i] = W;
            if (kop.Wyznacznik() == 0)
            {
                std::cout << "uklad nioznaczony" << std::endl;
                return;
            }


        }

        std::cout << "brak rozwiazan" << std::endl;
    }

    std::cout << "wektor rozwiazania" << std::endl;
    for (int i = 0; i < ROZMIAR; i++)
    {
        kop = M;
        kop[i] = W;
        wynik[i] = kop.Wyznacznik() / wyzn;
        std::cout << wynik[i] << " ";
    }
    std::cout << std::endl;

}
std::istream& operator >> (std::istream& Strm, UkladRownanLiniowych& UklRown)
{
    Strm >> UklRown.set_M() >> UklRown.set_W();
    return Strm;
}

std::ostream& operator << (std::ostream& Strm, const UkladRownanLiniowych& UklRown)
{
    Strm << "M^T" << std::endl;
    Strm << UklRown.get_M();
    Strm << "Wektor wyrazow wolnych" << std::endl;
    Strm << UklRown.get_W();

    return Strm;
}
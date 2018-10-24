#include "CWieza.h"
#include "CFigura.h"


    CWieza::CWieza(char kolorek) : CFigura(kolorek) {}
    CWieza::~CWieza() {}

    char CWieza::ZnakPionka()
    {
        return 'W';
    }
    bool CWieza::Ruch(int PWiersz, int PKolumna, int KWiersz, int KKolumna, CFigura * Tabliczka[8][8])
    {
        if (PWiersz == KWiersz)         // realizacja poruszania się wzdłuż wierszy
        {
            int RoznicaKolumn = (KKolumna - PKolumna>0) ? 1 : -1;        //jeżeli ruch w prawo przypisanie RoznicaKolumn=1 jezeli w lewo RoznicaKolumn=-1
            for (int SprawdzanaKolumna = PKolumna + RoznicaKolumn; SprawdzanaKolumna != KKolumna; SprawdzanaKolumna = SprawdzanaKolumna + RoznicaKolumn)
            {                                                    // sprawdzenie po kolei czy nic nie stoi na drodze
                if (Tabliczka[PWiersz][SprawdzanaKolumna] != 0) // jezeli cel jest zajety zwraca false
                {
                    return false;
                }
            }
            return true;
        }

        else if (PKolumna == KKolumna)        //realizacja poruszania się wzdłuż kolumn
        {
            int RoznicaWierszy = (KWiersz - PWiersz>0) ? 1 : -1;    //jeżeli ruch w dół przypisanie RoznicaWierszy=1 jezeli w góre RoznicaWierszy=-1
            for (int SprawdzanyWiersz = PWiersz + RoznicaWierszy; SprawdzanyWiersz != KWiersz; SprawdzanyWiersz = SprawdzanyWiersz + RoznicaWierszy)
            {                                                         // sprawdzenie po kolei czy nic nie stoi na drodze
                if (Tabliczka[SprawdzanyWiersz][PKolumna] != 0)       //jeżeli cel jest zajęty zwraca false
                {
                    return false;
                }
            }
            return true;
        }
        else
            return false;
    }

#include "CSkoczek.h"
#include "CFigury.h"



    CSkoczek::CSkoczek(char kolorek) : CFigury(kolorek) {}
    CSkoczek::~CSkoczek() {}

    char CSkoczek::ZnakPionka()
    {
        return 'L';
    }
    bool CSkoczek::Ruch(int PWiersz, int PKolumna, int KWiersz, int KKolumna, CFigury * Tabliczka[8][8])
    {
        if ((KKolumna - PKolumna == KWiersz - PWiersz) || (KKolumna - PKolumna == PWiersz - KWiersz))  // ogólna definicja ruchu skoczka po skosie(zmiana takiej samej ilosci kolumn i wierszy)

        {
            int RoznicaKolumn = (KKolumna - PKolumna>0) ? 1 : -1;    //ruch w prawa strone planszy RoznicaKolumn=1 w lewa RoznicaKolumn=-1
            int RoznicaWierszy = (KWiersz - PWiersz>0) ? 1 : -1;     //ruch w dół planszy RoznicaWierszy=1 w góre RoznicaWierszy=-1
            int SprawdzanaKolumna;
            int SprawdzanyWiersz;
            for (SprawdzanyWiersz = PWiersz + RoznicaWierszy, SprawdzanaKolumna = PKolumna + RoznicaKolumn;                 //for odpowiada za sprawdzenie pole po polu czy nic
                SprawdzanyWiersz != KWiersz;                                                                                //nie stoi na drodze skoczka
                SprawdzanyWiersz = SprawdzanyWiersz + RoznicaWierszy, SprawdzanaKolumna = SprawdzanyWiersz + RoznicaKolumn) // aż do celu
            {
                if (Tabliczka[SprawdzanyWiersz][SprawdzanaKolumna] != 0)                                                     //jeżeli cel nie jest pusty zwraca false
                {
                    return false;
                }
            }
            return true;
        }
        return false;                         //WYDAJE MI SIE ZE POWINNO BYĆ ELSE {} !!!!!!!!!!!!!!
    }

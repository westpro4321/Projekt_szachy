#include "CKrolowa.h"
#include "CFigura.h"


	CKrolowa::CKrolowa(char kolorek) : CFigura(kolorek, "Queen") {}
    CKrolowa::~CKrolowa() {}

    char CKrolowa:: ZnakPionka()
    {
        return 'Q';
    }
	bool CKrolowa::Ruch(int PWiersz, int PKolumna, int KWiersz, int KKolumna, CFigura * Tabliczka[8][8])

    {


        if (PWiersz == KWiersz) {                 //ruch wzdłuż wierszy

            int RoznicaKolumn = (KKolumna - PKolumna > 0) ? 1 : -1;   //ruch w prawa strone planszy RoznicaKolumn=1 w lewa RoznicaKolumn=-1
            for (int SprawdzanaKolumna = PKolumna + RoznicaKolumn; SprawdzanaKolumna != KKolumna;      //sprawdzenie pole po polu czy nic nie stoi na drodze <--->
                SprawdzanaKolumna = SprawdzanaKolumna + RoznicaKolumn) {
                if (Tabliczka[PWiersz][SprawdzanaKolumna] != 0) {      //BYŁ BŁĄD W Tabliczka[!!!][]
                    return false;
                }
            }                                                          //    ^
            return true;                                               //    |
        }                                                            //      |
        else if (KKolumna == PKolumna) {          //ruch wzdłuż kolumn       |
                                                                     //
            int RoznicaWierszy = (KWiersz - PWiersz> 0) ? 1 : -1;   //ruch w górę planszy RoznicaWierszy=1 w dół RoznicaWierszy=-1
            for (int SprawdzanyWiersz = PWiersz + RoznicaWierszy; SprawdzanyWiersz != KWiersz;
                SprawdzanyWiersz = SprawdzanyWiersz + RoznicaWierszy) {                             //sprawdzenie pole po polu czy nic nie stoi na drodze
                if (Tabliczka[SprawdzanyWiersz][PKolumna] != 0) {                                  //jeżeli cel nie jest pusty zwraca false
                    return false;
                }
            }
            return true;
        }
        else if ((KKolumna - PKolumna == KWiersz - PWiersz) || (KKolumna - PKolumna == PWiersz - KWiersz))        // ogólna definicja ruchu po skosie

        {
            int RoznicaKolumn = (KKolumna - PKolumna>0) ? 1 : -1;         //tak samo jak dla skoczka
            int RoznicaWierszy = (KWiersz - PWiersz>0) ? 1 : -1;
            int SprawdzanaKolumna;
            int SprawdzanyWiersz;
            for (SprawdzanyWiersz = PWiersz + RoznicaWierszy, SprawdzanaKolumna = PKolumna + RoznicaKolumn;
                SprawdzanyWiersz != KWiersz;
                SprawdzanyWiersz = SprawdzanyWiersz + RoznicaWierszy, SprawdzanaKolumna = SprawdzanyWiersz + RoznicaKolumn)
            {
                if (Tabliczka[SprawdzanyWiersz][SprawdzanaKolumna] != 0)
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }



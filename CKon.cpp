#include "CKon.h"
#include "CFigura.h"


   CKon::CKon(char kolorek) : CFigura(kolorek, "Horse") {}
   CKon::~CKon() {}

    char CKon::ZnakPionka()
    {
        return 'H';
    }
    bool CKon::Ruch(int PWiersz, int PKolumna, int KWiersz, int KKolumna, CFigura * Tabliczka[8][8])
    {

        if ((PKolumna == KKolumna + 1) || (PKolumna == KKolumna - 1)) {       // przemieszczenie w lewo lub prawo (wzgl kolumn)     RUCH DWA WZDŁUŻ KOLUMNY POTEM LEWO LUB PRAWO
            if ((PWiersz == KWiersz + 2) || (PWiersz == KWiersz - 2)) {       // przemiszczenie w dół lub góre (wzgl wierszy)       OGÓLNE DLA OBU KOLORÓW
                return true;
            }
        }
        if ((PKolumna == KKolumna + 2) || (PKolumna == KKolumna - 2)) {       // przemieszczenie w lewo lub prawo (kol)             RUCH DWA WZDŁUŻ WIERSZA POTEM GÓRA LUB DÓŁ
            if ((PWiersz == KWiersz + 1) || (PWiersz == KWiersz - 1)) {       // przemieszczenie w lewo lub prawo (wier)            OGÓLNE DLA OBU KOLORÓW
                return true;
            }
        }                                                                     //BRAK SPRAWDZERNIA CZY JEST PUSTY CEL ?!?!?!
        return false;
    }

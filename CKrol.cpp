#include "CKrol.h"
#include "CFigura.h"



	CKrol::CKrol(char kolorek) : CFigura(kolorek, "King") {}
    CKrol::~CKrol() {}

    char CKrol::ZnakPionka()
    {
        return 'K';
    }
    bool CKrol::Ruch(int PWiersz, int PKolumna, int KWiersz, int KKolumna, CFigura * Tabliczka[8][8])
    {
        int RoznicaWierszy = KWiersz - PWiersz;
        int RoznicaKolumn = KKolumna - PKolumna;
        if (((RoznicaWierszy >= -1) && (RoznicaWierszy <= 1)) &&     //ruch o jedno pole w kazdym z kierunków
            ((RoznicaKolumn >= -1) && (RoznicaKolumn <= 1)))
        {
            return true;
        }
        return false;
    }


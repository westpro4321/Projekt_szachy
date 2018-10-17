#include "CKrol.h"
#include "CFigury.h"



    CKrol::CKrol(char kolorek) : CFigury(kolorek) {}
    CKrol::~CKrol() {}

    char CKrol::ZnakPionka()
    {
        return 'K';
    }
    bool CKrol::Ruch(int PWiersz, int PKolumna, int KWiersz, int KKolumna, CFigury * Tabliczka[8][8])
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


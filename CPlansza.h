#ifndef CPLANSZA_H
#define CPLANSZA_H
#include "CKrol.h"
#include "CKrolowa.h"
#include "CSkoczek.h"
#include "CKon.h"
#include "CWieza.h"
#include "CPion.h"
#include "CFigura.h"

class CPlansza
{

public:



    CPlansza();
    ~CPlansza();
    void DrukujPlansze();
    bool Szach(char kolorek);
    bool MozliwoscUcieczki(char kolorek);
	CFigura * Tablica[8][8];
};


#endif // CPLANSZA_H

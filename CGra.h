#ifndef CGRA_H
#define CGRA_H
#include "CFigura.h"
#include "CPlansza.h"

class CGra
{

public:
    CGra();
    ~CGra();
    void Start();
	void WykonajRuch(CFigura*tabliczka[8][8]);
    void ZmianaZawodnika();
    bool SzachMat();

private:
    CPlansza Szachownica;
    char KolejGracza;

};


#endif // CGRA_H

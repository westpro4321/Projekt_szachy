#ifndef CPLANSZA_H
#define CPLANSZA_H

#include "CFigura.h"

class CPlansza
{
public:
    CPlansza();
    ~CPlansza();
    bool Szach(char kolorek);
    bool MozliwoscUcieczki(char kolorek);
	void PrzesunFigure(QPoint pocz, QPoint doc);

	CFigura * Tablica[8][8];
};


#endif // CPLANSZA_H

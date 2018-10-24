#ifndef CPION_H
#define CPION_H
#include "CFigura.h"

class CPion : public CFigura
{
public:
    CPion(char kolorek);//konstruktor nadający kolor
    ~CPion();           // destruktor
private:
    virtual char ZnakPionka(); //Znak w konsoli , w GUI będzie to grafika dla danej figury

	bool Ruch(int PWiersz, int PKolumna, int KWiersz, int KKolumna, CFigura * Tabliczka[8][8]);
};

#endif // CPION_H

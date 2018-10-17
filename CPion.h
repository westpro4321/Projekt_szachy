#ifndef CPION_H
#define CPION_H
#include "CFigury.h"

class CPion : public CFigury
{
public:
    CPion(char kolorek);//konstruktor nadający kolor
    ~CPion();           // destruktor
private:
    virtual char ZnakPionka(); //Znak w konsoli , w GUI będzie to grafika dla danej figury

    bool Ruch(int PWiersz, int PKolumna, int KWiersz, int KKolumna, CFigury * Tabliczka[8][8]);
};

#endif // CPION_H

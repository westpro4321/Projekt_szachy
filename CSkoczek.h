#ifndef CSKOCZEK_H
#define CSKOCZEK_H
#include "CFigury.h"

class CSkoczek : public CFigury
{
public:

    CSkoczek(char kolorek);
    ~CSkoczek();
private:
    virtual char ZnakPionka();

    bool Ruch(int PWiersz, int PKolumna, int KWiersz, int KKolumna, CFigury * Tabliczka[8][8]);
};

#endif // CSKOCZEK_H

#ifndef CSKOCZEK_H
#define CSKOCZEK_H
#include "CFigura.h"

class CSkoczek : public CFigura
{
public:

    CSkoczek(char kolorek);
    ~CSkoczek();
private:
    virtual char ZnakPionka();

    bool Ruch(int PWiersz, int PKolumna, int KWiersz, int KKolumna, CFigura * Tabliczka[8][8]);
};

#endif // CSKOCZEK_H

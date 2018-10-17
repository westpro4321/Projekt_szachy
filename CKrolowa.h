#ifndef CKROLOWA_H
#define CKROLOWA_H
#include "CFigury.h"

class CKrolowa : public CFigury
{
public:
    CKrolowa(char kolorek);
    ~CKrolowa();
private:
    virtual char ZnakPionka();
    bool Ruch(int PWiersz, int PKolumna, int KWiersz, int KKolumna, CFigury * Tabliczka[8][8]);
};

#endif // CKROLOWA_H

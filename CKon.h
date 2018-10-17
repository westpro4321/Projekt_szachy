#ifndef CKON_H
#define CKON_H
#include "CFigury.h"

class CKon : public CFigury
{
public:

    CKon(char kolorek);
    ~CKon();
private:
    virtual char ZnakPionka();

    bool Ruch(int PWiersz, int PKolumna, int KWiersz, int KKolumna, CFigury * Tabliczka[8][8]);
};

#endif // CKON_H

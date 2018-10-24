#ifndef CKON_H
#define CKON_H
#include "CFigura.h"

class CKon : public CFigura
{
public:

    CKon(char kolorek);
    ~CKon();
private:
    virtual char ZnakPionka();

    bool Ruch(int PWiersz, int PKolumna, int KWiersz, int KKolumna, CFigura * Tabliczka[8][8]);
};

#endif // CKON_H

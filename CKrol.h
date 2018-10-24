#ifndef CKROL_H
#define CKROL_H
#include "CFigura.h"

class CKrol : public CFigura
{
public:
    CKrol(char kolorek);
    ~CKrol();
private:
    virtual char ZnakPionka();
    bool Ruch(int PWiersz, int PKolumna, int KWiersz, int KKolumna, CFigura * Tabliczka[8][8]);
};

#endif // CKROL_H

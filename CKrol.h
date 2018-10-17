#ifndef CKROL_H
#define CKROL_H
#include "CFigury.h"

class CKrol : public CFigury
{
public:
    CKrol(char kolorek);
    ~CKrol();
private:
    virtual char ZnakPionka();
    bool Ruch(int PWiersz, int PKolumna, int KWiersz, int KKolumna, CFigury * Tabliczka[8][8]);
};

#endif // CKROL_H

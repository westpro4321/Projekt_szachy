#ifndef CWIEZA_H
#define CWIEZA_H
#include "CFigury.h"

class CWieza : public CFigury
{
public:
    CWieza(char kolorek);
    ~CWieza();
private:
    virtual char ZnakPionka();
    bool Ruch(int PWiersz, int PKolumna, int KWiersz, int KKolumna, CFigury * Tabliczka[8][8]);

};

#endif // CWIEZA_H

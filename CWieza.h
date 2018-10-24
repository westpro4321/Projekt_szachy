#ifndef CWIEZA_H
#define CWIEZA_H
#include "CFigura.h"

class CWieza : public CFigura
{
public:
    CWieza(char kolorek);
    ~CWieza();
private:
    virtual char ZnakPionka();
    bool Ruch(int PWiersz, int PKolumna, int KWiersz, int KKolumna, CFigura * Tabliczka[8][8]);

};

#endif // CWIEZA_H

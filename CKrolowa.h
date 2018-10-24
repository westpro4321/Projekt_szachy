#ifndef CKROLOWA_H
#define CKROLOWA_H
#include "CFigura.h"

class CKrolowa : public CFigura
{
public:
    CKrolowa(char kolorek);
    ~CKrolowa();
private:
    virtual char ZnakPionka();
	bool Ruch(int PWiersz, int PKolumna, int KWiersz, int KKolumna, CFigura * Tabliczka[8][8]);
};

#endif // CKROLOWA_H

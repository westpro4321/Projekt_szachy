#ifndef CFIGURY_H
#define CFIGURY_H

#include <QPixmap>

class CFigura
{
public:
	CFigura(char kolorek, QString nazwa= QString());//Każda figura ma kolor biały lub czarny
    ~CFigura();
    virtual char ZnakPionka() = 0;// Każdy Pionek ma swoj znak
    char NadajKolor(); //Nadanie koloru danej figurze
    bool MozliwyRuch(int PWiersz, int PKolumna, int KWiersz, int KKolumna, CFigura* Tabliczka[8][8]); //sprawdza czy mozliwy ruch lub bicie
	QPixmap Obrazek();

private:
    virtual bool Ruch(int PWiersz, int PKolumna, int KWiersz, int KKolumna, CFigura* Tabliczka[8][8]) = 0; //kazdy pionek ma swoj indywidualny algorytm ruchu nadpisanie 0
    char kolor;     //prywatny kolor każdej z figur
	QPixmap obrazek;
};

#endif // CFIGURY_H

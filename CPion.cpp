#include "CPion.h"
#include "CFigura.h"


	CPion::CPion(char kolorek) : CFigura(kolorek, "Pawn") {}  //konstruktor nadający kolor
    CPion::~CPion() {}                               // destruktor

    char CPion::ZnakPionka() //Znak w konsoli , w GUI będzie to grafika dla danej figury
    {
        return 'P';
    }
	bool CPion::Ruch(int PWiersz, int PKolumna, int KWiersz, int KKolumna, CFigura * Tabliczka[8][8]) {   // ruch (współrzędne początka i końca ruchu oraz wskaźnik do planszy)czy ruch moze zostac wykonany
		CFigura* Cel = Tabliczka[KWiersz][KKolumna];                  // wskaźnik do współrzędnych końca ruchu
        if (Cel == 0) {                                             // Cel nie jest zajety przez pionek przeciwnego koloru

            if (PKolumna == KKolumna) {                             // pion porusza sie wzdłuż kolumny
                if (NadajKolor() == 'B') {
                    if ((KWiersz == PWiersz-1)||(PWiersz==6 &&(KWiersz == PWiersz-2))) {                     //ruch do przodu białego pionka (w dół planszy)??
                        return true;
                    }
                }
                else {
                    if ((KWiersz == PWiersz +1)||(PWiersz==1 && (KWiersz == PWiersz +2))) {                    //ruch do przodu pionka czarnego  (w górę planszy)???
                        return true;
                    }
                }
            }
        }
        else                                                        //bicie
        {
            if ((PKolumna == KKolumna + 1) || (PKolumna == KKolumna - 1)) {    //realizacja bicia po skosie (zmiana kolumny przez piona)
                if (NadajKolor() == 'B') {
                    if (KWiersz == PWiersz -1)                                 //realizacja bicia po skosie (w dół planszy) (zmiana wiersza) (kol. + wier. - ruch po skosie)
                    {
                        return true;
                    }
                }
                else if (KWiersz == PWiersz + 1)                               //realizacja bicia po skosie (w góre planszy)
                {
                    return true;
                }
            }
            }
        return false;
    }




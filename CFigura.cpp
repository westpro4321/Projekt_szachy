#include "CFigura.h"



	CFigura::CFigura(char kolorek)//Każda figura ma kolor biały lub czarny
    {
        kolor=kolorek;
    }
	CFigura::~CFigura(){}
	char CFigura::NadajKolor() //Nadanie koloru danej figurze
    {
        return kolor;
    }
	bool CFigura::MozliwyRuch(int PWiersz, int PKolumna, int KWiersz, int KKolumna, CFigura* Tabliczka[8][8]) //sprawdza czy mozliwy ruch lub bicie
    {
		CFigura* Cel = Tabliczka[KWiersz][KKolumna]; // Wskaznik na cel
        if ((Cel == 0) || (kolor != Cel->NadajKolor())) {  // jeżeli cel pusty lub aktualny kolor gracza rózni sie od przeciwnika (mozliwe zbicie)
            return Ruch(PWiersz, PKolumna, KWiersz, KKolumna, Tabliczka); // funkcja odpowiadająca za rzeczywisty ruch
        }
        return false;
    }


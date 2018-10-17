#include "CFigury.h"



    CFigury::CFigury(char kolorek)//Każda figura ma kolor biały lub czarny
    {
        kolor=kolorek;
    }
    CFigury::~CFigury(){}
    char CFigury::NadajKolor() //Nadanie koloru danej figurze
    {
        return kolor;
    }
    bool CFigury::MozliwyRuch(int PWiersz, int PKolumna, int KWiersz, int KKolumna, CFigury* Tabliczka[8][8]) //sprawdza czy mozliwy ruch lub bicie
    {
        CFigury* Cel = Tabliczka[KWiersz][KKolumna]; // Wskaznik na cel
        if ((Cel == 0) || (kolor != Cel->NadajKolor())) {  // jeżeli cel pusty lub aktualny kolor gracza rózni sie od przeciwnika (mozliwe zbicie)
            return Ruch(PWiersz, PKolumna, KWiersz, KKolumna, Tabliczka); // funkcja odpowiadająca za rzeczywisty ruch
        }
        return false;
    }


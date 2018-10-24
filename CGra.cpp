#include "CGra.h"
#include "CFigura.h"
#include "CPlansza.h"
#include<time.h>
#include<stdlib.h>

#include<iostream>
using namespace std ;



    CGra::CGra() : KolejGracza('B') {} //konstruktor jako przydzielenie pierwszej kolejki Graczowi Bia�emu
    CGra::~CGra() {}
    void CGra::Start()                //metoda odpowiadaj�ca za wykonanie ruchu
    {
        do {                          
            WykonajRuch(Szachownica.Tablica);                        // Funkcja wykonuj�ca ruch przekazuj�ca rzeczywist� plansze obiekt CPlansza Szachownica.Tablica                       
            system ("cls");
            ZmianaZawodnika();                                       //Zmiana zawodnika, zmiana koloru
        } while (!SzachMat());                                       // P�tla startu gry, a� do momentu gdy nie bedzie SzachMata
        Szachownica.DrukujPlansze(); 
    }

	void CGra::WykonajRuch(CFigura*tabliczka[8][8])           //zmienna symbolizuj�ca atrybut tablicy obiektu CPlansza Szachownica wprowadzaj�ca zmiany na rzewczywistej planszy
    {
        using namespace std;
        bool poprawny = false;                       //zmienna logiczna odpowiadaj�ca za informacj� czy ruch moze by� wykonany i nie ma zagrozenia SzachMatem
		bool zagrozenie = false;                     //zmienna logiczna zwracaj� true przy zagro�eniu przy danym ruchu SzachMatem
        do {
            Szachownica.DrukujPlansze();

			cout<<endl<<"Kolej Gracza : ";

            if(KolejGracza=='B')                    //funkcje wy�wietlania       
			{
			    cout << "Bialy" << endl ;
			}else
			{
				cout<<"Czarny"<<endl;
			}
			cout<<"Podaj wiersz i kolumne figury: "<<endl;
            int WierszStart;
            int KolumnaStart;
            cin >> WierszStart >> KolumnaStart;          //wyb�r danej figury do ruchu


            cout << "CEL" << endl << "Podaj wspolrzedne koncowe: " << endl;
            int WierszKoniec;
            int KolumnaKoniec;
            cin >> WierszKoniec >> KolumnaKoniec;         // Wspolrzedne ko�cowe

            if ((WierszStart >= 0 && WierszStart <= 7) &&
                (KolumnaStart >= 0 && KolumnaStart <= 7) &&         //zabezpieczenia przed wprowadzonymi danymi
                (WierszKoniec >= 0 && WierszKoniec <= 7) &&
                (KolumnaKoniec >= 0 && KolumnaKoniec <= 7)) {

				CFigura* PunktStart = tabliczka[WierszStart][KolumnaStart];        //Obiekt klasy CFigury odpowiadaj�cy za aktualn� pozycje ruszaj�cego si� piona

                if ((PunktStart != 0) && (PunktStart->NadajKolor() == KolejGracza)) {   //Je�eli to pole nie jest puste i jest kolej aktualnego gracza

                    if (PunktStart->MozliwyRuch(WierszStart, KolumnaStart, WierszKoniec, KolumnaKoniec, tabliczka))        //Jezeli jest mo�liwy ruch | przekazanie do metody obiektu CFigury MozliwyRuch()
                    {
                        // Wykonanie ruchu
						CFigura* tmp = tabliczka[WierszKoniec][KolumnaKoniec];                               //zmienna tymczasowa do przechowania stanu obiektu znajduj�cego si� w wyznaczonym celu
                        tabliczka[WierszKoniec][KolumnaKoniec] = tabliczka[WierszStart][KolumnaStart];        //rzeczywiste (tajne )przemieszczenie figury w pozycje docelow�
                        tabliczka[WierszStart][KolumnaStart] = 0;                                             //wyzerowanie pozycji startowej (wyj�ciowej)
                        // sprawdzenie czy (tajny) ruch wywo�a� sytuacj� Szach na planszy
                        if (!Szachownica.Szach(KolejGracza)) { //je�eli wykonany ruch nie powoduje sytuacji Szach na planszy
                            delete tmp;                        //zawolnienie pamieci po obiekcie z pocz�tkowego "CELu"   i faktyczna sytuacja na planszy pozostaje taka ja powy�ej          
                            poprawny = true;                   //ruch poprawny
                        }
                        else { //Wycofanie (tajnego) przesuni�cia
                            tabliczka[WierszStart][KolumnaStart] = tabliczka[WierszKoniec][KolumnaKoniec];    //powrot pionka
                            tabliczka[WierszKoniec][KolumnaKoniec] = tmp;
							zagrozenie = true;                                   //Zagrozenie Szachem zmienna logiczna
                        }
                    }
                }
            }
            if (!poprawny) {         //jezeli ruch niepoprawny
                system ("cls");
				
			if(zagrozenie==true)      //informacja o zagrozeniu SzachMatem
				cout<<"!!! Ruch zagrazajacy Szach Mat !!!"<<endl;
				else
                cout << "Niepoprawny ruch" << endl;

                _sleep(1500);
                system ("cls");
            }
        } while (!poprawny); //wykonywanie danej kolejki a� do wprowadzenia poprawnego ruchu piona       
    }

    void CGra::ZmianaZawodnika()   // metoda zmiany zawodnika
    {
        KolejGracza = (KolejGracza == 'B') ? 'C' : 'B';  //jezeli kolej danego Gracza to Bia�y , nastapi zmiana na Czarny i odwrotnie
    }
    bool CGra::SzachMat()                                //metoda odpowiadaj�ca za zwrocenie informacji o Szach Macie
    {
		using namespace std;
        bool bCanMove(false);                           // zmienna logiczna ustawiona na fa�sz
        bCanMove = Szachownica.MozliwoscUcieczki(KolejGracza);        //nastawienie zmiennej logicznej na zwracana wartosc z metody zwracaj�cej mozliwosc ucieczki obiektu CPlansza Szachownica 
        if (!bCanMove) {                                              //jezeli nie ma mozliwo�ci ucieczki   
        if (Szachownica.Szach(KolejGracza)) {                         //jezeli gracz jest w szachu
        ZmianaZawodnika();                                            //zmiana na zawodnika kt�ry wygrywa gre
        cout << "Checkmate, " << KolejGracza << " Wins!" <<endl;      //komunikat o wygranej
        } else {
        cout << "Stalemate!" <<endl;
        }
        }
        return !bCanMove;                                            // zwraca prawde gdy SzachMat

        return true;
    }


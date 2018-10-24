#include "CGra.h"
#include "CFigura.h"
#include "CPlansza.h"
#include<time.h>
#include<stdlib.h>

#include<iostream>
using namespace std ;



    CGra::CGra() : KolejGracza('B') {} //konstruktor jako przydzielenie pierwszej kolejki Graczowi Bia³emu
    CGra::~CGra() {}
    void CGra::Start()                //metoda odpowiadaj¹ca za wykonanie ruchu
    {
        do {                          
            WykonajRuch(Szachownica.Tablica);                        // Funkcja wykonuj¹ca ruch przekazuj¹ca rzeczywist¹ plansze obiekt CPlansza Szachownica.Tablica                       
            system ("cls");
            ZmianaZawodnika();                                       //Zmiana zawodnika, zmiana koloru
        } while (!SzachMat());                                       // Pêtla startu gry, a¿ do momentu gdy nie bedzie SzachMata
        Szachownica.DrukujPlansze(); 
    }

	void CGra::WykonajRuch(CFigura*tabliczka[8][8])           //zmienna symbolizuj¹ca atrybut tablicy obiektu CPlansza Szachownica wprowadzaj¹ca zmiany na rzewczywistej planszy
    {
        using namespace std;
        bool poprawny = false;                       //zmienna logiczna odpowiadaj¹ca za informacjê czy ruch moze byæ wykonany i nie ma zagrozenia SzachMatem
		bool zagrozenie = false;                     //zmienna logiczna zwracaj¹ true przy zagro¿eniu przy danym ruchu SzachMatem
        do {
            Szachownica.DrukujPlansze();

			cout<<endl<<"Kolej Gracza : ";

            if(KolejGracza=='B')                    //funkcje wyœwietlania       
			{
			    cout << "Bialy" << endl ;
			}else
			{
				cout<<"Czarny"<<endl;
			}
			cout<<"Podaj wiersz i kolumne figury: "<<endl;
            int WierszStart;
            int KolumnaStart;
            cin >> WierszStart >> KolumnaStart;          //wybór danej figury do ruchu


            cout << "CEL" << endl << "Podaj wspolrzedne koncowe: " << endl;
            int WierszKoniec;
            int KolumnaKoniec;
            cin >> WierszKoniec >> KolumnaKoniec;         // Wspolrzedne koñcowe

            if ((WierszStart >= 0 && WierszStart <= 7) &&
                (KolumnaStart >= 0 && KolumnaStart <= 7) &&         //zabezpieczenia przed wprowadzonymi danymi
                (WierszKoniec >= 0 && WierszKoniec <= 7) &&
                (KolumnaKoniec >= 0 && KolumnaKoniec <= 7)) {

				CFigura* PunktStart = tabliczka[WierszStart][KolumnaStart];        //Obiekt klasy CFigury odpowiadaj¹cy za aktualn¹ pozycje ruszaj¹cego siê piona

                if ((PunktStart != 0) && (PunktStart->NadajKolor() == KolejGracza)) {   //Je¿eli to pole nie jest puste i jest kolej aktualnego gracza

                    if (PunktStart->MozliwyRuch(WierszStart, KolumnaStart, WierszKoniec, KolumnaKoniec, tabliczka))        //Jezeli jest mo¿liwy ruch | przekazanie do metody obiektu CFigury MozliwyRuch()
                    {
                        // Wykonanie ruchu
						CFigura* tmp = tabliczka[WierszKoniec][KolumnaKoniec];                               //zmienna tymczasowa do przechowania stanu obiektu znajduj¹cego siê w wyznaczonym celu
                        tabliczka[WierszKoniec][KolumnaKoniec] = tabliczka[WierszStart][KolumnaStart];        //rzeczywiste (tajne )przemieszczenie figury w pozycje docelow¹
                        tabliczka[WierszStart][KolumnaStart] = 0;                                             //wyzerowanie pozycji startowej (wyjœciowej)
                        // sprawdzenie czy (tajny) ruch wywo³a³ sytuacjê Szach na planszy
                        if (!Szachownica.Szach(KolejGracza)) { //je¿eli wykonany ruch nie powoduje sytuacji Szach na planszy
                            delete tmp;                        //zawolnienie pamieci po obiekcie z pocz¹tkowego "CELu"   i faktyczna sytuacja na planszy pozostaje taka ja powy¿ej          
                            poprawny = true;                   //ruch poprawny
                        }
                        else { //Wycofanie (tajnego) przesuniêcia
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
        } while (!poprawny); //wykonywanie danej kolejki a¿ do wprowadzenia poprawnego ruchu piona       
    }

    void CGra::ZmianaZawodnika()   // metoda zmiany zawodnika
    {
        KolejGracza = (KolejGracza == 'B') ? 'C' : 'B';  //jezeli kolej danego Gracza to Bia³y , nastapi zmiana na Czarny i odwrotnie
    }
    bool CGra::SzachMat()                                //metoda odpowiadaj¹ca za zwrocenie informacji o Szach Macie
    {
		using namespace std;
        bool bCanMove(false);                           // zmienna logiczna ustawiona na fa³sz
        bCanMove = Szachownica.MozliwoscUcieczki(KolejGracza);        //nastawienie zmiennej logicznej na zwracana wartosc z metody zwracaj¹cej mozliwosc ucieczki obiektu CPlansza Szachownica 
        if (!bCanMove) {                                              //jezeli nie ma mozliwoœci ucieczki   
        if (Szachownica.Szach(KolejGracza)) {                         //jezeli gracz jest w szachu
        ZmianaZawodnika();                                            //zmiana na zawodnika który wygrywa gre
        cout << "Checkmate, " << KolejGracza << " Wins!" <<endl;      //komunikat o wygranej
        } else {
        cout << "Stalemate!" <<endl;
        }
        }
        return !bCanMove;                                            // zwraca prawde gdy SzachMat

        return true;
    }


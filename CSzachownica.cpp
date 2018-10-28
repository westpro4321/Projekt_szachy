#include "CSzachownica.h"
#include "CPlansza.h"
#include "CPoleSzachownicy.h"

#include <QDebug>


CSzachownica::CSzachownica(QObject *parent) :
	QGraphicsScene(parent),
	plansza(new CPlansza)
{
	// Konstruujemy szachownicę
	for (int i=0; i<8; i++)
	{
		for (int j=0; j<8; j++)
		{
			QColor kolor(Qt::darkGray);
			if ((i + j) % 2 == 0)
				kolor = Qt::white;

			CPoleSzachownicy *pole = new CPoleSzachownicy(i, j);
			pole->ustawKolor(kolor);
			addItem(pole);
			polaSzachownicy[i][j] = pole;
			if (CFigura *f = plansza->Tablica[i][j])
			{
				pole->ustawFigure(f);
			}
			connect(pole, SIGNAL(kliknieto(CPoleSzachownicy*)), this, SLOT(kliknietoPole(CPoleSzachownicy*)));
		}
	}
}

void CSzachownica::kliknietoPole(CPoleSzachownicy *aktualnyElement)
{
	if (aktualnyElement->pobierzFigure())
	qDebug() << Q_FUNC_INFO << aktualnyElement->pobierzFigure()->ZnakPionka() << aktualnyElement->pobierzFigure()->NadajKolor();

	// Kliknięto w puste pole lub nie swója figure przy wyborze
	if (zaznaczonyElement == nullptr && (aktualnyElement->pobierzFigure() == nullptr || aktualnyElement->pobierzFigure()->NadajKolor() != aktualnyGracz))
		return;


	if (zaznaczonyElement == nullptr || (aktualnyElement->pobierzFigure() && aktualnyElement->pobierzFigure()->NadajKolor() == aktualnyGracz))
	{
		if (zaznaczonyElement)
		{
			wyczyscZaznaczenia();
		}
		zaznaczonyElement = aktualnyElement;
		zaznaczonyElement->ustawWybrane(true);
		wyznaczMozliweRuchy();
	}
	else
	{
		if (aktualnyElement->jestMozliwyRuch())
		{
			przesunFigure(zaznaczonyElement, aktualnyElement);
			zaznaczonyElement = nullptr;
			wyczyscZaznaczenia();
			zmienGracza();
		}
	}


//    if (zaznaczonyElement)
//    {
//        if ()
//        {
//            if ()
//            {
//                zaznaczonyElement->ustawWybrane(false);
//                zaznaczonyElement = klikniete;
//                zaznaczonyElement->ustawWybrane(true);
//            }
//        }
//        else
//        {
//            // TODO: czy możliwy ruch
//            klikniete->ustawFigure(zaznaczonyElement->zdejmijFigure());
//            zaznaczonyElement->ustawWybrane(false);
//            zaznaczonyElement = nullptr;
//            zmienGracza();
//        }
//    }
//    else
//    {
//        if (klikniete->pobierzFigure() && klikniete->pobierzFigure()->NadajKolor() == aktualnyGracz)
//        {
//            zaznaczonyElement = klikniete;
//            klikniete->ustawWybrane(true);
//        }

//        zaznaczonyElement = klikniete;
//        klikniete->ustawWybrane(true);

//        QList<QGraphicsItem *> pola = scena->items();
//        for(auto p: pola)
//        {
//            CPoleSzachownicy *pole = dynamic_cast<CPoleSzachownicy *>(p);
//            if (pole != zaznaczonyElement)
//            {
//                qDebug() << zaznaczonyElement->pobierzWiersz() << zaznaczonyElement->pobierzKolumne() << pole->pobierzWiersz() << pole->pobierzKolumne();
//                if (zaznaczonyElement->pobierzFigure()->MozliwyRuch(zaznaczonyElement->pobierzWiersz(), zaznaczonyElement->pobierzKolumne(),
//                                                           pole->pobierzWiersz(), pole->pobierzKolumne(), plansza->Tablica))
//                {
//                    pole->ustawMozliwyRuch(true);
//                }
//            }
//        }
//    }

}

void CSzachownica::zmienGracza()
{
	aktualnyGracz = (aktualnyGracz == 'B') ? 'C' : 'B';
}

void CSzachownica::wyczyscZaznaczenia()
{
	for (int i=0; i<8; i++)
	{
		for (int j=0; j<8; j++)
		{
			CPoleSzachownicy *pole = polaSzachownicy[i][j];
			pole->ustawWybrane(false);
			pole->ustawMozliwyRuch(false);
		}
	}
}

void CSzachownica::wyznaczMozliweRuchy()
{
	for (int i=0; i<8; i++)
	{
		for (int j=0; j<8; j++)
		{
			CPoleSzachownicy *pole = polaSzachownicy[i][j];
//			if (pole != zaznaczonyElement)
			{
				if (zaznaczonyElement->pobierzFigure()->MozliwyRuch(zaznaczonyElement->pobierzWiersz(), zaznaczonyElement->pobierzKolumne(),
																	pole->pobierzWiersz(), pole->pobierzKolumne(), plansza->Tablica))
				{
					pole->ustawMozliwyRuch(true);
				}
			}
		}
	}
}

void CSzachownica::przesunFigure(CPoleSzachownicy *pocz, CPoleSzachownicy *doc)
{
	doc->ustawFigure(pocz->zdejmijFigure());
	plansza->PrzesunFigure(pocz->pobierzPozycje(), doc->pobierzPozycje());
}

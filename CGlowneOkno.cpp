#include "CGlowneOkno.h"
#include "ui_cglowneokno.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QColor>
#include <QDebug>
#include <CPoleSzachownicy.h>
#include <CPlansza.h>


CGlowneOkno::CGlowneOkno(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::CGlowneOkno),
	scena(new QGraphicsScene(this)),
	plansza(new CPlansza)
{
	ui->setupUi(this);
	scena->setSceneRect(0, 0, 800, 800);
	ui->widok->setScene(scena);

	// Tworzymy szachownicę
	for (int i=0; i<8; i++)
	{
		for (int j=0; j<8; j++)
		{
                        QColor kolor(Qt::darkGray);
			if ((i + j) % 2 == 0)
				kolor = Qt::white;

			CPoleSzachownicy *pole = new CPoleSzachownicy(i, j);
			pole->ustawKolor(kolor);
                        scena->addItem(pole);

			if (CFigura *f = plansza->Tablica[i][j])
			{
				pole->ustawFigure(f);
			}

                        connect(pole, SIGNAL(kliknieto(CPoleSzachownicy*)), this, SLOT(kliknietoPole(CPoleSzachownicy*)));
		}
	}
}

CGlowneOkno::~CGlowneOkno()
{
    delete ui;
}

void CGlowneOkno::kliknietoPole(CPoleSzachownicy *klikniete)
{
    if (klikniete->pobierzFigure())
    qDebug() << Q_FUNC_INFO << klikniete->pobierzFigure()->ZnakPionka() << klikniete->pobierzFigure()->NadajKolor();

    if (zaznaczonyElement == nullptr && klikniete->pobierzFigure() == nullptr)
        return;

    if (zaznaczonyElement)
    {
        if (klikniete->pobierzFigure())
        {
            if (klikniete->pobierzFigure()->NadajKolor() == aktualnyGracz)
            {
                zaznaczonyElement->ustawWybrane(false);
                zaznaczonyElement = klikniete;
                zaznaczonyElement->ustawWybrane(true);
            }
        }
        else
        {
            // TODO: czy możliwy ruch
            klikniete->ustawFigure(zaznaczonyElement->zdejmijFigure());
            zaznaczonyElement->ustawWybrane(false);
            zaznaczonyElement = nullptr;
            zmienGracza();
        }
    }
    else if (klikniete->pobierzFigure() && klikniete->pobierzFigure()->NadajKolor() == aktualnyGracz)
    {
        zaznaczonyElement = klikniete;
        klikniete->ustawWybrane(true);
    }

}

void CGlowneOkno::zmienGracza()
{
    aktualnyGracz = (aktualnyGracz == 'B') ? 'C' : 'B';
}

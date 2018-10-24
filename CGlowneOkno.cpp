#include "CGlowneOkno.h"
#include "ui_cglowneokno.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QColor>
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
			QColor kolor(Qt::black);
			if ((i + j) % 2 == 0)
				kolor = Qt::white;

			CPoleSzachownicy *pole = new CPoleSzachownicy(i, j);
			pole->ustawKolor(kolor);
			scena->addItem(pole);

			if (CFigura *f = plansza->Tablica[i][j])
			{
				pole->ustawFigure(f);
			}
		}
	}


}

CGlowneOkno::~CGlowneOkno()
{
	delete ui;
}

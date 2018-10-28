#ifndef CSZACHOWNICA_H
#define CSZACHOWNICA_H

#include <QGraphicsScene>

class CFigura;
class CPlansza;
class CPoleSzachownicy;

class CSzachownica : public QGraphicsScene
{
	Q_OBJECT
public:
	explicit CSzachownica(QObject *parent = nullptr);

protected slots:
	void kliknietoPole(CPoleSzachownicy*);

protected:
	void zmienGracza();
	void wyczyscZaznaczenia();
	void wyznaczMozliweRuchy();
	void przesunFigure(CPoleSzachownicy *pocz, CPoleSzachownicy *doc);

	CPlansza *plansza;
	CPoleSzachownicy *polaSzachownicy[8][8];
	CPoleSzachownicy *zaznaczonyElement = nullptr;
	char aktualnyGracz = 'B';
};

#endif // CSZACHOWNICA_H

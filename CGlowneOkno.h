#ifndef CGLOWNEOKNO_H
#define CGLOWNEOKNO_H

#include <QMainWindow>

namespace Ui {
class CGlowneOkno;
}

class QGraphicsScene;
class CPlansza;
class CPoleSzachownicy;

class CGlowneOkno : public QMainWindow
{
	Q_OBJECT

public:
	explicit CGlowneOkno(QWidget *parent = 0);
	~CGlowneOkno();

protected slots:
        void kliknietoPole(CPoleSzachownicy*);
        void zmienGracza();

private:
	Ui::CGlowneOkno *ui;
	QGraphicsScene *scena;
	CPlansza *plansza;
        CPoleSzachownicy *zaznaczonyElement = nullptr;
        char aktualnyGracz = 'B';
};

#endif // CGLOWNEOKNO_H

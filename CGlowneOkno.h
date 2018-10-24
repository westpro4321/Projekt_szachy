#ifndef CGLOWNEOKNO_H
#define CGLOWNEOKNO_H

#include <QMainWindow>

namespace Ui {
class CGlowneOkno;
}

class QGraphicsScene;
class CPlansza;
class CGlowneOkno : public QMainWindow
{
	Q_OBJECT

public:
	explicit CGlowneOkno(QWidget *parent = 0);
	~CGlowneOkno();

private:
	Ui::CGlowneOkno *ui;
	QGraphicsScene *scena;
	CPlansza *plansza;
};

#endif // CGLOWNEOKNO_H

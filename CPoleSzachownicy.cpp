#include "CPoleSzachownicy.h"
#include <QBrush>
#include <QColor>
#include <QGraphicsScene>
#include <QPainter>
#include <CFigura.h>

const int WYMIAR_POLA = 100; // w pikselach

CPoleSzachownicy::CPoleSzachownicy(int y, int x, QGraphicsItem *parent) :
	QGraphicsRectItem(x * WYMIAR_POLA, y * WYMIAR_POLA, WYMIAR_POLA, WYMIAR_POLA, parent),
	x(x),
	y(y)
{
}

CPoleSzachownicy::~CPoleSzachownicy()
{
}

void CPoleSzachownicy::ustawKolor(QColor kolor)
{
	QBrush pedzel(kolor);
	setBrush(pedzel);
}

void CPoleSzachownicy::ustawFigure(CFigura *f)
{
	figura = f;
	scene()->update();
}

void CPoleSzachownicy::usunFigure()
{
	figura = nullptr;
	scene()->update();
}

void CPoleSzachownicy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	QGraphicsRectItem::paint(painter, option, widget);
	if (figura)
	{
//		QColor kolor(figura->NadajKolor() == 'C' ? Qt::black : Qt::white);
		QColor kolor(Qt::red);
		QPen pen(kolor);
		painter->setPen(pen);
		painter->drawText(rect(), QString(figura->ZnakPionka()));
	}
}

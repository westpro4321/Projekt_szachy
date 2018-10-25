#include "CPoleSzachownicy.h"
#include <QBrush>
#include <QColor>
#include <QGraphicsScene>
#include <QPainter>
#include <QDebug>
#include <CFigura.h>

const int WYMIAR_POLA = 100; // w pikselach

CPoleSzachownicy::CPoleSzachownicy(int y, int x, QGraphicsItem *parent) :
    QGraphicsRectItem(x * WYMIAR_POLA, y * WYMIAR_POLA, WYMIAR_POLA, WYMIAR_POLA, parent),
    wiersz(y),
    kolumna(x)
{
}

CPoleSzachownicy::~CPoleSzachownicy()
{
}

void CPoleSzachownicy::ustawKolor(QColor kolor)
{
    this->kolor = kolor;
    setBrush(kolor);
}

void CPoleSzachownicy::ustawFigure(CFigura *f)
{
    if (figura)
        delete figura;

    figura = f;
    scene()->update();
}

CFigura *CPoleSzachownicy::zdejmijFigure()
{
    CFigura *ret = figura;
    figura = nullptr;
    scene()->update();
    return ret;
}

CFigura *CPoleSzachownicy::pobierzFigure()
{
    return figura;
}

int CPoleSzachownicy::pobierzWiersz()
{
    return wiersz;
}

int CPoleSzachownicy::pobierzKolumne()
{
    return kolumna;
}

void CPoleSzachownicy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsRectItem::paint(painter, option, widget);

    if (figura)
    {
        painter->drawPixmap(boundingRect().toAlignedRect(), figura->Obrazek());
    }
}

void CPoleSzachownicy::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit kliknieto(this);
}

void CPoleSzachownicy::ustawWybrane(bool wybrane)
{
    this->wybrane = wybrane;
    if (wybrane)
    {
        setBrush(Qt::blue);
    }
    else
    {
        setBrush(kolor);
    }
    scene()->update();
}

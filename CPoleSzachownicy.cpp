#include "CPoleSzachownicy.h"
#include <QBrush>
#include <QColor>
#include <QGraphicsScene>
#include <QPainter>
#include <QDebug>
#include <QPoint>
#include <CFigura.h>

const int WYMIAR_POLA = 100; // w pikselach

CPoleSzachownicy::CPoleSzachownicy(int y, int x, QGraphicsItem *parent) :
    QGraphicsRectItem(x * WYMIAR_POLA, y * WYMIAR_POLA, WYMIAR_POLA, WYMIAR_POLA, parent),
    pozycja(x, y)
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
    return pozycja.y();
}

int CPoleSzachownicy::pobierzKolumne()
{
    return pozycja.x();
}

QPoint CPoleSzachownicy::pobierzPozycje()
{
    return pozycja;
}

void CPoleSzachownicy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsRectItem::paint(painter, option, widget);

    if (figura)
    {
        painter->drawPixmap(boundingRect().toAlignedRect(), figura->Obrazek());
    }
}

void CPoleSzachownicy::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    emit kliknieto(this);
}

void CPoleSzachownicy::ustawWybrane(bool wybrane)
{
    this->wybrane = wybrane;
    ustawKolorSpecjalny(wybrane, Qt::blue);
}

bool CPoleSzachownicy::jestWybrane()
{
    return wybrane;
}

void CPoleSzachownicy::ustawMozliwyRuch(bool mozliwy)
{
    this->mozliwy = mozliwy;
    ustawKolorSpecjalny(mozliwy, Qt::darkBlue);
}

bool CPoleSzachownicy::jestMozliwyRuch()
{
    return mozliwy;
}

void CPoleSzachownicy::ustawKolorSpecjalny(bool specjalny, QColor kolor)
{
    if (specjalny)
    {
        setBrush(kolor);
    }
    else
    {
        setBrush(this->kolor);
    }
    scene()->update();
}

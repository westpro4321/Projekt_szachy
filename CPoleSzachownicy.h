#ifndef CPOLESZACHOWNICY_H
#define CPOLESZACHOWNICY_H

#include <QGraphicsRectItem>

class CFigura;

class CPoleSzachownicy : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit CPoleSzachownicy(int y, int x, QGraphicsItem *parent = nullptr);
    ~CPoleSzachownicy();

    void ustawKolor(QColor kolor);
    void ustawFigure(CFigura *f);
    CFigura *pobierzFigure();
    CFigura * zdejmijFigure();
    int pobierzWiersz();
    int pobierzKolumne();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void ustawWybrane(bool wybrane);

signals:
    void kliknieto(CPoleSzachownicy *);

private:
    int wiersz = -1;
    int kolumna = -1;
    CFigura *figura = nullptr;
    QColor kolor;
    bool wybrane = false;
};

#endif // CPOLESZACHOWNICY_H

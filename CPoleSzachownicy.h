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
    QPoint pobierzPozycje();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void ustawWybrane(bool wybrane);
    bool jestWybrane();
    void ustawMozliwyRuch(bool mozliwy);
    bool jestMozliwyRuch();

signals:
    void kliknieto(CPoleSzachownicy *);

protected:
    void ustawKolorSpecjalny(bool specjalny, QColor kolor = QColor());

private:
    QPoint pozycja;
    CFigura *figura = nullptr;
    QColor kolor;
    bool wybrane = false;
    bool mozliwy = false;
};

#endif // CPOLESZACHOWNICY_H

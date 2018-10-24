#ifndef CPOLESZACHOWNICY_H
#define CPOLESZACHOWNICY_H

#include <QGraphicsRectItem>

class CFigura;

class CPoleSzachownicy : public QGraphicsRectItem
{
public:
	explicit CPoleSzachownicy(int y, int x, QGraphicsItem *parent = nullptr);
	~CPoleSzachownicy();

	void ustawKolor(QColor kolor);
	void ustawFigure(CFigura *f);
	void usunFigure();

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
	int x = -1;
	int y = -1;
	CFigura *figura = nullptr;
};

#endif // CPOLESZACHOWNICY_H

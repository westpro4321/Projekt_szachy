#ifndef CGLOWNEOKNO_H
#define CGLOWNEOKNO_H

#include <QMainWindow>

namespace Ui {
class CGlowneOkno;
}

class CSzachownica;

class CGlowneOkno : public QMainWindow
{
    Q_OBJECT

public:
    explicit CGlowneOkno(QWidget *parent = 0);
    ~CGlowneOkno();

private:
    Ui::CGlowneOkno *ui;
    CSzachownica *szachownica;
};

#endif // CGLOWNEOKNO_H

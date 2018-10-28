#include "CGlowneOkno.h"
#include "ui_cglowneokno.h"
#include "CSzachownica.h"

CGlowneOkno::CGlowneOkno(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::CGlowneOkno),
        szachownica(new CSzachownica(this))
{
	ui->setupUi(this);
        szachownica->setSceneRect(0, 0, 800, 800);
        ui->widok->setScene(szachownica);
}

CGlowneOkno::~CGlowneOkno()
{
    delete ui;
}

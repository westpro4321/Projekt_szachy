// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "CGra.h"
/*#include "CPlansza.h"
#include "CKrol.h"
#include "CKrolowa.h"
#include "CSkoczek.h"
#include "CKon.h"
#include "CWieza.h"
#include "CPion.h"
#include "CFigury.h"*/
#include <iostream>
#include <string>
#include <cmath>
#include <QApplication>
#include <CGlowneOkno.h>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	CGlowneOkno okno;
	okno.show();
	return app.exec();
}

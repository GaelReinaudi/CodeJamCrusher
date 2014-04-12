#include "stdafx.h"
#include "visualproblemsolver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CookieClickerAlpha w;
	w.show();
	return a.exec();
}

#include "stdafx.h"
#include "visualproblemsolver.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SafetyinNumbers w;
	w.show();
	return a.exec();
}

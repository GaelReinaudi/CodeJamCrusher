#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

#include "problemzipper.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ProblemZipper w;
	w.show();
	return a.exec();
}

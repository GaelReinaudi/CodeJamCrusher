#include "problemzipper.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ProblemZipper w;
	w.show();
	return a.exec();
}

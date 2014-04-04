#include "stdafx.h"
#include "HallofMirrorsCase.h"
#include <QtAlgorithms>
#include <QPoint>

QString SolveCase( const HallofMirrorsCase & Case )
{
	return Case.Solve();
}

void HallofMirrorsCase::ParseCase( QTextStream & inputStream )
{
	inputStream >> H;
	inputStream >> W;
	inputStream >> D;
	inputStream.readLine();
	char symb;
	for(int j = 0; j < H; j++) {
		for(int i = 0; i < W; i++) {
			inputStream >> symb;
			if(symb == 'X')
				MyPos = QPoint(i, j);
		}
		inputStream.readLine();
	}
}

QPoint ReflexionHwall(QPoint aPoint, int HmirrorCenterPos) {
	int Xpos = aPoint.x();
	int newX = 2 * HmirrorCenterPos - Xpos;
	if(newX > Xpos)
		newX--;
	else
		newX++;
	return QPoint(newX, aPoint.y());
}

QPoint ReflexionVwall(QPoint aPoint, int VmirrorCenterPos) {
	int Ypos = aPoint.y();
	int newY = 2 * VmirrorCenterPos - Ypos;
	if(newY > Ypos)
		newY--;
	else
		newY++;
	return QPoint(aPoint.x(), newY);
}

inline uint qHash(const QPoint& p)
{
	return qHash(p.x()+ 100 * p.y());
}

inline uint qHash(const QVector2D& p)
{
	return qHash(int(1*double(p.x() + 100 * p.y())));
}

QString HallofMirrorsCase::Solve() const
{
	QString caseSolution("Case #%1: %2");
	caseSolution = caseSolution.arg(m_CaseNumber);

	int nImages = 0;

	QHash<QPoint, bool> virtualPoints;
	QHash<int, bool> virtualHwalls;
	QHash<int, bool> virtualVwalls;
	virtualPoints.insert(MyPos, true);
	int numReflexion = D * 2;
	for(int i = 0; i < numReflexion; i++) {
		foreach(QPoint p, virtualPoints.keys()) {
			if(p.x() < W - 1)
				virtualPoints.insert(ReflexionHwall(p, W - 1), true);
			if(p.x() > 0)
				virtualPoints.insert(ReflexionHwall(p, 0), true);
			if(p.y() < H - 1)
				virtualPoints.insert(ReflexionVwall(p, H - 1), true);
			if(p.y() > 0)
				virtualPoints.insert(ReflexionVwall(p, 0), true);
		}
	}

	QHash<QPoint, bool> vecUsed;

	foreach(QPoint p, virtualPoints.keys()) {
		QVector2D vec(p - MyPos);
		double length = vec.length();
		if(length < D + 1e-6 && length > 1e-6) {
			nImages++;
			QPoint vecpoint = (vec.normalized() * 10000000).toPoint();

			vecUsed.insert(vecpoint, true);
		}
	}
	nImages = vecUsed.count();

	return caseSolution.arg(nImages);

	return caseSolution.arg("failed").arg("failed");
}



















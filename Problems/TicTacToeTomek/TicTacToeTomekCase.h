#ifndef TicTacToeTomekCase_H
#define TicTacToeTomekCase_H

#include "GoogleCase.h"
#include <QTextStream>

class TicTacToeTomekCase;

QString SolveCase(const TicTacToeTomekCase & Case);

class TicTacToeTomekCase : public GoogleCase
{
public:
	TicTacToeTomekCase();
	~TicTacToeTomekCase() {}

	//! Re-implemented
	void ParseCase(QTextStream & inputStream);
	QString Solve() const;

	mutable QString m_SolString;
//	QTextStream &m_Out;

	long double BinarySearch(long double Min, long double Max) const;
	long double MyPos(long double startTime, long double a, long double time) const;
	bool HitCar(long double startTime, long double a) const;

	mutable int N;
	mutable QVector<QVector<int> > t;
};

#endif // TicTacToeTomekCase_H

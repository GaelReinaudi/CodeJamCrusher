#ifndef OutofGasCase_H
#define OutofGasCase_H

#include "GoogleCase.h"
#include <QTextStream>

class OutofGasCase;

QString SolveCase(const OutofGasCase & Case);

class OutofGasCase : public GoogleCase
{
public:
	OutofGasCase();
	~OutofGasCase() {}

	//! Re-implemented
	void ParseCase(QTextStream & inputStream);
	QString Solve() const;

	mutable QString m_SolString;
//	QTextStream &m_Out;

	long double BinarySearch(long double Min, long double Max) const;
	long double MyPos(long double startTime, long double a, long double time) const;
	bool HitCar(long double startTime, long double a) const;

	mutable int N;
	mutable double D;
	mutable int A;
	mutable QList<long double> m_A;
	mutable QMap<long double, long double> m_TX;
	mutable long double m_LocalA;
};

#endif // OutofGasCase_H

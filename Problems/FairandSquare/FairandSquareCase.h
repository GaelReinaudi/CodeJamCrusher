#ifndef FairandSquareCase_H
#define FairandSquareCase_H

#include "GoogleCase.h"
#include <QTextStream>

class FairandSquareCase;

QString SolveCase(const FairandSquareCase & Case);

class DecimalNum : public QVector<int>
{
	
};

class FairandSquareCase : public GoogleCase
{
public:
	FairandSquareCase();
	~FairandSquareCase() {}

	//! Re-implemented
	void ParseCase(QTextStream & inputStream);
	QString Solve() const;

	mutable QString m_SolString;
//	QTextStream &m_Out;

	inline quint64 Calc() const;
	inline bool CanDo() const;
	inline long double BinarySearch( long double Min, long double Max ) const;
	mutable qulonglong A;
	mutable qulonglong B;
	mutable int N;
	mutable int M;
	mutable QVector<QVector<int> > t;
	mutable QVector<QVector<int> > tt;
};

#endif // FairandSquareCase_H

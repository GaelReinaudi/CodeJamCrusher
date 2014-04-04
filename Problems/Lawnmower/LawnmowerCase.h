#ifndef LawnmowerCase_H
#define LawnmowerCase_H

#include "GoogleCase.h"
#include <QTextStream>

class LawnmowerCase;

QString SolveCase(const LawnmowerCase & Case);

class LawnmowerCase : public GoogleCase
{
public:
	LawnmowerCase();
	~LawnmowerCase() {}

	//! Re-implemented
	void ParseCase(QTextStream & inputStream);
	QString Solve() const;

	mutable QString m_SolString;
//	QTextStream &m_Out;

	inline bool colOK(int i, int j) const;
	inline bool linOK(int i, int j) const;
	inline bool CanDo() const;
	inline long double BinarySearch( long double Min, long double Max ) const;
	mutable int N;
	mutable int M;
	mutable QVector<QVector<int> > t;
	mutable QVector<QVector<int> > tt;
};

#endif // LawnmowerCase_H

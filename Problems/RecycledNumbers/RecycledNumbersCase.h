#ifndef RecycledNumbersCase_H
#define RecycledNumbersCase_H

#include "GoogleCase.h"

class RecycledNumbersCase;

QString SolveCase(const RecycledNumbersCase & Case);

class RecycledNumbersCase : public GoogleCase
{
public:
	RecycledNumbersCase() {}
	~RecycledNumbersCase() {}

	//! Re-implemented
	void ParseCase(QTextStream & inputStream);
	QString Solve() const;


public:
	mutable int A;
	mutable int B;
	mutable int nDigit;
};

#endif // RecycledNumbersCase_H

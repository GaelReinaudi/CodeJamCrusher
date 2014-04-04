#ifndef GoroSortCase_H
#define GoroSortCase_H

#include "GoogleCase.h"

class GoroSortCase;

QString SolveCase(const GoroSortCase & Case);

class GoroSortCase : public GoogleCase
{
public:
	GoroSortCase() {}
	~GoroSortCase() {}

	//! Re-implemented
	void ParseCase(QTextStream & inputStream);
	QString Solve() const;


public:
	int N;
	mutable QList<int> A, B;

};

#endif // GoroSortCase_H

#ifndef DancingWiththeGooglersCase_H
#define DancingWiththeGooglersCase_H

#include "GoogleCase.h"

class DancingWiththeGooglersCase;

QString SolveCase(const DancingWiththeGooglersCase & Case);

class DancingWiththeGooglersCase : public GoogleCase
{
public:
	DancingWiththeGooglersCase() {}
	~DancingWiththeGooglersCase() {}

	//! Re-implemented
	void ParseCase(QTextStream & inputStream);
	QString Solve() const;


public:
	mutable int N;
	mutable int S;
	mutable int p;
	mutable QList<int> t;

};

#endif // DancingWiththeGooglersCase_H

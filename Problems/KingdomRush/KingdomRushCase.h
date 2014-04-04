#ifndef KingdomRushCase_H
#define KingdomRushCase_H

#include "GoogleCase.h"

class KingdomRushCase;

QString SolveCase(const KingdomRushCase & Case);

class KingdomRushCase : public GoogleCase
{
public:
	KingdomRushCase() {}
	~KingdomRushCase() {}

	//! Re-implemented
	void ParseCase(QTextStream & inputStream);
	QString Solve() const;


public:
	mutable int N;
	mutable QList<int> A;
	mutable QList<int> B;
	mutable QList<bool> madeA;
	mutable QList<bool> madeB;
};

#endif // KingdomRushCase_H

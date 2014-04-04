#ifndef StoreCreditCase_H
#define StoreCreditCase_H

#include "GoogleCase.h"

class StoreCreditCase;

QString SolveCase(const StoreCreditCase & Case);

class StoreCreditCase : public GoogleCase
{
public:
	StoreCreditCase() {}
	~StoreCreditCase() {}

	//! Re-implemented
	void ParseCase(QTextStream & inputStream);
	QString Solve() const;

public:
	int C;
	int I;
	QVarLengthArray<int> P;

};

#endif // StoreCreditCase_H

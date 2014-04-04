#ifndef EqualSumsCase_H
#define EqualSumsCase_H

#include "GoogleCase.h"

class EqualSumsCase;

QString SolveCase(const EqualSumsCase & Case);

class EqualSumsCase : public GoogleCase
{
public:
	EqualSumsCase() {}
	~EqualSumsCase() {}

	//! Re-implemented
	void ParseCase(QTextStream & inputStream);
	QString Solve() const;

public:
	mutable int N;
	mutable QVector<qint64> S1;
	mutable QHash<int, QList<int> > m_SumList;
	mutable bool done;
};

#endif // EqualSumsCase_H

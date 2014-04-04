#ifndef SafetyinNumbersCase_H
#define SafetyinNumbersCase_H

#include "GoogleCase.h"

class SafetyinNumbersCase;

QString SolveCase(const SafetyinNumbersCase & Case);

class SafetyinNumbersCase : public GoogleCase
{
public:
	SafetyinNumbersCase() {}
	~SafetyinNumbersCase() {}

	//! Re-implemented
	void ParseCase(QTextStream & inputStream);
	QString Solve() const;


public:
	mutable int N;
	mutable int m_MaxGrade;
	mutable QList<int> S;
	mutable QList<int> m_TotalSumOthers;
	mutable QList<int> m_MaxGradeOthers;
	int m_totalSum;
};

#endif // SafetyinNumbersCase_H

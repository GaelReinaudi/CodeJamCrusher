#ifndef PasswordProblemCase_H
#define PasswordProblemCase_H

#include "GoogleCase.h"

class PasswordProblemCase;

QString SolveCase(const PasswordProblemCase & Case);

class PasswordProblemCase : public GoogleCase
{
public:
	PasswordProblemCase() {}
	~PasswordProblemCase() {}

	//! Re-implemented
	void ParseCase(QTextStream & inputStream);
	QString Solve() const;


public:
	mutable int A;
	mutable int B;
	QVector<double> Prob;
};

#endif // PasswordProblemCase_H

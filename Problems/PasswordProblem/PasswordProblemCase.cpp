#include "stdafx.h"
#include "PasswordProblemCase.h"
#include <QtAlgorithms>
#include <QPoint>

QString SolveCase( const PasswordProblemCase & Case )
{
	return Case.Solve();
}

void PasswordProblemCase::ParseCase( QTextStream & inputStream )
{
	inputStream >> A;
	inputStream >> B;
// 	Prob.reserve(A);
	for(int i = 0; i < A; i++) {
		double pri;
		inputStream >> pri;
		Prob.append(pri);
	}

// 	for(int j = 0; j < A; j++) {
// 		for(int i = 0; i < W; i++) {
// 			inputStream >> symb;
// 			if(symb == 'X')
// 				MyPos = QPoint(i, j);
// 		}
// 		inputStream.readLine();
// 	}
}

QString PasswordProblemCase::Solve() const
{
	QString caseSolution("Case #%1: %2");
	caseSolution = caseSolution.arg(m_CaseNumber);

	double expKeyStroke = B + 2;

	double kStrokeN = B - A + 1;

	int keyStrokeRightAway = B + 2;

	for(int i = 0; i < A; i++) {
		double probCorrect_i = 1.0;
		double keyStrokeExpected = 0.0;
		for(int j = 0; j < A - i; j++) {
			int keyStroke = 1;//for enter
			probCorrect_i *= Prob[j];
			keyStroke += B - A + 2 * i;
			keyStrokeExpected = keyStroke + (1 - probCorrect_i) * (B + 1);
		}
		expKeyStroke = qMin(expKeyStroke, keyStrokeExpected);
	}

	return caseSolution.arg(expKeyStroke, 6, 'f');

	return caseSolution.arg("failed").arg("failed");
}



















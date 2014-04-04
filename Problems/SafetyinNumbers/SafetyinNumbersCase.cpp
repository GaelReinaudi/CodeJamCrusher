#include "stdafx.h"
#include "SafetyinNumbersCase.h"
#include <QtAlgorithms>
#include <QPoint>

QString SolveCase( const SafetyinNumbersCase & Case )
{
	return Case.Solve();
}

void SafetyinNumbersCase::ParseCase( QTextStream & inputStream )
{
	m_totalSum = 0;
	m_MaxGrade = 0;
	inputStream >> N;
	for(int i = 0; i < N; i++) {
		int si;
		inputStream >> si;
		S.append(si);
		m_totalSum += si;
		m_MaxGrade = qMax(m_MaxGrade, si);
	}
	for(int i = 0; i < N; i++) {
		m_TotalSumOthers.append(m_totalSum - S[i]);
		int maxOthers = 0;
		for(int j = 0; j < N ; j++) {
			if(j != i)
				maxOthers = qMax(maxOthers, S[j]);
		}
		m_MaxGradeOthers.append(maxOthers);
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

QString SafetyinNumbersCase::Solve() const
{
	QString caseSolution("Case #%1: %2");
	caseSolution = caseSolution.arg(m_CaseNumber);

	QString minPercentsToReturn;

	for(int iCandidate = 0; iCandidate < N ; iCandidate++) {
		QList<int> SwithoutI = S;
		SwithoutI.removeAt(iCandidate);

		double sumOth = 0.0;
		for(int i = 0; i < N - 1; i++) {
			double precnetother = double(1.0 - double(SwithoutI[i]) / double(m_TotalSumOthers[iCandidate]) / 2.0);
			sumOth += precnetother;
		}

		double minPercent = double(1.0 - S[iCandidate] / m_totalSum / 2.0);
		minPercent /= (sumOth + minPercent);
		minPercent *= 100.0;
		//sumOth

		minPercentsToReturn += QString(" %1").arg(minPercent, 7, 'f');
	}

	return caseSolution.arg(minPercentsToReturn);
}



















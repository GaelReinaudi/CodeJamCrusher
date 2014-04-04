#include "stdafx.h"
#include "KingdomRushCase.h"
#include <QtAlgorithms>
#include <QPoint>

QString SolveCase( const KingdomRushCase & Case )
{
	return Case.Solve();
}

void KingdomRushCase::ParseCase( QTextStream & inputStream )
{
	inputStream >> N;
	for(int i = 0; i < N; i++) {
		int ai, bi;
		inputStream >> ai;
		inputStream >> bi;
		A.append(ai);
		B.append(bi);
		madeA.append(false);
		madeB.append(false);
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

QString KingdomRushCase::Solve() const
{
	QString caseSolution("Case #%1: %2");
	caseSolution = caseSolution.arg(m_CaseNumber);

	int completeLevelB = 0;
	int completeLevelA = 0;
	int stars = 0;

	while(completeLevelB != N) {
		bool doneB = false;
		bool doneA = false;

		for(int i = 0; i < N; i++) {
			if(B[i] <= stars && !madeB[i]) {
				stars++;
				completeLevelB++;
				doneB = true;
				if(!madeA[i])
					stars++;
				madeA[i] = true;
				madeB[i] = true;
			}
		}

		if(!doneB) {
			for(int i = 0; i < N; i++) {
				if(A[i] <= stars && !madeA[i] && !madeB[i]) {
					stars++;
					completeLevelA++;
					madeA[i] = true;
					doneA = true;
					break;
				}
			}
			if(!doneA)
				return caseSolution.arg("Too Bad");
		}
	}

	return caseSolution.arg(completeLevelA + completeLevelB);

	return caseSolution.arg("Too Bad");
}



















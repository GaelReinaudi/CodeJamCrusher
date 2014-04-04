#include "stdafx.h"
#include "DancingWiththeGooglersCase.h"
#include <QtAlgorithms>

QString SolveCase( const DancingWiththeGooglersCase & Case )
{
	return Case.Solve();
}

void DancingWiththeGooglersCase::ParseCase( QTextStream & inputStream )
{
	inputStream >> N;
	inputStream >> S;
	inputStream >> p;
	for(int i = 0; i < N ; i++) {
		int ti;
		inputStream >> ti;
		t.append(ti);
	}
}

QString DancingWiththeGooglersCase::Solve() const
{
	QString caseSolution("Case #%1: %2");
	caseSolution = caseSolution.arg(m_CaseNumber);

	int nGooglers = 0;
	foreach(int ti, t) {
		int bestBeforeStar = 0;
		bool elligibleForStar = false;
		switch(ti % 3) {
			case 0:
				bestBeforeStar = ti / 3 + 0;
				elligibleForStar = bestBeforeStar >= 1 && ti <= 27  && bestBeforeStar == p - 1;
				break;
			case 1:
				bestBeforeStar = ti / 3 + 1;
//				elligibleForStar = bestBeforeStar >= 1 && ti <= 28 && bestBeforeStar == p - 1;
				break;
			case 2:
				bestBeforeStar = ti / 3 + 1 + 0;
				elligibleForStar = bestBeforeStar >= 1 && ti <= 26 && bestBeforeStar == p - 1;
				break;
		}
		if(bestBeforeStar >= p)
			nGooglers++;
		else if(elligibleForStar && S > 0) {
			S--;
			nGooglers++;
		}

	}
	if(S > 0)
		S = 0;
// 	m_Phrase.replace("0q", "z");
// 
	return caseSolution.arg(nGooglers);

	return caseSolution.arg("failed").arg("failed");
}



















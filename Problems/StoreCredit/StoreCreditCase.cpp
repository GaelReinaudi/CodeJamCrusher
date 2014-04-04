#include "stdafx.h"
#include "StoreCreditCase.h"

QString SolveCase( const StoreCreditCase & Case )
{
	return Case.Solve();
}

void StoreCreditCase::ParseCase( QTextStream & inputStream )
{
	inputStream >> C;
	inputStream >> I;
	P.resize(I);

	for(int iItem = 0; iItem < I; iItem++) {
		inputStream >> P[iItem];
	}
}

QString StoreCreditCase::Solve() const
{
	QString caseSolution("Case #%1: %2 %3");
	caseSolution = caseSolution.arg(m_CaseNumber);

	// for each item
	for(int iPrice = 0; iPrice < I; iPrice++) {
		// and for each higher ranked item
		for(int iPrice2 = iPrice + 1; iPrice2 < I; iPrice2++) {
			// try too combine
			if(P[iPrice] + P[iPrice2] == C) {
				return caseSolution.arg(iPrice + 1).arg(iPrice2 + 1);		
			}
		}
	}
	return caseSolution.arg("failed").arg("failed");
}
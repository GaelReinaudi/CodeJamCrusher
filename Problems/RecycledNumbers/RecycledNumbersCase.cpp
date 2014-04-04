#include "stdafx.h"
#include "RecycledNumbersCase.h"
#include <QtAlgorithms>

QString SolveCase( const RecycledNumbersCase & Case )
{
	return Case.Solve();
}

void RecycledNumbersCase::ParseCase( QTextStream & inputStream )
{
	inputStream >> A;
	inputStream >> B;
	nDigit = QString("%1").arg(B).count();
}

int PowTen(int p) {
	int i = 1;
	for (int j = 0; j < p; j++)  
		i *= 10;
	return i;
}

QString RecycledNumbersCase::Solve() const
{
	QString caseSolution("Case #%1: %2");
	caseSolution = caseSolution.arg(m_CaseNumber);

	int nPair = 0;
	if(A == B || nDigit <= 1)
		return caseSolution.arg(nPair);

	QHash<QPair<int,int>, bool> pairsExisting;

	for(int ithPlace = 1; ithPlace < nDigit; ithPlace++) {
		int frac = PowTen(nDigit - ithPlace);
		int mult = PowTen(ithPlace);

		for(int n = A; n <= B; n++) {
			int MoveLeft = n % frac; // the digits that move to the left
			int m = n / frac + (MoveLeft * mult);
			if(m <= B && m > n) {
				nPair++;
				pairsExisting.insert(QPair<int, int>(n, m), true);
			}
		}
	}
	nPair = pairsExisting.count();

	return caseSolution.arg(nPair);

	return caseSolution.arg("failed").arg("failed");
}



















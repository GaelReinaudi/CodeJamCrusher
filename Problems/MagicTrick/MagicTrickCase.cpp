#include "stdafx.h"
#include "MagicTrickCase.h"
#include <QtAlgorithms>
#include <QPoint>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;

typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

QVector<qulonglong> list1014;
QVector<qulonglong> rootlist1014;
Pal012 IterRoot10100;
QVector<Pal012> rootlist10100;


MagicTrickCase::MagicTrickCase()
{
}

QString SolveCase( const MagicTrickCase & Case )
{
	return Case.Solve();
}

void MagicTrickCase::ParseCase( QTextStream & inputStream )
{
	inputStream >> guess1;
	guess1--;
 	for(int i = 0; i < 4; i++) {
 		for(int j = 0; j < 4 ; j++) {
 			inputStream >> grid1[i][j];
 		}
 	}
	inputStream >> guess2;
	guess2--;
 	for(int i = 0; i < 4; i++) {
 		for(int j = 0; j < 4 ; j++) {
 			inputStream >> grid2[i][j];
 		}
 	}
}

QString MagicTrickCase::Solve() const
{
	QString caseSolution("Case #%1: %2");
	caseSolution = caseSolution.arg(m_CaseNumber);

	QTextStream m_Out(&m_SolString);

	
	//caseSolution = caseSolution.arg(BinarySearch(0,0));

	const Line & l2 = grid2[guess2];
	int nCom = 0;
	int j1 = -1;
	for( int i = 0; i < 4; ++i)
	{
		int g2 = l2[i];
		for(int j =0 ; j < 4; ++j)
		{
			if(g2 == grid1[guess1][j])
			{
				++nCom;
				j1 = j;
			}
		}
	}
	if(nCom > 1)
		caseSolution = caseSolution.arg("Bad magician!");
	if(nCom <= 0)
		caseSolution = caseSolution.arg("Volunteer cheated!");
	if(nCom == 1)
		caseSolution = caseSolution.arg(grid1[guess1][j1]);



	caseSolution = caseSolution.arg(m_SolString);
	return caseSolution;
}

inline bool MagicTrickCase::Calc(qulonglong n) const
{
	qulonglong TsN = 2*r + 2 * n - 1;
	return TsN > t/n;
}

inline qulonglong MagicTrickCase::BinarySearch( long double Min, long double Max ) const
{
	qulonglong lo = 1;
	qulonglong hi = Q_INT64_C(18446744073709551615);//18,446,744,073,709,551,615
	qulonglong mid;
	while (lo < hi) {
		mid = lo + (hi-lo)/2;
		if (Calc(mid) == true)
			hi = mid;
		else
			lo = mid+1;
	}
	if (Calc(lo) == false)
		;  // p(x) is false for all x in S!
	// lo is the least x for which p(x) is true

	return lo - 1;
}















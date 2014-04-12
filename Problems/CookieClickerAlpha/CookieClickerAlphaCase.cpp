#include "stdafx.h"
#include "CookieClickerAlphaCase.h"
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


CookieClickerAlphaCase::CookieClickerAlphaCase()
{
}

QString SolveCase( const CookieClickerAlphaCase & Case )
{
	return Case.Solve();
}

void CookieClickerAlphaCase::ParseCase( QTextStream & inputStream )
{
	inputStream >> C;
	inputStream >> F;
	inputStream >> X;
}

QString CookieClickerAlphaCase::Solve() const
{
	QString caseSolution("Case #%1: %2");
	caseSolution = caseSolution.arg(m_CaseNumber);

	QTextStream m_Out(&m_SolString);

	
	//caseSolution = caseSolution.arg(BinarySearch(0,0));
	caseSolution = caseSolution.arg(compute(), 0, 'f', 7);


	caseSolution = caseSolution.arg(m_SolString);
	return caseSolution;
}

inline bool CookieClickerAlphaCase::Calc(qulonglong n) const
{
	qulonglong TsN = 2*r + 2 * n - 1;
	return TsN > t/n;
}

inline qulonglong CookieClickerAlphaCase::BinarySearch( long double Min, long double Max ) const
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


inline double CookieClickerAlphaCase::compute() const
{
	const int Fmax = 20000000;
	QVector<double> tF(Fmax);
	tF[0] = 0.0;
	int totalFarm = 0;
	for(int i = 1; i < Fmax; ++i)
	{
		tF[i] = tF[i - 1] + C / (2 + double(i-1) * F);
	}
	double tx = 1e20;
	for(int i = 0; i < Fmax; ++i)
	{
		double newtX = tF[i] + X / (2 + double(i) * F);
		if(newtX < tx)
			tx = newtX;
		else 
			break;
		if(i==Fmax-1)
			newtX = 0;
	}
	return tx;
}













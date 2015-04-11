#include "stdafx.h"
#include "InfiniteHouseOfPancakesCase.h"
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


InfiniteHouseOfPancakesCase::InfiniteHouseOfPancakesCase()
{
}

QString SolveCase( const InfiniteHouseOfPancakesCase & Case )
{
	return Case.Solve();
}

void InfiniteHouseOfPancakesCase::ParseCase( QTextStream & inputStream )
{
	inputStream >> D;
	int pi = 0;
	for (int i = 0; i < 1024; ++i) {
		numStackAtN[i] = 0;;
	}
	for (int i = 0; i < D; ++i) {
		inputStream >> pi;
		biggestStack = qMax(biggestStack, pi);
		++numStackAtN[pi];
	}
	qDebug() << numStackAtN[0] << numStackAtN[1] << numStackAtN[2] << numStackAtN[3] << numStackAtN[4] << "biggest" << biggestStack;
}

QString InfiniteHouseOfPancakesCase::Solve() const
{
	QString caseSolution("Case #%1: %2");
	caseSolution = caseSolution.arg(m_CaseNumber);

	QTextStream out(&m_SolString);

	
	//caseSolution = caseSolution.arg(BinarySearch(0,0));
	//caseSolution = caseSolution.arg(compute(out));
	compute(out);
	int ff = m_SolString.count("Impos");
	++ff;

	caseSolution = caseSolution.arg(m_SolString);
	return caseSolution;
}

inline bool InfiniteHouseOfPancakesCase::Calc(qulonglong n) const
{
	qulonglong TsN = 2*r + 2 * n - 1;
	return TsN > t/n;
}

inline qulonglong InfiniteHouseOfPancakesCase::BinarySearch( long double Min, long double Max ) const
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
	{
		;  // Calc(x) is false for all x in S!
	}
	// lo is the least x for which Calc(x) is true

	return lo;
}

inline void InfiniteHouseOfPancakesCase::compute(QTextStream & out) const
{
	int flip = 0;
	qint64 tot = 0;
	int withMax = 0;
	int pMax = 0;
	int totalCost = 1024;
	for (int i = 1; i <= biggestStack; ++i) {
		int c = costBringAllAtN(i);
		c += i;
		totalCost = qMin(totalCost, c);
	}
	out << totalCost;
}

inline int InfiniteHouseOfPancakesCase::costBringAllAtN(int n) const
{
	int cost = 0;
	for (int i = 0; i <= biggestStack; ++i) {
		if (i <= n)
			continue;
		int costPerstack = (i - 1) / n;
		cost += costPerstack * numStackAtN[i];
	}
	return cost;
}











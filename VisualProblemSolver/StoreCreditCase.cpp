#include "stdafx.h"
#include "StoreCreditCase.h"
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


StoreCreditCase::StoreCreditCase()
{
}

QString SolveCase( const StoreCreditCase & Case )
{
	return Case.Solve();
}

void StoreCreditCase::ParseCase( QTextStream & inputStream )
{
	inputStream >> D;
	int pi = 0;
	for (int i = 0; i < D; ++i) {
		inputStream >> pi;
		p.append(pi);
	}
}

QString StoreCreditCase::Solve() const
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

inline bool StoreCreditCase::Calc(qulonglong n) const
{
	qulonglong TsN = 2*r + 2 * n - 1;
	return TsN > t/n;
}

inline qulonglong StoreCreditCase::BinarySearch( long double Min, long double Max ) const
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


inline void StoreCreditCase::compute(QTextStream & out) const
{
	int flip = 0;
	qint64 tot = 0;
	int withMax = 0;
	int pMax = 0;
	for (int i = 0; i < D; ++i) {
		pMax = qMax(pMax, p[i]);
	}
	for (int i = 0; i < D; ++i) {
		if (p[i] == pMax)
			++withMax;
	}

	out << flip;
}

inline int StoreCreditCase::waitingCost(const QVector<int>& pList) const
{
	int withMax = 0;
	int pMax = 0;
	for (int i = 0; i < pList.count(); ++i) {
		pMax = qMax(pMax, pList[i]);
	}
	return pMax;
}

inline int StoreCreditCase::splitAllAtCost(int n, QVector<int>& pList) const
{
	int split = 0;
	for (int i = 0; i < pList.count(); ++i) {
		if (pList[i] > n) {
			pList.append(pList[i] - n);
			pList[i] = n;
			++split;
		}
	}
	return split;
}











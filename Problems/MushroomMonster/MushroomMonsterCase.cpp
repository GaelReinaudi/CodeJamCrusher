#include "stdafx.h"
#include "MushroomMonsterCase.h"
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


MushroomMonsterCase::MushroomMonsterCase()
{
}

QString SolveCase( const MushroomMonsterCase & Case )
{
	return Case.Solve();
}

void MushroomMonsterCase::ParseCase( QTextStream & inputStream )
{
	//inputStream >> S;
	//inputStream >> list;
	//for (int i = 0; i < list.count(); ++i) {
	//	c.append(list.mid(i, 1).toInt());
	//}
	inputStream >> N;
	for (int i = 0; i < N; ++i) {
		int mi;
		inputStream >> mi;
		c.append(mi);
	}
}

QString MushroomMonsterCase::Solve() const
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

inline bool MushroomMonsterCase::Calc(qulonglong n) const
{
	qulonglong TsN = 2*r + 2 * n - 1;
	return TsN > t/n;
}

inline qulonglong MushroomMonsterCase::BinarySearch( long double Min, long double Max ) const
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


inline void MushroomMonsterCase::compute(QTextStream & out) const
{
	qint64 min1 = 0;
	qint64 min2 = 0;
	for (int i = 1; i < N; ++i) {
		qint64 diff = c[i] - c[i - 1];
		if (diff < 0) {
			min1 += -diff;
		}
	}
	qint64 per10s = 0;
	for (int i = 1; i < N; ++i) {
		qint64 diff = c[i] - c[i - 1];
		if (diff < 0) {
			per10s = qMax(per10s, -diff);
		}
	}
	for (int i = 0; i < N-1; ++i) {
		if (c[i] < per10s) {
			min2 += c[i];
		}
		else {
			min2 += per10s;
		}
	}
	//if(A>B)
	//	qSwap(A,B);
	//int BK = qMin(B,K);
	//for(int a = 0; a < A; ++a)
	//{
	//	for(int b = 0; b < B; ++b)
	//	{
	//		for(int k = 0; k < K; ++k)
	//		{
	//			n += bool(((a & b) == k));
	//		}
	//	}
	//}
	out << min1;
	out << " ";
	out << min2;
}













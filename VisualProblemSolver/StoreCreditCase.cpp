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
	inputStream >> R;
	inputStream >> C;
	inputStream >> M;
}

QString StoreCreditCase::Solve() const
{
	QString caseSolution("Case #%1: %2");
	caseSolution = caseSolution.arg(m_CaseNumber);

	QTextStream out(&m_SolString);

	
	//caseSolution = caseSolution.arg(BinarySearch(0,0));
	//caseSolution = caseSolution.arg(compute(out));
	compute(out);

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
		;  // p(x) is false for all x in S!
	// lo is the least x for which p(x) is true

	return lo - 1;
}


inline void StoreCreditCase::compute(QTextStream & out) const
{
	out << endl;
	if(R == 1 && C == 1)
	{
		if(M > 0)
		{
			out << "Impossible";
			return;
		}
		out << "c" << endl;
		return;
	}
	if(R == 1)
	{
		if(M > C - 2)
		{
			out << "Impossible";
			return;
		}
		out << "c";
		for(int i = 1; i < C-M; ++i)
			out << ".";
		for(int i = C-M; i < C; ++i)
			out << "*";
		return;
	}
	if(C == 1)
	{
		if(M > R - 2)
		{
			out << "Impossible";
			return;
		}
		out << "c";
		for(int i = 1; i < R-M; ++i)
			out  << endl << ".";
		for(int i = R-M; i < R; ++i)
			out  << endl << "*";
		return;
	}
	// here R >= 2 and C >= 2
	if(M > R * C - 4)
	{
		out << "Impossible";
		return;
	}

	int r = R * C - M;
	int v = r;
	int x = v / R - 1;
	out << "c";
	--r;
	for(int i = 0; i < R; ++i)
	{
		if(i == 0)// first line
		{
			out << ".";
			--r;
			for(int j = 2; j < C; ++j)
			{
				if(j <= x + (v % R > i ? 1 : 0))
				{
					out << ".";
					--r;
				}
				else
				{
					out << "*";
				}
			}
		}
		else
		{
			out << endl;
			for(int j = 0; j < C; ++j)
			{
				if(j <= x + (v % R >= i + 1 ? 1 : 0))
				{
					out << ".";
					--r;
				}
				else
				{
					out << "*";
				}
			}
		}

	}

}













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
	inputStream >> N;
	inputStream >> M;
	for(int n = 0; n < N; ++n)
	{
		zs.append(0);
		inputStream >> zs[n];
	}
	for(int m = 0; m < M; ++m)
	{
		int fro = 0;
		int too = 0;
		inputStream >> fro;
		inputStream >> too;
		ts[zs[fro-1]] = zs[too-1];
	}
	qSort(zs.begin(), zs.end());
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
	{
		;  // Calc(x) is false for all x in S!
	}
	// lo is the least x for which Calc(x) is true

	return lo;
}


inline void StoreCreditCase::compute(QTextStream & out) const
{
	quint64 n = 0;

	bool couldFinish = false;
	for(int n = 0; n < N; ++n)
	{
		QString str;
		QVector<int> tzp = zs;
		if(finishTrip(zs[n], str, tzp))
		{
			out << str;
			return;
		}
	}
	out << "aaaaaaaaaaaaaaaaaaaaaaaaaa";
}



inline int StoreCreditCase::finishTrip(int zip, QString & str, QVector<int> & tzp) const
{
	if(tzp.size() == 1)
	{
		str.append(QString::number(tzp[0]));
		return 1;
	}
	tzp.remove(tzp.indexOf(zip));
	for(int n = 0; n < tzp.size(); ++n)
	{
		QString ss = str;
		QVector<int> zz = tzp;
		if(finishTrip(zs[n], ss, zz))
		{
			str.append(ss);
			return 1;
		}
	}
	return 0;
}













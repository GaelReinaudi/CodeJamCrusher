#include "stdafx.h"
#include "BuleysCase.h"
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


BuleysCase::BuleysCase()
// 	: m_Out(*(new QTextStream(&m_SolString)))
{
}

QString SolveCase( const BuleysCase & Case )
{
	return Case.Solve();
}

void BuleysCase::ParseCase( QTextStream & inputStream )
{
	inputStream >> r;
	inputStream >> t;
//	inputStream >> A;
//	double lastxx = 0.0;
//	double lasttt = 0.0;
// 	for(int i = 0; i < N; i++) {
// // 		QString line;
// // 		inputStream >> line;
// 		t.append(QVector<int>(M));
// 		for(int j = 0; j < M ; j++) {
// 			inputStream >> t[i][j];
// 			tt[j][i] = t[i][j];
// 		}
// 	}
}

QString BuleysCase::Solve() const
{
	QString caseSolution("Case #%1: %2");
	caseSolution = caseSolution.arg(m_CaseNumber);

	QTextStream m_Out(&m_SolString);

	

	caseSolution = caseSolution.arg(BinarySearch(0,0));


	caseSolution = caseSolution.arg(m_SolString);
	return caseSolution;
}

inline quint64 BuleysCase::Calc(qulonglong n) const
{
	qulonglong T = 2*r*n + 2 * n*n - n;
	return T > t ? 1 : 0;
}

inline qulonglong BuleysCase::BinarySearch( long double Min, long double Max ) const
{
	qulonglong theN = 0;
	qulonglong lo = 1;
	qulonglong hi = 10000000000;
	while (lo < hi) {
	qulonglong mid = lo + (hi-lo)/2;
		if (Calc(mid) == true)
			hi = mid;
		else
		lo = mid+1;
	}
	if (Calc(lo) == false)
		;                // p(x) is false for all x in S!

	return lo - 1;
}















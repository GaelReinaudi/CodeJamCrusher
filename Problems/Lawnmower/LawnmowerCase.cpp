#include "stdafx.h"
#include "LawnmowerCase.h"
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

LawnmowerCase::LawnmowerCase()
// 	: m_Out(*(new QTextStream(&m_SolString)))
{
}

QString SolveCase( const LawnmowerCase & Case )
{
	return Case.Solve();
}

void LawnmowerCase::ParseCase( QTextStream & inputStream )
{
	inputStream >> N;
	inputStream >> M;
//	inputStream >> A;
//	double lastxx = 0.0;
//	double lasttt = 0.0;
	for(int j = 0; j < M ; j++) {
		tt.append(QVector<int>(N));
	}
	for(int i = 0; i < N; i++) {
// 		QString line;
// 		inputStream >> line;
		t.append(QVector<int>(M));
		for(int j = 0; j < M ; j++) {
			inputStream >> t[i][j];
			tt[j][i] = t[i][j];
		}
	}
	t;
	tt;
}

QString LawnmowerCase::Solve() const
{
	QString caseSolution("Case #%1: %2");
	caseSolution = caseSolution.arg(m_CaseNumber);

	QTextStream m_Out(&m_SolString);

// 	foreach(long double aa, m_A) {
// 		m_LocalA = aa;
// 		long double start = BinarySearch(0.0, m_TX.key(D));
// 		m_Out << endl << QString("%1").arg(start + qSqrt((2 * D) / m_LocalA), 9, 'f');
// 	}

	if(CanDo())
		m_SolString = "YES";
	else
		m_SolString = "NO";


	caseSolution = caseSolution.arg(m_SolString);
	return caseSolution;
}

inline bool LawnmowerCase::CanDo() const
{
	bool canDo = true;
	for(int i = 0; i < N ; i++) {
		for(int j = 0; j < M ; j++) {
			if(!linOK(i, j) && !colOK(i, j))
				return false;
		}
	}

	return canDo;
}

inline bool LawnmowerCase::linOK(int i, int j) const
{
	int v = t[i][j];
	for(int x = 0; x < M ; x++) {
		if(t[i][x] > v)
			return false;
	}
	return true;
}

inline bool LawnmowerCase::colOK(int i, int j) const
{
	int v = tt[j][i];
	for(int x = 0; x < N ; x++) {
		if(tt[j][x] > v)
			return false;
	}
	return true;
}

inline long double LawnmowerCase::BinarySearch( long double Min, long double Max ) const
{
	long double startTime;
// 	while(Max - Min > 1e-8) {
// 		startTime = (Max + Min) * 0.5;
// 		if(HitCar(startTime, m_LocalA))
// 			Min = startTime;
// 		else
// 			Max = startTime;
// 	}
 	return startTime;
}















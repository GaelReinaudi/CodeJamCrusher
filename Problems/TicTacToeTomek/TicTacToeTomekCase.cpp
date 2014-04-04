#include "stdafx.h"
#include "TicTacToeTomekCase.h"
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

TicTacToeTomekCase::TicTacToeTomekCase()
// 	: m_Out(*(new QTextStream(&m_SolString)))
{
}

QString SolveCase( const TicTacToeTomekCase & Case )
{
	return Case.Solve();
}

void TicTacToeTomekCase::ParseCase( QTextStream & inputStream )
{
//	inputStream >> D;
//	inputStream >> N;
//	inputStream >> A;
//	double lastxx = 0.0;
//	double lasttt = 0.0;
	for(int i = 0; i < 4; i++) {
		QString line;
		inputStream >> line;
		t.append(QVector<int>(4));
		for(int j = 0; j < 4 ; j++) { // O=10   X = 100    T = 0    . = 1
			t[i][j] = (line[j] == 'O'? 10 : line[j] == 'X'? 100 : line[j] == 'T' ? 0 : 1);
		}
	}
	t;
}

QString TicTacToeTomekCase::Solve() const
{
	QString caseSolution("Case #%1: %2");
//	caseSolution = caseSolution.arg(m_CaseNumber);
	caseSolution = caseSolution.arg(m_CaseNumber).arg("");

	QTextStream m_Out(&m_SolString);

// 	foreach(long double aa, m_A) {
// 		m_LocalA = aa;
// 		long double start = BinarySearch(0.0, m_TX.key(D));
// 		m_Out << endl << QString("%1").arg(start + qSqrt((2 * D) / m_LocalA), 9, 'f');
// 	}
	t;
	for(int d = 0; d < 2 ; d++) {
		int sum = 0;
		for(int j = 0; j < 4 ; j++) {
			sum += t[j][d?j:3-j];
		}
		if(sum == 30 || sum == 40)
			return caseSolution + "O won";
		if(sum == 300 || sum == 400)
			return caseSolution + "X won";
	}
	for(int l = 0; l < 4 ; l++) {
		int sum = 0;
		for(int j = 0; j < 4 ; j++) {
			sum += t[l][j];
		}
		if(sum == 30 || sum == 40)
			return caseSolution + "O won";
		if(sum == 300 || sum == 400)
			return caseSolution + "X won";
	}
	for(int j = 0; j < 4 ; j++) {
		int sum = 0;
		for(int l = 0; l < 4 ; l++) {
			sum += t[l][j];
		}
		if(sum == 30 || sum == 40)
			return caseSolution + "O won";
		if(sum == 300 || sum == 400)
			return caseSolution + "X won";
	}
	for(int j = 0; j < 4 ; j++) {
		int sum = 0;
		for(int l = 0; l < 4 ; l++) {
			sum += t[l][j];
		}
		if(sum % 10)
			return caseSolution + "Game has not completed";
	}
	return caseSolution + "Draw";


	caseSolution = caseSolution.arg(m_SolString);
	return caseSolution;
}

bool TicTacToeTomekCase::HitCar( long double startTime, long double a ) const
{
// 	foreach(long double time, m_TX.keys()) {
// 		long double otherCar = m_TX.value(time);
// 		if(MyPos(startTime, a, time) > otherCar && otherCar <= D)
// 			return true;
// 	}
	return false;
}

long double TicTacToeTomekCase::MyPos( long double startTime, long double a, long double time ) const
{
	long double relt = time - startTime;
	if(relt <= 0.0)
		return 0.0;
	return relt * relt * a / 2.0;
}

long double TicTacToeTomekCase::BinarySearch( long double Min, long double Max ) const
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















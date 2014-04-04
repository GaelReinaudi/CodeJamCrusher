#include "stdafx.h"
#include "OutofGasCase.h"
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

OutofGasCase::OutofGasCase()
// 	: m_Out(*(new QTextStream(&m_SolString)))
{
}

QString SolveCase( const OutofGasCase & Case )
{
	return Case.Solve();
}

void OutofGasCase::ParseCase( QTextStream & inputStream )
{
	inputStream >> D;
	inputStream >> N;
	inputStream >> A;
	double lastxx = 0.0;
	double lasttt = 0.0;
	for(int i = 0; i < N; i++) {
		double xx,tt;
		inputStream >> tt;
		inputStream >> xx;
		if(lastxx <= D && xx >= D) {
			tt = lasttt + (D-lastxx)/(xx-lastxx) * (tt - lasttt);
			m_TX.insert(tt, D);
		}
		else
			m_TX.insert(tt,xx);
		lastxx = xx;
		lasttt = tt;
	}
	for(int i = 0; i < A ; i++) {
		double aa;
		inputStream >> aa;
		m_A.append(aa);
	}


	long double tForD = m_TX.values().last();
}

QString OutofGasCase::Solve() const
{
	QString caseSolution("Case #%1: %2");
	caseSolution = caseSolution.arg(m_CaseNumber);

	QTextStream m_Out(&m_SolString);

	foreach(long double aa, m_A) {
		m_LocalA = aa;
		long double start = BinarySearch(0.0, m_TX.key(D));
		m_Out << endl << QString("%1").arg(start + qSqrt((2 * D) / m_LocalA), 9, 'f');
	}

	caseSolution = caseSolution.arg(m_SolString);
	return caseSolution;
}

bool OutofGasCase::HitCar( long double startTime, long double a ) const
{
	foreach(long double time, m_TX.keys()) {
		long double otherCar = m_TX.value(time);
		if(MyPos(startTime, a, time) > otherCar && otherCar <= D)
			return true;
	}
	return false;
}

long double OutofGasCase::MyPos( long double startTime, long double a, long double time ) const
{
	long double relt = time - startTime;
	if(relt <= 0.0)
		return 0.0;
	return relt * relt * a / 2.0;
}

long double OutofGasCase::BinarySearch( long double Min, long double Max ) const
{
	long double startTime;
	while(Max - Min > 1e-10) {
		startTime = (Max + Min)*0.5;
		if(HitCar(startTime, m_LocalA))
			Min = startTime;
		else
			Max = startTime;
	}
	return startTime;
}















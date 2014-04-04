#include "stdafx.h"
#include "FairandSquareCase.h"
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

inline bool isPal(qulonglong & n)
{
	QString nums = QString::number(n);
	int l = nums.length();
	int half = l / 2;
	for(int i = 0; i < half ; i++) {
		if(nums[i] != nums[l - 1 - i])
			return false;
	}
	return true;
}

namespace {
	int a() {
	for(qulonglong i = 1; i < 10000000 ; ++i) {
		if(isPal(i)) {
			qulonglong ii = i * i;
			if(isPal(ii)) {
				rootlist1014 << i;
				list1014 << ii;
			}
		}
	}
	return 0;
	}
	int d = a();
}

FairandSquareCase::FairandSquareCase()
// 	: m_Out(*(new QTextStream(&m_SolString)))
{
}

QString SolveCase( const FairandSquareCase & Case )
{
	return Case.Solve();
}

void FairandSquareCase::ParseCase( QTextStream & inputStream )
{
	inputStream >> A;
	inputStream >> B;
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

QString FairandSquareCase::Solve() const
{
	QString caseSolution("Case #%1: %2");
	caseSolution = caseSolution.arg(m_CaseNumber);

	QTextStream m_Out(&m_SolString);

// 	foreach(long double aa, m_A) {
// 		m_LocalA = aa;
// 		long double start = BinarySearch(0.0, m_TX.key(D));
// 		m_Out << endl << QString("%1").arg(start + qSqrt((2 * D) / m_LocalA), 9, 'f');
// 	}

	caseSolution = caseSolution.arg(Calc());


	caseSolution = caseSolution.arg(m_SolString);
	return caseSolution;
}

inline quint64 FairandSquareCase::Calc() const
{
	QVector<int> list1000;
	list1000 << 1 << 4 << 9 << 121 << 484;

	int count = list1014.size();
	rootlist1014;
	for(int i = 0; i < list1014.size() ; i++) {
		if(A > list1014[i])
			count--;
		if(B < list1014[i])
			count--;
	}

	return count;
}

inline long double FairandSquareCase::BinarySearch( long double Min, long double Max ) const
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















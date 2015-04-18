#include "stdafx.h"
#include "HaircutCase.h"
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


HaircutCase::HaircutCase()
{
}

QString SolveCase( const HaircutCase & Case )
{
	return Case.Solve();
}

void HaircutCase::ParseCase( QTextStream & inputStream )
{
	//inputStream >> S;
	//inputStream >> list;
	//for (int i = 0; i < list.count(); ++i) {
	//	c.append(list.mid(i, 1).toInt());
	//}
	inputStream >> B;
	inputStream >> N;
	for (int i = 0; i < B; ++i) {
		int mi;
		inputStream >> mi;
		c.append(mi);
	}
}

QString HaircutCase::Solve() const
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

inline bool HaircutCase::Calc(qulonglong n) const
{
	qulonglong cust = 0;
	for (int i = 0; i < B; ++i) {
		qulonglong nCust = n / c[i];
		cust += nCust;
	}
	return cust >= N - B;
}

inline qulonglong HaircutCase::BinarySearch(long double Min, long double Max) const
{
	qulonglong lo = 0;
	qulonglong hi = Q_INT64_C(18446744073709);// 551615);//18,446,744,073,709,551,615
	qulonglong mid;
	while (lo < hi) {
		mid = lo + (hi - lo) / 2;
		if (Calc(mid) == true)
			hi = mid;
		else
			lo = mid + 1;
	}
	if (Calc(lo) == false)
	{
		;  // Calc(x) is false for all x in S!
	}
	// lo is the least x for which Calc(x) is true

	return lo;
}
inline bool HaircutCase::Calc2(qulonglong n) const
{
	qulonglong cust = 0;
	for (qulonglong i = 0; i < B; ++i) {
		qulonglong nCust = n / c[i];
		//if (n % c[i] == 0) 
		{
			++nCust;
		}
		cust += nCust;
		if (cust >= N) {
			return true;
		}
	}
	return false;
}

inline qulonglong HaircutCase::BinarySearch2(long double Min, long double Max) const
{
	qulonglong lo = 0;
	qulonglong hi = Q_INT64_C(18446744073709551615) / qulonglong(B+1);//18,446,744,073,709,551,615
	qulonglong mid;
	while (lo < hi) {
		mid = lo + (hi - lo) / 2;
		if (Calc2(mid) == true)
			hi = mid;
		else
			lo = mid + 1;
	}
	if (Calc2(lo) == false)
	{
		qDebug() << "EEER";  // Calc(x) is false for all x in S!
	}
	// lo is the least x for which Calc(x) is true

	return lo;
}


inline void HaircutCase::compute(QTextStream & out) const
{
	qint64 barb = 0;

	if (N <= B) {
		out << N;
		return;
	}
	qint64 t = 0;
	qint64 tWaitNmB = BinarySearch(0, 0);
	qulonglong tWait = BinarySearch2(0, 0);
	//// B person in front of me
	//for (int i = 0; i < B; ++i) {

	//}
	qulonglong doneAtT = 0;
	// B person in front of me
	for (int i = 0; i < B; ++i) {
		qulonglong nCust = tWait / c[i];
		doneAtT += nCust;
	}
	qulonglong workedOnAtT = 0;
	// B person in front of me
	for (int i = 0; i < B; ++i) {
		qulonglong nCust = tWait / c[i];
		if (tWait % c[i] != 0)
			++nCust;
		workedOnAtT += nCust;
	}
	qulonglong takenNow = N - workedOnAtT;// -doneAtT;
	//while (true)
	{
		for (int i = 0; i < B; ++i) {
			if (tWait % c[i] == 0) {
				--takenNow;
				if (takenNow <= 0) {
					out << i + 1;
					return;
				}
			}
		}
		++tWait;
	}
	out << "ERR";
}













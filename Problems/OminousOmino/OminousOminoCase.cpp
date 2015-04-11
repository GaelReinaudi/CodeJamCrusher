#include "stdafx.h"
#include "OminousOminoCase.h"
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


OminousOminoCase::OminousOminoCase()
{
}

QString SolveCase( const OminousOminoCase & Case )
{
	return Case.Solve();
}

void OminousOminoCase::ParseCase( QTextStream & inputStream )
{
	inputStream >> X;
	inputStream >> R;
	inputStream >> C;
}

QString OminousOminoCase::Solve() const
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

inline bool OminousOminoCase::Calc(qulonglong n) const
{
	qulonglong TsN = 2*r + 2 * n - 1;
	return TsN > t/n;
}

inline qulonglong OminousOminoCase::BinarySearch( long double Min, long double Max ) const
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


inline void OminousOminoCase::compute(QTextStream & out) const
{
	if (X == 1) {
		out << "GABRIEL";
		return;
	}
	if (X == 2) {
		if ((R * C) % 2) {
			out << "RICHARD";
			return;
		}
		out << "GABRIEL";
		return;
	}
	if (X == 3) {
		if ((R * C) % 3) {
			out << "RICHARD";
			return;
		}
		if (R <= 1 || C <= 1) {
			out << "RICHARD";
			return;
		}
		out << "GABRIEL";
		return;
	}
	if (X == 4) {
		if ((R * C) % 4) {
			out << "RICHARD";
			return;
		}
		if (R <= 2 || C <= 2) {
			out << "RICHARD";
			return;
		}
		out << "GABRIEL";
		return;
	}
	out << "GABRIEL";
	return;
}













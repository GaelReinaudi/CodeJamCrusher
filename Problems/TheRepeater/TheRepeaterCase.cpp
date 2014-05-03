#include "stdafx.h"
#include "TheRepeaterCase.h"
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


TheRepeaterCase::TheRepeaterCase()
{
}

QString SolveCase( const TheRepeaterCase & Case )
{
	return Case.Solve();
}

void TheRepeaterCase::ParseCase( QTextStream & inputStream )
{

	inputStream >> N;
	for(int i = 0; i < N; ++i)
	{
		strings.append(QString());
		inputStream >> strings[i];
	}
}

QString TheRepeaterCase::Solve() const
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

inline bool TheRepeaterCase::Calc(qulonglong n) const
{
	qulonglong TsN = 2*r + 2 * n - 1;
	return TsN > t/n;
}

inline qulonglong TheRepeaterCase::BinarySearch( long double Min, long double Max ) const
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


inline void TheRepeaterCase::compute(QTextStream & out) const
{
	if(caseNumber() == 6)
	{
		// can put a break point here
		int fff=0; ++fff;
	}
	// each string
	QStringList noDup = strings;
	QList<QList<int> > rep;
	for(int n = 0; n < N; ++n)
	{
		QString & str = noDup[n];
		rep.append(QList<int>());
		// cut duplicate
		int i = 0;
		int locRep = 1;
		if(str.size() == 1)
			rep[n].append(1);
		else{
		while(i < str.size() - 1)
		{
			if(str[i] == str[i+1])
			{
				str.remove(i, 1);
				++locRep;
				if(i == str.size() - 1)
					rep[n].append(locRep);
			}
			else
			{
				rep[n].append(locRep);
				locRep = 1;
				if(i == str.size() - 2)
					rep[n].append(1);
				++i;
			}
		}
		}
	}
	noDup.removeDuplicates();
	if(noDup.count() > 1)
	{
		out << "Fegla Won";
		return;
	}

		int nIter = 0;
	for(int r = 0; r < rep[0].size(); ++r)
	{
		double ncharTot = 0;
		// each string
		for(int n = 0; n < N; ++n)
		{
			ncharTot += rep[n][r];
		}
		double av = ncharTot / strings.count();
		for(int n = 0; n < N; ++n)
		{
			int strSz = rep[n][r];
			int diff = int(av+0.5) - strSz;
			nIter += qAbs(diff);
		}
	}
	out << nIter;
}













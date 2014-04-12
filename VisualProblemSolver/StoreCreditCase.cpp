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
	int ff = m_SolString.count("Impos");
	++ff;

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
	QVector<QString> l(R);
	out << endl;
	if(R == 1 && C == 1)
	{
		if(M > 0)
		{
			goto bad;
		}
		out << "c" << endl;
		return;
	}
	if(R == 1)
	{
		if(M > C - 2)
		{
			goto bad;
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
			goto bad;
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
			goto bad;
	}

	int r = R * C - M;
	int v = r;
	bool isPair = v % 2 == 0;

	for(int i = 0; i < R; ++i)
		l[i] = QString(C, '*');
	l[0][0] = 'c';
	--r;
	l[0][1] = '.';
	--r;

	int imax = 0;
	for(int i = 1; i < R; ++i)
	{
		if(r >= 2 && isPair || r >= 6 && !isPair )
		{
			l[i][0] = '.';
			--r;
			l[i][1] = '.';
			--r;
			imax = i;
		}
		else if(r==3 || r == 5)
		{
			if((R > 4 && i>=3 && i < R-1) || (R == 4 && i==3))
			{
				l[i][0] = '.';
				--r;
				l[i][1] = '.';
				l[0][0] = '*';
				l[2][0] = 'c';
				imax = i;
				if(r==2 && i < R-1)
					goto bad;
			}
			else
			{
				goto bad;
			}
		}
	}
	if(R==2 && imax>=2)
	{
	}
	
	if(imax < 1)
	{

		goto bad;
	}
	if(r==0)
		goto theend;
	int jj = 2;
	for(int ffff = 0; ffff <= 50; ++ffff)
	{
		l[0][jj] = '.';
		--r;
		if(r<0)
		{
			goto bad;
		}

		for(int i = 1; i <= imax; ++i)
		{
			if(r == 1)
			{
				l[i][jj] = '.';
				--r;
				goto theend;
			}
			if(r >= 3)
			{
				l[i][jj] = '.';
				--r;
			}
			else if(r == 2 && i < imax)
			{
				l[i][jj] = '.';
				l[i + 1][jj] = '.';
				--r;
				--r;
				goto theend;
			}
			else if(r == 2 && jj < C - 1)
			{
				if(i == 1)
				{
					if(jj >= 2)
					{
						l[i][jj] = '.';
						l[0][0] = '*';
						l[0][2] = 'c';
					}
					else if(imax >= 3)
					{
						l[i][jj] = '.';
						l[0][0] = '*';
						l[2][0] = 'c';
					}
					else
						goto bad;
				}
				else
				{
					l[0][jj+1] = '.';
					l[1][jj+1] = '.';
					--r;
					--r;
					goto theend;
				}
			}
			else if(r == 2 && jj < C - 1)
			{
			}
		}
		++jj;
		if(ffff == 50)
		{
			goto bad;
		}
	}
theend:

		assert(r>=0);


	for(int i = 0; i < R; ++i)
	{
		if(l[i][C] == '.')
			goto bad;
	}

	out << l[0];
	for(int i = 1; i < R; ++i)
	{
		out << endl << l[i];
	}
	return;

bad:
	out << "Impossible";
	return;

}













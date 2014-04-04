#include "stdafx.h"
#include "PerfectHarmonyCase.h"
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


QString SolveCase( const PerfectHarmonyCase & Case )
{
	return Case.Solve();
}

void PerfectHarmonyCase::ParseCase( QTextStream & inputStream )
{
	m_Min = 1e17;
	inputStream >> N;
	inputStream >> L;
	inputStream >> H;
	for(int i = 0; i < N; i++) {
		qint64 si;
		inputStream >> si;
		Freqs.append(si);
		m_Min = qMin(m_Min, si);
	}
	m_Min = qMin(m_Min, H);
}

QString PerfectHarmonyCase::Solve() const
{
	QString caseSolution("Case #%1: %2");
	caseSolution = caseSolution.arg(m_CaseNumber);
	QTextStream out(&caseSolution);

	for(qint64 i = L; i <= H ; i++) {
		bool allGood = true;
		for(int j = 0; j < N ; j++) {
			if(Freqs[j] % i && i % Freqs[j]) {
				allGood = false;
				break;
			}
		}
		if(allGood)
			return caseSolution.arg(i);
	}
	return caseSolution.arg("NO");
}



















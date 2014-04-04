#include "stdafx.h"
#include "DiamondInheritanceCase.h"
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

DiamondInheritanceCase::DiamondInheritanceCase()
	: m_Out(*(new QTextStream(&m_SolString)))
{
}

QString SolveCase( const DiamondInheritanceCase & Case )
{
	return Case.Solve();
}

void DiamondInheritanceCase::ParseCase( QTextStream & inputStream )
{
	inputStream >> N;
	for(int i = 1; i <= N; i++) {
		int Inerti;
		inputStream >> Inerti;
		for(int j = 0; j < Inerti ; j++) {
			int ineritedFrom;
			inputStream >> ineritedFrom;
			m_InheritMap.insert(i, ineritedFrom);
		}
	}
	m_Under.append(QSet<int>());
	for(int i = 1; i <= N; i++) {
		m_Under.append(QSet<int>());//m_InheritMap.values(i).toSet());
	}
}

QString DiamondInheritanceCase::Solve() const
{
	QString caseSolution("Case #%1: %2");
	caseSolution = caseSolution.arg(m_CaseNumber);

	for(int i = 1; i <= N ; i++) {
	foreach(int iClass, (m_InheritMap.values(i)).toSet()) {
		m_Under[iClass] += i;
		}
	}

	m_Diamond = false;
	int iter = 0;
	for(int i = 0; i < 1000 ; i++) {
		MoveInheritance();
		if(m_Diamond)
			break;
		
	}
			iter++;

		





	if(m_Diamond)
		return caseSolution.arg("Yes");

	return caseSolution.arg("No");
}

bool DiamondInheritanceCase::MoveInheritance() const
{
	bool merged = false;
	for(int i = 1; i <= N ; i++) {
		int basescount = m_Under[i].count();

		foreach(int iClass, m_Under[i]) {
			m_Under[iClass] -= iClass;
			if(m_Under[iClass].contains(i))
				m_Diamond = true;
			else
				merged = true;
			m_Under[iClass] += m_Under[i];
			m_Under[iClass] -= iClass;
		}
	}
	return merged;
}


















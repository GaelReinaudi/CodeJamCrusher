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
	m_Bases.append(QSet<int>());
	for(int i = 1; i <= N; i++) {
		m_Bases.append(m_InheritMap.values(i).toSet());
	}
}

QString DiamondInheritanceCase::Solve() const
{
	QString caseSolution("Case #%1: %2");
	caseSolution = caseSolution.arg(m_CaseNumber);

	m_Diamond = false;
	int iter = 0;
		while(MoveInheritance())
			iter++;

	for(int i = 1; i <= N ; i++) {
		

		foreach(int firstClass, m_Bases[i]) {
			foreach(int secondClass, QSet<int>(m_Bases[i]) -= firstClass) {
				QSet<int> inter(m_Bases[firstClass]);
				inter.intersect(m_Bases[secondClass]);
				if(inter.count())

			}			
		}


	}

	if(m_Diamond)
		return caseSolution.arg("Yes");

	return caseSolution.arg("No");
}

bool DiamondInheritanceCase::MoveInheritance() const
{
	bool merged = false;
	for(int i = 1; i <= N ; i++) {
		int basescount = m_Bases[i].count();

// 		QList<int> baseilist = m_Bases[i].toList();
		foreach(int iClass, m_Bases[i].toList()) {
			QSet<int> copyC = m_Bases[iClass];
// 			if(!(copyC.intersect(m_Bases[i]).isEmpty()))
// 				m_Diamond = true;
// 			QList<int> baseclasslist = m_Bases[iClass].toList();
			m_Bases[i] += m_Bases[iClass];
		}
	
// 		baseilist = m_Bases[i].toList();
		
		if(m_Bases[i].count() != basescount)
			merged = true;
	}
	return merged;
}


















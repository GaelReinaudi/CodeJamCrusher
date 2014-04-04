#include "stdafx.h"
#include "SquareTilesCase.h"
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


QString SolveCase( const SquareTilesCase & Case )
{
	return Case.Solve();
}

void SquareTilesCase::ParseCase( QTextStream & inputStream )
{
	inputStream >> R;
	inputStream >> C;
	inputStream.readLine();
	for(int i = 0; i < R ; i++) {
		tiles += inputStream.readLine();
	}
	return;

// 	inputStream >> N;
// 	for(int i = 0; i < N; i++) {
// 		int si;
// 		inputStream >> si;
// 		S1.append(si);
// 	}

}

bool SquareTilesCase::ReplaceNextTiles() const
{
	int indexFirst = tiles.indexOf("##");
	if(indexFirst % C == C - 1)
		return false;
	if(indexFirst > (R-1) * C)
		return false;
	if(tiles.mid(indexFirst + C, 2) == "##") {
		tiles.replace(indexFirst, 2, "/\\");
		tiles.replace(indexFirst + C, 2, "\\/");
		return true;
	}
	return false;
}

QString SquareTilesCase::Solve() const
{
	QString caseSolution("Case #%1: %2");
	caseSolution = caseSolution.arg(m_CaseNumber);
	QTextStream out(&caseSolution);

	while(ReplaceNextTiles())
		;
	if(!tiles.contains('#')) {
		for(int i = R - 1; i >= 0 ; i--) {
			tiles.insert(i * C, "\n");
			
		}
		return caseSolution.arg(tiles);
	}
	return caseSolution.arg("\nImpossible");

// 	QMap<int, int> was;
// 	quint64 fffff = (one << N);
// 	if(fffff == 0)
// 		fffff++;
// 	for (int m = 1; m < fffff; m++) {
// 		int sum = 0;
// 		for (int i = 0; i < N; i++) 
// 			if (m & (1 << i)) 
// 				sum += S1[i];
// 		if (was.count(sum)) {
// 			caseSolution = caseSolution.arg("\n");
// 			QVector<int> res;
// 			for(int i = 0; i < N; i++) 
// 				if(m & (1 << i)) 
// 					res.push_back(S1[i]);
// 			for(int i = 0; i < res.count(); i++)
// 				out << " " << res[i];
// 			out <<endl;
// 			res.clear();
// 			for(int i = 0; i < N; i++) 
// 				if(was[sum] & (1 << i)) 
// 					res.push_back(S1[i]);
// 			for(int i = 0; i < res.count(); i++)
// 				out << " " << res[i];
// 
// 			// 			outSet(m);
// 			// 			outSet(was[sum]);
// 			return caseSolution;
// 		}
// 		was.insert(sum, m);
// 	}
// 	return caseSolution.arg("\nImpossible");
}



















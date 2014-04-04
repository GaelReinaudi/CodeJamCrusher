#include "stdafx.h"
#include "EqualSumsCase.h"
#include <QtAlgorithms>
#include <QPoint>

QString SolveCase( const EqualSumsCase & Case )
{
	return Case.Solve();
}

void EqualSumsCase::ParseCase( QTextStream & inputStream )
{
	done = false;
	inputStream >> N;
	for(int i = 0; i < N; i++) {
		int si;
		inputStream >> si;
		S1.append(si);
	}

}

QString EqualSumsCase::Solve() const
{
	QString caseSolution("Case #%1: %2");
	caseSolution = caseSolution.arg(m_CaseNumber);
	QTextStream out(&caseSolution);

	quint64 one = 1;
	qint64 s = one << 62;

// 	for(int i = 0; i < 500 ; i++) {
// 		out << QString("%1").arg((one<<i), 0, 2) << " " << (one<<i) << endl;
// 	}
// 
// 	return caseSolution;

	QMap<int, int> was;
	quint64 fffff = (one << N);
	if(fffff == 0)
		fffff++;
	for (int m = 1; m < fffff; m++) {
		int sum = 0;
		for (int i = 0; i < N; i++) 
			if (m & (1 << i)) 
				sum += S1[i];
		if (was.count(sum)) {
			caseSolution = caseSolution.arg("\n");
			QVector<int> res;
			for(int i = 0; i < N; i++) 
				if(m & (1 << i)) 
					res.push_back(S1[i]);
			for(int i = 0; i < res.count(); i++)
				out << " " << res[i];
			out <<endl;
			res.clear();
			for(int i = 0; i < N; i++) 
				if(was[sum] & (1 << i)) 
					res.push_back(S1[i]);
			for(int i = 0; i < res.count(); i++)
				out << " " << res[i];

			// 			outSet(m);
			// 			outSet(was[sum]);
			return caseSolution;
		}
		was.insert(sum, m);
	}

	return caseSolution.arg("Impossible");
}



















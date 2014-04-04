#include "stdafx.h"
#include "RopeIntranetCase.h"
#include <QtAlgorithms>

QString SolveCase( const RopeIntranetCase & Case )
{
	return Case.Solve();
}

void RopeIntranetCase::ParseCase( QTextStream & inputStream )
{
	inputStream >> m_Ropes;
	for(int i = 0; i < m_Ropes ; i++) {
		int A,B;
		inputStream >> A;
		inputStream >> B;
		AB.insert(A,B);
	}

// 	m_Phrase = inputStream.readLine();//.trimmed();

// 	for(int i = 0; i < m_N; i++) {
// 		int valX, valY;
// 		inputStream >> valX;
// 		inputStream >> valY;
// 		X.append(valX);
// 		mY.append(-valY);
// 
// 		inputStream.readLine();
// 	}

}

QString RopeIntranetCase::Solve() const
{
	QString caseSolution("Case #%1: %2");
	caseSolution = caseSolution.arg(m_CaseNumber);

	int nCross = 0;
	QList<int> As = AB.keys();
	qSort(As.begin(), As.end());
	for(int i = 0; i < m_Ropes; i++) {
		for(int j = i + 1; j < m_Ropes; j++) {
			if(AB.value(As[j]) < AB.value(As[i]))
				nCross++;
		}
	}

	return caseSolution.arg(nCross);

// 	m_Phrase.replace(" ", "*");
// 	m_Phrase.replace("a", " 2");
// 	m_Phrase.replace("b", " 22");
// 	m_Phrase.replace("c", " 222");
// 	m_Phrase.replace("d", " 3");
// 	m_Phrase.replace("e", " 33");
// 	m_Phrase.replace("f", " 333");
// 	m_Phrase.replace("g", " 4");
// 	m_Phrase.replace("h", " 44");
// 	m_Phrase.replace("i", " 444");
// 	m_Phrase.replace("j", " 5");
// 	m_Phrase.replace("k", " 55");
// 	m_Phrase.replace("l", " 555");
// 	m_Phrase.replace("m", " 6");
// 	m_Phrase.replace("n", " 66");
// 	m_Phrase.replace("o", " 666");
// 	m_Phrase.replace("p", " 7");
// 	m_Phrase.replace("q", " 77");
// 	m_Phrase.replace("r", " 777");
// 	m_Phrase.replace("s", " 7777");
// 	m_Phrase.replace("t", " 8");
// 	m_Phrase.replace("u", " 88");
// 	m_Phrase.replace("v", " 888");
// 	m_Phrase.replace("w", " 9");
// 	m_Phrase.replace("x", " 99");
// 	m_Phrase.replace("y", " 999");
// 	m_Phrase.replace("z", " 9999");
// 	m_Phrase.replace("*", " 0");
// 
// 	m_Phrase = m_Phrase.trimmed();
// 
// 	int indexSpace = m_Phrase.indexOf(" ");
// 	while(indexSpace >= 0) {
// 		if(m_Phrase.at(indexSpace - 1) != m_Phrase.at(indexSpace + 1))
// 			m_Phrase.remove(indexSpace, 1);
// 		else
// 			indexSpace++;
// 		indexSpace = m_Phrase.indexOf(" ", indexSpace);
// 	}
// 
// 	return caseSolution.arg(m_Phrase);
// 
// 	return caseSolution.arg("failed").arg("failed");
}












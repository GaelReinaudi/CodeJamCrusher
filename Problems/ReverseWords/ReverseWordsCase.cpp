#include "stdafx.h"
#include "ReverseWordsCase.h"

QString SolveCase( const ReverseWordsCase & Case )
{
	return Case.Solve();
}

void ReverseWordsCase::ParseCase( QTextStream & inputStream )
{
	Sentence = inputStream.readLine().trimmed();
}

QString ReverseWordsCase::Solve() const
{
	QString caseSolution("Case #%1:");
	caseSolution = caseSolution.arg(m_CaseNumber);

	QStringList Phrase = Sentence.split(" ");
	int nWorld = Phrase.count();
	// for each item
	for(int i = 0; i < nWorld; i++) {
		caseSolution += " ";
		caseSolution += Phrase[nWorld - 1 - i];
	}
	return caseSolution.arg("failed").arg("failed");
}
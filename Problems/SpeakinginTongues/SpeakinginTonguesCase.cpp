#include "stdafx.h"
#include "SpeakinginTonguesCase.h"
#include <QtAlgorithms>

QString SolveCase( const SpeakinginTonguesCase & Case )
{
	return Case.Solve();
}

void SpeakinginTonguesCase::ParseCase( QTextStream & inputStream )
{
	m_Phrase = inputStream.readLine();//.trimmed();
}

QString SpeakinginTonguesCase::Solve() const
{
	QString caseSolution("Case #%1: %2");
	caseSolution = caseSolution.arg(m_CaseNumber);

	m_Phrase.replace("a", "0a");
	m_Phrase.replace("b", "0b");
	m_Phrase.replace("c", "0c");
	m_Phrase.replace("d", "0d");
	m_Phrase.replace("e", "0e");
	m_Phrase.replace("f", "0f");
	m_Phrase.replace("g", "0g");
	m_Phrase.replace("h", "0h");
	m_Phrase.replace("i", "0i");
	m_Phrase.replace("j", "0j");
	m_Phrase.replace("k", "0k");
	m_Phrase.replace("l", "0l");
	m_Phrase.replace("m", "0m");
	m_Phrase.replace("n", "0n");
	m_Phrase.replace("o", "0o");
	m_Phrase.replace("p", "0p");
	m_Phrase.replace("q", "0q");
	m_Phrase.replace("r", "0r");
	m_Phrase.replace("s", "0s");
	m_Phrase.replace("t", "0t");
	m_Phrase.replace("u", "0u");
	m_Phrase.replace("v", "0v");
	m_Phrase.replace("w", "0w");
	m_Phrase.replace("x", "0x");
	m_Phrase.replace("y", "0y");
	m_Phrase.replace("z", "0z");


	m_Phrase.replace("0a", "y");
	m_Phrase.replace("0y", "a");
	m_Phrase.replace("0l", "g");
	m_Phrase.replace("0m", "l");
	m_Phrase.replace("0x", "m");
	m_Phrase.replace("0h", "x");
	m_Phrase.replace("0b", "h");
	m_Phrase.replace("0n", "b");
	m_Phrase.replace("0f", "c");
	m_Phrase.replace("0i", "d");
	m_Phrase.replace("0c", "e");
	m_Phrase.replace("0w", "f");
	m_Phrase.replace("0k", "i");
	m_Phrase.replace("0u", "j");
	m_Phrase.replace("0o", "k");
	m_Phrase.replace("0s", "n");
	m_Phrase.replace("0e", "o");
	m_Phrase.replace("0v", "p");
	m_Phrase.replace("0z", "q");
	m_Phrase.replace("0p", "r");
	m_Phrase.replace("0d", "s");
	m_Phrase.replace("0r", "t");
	m_Phrase.replace("0j", "u");
	m_Phrase.replace("0g", "v");
	m_Phrase.replace("0t", "w");
	m_Phrase.replace("0q", "z");

	return caseSolution.arg(m_Phrase);

	return caseSolution.arg("failed").arg("failed");
}












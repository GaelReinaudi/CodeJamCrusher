#ifndef T9SpellingCase_H
#define T9SpellingCase_H

#include "GoogleCase.h"

class T9SpellingCase;

QString SolveCase(const T9SpellingCase & Case);

class T9SpellingCase : public GoogleCase
{
public:
	T9SpellingCase() {}
	~T9SpellingCase() {}

	//! Re-implemented
	void ParseCase(QTextStream & inputStream);
	QString Solve() const;


public:
	// value
	mutable QString m_Phrase;

};

#endif // T9SpellingCase_H

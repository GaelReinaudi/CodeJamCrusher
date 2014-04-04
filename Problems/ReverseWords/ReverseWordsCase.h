#ifndef ReverseWordsCase_H
#define ReverseWordsCase_H

#include "GoogleCase.h"

class ReverseWordsCase;

QString SolveCase(const ReverseWordsCase & Case);

class ReverseWordsCase : public GoogleCase
{
public:
	ReverseWordsCase() {}
	~ReverseWordsCase() {}

	//! Re-implemented
	void ParseCase(QTextStream & inputStream);
	QString Solve() const;

public:
	QString Sentence;

};

#endif // ReverseWordsCase_H

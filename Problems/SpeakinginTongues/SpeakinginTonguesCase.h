#ifndef SpeakinginTonguesCase_H
#define SpeakinginTonguesCase_H

#include "GoogleCase.h"

class SpeakinginTonguesCase;

QString SolveCase(const SpeakinginTonguesCase & Case);

class SpeakinginTonguesCase : public GoogleCase
{
public:
	SpeakinginTonguesCase() {}
	~SpeakinginTonguesCase() {}

	//! Re-implemented
	void ParseCase(QTextStream & inputStream);
	QString Solve() const;


public:
	mutable QString m_Phrase;

};

#endif // SpeakinginTonguesCase_H

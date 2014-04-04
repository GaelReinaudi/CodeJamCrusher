#ifndef HallofMirrorsCase_H
#define HallofMirrorsCase_H

#include "GoogleCase.h"

class HallofMirrorsCase;

QString SolveCase(const HallofMirrorsCase & Case);

class HallofMirrorsCase : public GoogleCase
{
public:
	HallofMirrorsCase() {}
	~HallofMirrorsCase() {}

	//! Re-implemented
	void ParseCase(QTextStream & inputStream);
	QString Solve() const;


public:
	mutable int H;
	mutable int W;
	mutable int D;
	QPoint MyPos;
};

#endif // HallofMirrorsCase_H

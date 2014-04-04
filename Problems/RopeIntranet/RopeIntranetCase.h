#ifndef RopeIntranetCase_H
#define RopeIntranetCase_H

#include "GoogleCase.h"

class RopeIntranetCase;

QString SolveCase(const RopeIntranetCase & Case);

class RopeIntranetCase : public GoogleCase
{
public:
	RopeIntranetCase() {}
	~RopeIntranetCase() {}

	//! Re-implemented
	void ParseCase(QTextStream & inputStream);
	QString Solve() const;


public:
	int m_Ropes;
	mutable QHash<int,int> AB;

};

#endif // RopeIntranetCase_H

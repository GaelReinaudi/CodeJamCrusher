#ifndef PerfectHarmonyCase_H
#define PerfectHarmonyCase_H

#include "GoogleCase.h"

class PerfectHarmonyCase;

QString SolveCase(const PerfectHarmonyCase & Case);

class PerfectHarmonyCase : public GoogleCase
{
public:
	PerfectHarmonyCase() {}
	~PerfectHarmonyCase() {}

	//! Re-implemented
	void ParseCase(QTextStream & inputStream);
	QString Solve() const;

public:
	int R;
	int C;
	mutable QString tiles;
	mutable qint64 N, L, H;
	mutable qint64 m_Min;
	mutable QVector<qint64> Freqs;
};

#endif // PerfectHarmonyCase_H

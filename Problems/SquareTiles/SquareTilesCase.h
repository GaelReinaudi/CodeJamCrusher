#ifndef SquareTilesCase_H
#define SquareTilesCase_H

#include "GoogleCase.h"

class SquareTilesCase;

QString SolveCase(const SquareTilesCase & Case);

class SquareTilesCase : public GoogleCase
{
public:
	SquareTilesCase() {}
	~SquareTilesCase() {}

	//! Re-implemented
	void ParseCase(QTextStream & inputStream);
	QString Solve() const;
	bool ReplaceNextTiles() const;

public:
	int R;
	int C;
	mutable QString tiles;
	mutable int N;
	mutable QVector<qint64> S1;
	mutable QHash<int, QList<int> > m_SumList;
	mutable bool done;
};

#endif // SquareTilesCase_H

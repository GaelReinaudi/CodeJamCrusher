#ifndef DiamondInheritanceCase_H
#define DiamondInheritanceCase_H

#include "GoogleCase.h"
#include <QTextStream>

class DiamondInheritanceCase;

QString SolveCase(const DiamondInheritanceCase & Case);

class DiamondInheritanceCase : public GoogleCase
{
public:
	DiamondInheritanceCase();
	~DiamondInheritanceCase() {}

	//! Re-implemented
	void ParseCase(QTextStream & inputStream);
	QString Solve() const;

	mutable QString m_SolString;
	QTextStream &m_Out;

	bool MoveInheritance() const;


	mutable int N;
	mutable QMultiHash<int, int> m_InheritMap;
	mutable QVector<QSet<int>> m_Under;
	mutable bool m_Diamond;
// 	int R;
// 	int C;
// 	mutable QString tiles;
// 	mutable qint64 N, L, H;
// 	mutable qint64 m_Min;
// 	mutable QVector<qint64> Freqs;
};

#endif // DiamondInheritanceCase_H

#ifndef GOOGLECASE_H
#define GOOGLECASE_H

// #include <QObject>

class GoogleCase //: public QObject
{

public:
	GoogleCase(/*QObject* parent = 0*/);
	~GoogleCase();

	//! Parses the data specific to that case assuming that the inputStream is at the good position because every other input where >> in the good order.
	virtual void ParseCase(QTextStream & inputStream) = 0;

public:
	int m_CaseNumber;

	
};

#endif // GOOGLECASE_H

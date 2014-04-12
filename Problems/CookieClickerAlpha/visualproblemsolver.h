#ifndef VISUALPROBLEMSOLVER_H
#define VISUALPROBLEMSOLVER_H

#include <QtWidgets/QWidget>
#include "ui_visualproblemsolver.h"

class CookieClickerAlphaCase;

typedef QVector<CookieClickerAlphaCase> VectorCases;

QString SolveCase(const CookieClickerAlphaCase & theCase);
void AppendResult(CookieClickerAlphaCase & theCase, const QString & resultCase);

class CookieClickerAlpha : public QWidget
{
	Q_OBJECT

public:
	CookieClickerAlpha(QWidget *parent = 0, Qt::WindowFlags flags = 0);

	~CookieClickerAlpha();

protected:
	void dragEnterEvent(QDragEnterEvent* event) {event->accept();}
	void dropEvent(QDropEvent* event);
	//! Breaks down the drop of the sample from the web page into input and output sample and runs the solver over it. Returns the sample input.
	QString MakeSampleInput( QString strFromSampleDrop );
	//! Opens the file path dropped, and prepares the the output file. Returns the content of the file. Without argument, the output file is set to be SampleOut.txt.
	QString MakeFileInOut( QString pathInput = "");
	//! Builds the case's data from the input stream. Returns the vector of cases.
	VectorCases ParseInput(QTextStream & inputStream);
	//! Starts a multi-threaded computation on the cases
	void MultiThreadedCompute(VectorCases & allCases);
	//! computes sequentially to help debug on the sample input
	void SequencialCompute( VectorCases & allCases );

protected slots:
	void LoadSample();
	void LoadFile();
	void CompareBoxesOutput();
	void EventFinishedComputation();

protected:
	int m_NumberCase;

private:
	QElapsedTimer m_Timer;
	QFutureWatcher<void> m_watcher;
	bool m_ShowFileContents;

	QString m_FileInPath;
	QString m_SampleTableFromWebSite;

private:
	Ui::CookieClickerAlphaClass ui;
};

#endif // VISUALPROBLEMSOLVER_H

#ifndef VISUALPROBLEMSOLVER_H
#define VISUALPROBLEMSOLVER_H

#include <QtGui/QWidget>
#include "ui_visualproblemsolver.h"

class RopeIntranetCase;

typedef QVector<RopeIntranetCase> VectorCases;

QString SolveCase(const RopeIntranetCase & theCase);
void AppendResult(RopeIntranetCase & theCase, const QString & resultCase);

class RopeIntranet : public QWidget
{
	Q_OBJECT

public:
	RopeIntranet(QWidget *parent = 0, Qt::WFlags flags = 0);

	~RopeIntranet();

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
	QFutureWatcher<void> m_watcher;
	bool m_ShowFileContents;

	QString m_FileInPath;
	QString m_SampleTableFromWebSite;

private:
	Ui::RopeIntranetClass ui;
};

#endif // VISUALPROBLEMSOLVER_H

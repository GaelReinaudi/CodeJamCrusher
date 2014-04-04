#include "stdafx.h"
#include "visualproblemsolver.h"
#include "StoreCreditCase.h"

QFile m_FileIn;
QFile m_FileOut;

StoreCredit::StoreCredit(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
	, m_NumberCase(0)
	, m_ShowFileContents(true)
{
	ui.setupUi(this);
	// reload settings
	QSettings settings("CodeJam", "StoreCredit");
	m_FileInPath = settings.value("fileInPath", "").toString();
	m_SampleTableFromWebSite = settings.value("sampleTableFromWebSite", "").toString();

	if(m_FileInPath != "") {
		// re-load a previously loaded file
		LoadFile();
	}
	else if(m_SampleTableFromWebSite != "") {
		LoadSample();
	}

	connect(ui.pUseSampleButton, SIGNAL(clicked(bool)), this, SLOT(LoadSample()));
	connect(&m_watcher, SIGNAL(progressValueChanged(int)), ui.pProgressBar, SLOT(setValue(int)));
	connect(&m_watcher, SIGNAL(finished()), this, SLOT(EventFinishedComputation()));
	ui.pFailedButton->hide();

	move(0, 50);
	restoreGeometry(settings.value("geometry").toByteArray());
}

StoreCredit::~StoreCredit()
{
	m_FileIn.close();
	m_FileOut.close();

	QSettings settings("CodeJam", "StoreCredit");
	settings.clear();
	settings.setValue("fileInPath", m_FileInPath);
	settings.setValue("sampleTableFromWebSite", m_SampleTableFromWebSite);
	settings.setValue("geometry", saveGeometry());
}

void StoreCredit::MultiThreadedCompute(VectorCases & allCases)
{
	// solving and making the output
	QFuture<void> future = QtConcurrent::mappedReduced(allCases, SolveCase, AppendResult, QtConcurrent::OrderedReduce | QtConcurrent::SequentialReduce);
	m_watcher.setFuture(future);
}

void StoreCredit::dropEvent( QDropEvent* event )
{
	const QMimeData* pMime = event->mimeData();
	if(pMime->hasUrls()) {
		m_FileInPath = pMime->urls().first().toLocalFile();
		LoadFile();
	}
	else if(pMime->hasText()) {
		m_SampleTableFromWebSite = pMime->text();
		LoadSample();
	}
}

QString StoreCredit::MakeSampleInput( QString strFromSampleDrop )
{
	strFromSampleDrop = strFromSampleDrop.trimmed();
	if(strFromSampleDrop.startsWith("Input"))
		strFromSampleDrop = strFromSampleDrop.remove("Input").trimmed();
	if(strFromSampleDrop.startsWith("Output"))
		strFromSampleDrop = strFromSampleDrop.remove("Output").trimmed();

	int indOut = strFromSampleDrop.lastIndexOf("Case #1");
	QString sampleIn = strFromSampleDrop.left(indOut).trimmed();
	QString sampleOut;

	if(indOut != -1)
		sampleOut = strFromSampleDrop.remove(0, indOut).trimmed();

	ui.pEditSampleInput->setPlainText(sampleIn);
	ui.pEditSampleOutput->setPlainText(sampleOut);
	return sampleIn;
}

VectorCases StoreCredit::ParseInput(QTextStream & inputStream)
{
	inputStream >> m_NumberCase;
	ui.pProgressBar->setRange(1, m_NumberCase);
	VectorCases allCases(m_NumberCase);
	inputStream.readLine();

	// reading each case
	for(int iCase = 1; iCase <= m_NumberCase; iCase++) {
		// sets the number of the case for latter filling the output file
		allCases[iCase-1].m_CaseNumber = iCase;
		// parse the data specific to that case
		allCases[iCase-1].ParseCase(inputStream);
	}
	return allCases;
}

QString StoreCredit::MakeFileInOut( QString pathInput  /*= ""*/)
{
	QString content;
	m_FileIn.close();
	if(pathInput.isEmpty())
		m_FileOut.setFileName("SampleOut.txt");
	else {
		m_FileIn.setFileName(pathInput);
		if(m_FileIn.fileName().contains("small"))
			m_FileOut.setFileName("../Outputs/VisualProblem-Small.txt");
		else if(m_FileIn.fileName().contains("large"))
			m_FileOut.setFileName("../Outputs/VisualProblem-Large.txt");
		else
			m_FileOut.setFileName("../Outputs/VisualProblem.txt");

		if(m_ShowFileContents) {
			if(m_FileIn.open(QIODevice::ReadOnly | QIODevice::Text))
				content = QTextStream(&m_FileIn).readAll();
			else
				content = QString("Cannot display Input: %1").arg(m_FileOut.fileName());
		}

		m_FileIn.close();
		if(!m_FileIn.open(QIODevice::ReadOnly | QIODevice::Text))
			return QString("Cannot open Input: %1\r\n%2").arg(m_FileIn.error()).arg(m_FileIn.fileName());
	}

	m_FileOut.close();
	if(!m_FileOut.open(QFile::WriteOnly | QFile::Truncate | QIODevice::Text))
		return QString("Cannot open Output: %1\r\n%2").arg(m_FileOut.error()).arg(m_FileOut.fileName());

	return content;
}

void StoreCredit::LoadSample()
{
	// if we load the sample, we ignore every memory of a file
	m_FileInPath.clear();
	// we also call the make file but with no argument it will write to SampleOut.txt
	MakeFileInOut();

	QString theInput = MakeSampleInput(m_SampleTableFromWebSite);
	QTextStream inputStream(&theInput);
	VectorCases allCases = ParseInput(inputStream);

	ui.pEditDrop->setPlainText(m_SampleTableFromWebSite);
	ui.pGroupSamplOut->setVisible(true);

	MultiThreadedCompute(allCases);
}

void StoreCredit::LoadFile()
{
	QString content = MakeFileInOut(m_FileInPath);

	QTextStream inputStream(&m_FileIn);
	// makes the case's data
	VectorCases allCases = ParseInput(inputStream);

	ui.pEditDrop->setPlainText(m_FileInPath);
	ui.pEditSampleInput->setPlainText(content);
	ui.pEditSampleOutput->clear();
	ui.pGroupSamplOut->setVisible(false);

	MultiThreadedCompute(allCases);
}

void StoreCredit::CompareBoxesOutput()
{
	bool passes = false;
	QString strIn = ui.pEditSampleOutput->toPlainText().trimmed();
	QString strOut = ui.pEditComputedOutput->toPlainText().trimmed();
	if(!ui.pEditSampleOutput->toPlainText().isEmpty())
		passes = strIn == strOut;
	ui.pPassedCheckBox->setChecked(passes);
}

void StoreCredit::EventFinishedComputation()
{
	m_FileIn.close();
	m_FileOut.close();
	QString content;
	if(m_ShowFileContents) {
		if(m_FileOut.open(QIODevice::ReadOnly | QIODevice::Text))
			content = QTextStream(&m_FileOut).readAll();
		else
			content = QString("Cannot display Output: %1").arg(m_FileOut.fileName());
	}
	m_FileIn.close();
	m_FileOut.close();
	ui.pEditComputedOutput->setPlainText(content);
	bool compFailed = ui.pEditComputedOutput->find("failed");
	if(compFailed)
		ui.pFailedButton->show();
	else
		ui.pFailedButton->hide();

	CompareBoxesOutput();
}

void AppendResult( StoreCreditCase & theCase, const QString & resultCase )
{
	QTextStream out(&m_FileOut);
	out << resultCase << endl;
}
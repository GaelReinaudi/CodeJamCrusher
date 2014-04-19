#include <QtWidgets>
#include "problemzipper.h"

ProblemZipper::ProblemZipper(QWidget *parent)
	: QWizard(parent)
{
	addPage(new ClassInfoPage);
	setWizardStyle(QWizard::ModernStyle);

	setWindowTitle(tr("Problem Zipper"));

	m_FolderCopyFilterOut << "Debug" << "Release" << "Release with Debug" << "_UpgradeReport_Files" << "Backup" << "ipch";// << "GeneratedFiles";
	m_ExtensionCopyFilterOut << "ncb" << "suo" << "sdf" << "htm" << "XML" << "gitignore" << "user" << "filters";// << "sln";

	// sets some variable for a specific porject to copy
	m_ToReplaceWithDeviceName = "StoreCredit";
	m_ToReplaceWithProblemName = "VisualProblemSolver";
	m_ToReplaceWithProjectName = "VisualProblemSolver";

	// try to find the directory of the project to copy
	m_FromDir = QDir("../");
	m_ToDir = QDir("../Problems");

	if(!m_FromDir.cd(m_ToReplaceWithProjectName))
		qWarning() << "couldn't find the source project: " << m_ToReplaceWithProjectName;

	if(!m_FromDir.exists() || !m_ToDir.exists()) {
		qWarning() << "couldn't find the directories. " << m_FromDir << "or" << m_ToDir;
	}
}

ProblemZipper::~ProblemZipper()
{

}

void ProblemZipper::accept()
{
	MakeListOfFilesToUse(m_FromDir);
	QString pathToProjectFolder = MakeProjectDirectory();
	if(!pathToProjectFolder.isEmpty()) {
		QDesktopServices::openUrl(QUrl("file:///" + pathToProjectFolder));
		ZipFolder(pathToProjectFolder);
	}
	QDialog::accept();
}

void ProblemZipper::MakeListOfFilesToUse(QDir fromDir)
{
	QStringList qsl = fromDir.entryList(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);

	foreach (QString file, qsl) {
		QFileInfo finfo(QString("%1/%2").arg(fromDir.path()).arg(file));
		// if it is a link, we don't use it
		if(finfo.isSymLink())
			continue;
		// if it is a QDir, we iterate inside it
		if(finfo.isDir()) {
			QString dirname = finfo.fileName();
			// but we filter out some folders
			if(m_FolderCopyFilterOut.contains(dirname))
				continue;
			QDir sd(finfo.filePath());
			MakeListOfFilesToUse(sd);
		} 
		else {
			// we filter out some files extensions
			if(m_ExtensionCopyFilterOut.contains(finfo.suffix()))
				continue;
			// takes the relative path since we stored the m_FromDir before starting this process
			m_FilesToCopy << QDir::toNativeSeparators(m_FromDir.relativeFilePath(finfo.absoluteFilePath()));
		}
	}
}

QString ProblemZipper::MakeProjectDirectory()
{
	QDir inDir = m_ToDir;
	QString className = field("problemName").toString().simplified().replace(" ", "");
	QString problemName = className;
	QString problemNameDir = problemName;
	problemNameDir = QDir::cleanPath(problemNameDir);
	inDir.mkdir(problemNameDir);
	if(!inDir.cd(problemNameDir))
		return "";

	foreach(QString relFilePathOriginal, m_FilesToCopy) {
		// opens the file from relatively to the m_FromDir
		QFile file(m_FromDir.filePath(relFilePathOriginal));
		if(!file.open(QFile::ReadOnly | QFile::Text)) {
			QMessageBox::warning(0, QObject::tr("Problem Zipper"), QObject::tr("Cannot read file %1:\n%2").arg(file.fileName()).arg(file.errorString()));
			continue;
		}
		// reads the content
		QByteArray content;
		content = file.readAll();
		// replaces strings
		content.replace(m_ToReplaceWithProblemName, problemNameDir.toUtf8());
		content.replace(m_ToReplaceWithDeviceName, className.toUtf8());
		content.replace(m_ToReplaceWithProjectName, className.toUtf8());
		// for the vcproj, we change the guid
		if(QFileInfo(file).suffix() == "vcproj") {
			int posGUID = content.indexOf("ProjectGUID");
			if(posGUID >= 0) {
				posGUID = content.indexOf("{", posGUID);
				content.replace(posGUID, 38, QUuid::createUuid().toString().toUtf8());
			}
		}

		// open the new file

		QString newFilePath = inDir.filePath(QDir::cleanPath(relFilePathOriginal));
		newFilePath.replace(m_ToReplaceWithProblemName,  problemName);
		newFilePath.replace(m_ToReplaceWithDeviceName,  className);
		newFilePath.replace(m_ToReplaceWithProjectName,  className);
		QFile newfile(newFilePath);
		// create the directory if needed
		QString relativeFilePathInDir = inDir.relativeFilePath(QFileInfo(newfile).absolutePath());
		inDir.mkpath(relativeFilePathInDir);

		if(!newfile.open(QFile::WriteOnly | QFile::Text)) {
			QMessageBox::warning(0, QObject::tr("Problem Zipper"), QObject::tr("Cannot write file %1:\n%2").arg(newfile.fileName()).arg(newfile.errorString()));
			continue;
		}
		newfile.write(content);
	}
	return QDir::toNativeSeparators(inDir.absolutePath());
}

void ProblemZipper::ZipFolder( QString pathToProjectFolder )
{
	QString FolderPath = QDir().relativeFilePath(pathToProjectFolder);
	QString FolderName = QDir(FolderPath).dirName();
	QString program = "7z";
	QStringList arguments;
	arguments << "a" << "-aoa" << "-tzip" << QString("../Outputs/%1.zip").arg(FolderName) 
		<< FolderPath + "/*.ui"
		<< FolderPath + "/*.h"
		<< FolderPath + "/*.cpp"
		<< FolderPath + "/*.txt"
		<< FolderPath + "/*.vcproj"
		<< FolderPath + "/*.vcxproj"
		<< FolderPath + "/*.pro"
		<< FolderPath + "/*.pri"
		;


	QProcess *myProcess = new QProcess(this);
	myProcess->start(program, arguments);
	myProcess->waitForFinished(5000);
}

ClassInfoPage::ClassInfoPage(QWidget *parent)
	: QWizardPage(parent)
{
	setTitle(tr("Problem Zipper"));
	setSubTitle(tr("Specify the name of the problem."
		"it will zip the VisualProblemSolver after renaming its content and classes."));

	problemNameLabel = new QLabel(tr("&Problem name:"));
	problemNameLineEdit = new QLineEdit;
	problemNameLabel->setBuddy(problemNameLineEdit);
	
	groupBox = new QGroupBox(tr("C&onstructor"));


	registerField("problemName*", problemNameLineEdit);

	QVBoxLayout *groupBoxLayout = new QVBoxLayout;
	groupBox->setLayout(groupBoxLayout);

	QGridLayout *layout = new QGridLayout;
	layout->addWidget(problemNameLabel, 0, 0);
	layout->addWidget(problemNameLineEdit, 0, 1);
	setLayout(layout);

}

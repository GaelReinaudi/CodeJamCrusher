#ifndef PROBLEMZIPPER_H
#define PROBLEMZIPPER_H

#include <QWizard>
#include <QDir>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QRadioButton;
QT_END_NAMESPACE

class ProblemZipper : public QWizard
{
	Q_OBJECT

public:
	ProblemZipper(QWidget *parent = 0);
	~ProblemZipper();

	void accept();
	//! makes the list of files that we want to use to make the new project
	void MakeListOfFilesToUse(QDir fromDir);
	//! makes the new project sub-directory in the provided directory. Returns the absolute path of the folder, or "" if couldn't make it.
	QString MakeProjectDirectory();
	void ZipFolder( QString pathToProjectFolder );
private:
private:
	//! list of files to copy to the destination directory. Populated by MakeListOfFilesToUse()
	QStringList m_FilesToCopy;
	//! Names of folder that we discard
	QStringList m_FolderCopyFilterOut;
	//! extension of files not to be used
	QStringList m_ExtensionCopyFilterOut;
	//! directory from which we take the project to copy
	QDir m_FromDir;
	//! directory into which we put the new project sub-directory
	QDir m_ToDir;
	QString m_ToReplaceWithDeviceName;
	QString m_ToReplaceWithProblemName;
	QString m_ToReplaceWithProjectName;

};

class ClassInfoPage : public QWizardPage
{
	Q_OBJECT

public:
	ClassInfoPage(QWidget *parent = 0);

private:
	QLabel *problemNameLabel;
	QLineEdit *problemNameLineEdit;
	QLineEdit *baseClassLineEdit;
	QCheckBox *qobjectMacroCheckBox;
	QGroupBox *groupBox;
	QRadioButton *qobjectCtorRadioButton;
	QRadioButton *qwidgetCtorRadioButton;
	QRadioButton *defaultCtorRadioButton;
	QCheckBox *copyCtorCheckBox;
};

#endif // PROBLEMZIPPER_H

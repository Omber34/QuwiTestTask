#pragma once
#include <QtWidgets/qdialog.h>
#include "ui_ProjectEditFormUI.h"
#include "ProjectInfo.h"

class ProjectEditDialog :
	public QDialog
{
	Q_OBJECT
public:
	ProjectEditDialog(QWidget * parent = nullptr);
	
	void setData(ProjectInfo const& project);
	QString getName() const;
	bool getActive() const;
	~ProjectEditDialog();


signals:
	void okClicked();
signals:
	void cancelClicked();
	
private:
	Ui::ProjectEditDialog::Ui_ProjectEditDialog  ui;
};


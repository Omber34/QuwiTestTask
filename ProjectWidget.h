#pragma once
#include <qwidget.h>
#include "ui_ProjectWidgetUI.h"
#include "ProjectInfo.h"

class ProjectWidget 
	: public QWidget
{
	Q_OBJECT

public:
	ProjectWidget(QWidget* parent = nullptr);

	void setData(ProjectInfo const& project);
	QString getName() const;
	int getActivity() const;

private:
	Ui::ProjectWidget ui;
};


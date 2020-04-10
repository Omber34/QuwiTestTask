#include "ProjectWidget.h"

ProjectWidget::ProjectWidget(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void ProjectWidget::setData(ProjectInfo const& project)
{
	ui.nameLineEdit->setText(project.getName());
	ui.activityComboBox->setCurrentIndex(project.getActive());
}

QString ProjectWidget::getName() const
{
	return ui.nameLineEdit->text();
}

int ProjectWidget::getActivity() const
{
	return ui.activityComboBox->currentIndex();
}


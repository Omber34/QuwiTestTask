#include "ProjectEditDialog.h"

ProjectEditDialog::ProjectEditDialog(QWidget * parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.buttonBox, &QDialogButtonBox::accepted, this, &ProjectEditDialog::okClicked);
}

void ProjectEditDialog::setData(ProjectInfo const& project)
{
	ui.activeCheckBox->setChecked(project.getActive());
	QString name = project.getName();
	ui.nameLineEdit->setText(name);
	QStringList users;
	for (auto user : project.getUserList())
	{
		users << user.getName();
	}
	ui.usersLabel->setText("Users: " + users.join(" "));
}

QString ProjectEditDialog::getName() const
{
	return ui.nameLineEdit->text();
}

bool ProjectEditDialog::getActive() const
{
	return ui.activeCheckBox->isChecked();
}

ProjectEditDialog::~ProjectEditDialog()
{
}

#include "LoginForm.h"

LoginForm::LoginForm(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.okButton, &QPushButton::clicked, this, &LoginForm::okClick);
	connect(ui.cancelButton, &QPushButton::clicked, this, &LoginForm::cancelClick);
}

QString LoginForm::getEmail() const
{
	return ui.emailLineEdit->text();
}

QString LoginForm::getPassword() const
{
	return ui.passLineEdit->text();
}

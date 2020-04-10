#pragma once
#include <qdialog.h>
#include "ui_LoginFormUI.h"

class LoginForm : public QDialog
{
	Q_OBJECT
public:

	LoginForm(QWidget* parent = nullptr);

	QString getEmail() const;
	QString getPassword() const;

signals:
	void okClick();
signals:
	void cancelClick();

private:
	Ui::Dialog ui;

};


#include "Loginer.h"
#include <QtWidgets/qmessagebox.h>

Loginer::Loginer(QWidget* widgetParent, QObject* objectParent )
	: loginForm(widgetParent),
	auth(objectParent)
{
	connect(&auth, &Authentificator::authReady, this, &Loginer::slotAuthReady);
	connect(&loginForm, &LoginForm::okClick, this, &Loginer::doAuth);
	connect(&loginForm, &LoginForm::cancelClick, &loginForm, &LoginForm::reject);
	connect(this, &Loginer::successAuth, &loginForm, &LoginForm::accept);
}

void Loginer::login()
{
	loginForm.exec();
}

QString Loginer::getAccessToken() const
{
	return auth.getToken();
}

Loginer::~Loginer()
{
}

void Loginer::doAuth()
{
	auth.auth(loginForm.getEmail(), loginForm.getPassword());
}

void Loginer::slotAuthReady()
{
	if (auth.hasToken())
	{
		emit successAuth();
	}
	else
	{
		QMessageBox::critical(&loginForm, "Failure", auth.getErrors());
	}
}

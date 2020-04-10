#pragma once
#include "LoginForm.h"
#include "Authentificator.h"

class Loginer 
	: public QObject
{
	Q_OBJECT
public:
	Loginer(QWidget* widgetParent = nullptr, QObject* objectParent = nullptr);

	void login();

	QString getAccessToken() const;

	~Loginer();

signals:
	void successAuth();
signals:
	void failAuth();

private:

	LoginForm loginForm;
	Authentificator auth;

	void doAuth();
	void slotAuthReady();
};


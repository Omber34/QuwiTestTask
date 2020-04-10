#include "MyApplication.h"
#include "LoginForm.h"
#include "MainWindow.h"
#include "DebugWindow.h"
#include "ProjectLoader.h"

#include "qjsondocument.h"
#include "qjsonvalue.h"
#include "qjsonobject.h"


MyApplication::MyApplication(QObject* parent)
	: QObject(parent),
	loginer(&_mainWindow, this),
	projectModel(this)
{
	connect(&loginer, &Loginer::successAuth, this, &MyApplication::slotAuthSuccess);
	_mainWindow.setProjectListModel(&projectModel);
}

void MyApplication::slotAuthSuccess()
{
	projectModel.setToken(loginer.getAccessToken());
	projectModel.reloadProjectList();
}

void MyApplication::start()
{
	login();
}

MyApplication::~MyApplication()
{
}

void MyApplication::login()
{
	loginer.login();
	mainWindow();
}

void MyApplication::mainWindow()
{
	_mainWindow.show();
}


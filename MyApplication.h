#pragma once
#include "Authentificator.h"
#include "MainWindow.h"
#include "Loginer.h"
#include "ProjectLoader.h"
#include "ProjectListModel.h"

class MyApplication 
	: public QObject
{
    Q_OBJECT

public:
    MyApplication(QObject *parent = nullptr);

	void start();

    ~MyApplication();

private:

	MainWindow _mainWindow;
	Loginer loginer;
	ProjectListModel projectModel;

	void slotAuthSuccess();

	void login();
	void mainWindow();


};

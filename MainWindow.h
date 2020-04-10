#pragma once
#include <qmainwindow.h>
#include "ui_MainWindowUI.h"
#include <qlistview.h>
class MainWindow :
	public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget* parent = nullptr);
	void setProjectListModel(QAbstractItemModel* model);
	~MainWindow();
private:
	Ui::MainWindow ui;
};


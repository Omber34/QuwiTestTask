#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_MainWindowUI.h"
#include <QtWidgets/qlistview.h>
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


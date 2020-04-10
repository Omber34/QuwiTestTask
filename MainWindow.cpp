#include "MainWindow.h"

#include "ProjectItemDelegate.h"

MainWindow::MainWindow(QWidget * parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.projectListView->setItemDelegate(new ProjectItemDelegate());
}

void MainWindow::setProjectListModel(QAbstractItemModel* model)
{
	ui.projectListView->setModel(model);
}

MainWindow::~MainWindow()
{
}

#include "DebugWindow.h"

DebugWindow::DebugWindow(QWidget * parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void DebugWindow::setText(QString const& text)
{
	ui.text->setText(text);
}

DebugWindow::~DebugWindow()
{
}

#pragma once
#include <qmainwindow.h>
#include "ui_DebugWindowUI.h"

class DebugWindow :
	public QMainWindow
{
	Q_OBJECT
public:
	DebugWindow(QWidget* parent = nullptr);
	void setText(QString const& text);
	~DebugWindow();
private:
	Ui::DebugWindow ui;
};


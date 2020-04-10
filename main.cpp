#include "MyApplication.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	MyApplication myApp;
	myApp.start();
	return a.exec();
}

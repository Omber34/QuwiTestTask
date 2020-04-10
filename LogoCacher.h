#pragma once
#include <qpixmap.h>
#include <qhash.h>
#include <mutex>

class LogoCacher
{
private:
	static LogoCacher* instance;
	QHash<QString, QPixmap> cache;
	std::mutex mutex;
	LogoCacher() = default;
public:
	static bool check(QString const& logoUrl);
	static QPixmap get(QString const& logoUrl);
	static void download(QString const& logoUrl);

};


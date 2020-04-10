#include "LogoCacher.h"
#include "NetworkManager.h"
#include <qimagereader.h>

LogoCacher* LogoCacher::instance = new LogoCacher();

bool LogoCacher::check(QString const& logoUrl)
{
	std::lock_guard<std::mutex> lock(instance->mutex);
	return instance->cache.find(logoUrl) != instance->cache.end();
}

QPixmap LogoCacher::get(QString const& logoUrl)
{
	std::lock_guard<std::mutex> lock(instance->mutex);
	return instance->cache.value(logoUrl);
}

void LogoCacher::download(QString const& logoUrl)
{
	if (logoUrl.isEmpty())
	{
		return;
	}
	if (check(logoUrl))
	{
		return;
	}
	QNetworkRequest request;
	request.setUrl(QUrl(logoUrl));

	QNetworkReply* reply = NetworkManager::getManager().get(request);

	QObject::connect( reply, &QNetworkReply::readyRead,
		[reply, logoUrl]()
		{
			if (reply->error())
				return;
			QImageReader imageReader(reply);
			imageReader.setAutoDetectImageFormat(true);
			QImage pic = imageReader.read();

			std::lock_guard<std::mutex> lock(instance->mutex);
			instance->cache.insert(logoUrl, QPixmap::fromImage(pic));

			reply->deleteLater();
		});
}

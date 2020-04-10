#include "ProjectLoader.h"
#include <qjsondocument.h>
#include <qjsonarray.h>
#include "NetworkManager.h"

ProjectLoader::ProjectLoader(QObject * parent)
	: QObject(parent)
{
}

void ProjectLoader::setAuthToken(QString const& token)
{
	authToken = token;
}

void ProjectLoader::loadProjects()
{
	QNetworkRequest request;
	request.setUrl(QUrl("https://api.quwi.com/v2/projects-manage/index"));
	request.setRawHeader("Client-Timezone-Offset", "60");
	request.setRawHeader("Client-Device", "desktop");
	request.setRawHeader("Authorization", ("Bearer " + authToken).toUtf8());
	QNetworkReply* reply = NetworkManager::getManager().get(request);

	connect(reply, &QNetworkReply::finished, 
		[reply, this]()
		{
			QJsonDocument response = QJsonDocument::fromJson(reply->readAll());
			serverResponse = response.object();

			reply->deleteLater();
			emit projectListReady();
		});
}

QJsonObject ProjectLoader::getServerResponse()
{
	return serverResponse;
}

ProjectLoader::~ProjectLoader()
{
}

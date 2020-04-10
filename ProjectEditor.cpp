#include "ProjectEditor.h"
#include "NetworkManager.h"
#include <qjsondocument.h>

ProjectEditor::ProjectEditor(QObject* parent)
	: QObject(parent)
{
}

void ProjectEditor::changeProject(ProjectInfo const& project, QJsonObject const& difference, std::shared_ptr<Command>  onSuccess)
{
	QNetworkRequest request;
	request.setUrl(QUrl("https://api.quwi.com/v2/projects-manage/update?id=" + QString::number(project.getProjectID())));
	request.setRawHeader("Content-Type", "application/json");
	request.setRawHeader("Authorization", ("Bearer " + authToken).toUtf8());
	QJsonDocument convertBody;
	convertBody.setObject(difference);
	QNetworkReply* reply = NetworkManager::getManager().post(request, convertBody.toJson());

	QObject::connect(reply, &QNetworkReply::readyRead,
		[reply, onSuccess]()
		{
			QString response = reply->readAll();
			if (onSuccess)
				onSuccess->execute();
			reply->deleteLater();
		});
}

void ProjectEditor::setAuthToken(QString const& token)
{
	authToken = token;
}

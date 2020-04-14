#include "Authentificator.h"
#include <qjsondocument.h>
#include "NetworkManager.h"

Authentificator::Authentificator(QObject* parent)
	: QObject(parent)
{
}

void Authentificator::auth(QString const& email, QString const& pass)
{
	QNetworkRequest request;
	request.setUrl(QUrl("https://api.quwi.com/v2/auth/login"));
	request.setRawHeader("Content-Type", "application/json");
	request.setRawHeader("Client-Timezone-Offset", "60");
	request.setRawHeader("Client-Device", "desktop");
	QJsonObject req;
	req.insert("email", email);
	req.insert("password", pass);
	QJsonDocument requestBody;
	requestBody.setObject(req);
	QNetworkReply* reply = NetworkManager::getManager().post(request, requestBody.toJson());

	connect(reply, &QNetworkReply::finished, 
		[reply, this]()
		{
			QJsonDocument response = QJsonDocument::fromJson(reply->readAll());
			serverResponse = response.object();
			QString resp = response.toJson();
			reply->deleteLater();
			emit authReady();
		}
	);
}

QString Authentificator::getToken() const
{
	return (*serverResponse.find("token")).toString();
}

bool Authentificator::hasToken() const
{
	return serverResponse.contains("token");
}

QString Authentificator::getErrors() const
{
	QString result = serverResponse.value("first_errors").toObject().value("email").toString();
	if (result.isEmpty())
		result = serverResponse.value("first_errors").toObject().value("password").toString();
	return result;
}

QJsonObject Authentificator::getServerResponse() const
{
	return serverResponse;
}

Authentificator::~Authentificator()
{
}

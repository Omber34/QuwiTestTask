#pragma once
#include <qnetworkreply.h>
#include <qjsonobject.h>
class Authentificator : public QObject
{
	Q_OBJECT

public:
	Authentificator(QObject* parent = nullptr);
	void auth(QString const& email, QString const& pass);
	QString getToken() const;
	bool hasToken() const;
	QString getErrors() const;
	QJsonObject getServerResponse() const;
	~Authentificator();

signals:
	void authReady();

private:
	QJsonObject serverResponse;
};


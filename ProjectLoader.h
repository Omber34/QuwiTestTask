#pragma once
#include <qobject.h>
#include <qjsonobject.h>

class ProjectLoader
	: public QObject
{
	Q_OBJECT

public:
	ProjectLoader(QObject* parent = nullptr);
	void setAuthToken(QString const& token);
	void loadProjects();
	QJsonObject getServerResponse();
	~ProjectLoader();

signals:
	void projectListReady();

private:
	QJsonObject serverResponse;
	QString authToken;
};


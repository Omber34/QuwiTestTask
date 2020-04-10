#pragma once
#include "ProjectInfo.h"
#include "Command.h"
#include <memory>

class ProjectEditor
	: public QObject
{

public:
	ProjectEditor(QObject * parent = nullptr);

	void changeProject(ProjectInfo const& project, QJsonObject const& difference, std::shared_ptr<Command> onSuccess);
	void setAuthToken(QString const& token);

private:
	QString authToken;
};


#pragma once
#include "UserInfo.h"
#include <qjsonobject.h>
#include <qmetatype.h>
#include <qpixmap.h>

class ProjectInfo 
{
public:

	ProjectInfo();
	ProjectInfo(QJsonObject const& json);
	ProjectInfo(ProjectInfo const& other);

	QString getName() const;
	int getProjectID() const;
	QString getLogoUrl() const;
	QString getTimeWeek() const;
	QString getTimeMonth() const;
	QString getTimeAll() const;
	QString getActiveString() const;
	int getActive() const;

	QList<UserInfo> getUserList() const;

	QPixmap getLogo() const;
	
	bool isValid() const;
	bool haveLogo() const;
private:

	QJsonObject jsonProject;
};

Q_DECLARE_METATYPE(ProjectInfo);
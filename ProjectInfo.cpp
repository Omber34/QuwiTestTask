#include "ProjectInfo.h"
#include "NetworkManager.h"
#include <qnetworkreply.h>
#include <qimagereader.h>
#include "LogoCacher.h"


ProjectInfo::ProjectInfo(ProjectInfo const& other)
	: jsonProject(other.jsonProject)
{
}

ProjectInfo::ProjectInfo()
{
}

ProjectInfo::ProjectInfo(QJsonObject const& json)
	: jsonProject(json)
{
	
}

QString ProjectInfo::getName() const
{
	return jsonProject.value("name").toString();
}

int ProjectInfo::getProjectID() const
{
	return jsonProject.value("id").toInt();;
}

QString ProjectInfo::getLogoUrl() const
{
	return jsonProject.value("logo_url").toString();
}

QString ProjectInfo::getTimeWeek() const
{
	return QString::number(jsonProject.value("spent_time_week").toInt());
}

QString ProjectInfo::getTimeMonth() const
{
	return QString::number(jsonProject.value("spent_time_month").toInt());
}

QString ProjectInfo::getTimeAll() const
{
	return QString::number(jsonProject.value("spent_time_all").toInt());
}

QString ProjectInfo::getActiveString() const
{
	if (jsonProject.value("is_active").toInt())
		return "Active";
	else
		return "Inactive";
}

int ProjectInfo::getActive() const
{
	return jsonProject.value("is_active").toInt();
}

QPixmap ProjectInfo::getLogo() const
{
	return LogoCacher::get(getLogoUrl());
}

bool ProjectInfo::isValid() const
{
	return !jsonProject.empty();
}

bool ProjectInfo::haveLogo() const
{
	return LogoCacher::check(getLogoUrl());
}

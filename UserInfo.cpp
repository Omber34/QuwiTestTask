#include "UserInfo.h"

UserInfo::UserInfo()
{
}

UserInfo::UserInfo(UserInfo const & other)
	: userJson(other.userJson)
{
}

UserInfo::UserInfo(QJsonObject const & json)
	: userJson(json)
{
}

QString UserInfo::getName() const
{
	return userJson.value("name").toString();
}

bool UserInfo::isValid() const
{
	return !userJson.isEmpty();
}

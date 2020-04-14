#pragma once
#include <qjsonobject.h>

class UserInfo
{
public:
	UserInfo();
	UserInfo(UserInfo const& other);
	UserInfo(QJsonObject const& json);

	QString getName() const;

	bool isValid() const;

private:
	QJsonObject userJson;
};
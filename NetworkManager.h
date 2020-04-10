#pragma once
#include <qnetworkaccessmanager.h>
#include <qnetworkreply.h>

class NetworkManager
{
	static QNetworkAccessManager manager;

	NetworkManager() = default;
public: 
	static QNetworkAccessManager& getManager();
};


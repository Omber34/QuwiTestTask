#pragma once
#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtNetwork/qnetworkreply.h>

class NetworkManager
{
	static QNetworkAccessManager manager;

	NetworkManager() = default;
public: 
	static QNetworkAccessManager& getManager();
};


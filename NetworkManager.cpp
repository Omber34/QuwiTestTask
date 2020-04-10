#include "NetworkManager.h"

QNetworkAccessManager NetworkManager::manager;

QNetworkAccessManager& NetworkManager::getManager()
{
	return manager;
}

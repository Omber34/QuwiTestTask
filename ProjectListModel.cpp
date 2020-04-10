#include "ProjectListModel.h"
#include <qjsondocument.h>
#include <qjsonarray.h>
#include "LogoCacher.h"

ProjectListModel::ProjectListModel(QObject* parent)
	: QAbstractListModel(parent), 
	projectLoader(this),
	projectEditor(this)
{
	connect(&projectLoader, &ProjectLoader::projectListReady, this, &ProjectListModel::projectsLoadedSlot);
}

int ProjectListModel::rowCount(const QModelIndex& parent) const
{
	return projectList.size();
}

QVariant ProjectListModel::data(const QModelIndex& index, int role) const
{
	if (!index.isValid())
		return QVariant();

	if (index.row() >= projectList.size())
		return QVariant();

	if (role == Qt::DisplayRole)
		return QVariant::fromValue(projectList.at(index.row()));
	else
		return QVariant();
}

QVariant ProjectListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	return QVariant();
}

Qt::ItemFlags ProjectListModel::flags(const QModelIndex& index) const
{
	if (!index.isValid())
		return Qt::ItemIsEnabled;

	return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool ProjectListModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	if (index.isValid() && role == Qt::EditRole) {
		QJsonObject difference = value.value<QJsonObject>();
		auto func = [this]() {
			reloadProjectList();
		};
		std::shared_ptr<Command> onSuccess (new TemplateCommand<decltype(func)>(func));
		projectEditor.changeProject(projectList.at(index.row()), difference, onSuccess);
		return true;
	}
	return false;
}

void ProjectListModel::setToken(QString const& token)
{
	authToken = token;
	projectLoader.setAuthToken(token);
	projectEditor.setAuthToken(token);
}

void ProjectListModel::reloadProjectList()
{
	projectLoader.loadProjects();
}

void ProjectListModel::projectsLoadedSlot()
{
	projectList.clear();

	QJsonArray projectListJson = projectLoader.getServerResponse().value("projects").toArray();
	beginResetModel();
	for (QJsonValueRef projectJson : projectListJson)
	{
		projectList.push_back(ProjectInfo(projectJson.toObject()));
		LogoCacher::download(projectList.back().getLogoUrl());
	}
	endResetModel();
}

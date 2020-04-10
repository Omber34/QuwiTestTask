#pragma once
#include <qabstractitemmodel.h>
#include "ProjectLoader.h"
#include "ProjectInfo.h"
#include "ProjectEditor.h"

class ProjectListModel : public QAbstractListModel
{
	Q_OBJECT

public:
	ProjectListModel(QObject* parent = nullptr);		

	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role) const override;
	QVariant headerData(int section, Qt::Orientation orientation,
		int role = Qt::DisplayRole) const override;

	Qt::ItemFlags flags(const QModelIndex& index) const override;
	bool setData(const QModelIndex& index, const QVariant& value,
		int role = Qt::EditRole) override;

	void setToken(QString const& token);
	void reloadProjectList();

private:
	ProjectLoader projectLoader;
	ProjectEditor projectEditor;
	QString authToken;
	QList<ProjectInfo> projectList;

	void projectsLoadedSlot();
};

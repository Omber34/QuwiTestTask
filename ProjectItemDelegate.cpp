#include <qpainter.h>
#include "ProjectItemDelegate.h"
#include "ProjectEditDialog.h"
#include "NetworkManager.h"

ProjectItemDelegate::ProjectItemDelegate(QObject* parent)
	: QAbstractItemDelegate(parent)
{}

void ProjectItemDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	ProjectInfo project = index.data().value<ProjectInfo>();
	QPoint topLeft = option.rect.topLeft();
	QPoint pointDrawLogo { topLeft.x() , topLeft.y()  };
	
	if (project.haveLogo())
	{
		QPixmap scaledLogo = project.getLogo().scaled({40,40});
		painter->drawPixmap(pointDrawLogo, scaledLogo);
	}
	
	QPoint pointDrawName{ topLeft.x() + 80 , topLeft.y() + 20 };
	painter->drawText(pointDrawName, project.getName());

	QPoint pointDrawActive{ topLeft.x() + 220 , topLeft.y() + 20 };
	painter->drawText(pointDrawActive, project.getActiveString());

	QPoint pointDrawWeek{ topLeft.x() + 350, topLeft.y() + 10 };
	painter->drawText(pointDrawWeek, project.getTimeWeek());

	QPoint pointDrawMonth{ topLeft.x() + 350, topLeft.y() + 20 };
	painter->drawText(pointDrawMonth, project.getTimeMonth());

	QPoint pointDrawAll{ topLeft.x() + 350, topLeft.y() + 30 };
	painter->drawText(pointDrawAll, project.getTimeAll());
}

QSize ProjectItemDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	return {400, 40};
}

QWidget* ProjectItemDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	ProjectEditDialog* editor = new ProjectEditDialog(parent);
	editor->setModal(true);
	connect(editor, &ProjectEditDialog::okClicked, 
		[this, editor]() mutable
		{
			emit const_cast<ProjectItemDelegate*>(this)->commitData(editor);
		});
	return editor;
}

void ProjectItemDelegate::setEditorData(QWidget* _editor, const QModelIndex& index) const
{
	ProjectEditDialog* editor = static_cast<ProjectEditDialog*>(_editor);
	ProjectInfo data = index.data().value<ProjectInfo>();
	editor->setData(data);
}

QJsonObject getDifference(QWidget* editor, QModelIndex const& index)
{
	ProjectInfo data = index.data().value<ProjectInfo>();
	ProjectEditDialog* projectWidget = static_cast<ProjectEditDialog*>(editor);
	QJsonObject difference;
	if (projectWidget->getName() != data.getName())
		difference.insert("name", projectWidget->getName());
	if (projectWidget->getActive() != data.getActive())
		difference.insert("is_active", projectWidget->getActive());
	return difference;
}

void ProjectItemDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const
{
	model->setData(index, getDifference(editor, index), Qt::EditRole);
}

void ProjectItemDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	ProjectEditDialog* projectWidget = static_cast<ProjectEditDialog*>(editor);
	projectWidget->setFixedSize({ 273,172 });
}


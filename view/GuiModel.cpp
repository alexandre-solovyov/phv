
#include <GuiModel.h>

GuiModel::GuiModel(QObject* theParent)
: QAbstractListModel (theParent)
{
}

GuiModel::~GuiModel()
{
}

QString GuiModel::centerItem() const
{
    return "CENTER1";
}

int GuiModel::rowCount(const QModelIndex& theParent) const
{
    if(theParent.isValid())
        return 0;
    else
        return 8; //TODO
}

QVariant GuiModel::data(const QModelIndex& theIndex, int theRole) const
{
    switch(theRole)
    {
    case Qt::DisplayRole:
    case NameRole:
        return "A" + QString::number(theIndex.row()+1);   //TODO
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> GuiModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    return roles;
}

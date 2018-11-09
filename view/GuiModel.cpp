
#include <GuiModel.h>

GuiModel::GuiModel(Model* theModel, QObject* theParent)
: QAbstractListModel (theParent), myModel(theModel)
{
}

GuiModel::~GuiModel()
{
}

QString GuiModel::centerItem() const
{
    return myCenterItem;
}

void GuiModel::setCenterItem(const QString& theCenterItem)
{
    myCenterItem = theCenterItem;
    myCurrent = myModel->get(myCenterItem);
    emit centerItemChanged(myCenterItem);
}

int GuiModel::rowCount(const QModelIndex& theParent) const
{
    if(theParent.isValid())
        return 0;
    else
        return myCurrent.Forms.size();
}

QVariant GuiModel::data(const QModelIndex& theIndex, int theRole) const
{
    switch(theRole)
    {
    case Qt::DisplayRole:
    case NameRole:
        return myCurrent.Forms[theIndex.row()].Particle;
    case TranslationRole:
        return myCurrent.Forms[theIndex.row()].Translation;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> GuiModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[TranslationRole] = "translation";
    return roles;
}


#ifndef GUI_MODEL_H
#define GUI_MODEL_H

#include <QAbstractListModel>

class GuiModel : public QAbstractListModel
{
  Q_OBJECT

public:
  enum Roles
  {
    NameRole = Qt::UserRole + 1,
  };

public:
  explicit GuiModel (QObject* theParent = nullptr);
  ~GuiModel() Q_DECL_OVERRIDE;

  virtual int rowCount(const QModelIndex& theParent = QModelIndex()) const override;
  virtual QVariant data(const QModelIndex& theIndex, int theRole = Qt::DisplayRole) const override;

  virtual QHash<int, QByteArray> roleNames() const override;
};

#endif // GUI_MODEL_H
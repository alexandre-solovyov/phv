
#ifndef GUI_MODEL_H
#define GUI_MODEL_H

#include <QAbstractListModel>
#include <model.h>

class GuiModel : public QAbstractListModel
{
  Q_OBJECT

public:
  enum Roles
  {
    NameRole = Qt::UserRole + 1,
    TranslationRole,
  };

public:
  explicit GuiModel (Model* theModel, QObject* theParent = nullptr);
  ~GuiModel() Q_DECL_OVERRIDE;

  Q_PROPERTY(QString centerItem READ centerItem WRITE setCenterItem NOTIFY centerItemChanged);

  QString centerItem() const;
  void setCenterItem(const QString&);

  virtual int rowCount(const QModelIndex& theParent = QModelIndex()) const override;
  virtual QVariant data(const QModelIndex& theIndex, int theRole = Qt::DisplayRole) const override;

  virtual QHash<int, QByteArray> roleNames() const override;

signals:
  void centerItemChanged(const QString&);

private:
  QString myCenterItem;
  Model* myModel;
  Verb myCurrent;
};

#endif // GUI_MODEL_H

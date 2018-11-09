#ifndef MODEL_H
#define MODEL_H

#include <QString>
#include <QList>

struct VerbForm
{
    QString Particle;
    QString Translation;
};

struct Verb
{
    QString Main;
    QList<VerbForm> Forms;

    void add(const QString&, const QString&);
};

class Model
{
public:
    Model();

    bool load(const QString&);
    Verb get(const QString&) const;

private:
    QMap<QString, Verb> myData;
};

#endif // MODEL_H

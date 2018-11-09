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

    Verb get(const QString&) const;
};

#endif // MODEL_H

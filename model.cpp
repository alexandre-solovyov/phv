#include "model.h"

void Verb::add(const QString& theParticle, const QString& theTranslation)
{
    VerbForm aForm;
    aForm.Particle = theParticle;
    aForm.Translation = theTranslation;
    Forms.append(aForm);
}

Model::Model()
{
}

Verb Model::get(const QString& theVerb) const
{
    //TODO: work with a database
    Verb aVerb;
    if(theVerb=="put")
    {
        aVerb.Main = theVerb;
        aVerb.add("on", "надевать");
        aVerb.add("out", "тушить");
        aVerb.add("off", "откладывать");
        aVerb.add("down", "критиковать");
        aVerb.add("over", "обманывать");
    }
    return aVerb;
}


#include <model.h>

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

bool Model::load(const QString& theFileName)
{
    QFile aFile( theFileName );
    if( !aFile.open( QIODevice::ReadOnly | QIODevice::Text ) )
        return false;

    QString aData = aFile.readAll();
    QStringList lines = aData.split( "\n", QString::SkipEmptyParts );
    aFile.close();

    Verb aVerb;
    foreach( QString aLine, lines )
    {
        if(aLine.isEmpty())
            continue;

        if(aLine[0].isSpace())
        {
            QStringList parts = aLine.split("=", QString::KeepEmptyParts);
            if(parts.size()==2)
                aVerb.add(parts[0].trimmed(), parts[1].trimmed());
        }
        else
        {
            if(!aVerb.Main.isEmpty())
                myData[aVerb.Main] = aVerb;

            aVerb.Main = aLine.trimmed();
            aVerb.Forms.clear();
        }
    }

    if(!aVerb.Main.isEmpty())
        myData[aVerb.Main] = aVerb;

    return true;
}

Verb Model::get(const QString& theVerb) const
{
    Verb aVerb;
    if(myData.contains(theVerb))
        aVerb = myData[theVerb];
    return aVerb;
}


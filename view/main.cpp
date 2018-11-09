#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <GuiModel.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QQmlContext* context = engine.rootContext();
    GuiModel* aModel = new GuiModel();
    context->setContextProperty ("guiModel", aModel);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

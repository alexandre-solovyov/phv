#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <model.h>
#include <GuiModel.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQmlContext* context = engine.rootContext();

    Model* aModel = new Model();
    aModel->load("d://phv//alex.data");
    GuiModel* aGuiModel = new GuiModel(aModel);
    aGuiModel->setCenterItem("put");
    context->setContextProperty ("guiModel", aGuiModel);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

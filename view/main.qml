import QtQuick 2.9
import QtQuick.Controls 2.2

ApplicationWindow {
    id: window
    visible: true
    width: 800
    height: 600
    title: qsTr("PHV")

    CircularView {
        id: mainView
        anchors.fill: parent
        model: guiModel

        interactive: true
        snapMode: PathView.NoSnap
    }
}

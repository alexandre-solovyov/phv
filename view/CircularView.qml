
import QtQuick 2.9
import QtQuick.Controls 2.2

PathView {
    id: circularView

    readonly property int cX: width / 2
    readonly property int cY: height / 2
    readonly property int size: Math.min(width, height)

    readonly property int centerItemSize: size / 2
    readonly property int subItemSize: size / 4
    readonly property int radius: centerItemSize/2 + subItemSize/2

    Rectangle {
        id: center_btn
        width: circularView.centerItemSize
        height: width

        opacity: 0.75

        radius: width / 2
        border.width: 3
        border.color: "blue"

        Text {
            text: circularView.model.centerItem
            font.pixelSize: centerItemSize * 0.25
            bottomPadding: centerItemSize * 0.1
            color: "black"
            anchors.centerIn: parent
        }

        anchors.centerIn: parent
    }

    delegate: Rectangle {
        width: circularView.subItemSize
        height: width

        opacity: 0.5

        radius: width / 2
        border.width: 3
        border.color: "blue"

        Text {
            id: name_text
            x: 0
            y: parent.height * 0.1
            width: parent.width
            height: parent.height * 0.5

            text: name
            font.pixelSize: subItemSize * 0.25
            color: "green"
            horizontalAlignment:  Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
        Text {
            y: parent.height * 0.4
            width: parent.width
            height: parent.height * 0.5

            text: translation
            font.pixelSize: subItemSize * 0.15
            color: "green"
            horizontalAlignment:  Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    path: Path {
        startX: circularView.cX + circularView.radius
        startY: circularView.cY
        PathArc {
            x: circularView.cX - circularView.radius
            y: circularView.cY
            radiusX: circularView.radius
            radiusY: circularView.radius
            useLargeArc: true
            direction: PathArc.Clockwise
        }
        PathArc {
            x: circularView.cX + circularView.radius
            y: circularView.cY
            radiusX: circularView.radius
            radiusY: circularView.radius
            useLargeArc: true
            direction: PathArc.Clockwise
        }
    }
}

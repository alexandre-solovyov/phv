
import QtQuick 2.9
import QtQuick.Controls 2.2

PathView {
    id: circularView

    signal launched(string page)

    readonly property int cX: width / 2
    readonly property int cY: height / 2
    readonly property int size: Math.min(width, height)

    readonly property int centerItemSize: size / 2
    readonly property int subItemSize: size / 4
    readonly property int radius: centerItemSize/2 + subItemSize/2

    interactive: false
    snapMode: PathView.NoSnap

    RoundButton {
        id: center_btn
        width: circularView.centerItemSize
        height: width
        text: circularView.model.centerItem

        background: Rectangle {
            radius: width / 2
            border.width: 3
            border.color: "blue"
        }

        anchors.centerIn: parent
    }

    delegate: RoundButton {
        width: circularView.subItemSize
        height: width
        text: name

        opacity: 0.5
        padding: 12

        background: Rectangle {
            radius: width / 2
            border.width: 3
            border.color: "blue"
        }

        onClicked: {
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

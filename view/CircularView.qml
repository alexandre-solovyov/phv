
import QtQuick 2.9
import QtQuick.Controls 2.2

PathView {
    id: circularView

    signal launched(string page)

    readonly property int cX: width / 2
    readonly property int cY: height / 2
    readonly property int itemSize: size / 4
    readonly property int size: Math.min(width - 80, height)
    readonly property int radius: size / 2 - itemSize / 3

    interactive: false
    snapMode: PathView.NoSnap

    delegate: RoundButton {
        width: circularView.itemSize
        height: circularView.itemSize
        text: name

        opacity: PathView.itemOpacity
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
        startX: circularView.cX
        startY: circularView.cY
        PathAttribute {
            name: "itemOpacity"
            value: 1.0
        }
        PathLine {
            x: circularView.cX + circularView.radius
            y: circularView.cY
        }
        PathAttribute {
            name: "itemOpacity"
            value: 0.7
        }
        PathArc {
            x: circularView.cX - circularView.radius
            y: circularView.cY
            radiusX: circularView.radius
            radiusY: circularView.radius
            useLargeArc: true
            direction: PathArc.Clockwise
        }
        PathAttribute {
            name: "itemOpacity"
            value: 0.5
        }
        PathArc {
            x: circularView.cX + circularView.radius
            y: circularView.cY
            radiusX: circularView.radius
            radiusY: circularView.radius
            useLargeArc: true
            direction: PathArc.Clockwise
        }
        PathAttribute {
            name: "itemOpacity"
            value: 0.3
        }
    }
}

import QtQuick 1.1
import com.nokia.meego 1.0

Page {
    id: page
    tools: commonTools

    Component.onCompleted: {
        monitor.heartRate.connect(setHeartRate)
        monitor.heartBeat.connect(runBeatAnimation)
    }

    Image {
        id: pageHeader
        anchors {
            top: page.top
            left: page.left
            right: page.right
        }

        height: parent.width < parent.height ? 72 : 46
        width: parent.width
        source: "image://theme/meegotouch-view-header-fixed" + (theme.inverted ? "-inverted" : "")
        z: 1

        Label {
            id: header
            anchors {
                verticalCenter: parent.verticalCenter
                left: parent.left
                leftMargin: 16
            }
            platformStyle: LabelStyle {
                fontFamily: "Nokia Pure Text Light"
                fontPixelSize: 32
            }
            text: "Heart Rate Monitor"
        }
    }

    Image {
        id: heartBeatImage
        anchors.top: pageHeader.bottom
        anchors.left: page.left
        anchors.right: page.right
        fillMode: Image.PreserveAspectFit
        source: "pictures/heart.png"
        opacity: 0.1

        SequentialAnimation on opacity {
            id: beatAnimation
            loops: 1
            PropertyAnimation { to: 1.0; duration: 150; easing.type: "OutQuad" }
            PropertyAnimation { to: 0.1; duration: 150; easing.type: "InQuad" }
        }
    }

    Label {
        id: heartRateLabel
        anchors.top: heartBeatImage.bottom
        anchors.left: page.left
        anchors.right: page.right
        anchors.bottom: page.bottom
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 50
        text: "---"
    }

    function setHeartRate(rate) {
        heartRateLabel.text = rate
    }
    function runBeatAnimation() {
        beatAnimation.start()
    }
}

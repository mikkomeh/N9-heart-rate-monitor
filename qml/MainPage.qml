import QtQuick 1.1
import com.nokia.meego 1.0
import HeartRateLibrary 1.0

Page {
    property int imageIndex: 0

    id: page
    tools: commonTools

    Connections {
        target: monitor
        onHeartBeat: beatAnimation.start()
        onHeartRate: setHeartRate(rate)
    }
    HeartRateMeasurement {
        id: lastMeasurement
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
        anchors.topMargin: 20
        height: 200
        fillMode: Image.PreserveAspectFit
        source: "pictures/heart.png"
        opacity: 0.3

        SequentialAnimation on opacity {
            id: beatAnimation
            loops: 1
            PropertyAnimation { to: 1.0; duration: 125; easing.type: "OutQuad" }
            PropertyAnimation { to: 0.3; duration: 125; easing.type: "InQuad" }
        }
    }

    Label {
        id: heartRateLabel
        anchors.top: heartBeatImage.bottom
        anchors.left: page.left
        anchors.right: page.right
        anchors.topMargin: 20
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 50
        text: "---"
    }

    Image {
        id: historyImage
        anchors.bottom: page.bottom
        anchors.left: page.left
        sourceSize.width: page.width
        sourceSize.height: 340
        source: "image://chart/image.png"
        cache: false
    }

    function setHeartRate(rate) {
        lastMeasurement.time = new Date()
        lastMeasurement.value = rate
        heartRateLabel.text = rate
        // Trick to force image reload
        historyImage.source = "image://chart/image" + page.imageIndex + ".png"
        page.imageIndex++
    }
    function saveMeasurement() {
        history.append(lastMeasurement.time, lastMeasurement.value)
    }
}

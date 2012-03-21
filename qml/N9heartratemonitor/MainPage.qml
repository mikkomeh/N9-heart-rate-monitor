import QtQuick 1.1
import com.nokia.meego 1.0

Page {
    id: page
    tools: commonTools

    property string title : "N9 Heart rate monitor"

    Component.onCompleted: {
        monitor.heartRate.connect(setHeartRate)
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
            text: page.title
        }
    }

    Label {
        id: heartRateLabel
        anchors.top: pageHeader.bottom
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
}

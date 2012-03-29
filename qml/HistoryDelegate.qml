import QtQuick 1.1
import "uiconstants.js" as Ui

Component {
    Row {
        height: Ui.DelegateHeight
        spacing: 15
        Image {
            height: Ui.DelegateHeight - 10
            source: "pictures/heart.png"
            fillMode: Image.PreserveAspectFit
        }

        Text {
            color: Ui.HistoryTextColor
            font.pixelSize: Ui.HistoryValueTextSize
            text: heartRate
        }
        Text {
            color: Ui.HistoryTextColor
            font.pixelSize: Ui.HistoryTimeTextSize
            text: Qt.formatDateTime(time, Qt.SystemLocaleShortDate)
        }
    }
}

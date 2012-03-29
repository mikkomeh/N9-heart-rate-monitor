import QtQuick 1.1
import com.nokia.meego 1.0

Page {
    id: historyPage
    tools: commonTools

    ListView {
        anchors.top: historyPage.top
        anchors.bottom: historyPage.bottom
        anchors.left: historyPage.left
        anchors.right: historyPage.right
        model: history
        delegate: HistoryDelegate {}
    }
}

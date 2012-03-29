import QtQuick 1.1
import com.nokia.meego 1.0

PageStackWindow {
    id: appWindow
    initialPage: mainPage

    MainPage {
        id: mainPage
    }
    HistoryPage {
        id: historyPage
    }

    Component.onCompleted: {
        screen.allowedOrientations = Screen.Portrait
        theme.inverted = true
    }

    ToolBarLayout {
        id: commonTools

        ToolIcon {
            platformIconId: "toolbar-back"
            onClicked: pageStack.pop();
            visible: pageStack.depth > 1
        }
        ToolIcon {
            platformIconId: "toolbar-view-menu"
            visible: pageStack.depth == 1
            onClicked: mainMenu.open();
        }
    }

    QueryDialog {
        id: aboutDialog
        titleText: "Heart Rate Monitor"
        message: "(C) 2012 Group of developers with too much free time\nv.0.1"
    }

    Menu {
        id: mainMenu
        visualParent: pageStack
        MenuLayout {
            MenuItem {
                text: qsTr("Store")
                onClicked: mainPage.saveMeasurement()
            }
            MenuItem {
                text: qsTr("History")
                onClicked: pageStack.push(historyPage)
            }
            MenuItem {
                text: qsTr("About")
                onClicked: aboutDialog.open()
            }
        }
    }
}

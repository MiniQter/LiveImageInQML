import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import com.mycompany.qmlcomponents 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("LiveImageInQML")

    SwipeView {
        anchors.fill: parent

        // subclass QQuickPaintedItem
        LiveImageItem {// calll setImage with real image
        }

        // use QQuickImageProvider
        Image {
            id: img

            property bool counter: false

            function reload() {
                counter = !counter
                source = "image://live/image?id=" + counter
            }

            asynchronous: false
            source: "image://live/image"
            fillMode: Image.PreserveAspectFit
            cache: false

            Connections {
                target: liveImageProvider

                function onImageChanged() {
                    img.reload()
                }
            }
        }
    }
}

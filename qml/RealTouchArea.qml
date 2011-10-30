import Qt 4.7

RootTouchArea {
    /*property bool useMouseTracker : false*/
    TouchArea {
        anchors.fill : parent
        onPressed : {
            parent.pressed( count, x, y )
        }
        onReleased : {
            parent.released( count, x, y )
        }
        onMoved : {
            parent.moved( count, currentX, currentY, lastX, lastY )
        }
    }
}

import Qt 4.7

RootTouchArea {
    /*property bool useMouseTracker : false*/
    TouchArea {
        anchors.fill : parent
        onPressed : {
            parent.pressed( x, y )
        }
        onReleased : {
            parent.released( x, y )
        }
        onMoved : {
            parent.moved( currentX, currentY, lastX, lastY )
        }
    }
}

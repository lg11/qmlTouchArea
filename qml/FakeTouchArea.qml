import Qt 4.7

Item {
    signal entered ()
    signal exited ()
    property bool acceptTouchEvent : true
    property int count : 0
    property bool pressed : count > 0
}

import Qt 4.7

Item {
    function getFocus ( x, y ) {
        var pos = Qt.point( x, y )
        var target = childAt( pos.x, pos.y )
        var parent = null
        var flag = true
        if ( target ) {
            parent = target.parent
            while ( flag ) {
                if ( target.acceptTouchEvent ) {
                    flag = false
                }
                else {
                    pos = target.mapFromItem( parent, pos.x, pos.y )
                    parent = target
                    target = parent.childAt( pos.x, pos.y )
                    if ( !target ) {
                        flag = false
                    }
                }
            }
        }
        return target
    }

    function enter( count, target ) {
        if ( target.count <= 0 ) {
            target.entered()
        }
        if ( target.count < count ) {
            target.count += 1
        }
    }

    function leave( count, target ) {
        if ( target.count > 0 ) {
            target.count -= 1
        }
        if ( target.count <= 0 ) {
            target.exited()
        }
    }

    function pressed ( count, x, y ) {
        var target = getFocus( x, y )
        if ( target ) {
            enter( count, target )
        }
    }

    function released ( count, x, y ) {
        var target = getFocus( x, y )
        if ( target ) {
            leave( count, target )
        }
    }

    function moved ( count, currentX, currentY, lastX, lastY ) {
        var currentTarget = getFocus( currentX, currentY )
                var lastTarget = getFocus( lastX, lastY )
        if ( currentTarget != lastTarget ) {
            if ( lastTarget ) {
                leave( count, lastTarget )
            }
            if ( currentTarget ) {
                enter( count, currentTarget )
            }
        }
    }
}

#ifndef TOUCHAREA_H
#define TOUCHAREA_H

#include <QtDeclarative/QDeclarativeItem>
#include <QEvent>
#include <QTouchEvent>

class TouchArea : public QDeclarativeItem {
    Q_OBJECT
signals :
    void pressed( int id, int count, qreal x ,qreal y ) ;
    void moved( int id, int count, qreal currentX, qreal currentY, qreal lastX, qreal lastY ) ;
    void released( int id, int count, qreal x, qreal y ) ;
    //void stationary( int id, qreal x, qreal y ) ;

public:
    TouchArea( QDeclarativeItem* parent = NULL ) : QDeclarativeItem( parent ) {
        this->setAcceptTouchEvents( true ) ;
        this->setFiltersChildEvents( true ) ;
    }

    ~TouchArea() {}

    bool processTouchEvent( QTouchEvent* event ) {
        const QList<QTouchEvent::TouchPoint>& points = event->touchPoints() ;
        foreach( const QTouchEvent::TouchPoint& point, points ) {
            switch( point.state() ) {
                case Qt::TouchPointPressed :
                    emit this->pressed( point.id(), points.count(), point.pos().rx(), point.pos().ry() ) ;
                    break ;
                case Qt::TouchPointMoved :
                    if ( point.lastPos() != point.pos() )
                        emit this->moved( point.id(), points.count(), point.pos().rx(), point.pos().ry(), point.lastPos().rx(), point.lastPos().ry() ) ;
                    break ;
                case Qt::TouchPointReleased :
                    emit this->released( point.id(), points.count(), point.pos().rx(), point.pos().ry() ) ;
                    break ;
                default :
                    break ;
            }
        }
        return true ;
    }

    virtual bool event( QEvent* event ) {
        bool flag ;
        switch ( event->type() ) {
            case QEvent::TouchBegin :
                flag = this->processTouchEvent( static_cast<QTouchEvent*>(event) ) ;
                break ;
            case QEvent::TouchUpdate :
                flag = this->processTouchEvent( static_cast<QTouchEvent*>(event) ) ;
                break ;
            case QEvent::TouchEnd :
                flag = this->processTouchEvent( static_cast<QTouchEvent*>(event) ) ;
                break ;
            default :
                flag = QDeclarativeItem::event( event ) ;
                break ;
        }
        return flag ;
    }

    //virtual bool sceneEvent( QGraphicsItem* item, QEvent* event ) {}
    //Q_INVOKABLE inline void reset() { this->length = 0 ; this->time.restart() ; }
} ;

QML_DECLARE_TYPE(TouchArea)

#endif // TOUCHAREA_H


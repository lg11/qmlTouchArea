#include "plugin.h"
#include "toucharea.h"

#include <QtDeclarative/qdeclarative.h>

void TouchareaPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<TouchArea>(uri, 1, 0, "TouchArea");
}

Q_EXPORT_PLUGIN2(Toucharea, TouchareaPlugin)


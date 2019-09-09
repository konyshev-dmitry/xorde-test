#ifndef CONNECTIONHELPER_H
#define CONNECTIONHELPER_H

#include <QObject>
#include <QMetaObject>
#include "xotools_global.h"

class XOTOOLSSHARED_EXPORT ConnectionHelper
{
public:
    ConnectionHelper();
    ~ConnectionHelper();

    void operator << (QMetaObject::Connection connection);

    void clear();

    QList<QMetaObject::Connection> m_connections;

    static void clear(QList<QMetaObject::Connection> &connections);
};

#endif // CONNECTIONHELPER_H

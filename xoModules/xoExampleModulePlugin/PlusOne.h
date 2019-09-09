#ifndef PLUSONE_H
#define PLUSONE_H

#include "ComponentBase.h"

class PlusOne : public ComponentBase
{
    Q_OBJECT
public:
    PlusOne(QObject* parent = nullptr);

protected:
    void objectReceiveEvent(QString) override;

    float m_in = 0;
    float m_out = 0;

};

#endif // CORTEXCONNECTORCOMPONENT_H

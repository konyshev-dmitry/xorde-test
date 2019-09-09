#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "ComponentBase.h"

class Multiply : public ComponentBase
{
    Q_OBJECT
public:
    Multiply(QObject* parent = nullptr);

protected:
    void objectReceiveEvent(QString) override;

    float m_factor = 1;
    float m_in = 0;
    float m_out = 0;

};

#endif // CORTEXCONNECTORCOMPONENT_H

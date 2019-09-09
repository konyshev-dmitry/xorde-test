#include "PlusOne.h"

PlusOne::PlusOne(QObject* parent) : ComponentBase("PlusOne", 0x20202020, "Adds 1 to the input", parent)
{
    setIcon(":/images/plus-one.svg");

    createInput("in", m_in);
    createOutput("out", m_out);
}

void PlusOne::objectReceiveEvent(QString)
{
    //There is only one input - no need to check the name
    m_out = m_in+1;
    touchOutput("out");
}

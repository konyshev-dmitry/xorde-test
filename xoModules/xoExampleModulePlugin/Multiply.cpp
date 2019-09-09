#include "Multiply.h"

Multiply::Multiply(QObject* parent) : ComponentBase("Multiply", 0x20202021, "Adds 1 to the input", parent)
{
    setIcon(":/images/multiply.svg");

    createSetting("factor", m_factor).min(-1000).max(1000).def(1).hint("Multiplication factor");
    createInput("in", m_in);
    createOutput("out", m_out);
}

void Multiply::objectReceiveEvent(QString)
{
    //There is only one input - no need to check the name
    m_out = m_in*m_factor;
    touchOutput("out");
}

#include "ExampleSlidersComponent.h"

#include <QGridLayout>
#include <QLabel>

ExampleSlidersComponent::ExampleSlidersComponent(QObject *parent) : ComponentBase("ExampleSlidersComponent", 0x01010101, "", parent)
{
    description = "Two output sliders, two input sliders."
                  "- 'out1' works by request."
                  "- 'out2' works by change in the slider."
                  "."
                  "- 'in1' works by change event"
                  "- 'in2' works by receive event";


    setIcon(":/images/arrow-left-right-bold.png");

    createSetting("title", m_title).def("Example sliders");

    createInput("in1", m_valueIn1).min(-10).max(10).def(0);
    createInput("in2", m_valueIn2).min(-10).max(10).def(0);

    createOutput("out1", m_valueOut1).min(-10).max(10).def(0).sampling(10ms);
    createOutput("out2", m_valueOut2).min(-10).max(10).def(0);
}

void ExampleSlidersComponent::onCreate()
{
    auto func_slider = []()
    {
        QSlider *slider = new QSlider(Qt::Horizontal);
        slider->setMinimum(-10);
        slider->setMaximum(10);
        return slider;
    };

    m_sliderOut1 = func_slider();
    m_sliderOut2 = func_slider();
    m_sliderIn1 = func_slider();
    m_sliderIn2 = func_slider();

    m_widget = new QWidget();
    m_widget->setMinimumSize(400, 200);
    m_widget->setWindowTitle(m_title);
    auto grid = new QGridLayout(m_widget);

    grid->addWidget(new QLabel("Outputs"), 0, 0, 1, 2, Qt::AlignCenter);

    grid->addWidget(new QLabel("Out1 (by 'request')"), 1, 0);
    grid->addWidget(new QLabel("Out2 (by ui signal)"), 2, 0);
    grid->addWidget(m_sliderOut1, 1, 1);
    grid->addWidget(m_sliderOut2, 2, 1);

    grid->addWidget(new QLabel("Inputs"), 3, 0, 1, 2, Qt::AlignCenter);

    grid->addWidget(new QLabel("In1 (by 'change')"), 4, 0);
    grid->addWidget(new QLabel("In2 (by 'receive')"), 5, 0);
    grid->addWidget(m_sliderIn1, 4, 1);
    grid->addWidget(m_sliderIn2, 5, 1);

    connect(m_sliderOut2, &QSlider::valueChanged, [=](int value)
    {
        m_valueOut2 = value;
        touchOutput("out2");
    });

    m_widget->setWindowFlag(Qt:: WindowStaysOnTopHint, true);
    m_widget->show();
}

void ExampleSlidersComponent::onDestroy()
{
    m_connections.clear();
}

void ExampleSlidersComponent::objectRequestEvent(QString name)
{
    if (name == "out1" && m_sliderOut1)
    {
        m_valueOut1 = m_sliderOut1->value();
    }
}

void ExampleSlidersComponent::objectReceiveEvent(QString name)
{
    if (name == "in1")
    {
        m_sliderIn1->setValue(m_valueIn1);
    }
}

void ExampleSlidersComponent::objectChangeEvent(QString name)
{
    if (name == "in2" && m_sliderIn2)
    {
        m_sliderIn2->setValue(m_valueIn2);
    }
    else if (name == "title" && m_widget)
    {
        m_widget->setWindowTitle(m_title);
    }
}


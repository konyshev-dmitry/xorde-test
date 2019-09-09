#ifndef EXAMPLESLIDERSCOMPONENT_H
#define EXAMPLESLIDERSCOMPONENT_H

#include <QObject>
#include "ComponentBase.h"
#include "helpers/ConnectionHelper.h"
#include <QSlider>

class ExampleSlidersComponent : public ComponentBase
{
    Q_OBJECT
public:
    explicit ExampleSlidersComponent(QObject *parent = nullptr);

protected:
    float m_valueOut1 = 0;
    float m_valueOut2 = 0;
    float m_valueIn1 = 0;
    float m_valueIn2 = 0;

    QString m_title = "Example sliders";

protected:
    void onCreate() override;
    void onDestroy() override;
    void objectRequestEvent(QString name) override;
    void objectReceiveEvent(QString name) override;
    void objectChangeEvent(QString name) override;

    void createVid();

    ConnectionHelper m_connections;

    QSlider *m_sliderIn1 = nullptr;
    QSlider *m_sliderIn2 = nullptr;
    QSlider *m_sliderOut1 = nullptr;
    QSlider *m_sliderOut2 = nullptr;
    QWidget *m_widget = nullptr;
};

#endif // EXAMPLESLIDERSCOMPONENT_H

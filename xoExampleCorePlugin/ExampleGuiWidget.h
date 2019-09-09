#ifndef EXAMPLEGUIWIDGET_H
#define EXAMPLEGUIWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>



class ExampleGuiWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ExampleGuiWidget(QWidget *parent = nullptr);

protected:
    QComboBox *m_comboSchemes = nullptr;
    QPushButton *m_btnReload = nullptr;
    QPushButton *m_btnStart = nullptr;
    QPushButton *m_btnStop = nullptr;

protected slots:
    void reloadSchemes();
    void setCurrentScheme(const QString &schemeName);
};

#endif // EXAMPLEGUIWIDGET_H

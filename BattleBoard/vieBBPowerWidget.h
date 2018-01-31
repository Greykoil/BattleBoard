#pragma once

#include <QWidget>
#include "ui_vieBBPowerWidget.h"

class vieBBPowerWidget : public QWidget
{
    Q_OBJECT

public:
    vieBBPowerWidget(QWidget *parent = Q_NULLPTR);
    ~vieBBPowerWidget();

private:
    Ui::vieBBPowerWidget ui;
};

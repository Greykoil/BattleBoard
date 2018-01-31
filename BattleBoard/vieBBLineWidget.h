#pragma once

#include <QWidget>
#include "ui_vieBBLineWidget.h"

class vieBBLineWidget : public QWidget
{
    Q_OBJECT

public:
    vieBBLineWidget(QWidget *parent = Q_NULLPTR);
    ~vieBBLineWidget();

private:
    Ui::vieBBLineWidget ui;
};

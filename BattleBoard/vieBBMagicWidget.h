#pragma once

#include <QWidget>
#include "ui_vieBBMagicWidget.h"

class vieBBMagicWidget : public QWidget
{
    Q_OBJECT

public:
    vieBBMagicWidget(QWidget *parent = Q_NULLPTR);
    ~vieBBMagicWidget();

private:
    Ui::vieBBMagicWidget ui;
};

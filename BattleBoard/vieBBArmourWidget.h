#pragma once

#include <QWidget>
#include "ui_vieBBArmourWidget.h"

class modArmourManager;

class vieBBArmourWidget : public QWidget
{
    Q_OBJECT

public:
    vieBBArmourWidget(modArmourManager* armour, QWidget *parent = Q_NULLPTR);


    ~vieBBArmourWidget() = default;


public slots:
    void redraw();

private:
    Ui::vieBBArmourWidget m_ui;

    modArmourManager* m_armour_manager;
};

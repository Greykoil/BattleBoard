#pragma once

#include <QDialog>
#include "ui_vieArmourWindow.h"

class modArmourManager;
class vieBBArmourWidget;
class modArmourSource;

class vieArmourWindow : public QDialog
{
    Q_OBJECT

public:
    vieArmourWindow(modArmourManager* model, QWidget *parent = Q_NULLPTR);
    ~vieArmourWindow() = default;

private slots:

    void actionOnAddNewPermenantSource();

    void actionOnAddNewLongDurationSource();

    void actionOnWornArmourChanged();

    //void update();

private:
    Ui::vieArmourWindow m_ui;

    modArmourManager* m_model;

    vieBBArmourWidget* m_armour_display;

    modArmourSource* m_worn_armour;
};

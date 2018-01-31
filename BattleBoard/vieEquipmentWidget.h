#pragma once

#include <QWidget>
#include "ui_vieEquipmentWidget.h"

class vieEquipmentWidget : public QWidget
{
    Q_OBJECT

public:
    vieEquipmentWidget(QWidget *parent = Q_NULLPTR);
    ~vieEquipmentWidget();

private:
    Ui::vieEquipmentWidget ui;
};

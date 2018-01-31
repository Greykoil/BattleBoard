#pragma once

#include <QWidget>
#include "ui_vieBBSkillsWidget.h"

class vieBBSkillsWidget : public QWidget
{
    Q_OBJECT

public:
    vieBBSkillsWidget(QWidget *parent = Q_NULLPTR);
    ~vieBBSkillsWidget();

private:
    Ui::vieBBSkillsWidget ui;
};

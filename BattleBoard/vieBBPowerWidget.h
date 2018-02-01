#pragma once

#include <QWidget>
#include "ui_vieBBPowerWidget.h"

class modPowerManager;

class vieBBPowerWidget : public QWidget
{
    Q_OBJECT

public:
  vieBBPowerWidget(modPowerManager* power_manager, QWidget *parent = Q_NULLPTR);
  
  void redraw();

  ~vieBBPowerWidget() = default;

private:
  Ui::vieBBPowerWidget m_ui;

  modPowerManager* m_power_manager;

};

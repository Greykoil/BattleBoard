#pragma once

#include <QWidget>
#include "ui_vieBBAbilityDisplayWidget.h"

class modAbility;

class vieBBAbilityDisplayWidget : public QWidget
{
    Q_OBJECT

public:
  vieBBAbilityDisplayWidget(modAbility* m_model, QWidget *parent = Q_NULLPTR);

  void redraw();

  ~vieBBAbilityDisplayWidget() = default;

private:
  Ui::vieBBAbilityDisplayWidget m_ui;

  modAbility* m_model;
};

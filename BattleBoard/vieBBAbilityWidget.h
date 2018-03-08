#pragma once

#include <QWidget>
#include "ui_vieBBAbilityWidget.h"
class modAbilityManager;

class vieBBAbilityWidget : public QWidget
{
  Q_OBJECT

public:
  vieBBAbilityWidget(modAbilityManager* model, QWidget *parent = Q_NULLPTR);

  void redraw();

  ~vieBBAbilityWidget() = default;

private:
    Ui::vieBBAbilityWidget m_ui;

    modAbilityManager* m_model;
};

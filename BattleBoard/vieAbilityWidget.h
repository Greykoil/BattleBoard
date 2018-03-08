#pragma once

#include <QWidget>
#include "ui_vieAbilityWidget.h"
class modAbility;

class vieAbilityWidget : public QWidget
{
    Q_OBJECT

public:
  vieAbilityWidget(modAbility* model, QWidget *parent = Q_NULLPTR);




  ~vieAbilityWidget() = default;

private slots:
  
  void onActionNameChanged(QString name);
  void onActionFrequency(QString type);
  void onActionChargesChanged(int charges);


private:
    Ui::vieAbilityWidget m_ui;
    modAbility* m_model;
};

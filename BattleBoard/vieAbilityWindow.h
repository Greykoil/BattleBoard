#pragma once

#include <QDialog>
#include "ui_vieAbilityWindow.h"

class modAbilityManager;

class vieAbilityWindow : public QDialog
{
  Q_OBJECT

public:
  vieAbilityWindow(modAbilityManager* model, QWidget *parent = Q_NULLPTR);

  ~vieAbilityWindow() = default;

private slots:

  void actionOnAddNewAbility();
  // Called when the user pushes the new ability button


private:
  Ui::vieAbilityWindow m_ui;
  
  modAbilityManager* m_model;

};

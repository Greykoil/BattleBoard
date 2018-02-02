#include "vieAbilityWindow.h"
#include "modAbilityManager.h"
#include "vieAbilityWidget.h"

vieAbilityWindow::vieAbilityWindow(
  modAbilityManager* mod, 
  QWidget *parent)
  : QDialog(parent),
    m_model(mod)
{
  m_ui.setupUi(this);
}


void vieAbilityWindow::actionOnAddNewAbility()
{
  modAbility* new_ability = m_model->add_new_ability();
  m_ui.verticalLayout->addWidget(new vieAbilityWidget(new_ability));
}
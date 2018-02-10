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
  vieAbilityWidget* widget = new vieAbilityWidget(new_ability);
  QListWidgetItem* item = new QListWidgetItem();
  item->setSizeHint(widget->sizeHint());
  m_ui.listWidget->addItem(item);
  m_ui.listWidget->setItemWidget(item, widget);
}
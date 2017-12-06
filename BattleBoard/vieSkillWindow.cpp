//=============================================================================
//D The top level window that displays the list of availble skills to the user
//
//-----------------------------------------------------------------------------

// Class header include
#include "vieSkillWindow.h"
#include "vwmSkillPage.h"
// includes from project
#include "vieSkillWidget.h"
#include "modCharacter.h"
//includes from QT

#include <assert.h>

//=============================================================================
vieSkillWindow::vieSkillWindow(
  vwmSkillPage* manager,
  modSkillManager* model,
  modCharacter* character,
  QWidget* parent
)
//
//-----------------------------------------------------------------------------
  : QDialog(parent),
    m_vm_manager(manager),
    m_model(model),
    m_character_model(character)
{
  manager->set_view(this);
  m_ui.setupUi(this);

  // Get a list of the visable skills
  m_vm_manager->full_skill_list(m_full_skill_list);
  
  // Here is a list of skills to display
  for (std::unique_ptr<vieSkillWidget>& skill : m_full_skill_list) {
    QListWidgetItem* item = new QListWidgetItem();
    item->setSizeHint(skill.get()->sizeHint());
    auto pair = std::make_pair(skill.get(), item);
    m_all_skills.push_back(pair);

    m_ui.listWidget->addItem(item);
    m_ui.listWidget->setItemWidget(item, skill.get());
    if (!skill->is_visable()) {
      item->setHidden(true);
    }
  }

  redraw();

}

//=============================================================================
void vieSkillWindow::redraw()
//
//D Triggered when the list of visable skills has changed
//  
//  Hide the skills that are not pickable and reveal the skills that are
// 
//-----------------------------------------------------------------------------
{
  // Update the available and spent points
  int spent_points = m_model->total_points_spent();
  int available_points = m_character_model->get_available_points();
  
  m_ui.pointsAvailable->setText(QString::number(available_points));
  m_ui.pointSpent->setText(QString::number(spent_points));

  for (auto widget : m_all_skills) {
    widget.second->setHidden(!(widget.first->is_visable()));

    widget.first->update_after_load();
  }
}

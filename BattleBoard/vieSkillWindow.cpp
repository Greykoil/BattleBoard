//=============================================================================
//D The top level window that displays the list of availble skills to the user
//
//-----------------------------------------------------------------------------

// Class header include
#include "vieSkillWindow.h"
#include "vwmSkillPage.h"
// includes from project
#include "vieSkillWidget.h"
//includes from QT

#include <assert.h>

//=============================================================================
vieSkillWindow::vieSkillWindow(
  vwmSkillPage* manager,
  QWidget* parent
)
//
//D Default constructor
//
//-----------------------------------------------------------------------------
  : QDialog(parent),
    m_vm_manager(manager)
{
  manager->set_view(this);
  m_ui.setupUi(this);

  // Get a list of the visable skills
  m_vm_manager->full_skill_list(m_full_skill_list);
  
  // Here is a list of skills to display
  for (auto& skill : m_full_skill_list) {
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
  for (auto widget : m_all_skills) {
    widget.second->setHidden(!(widget.first->is_visable()));
  }
}

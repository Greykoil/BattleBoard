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
  m_ui.setupUi(this);

  // Get a list of the visable skills
  m_vm_manager->full_skill_list(m_full_skill_list);
  
  
  // Here is a list of skills to display
  for (auto& skill : m_full_skill_list) {
    QListWidgetItem* item = new QListWidgetItem();
    item->setSizeHint(skill.get()->sizeHint());
    m_ui.listWidget->addItem(item);
    m_ui.listWidget->setItemWidget(item, skill.get());
  }
}

//=============================================================================
void vieSkillWindow::redraw()
//
//D Triggered when the list of visable skills has changed
//  
//  There should be a way of updating the list rather than 
//  redrawing everything
//-----------------------------------------------------------------------------
{
  // Clear the current visable and reload

  // We want to clear out any widgets that are not visable and add any that are
  for (auto skill : m_visable_skills) {
    m_ui.verticalLayout_2->removeWidget(skill);
  }

  m_visable_skills.clear();
  // Here is a list of skills to display
  //for (auto& skill : m_full_skill_list) {
  //  if (skill->is_visable()) {
  //    m_visable_skills.push_back(skill.get());
  //    m_ui.verticalLayout_2->addWidget(skill.get());
  //    m_ui.verticalLayout_2->addWidget(skill.get());
  //  }
  //}
}

//=============================================================================
vieSkillWindow::~vieSkillWindow()
//
//D Default Destructor
//
//-----------------------------------------------------------------------------
{

}

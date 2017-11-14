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
  m_vm_manager->initial_skill_list(m_visable_skills);

  // Here is a random list of skills to choose from
  for (auto& skill : m_visable_skills) {
    m_ui.verticalLayout_2->addWidget(skill.get());
  }

}

//=============================================================================
vieSkillWindow::~vieSkillWindow()
//
//D Default Destructor
//
//-----------------------------------------------------------------------------
{

}

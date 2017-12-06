//=============================================================================
//D The view model manager for interfacing the view skill page and the 
//  model list of skills
//
//-----------------------------------------------------------------------------
// includes from our libraries
#include "vwmSkillPage.h"
#include "modSkillManager.h"
#include "modSkill.h"
#include "vieSkillWidget.h"
#include "vieSkillWindow.h"
#include "vwmCharacter.h"
// system includes
#include <assert.h>

//=============================================================================
vwmSkillPage::vwmSkillPage(
  modSkillManager* model_skill_page,
  vwmCharacter* parent
)
//
// Default constructort
//
//-----------------------------------------------------------------------------
  : m_model_skill_page(model_skill_page),
    m_parent(parent),
    m_skills()
{
  assert(m_model_skill_page != nullptr);
}

//=============================================================================
void vwmSkillPage::full_skill_list(
  std::vector<std::unique_ptr<vieSkillWidget>>& vector
)
//
//D Fill the passed in vector with the initial list of visable skills
//
//-----------------------------------------------------------------------------
{
  for (int i = 0; i < m_model_skill_page->num_skills(); ++i) {
    m_skills.push_back(std::make_unique<vwmSkill>(m_model_skill_page->skill(i), this));
  }

  for (std::unique_ptr<vwmSkill>& skill_vm: m_skills) {
    vector.push_back(skill_vm->make_widget());
  }
}

//=============================================================================
int vwmSkillPage::num_skills()
//
//D
//
//-----------------------------------------------------------------------------
{
  return m_skills.size();
}

//=============================================================================
vwmSkill* vwmSkillPage::skill(int n)
//
//D
//
//-----------------------------------------------------------------------------
{
  return m_skills[n].get();
}

//=============================================================================
void vwmSkillPage::update_displayed_skills()
//
//D
//
//-----------------------------------------------------------------------------
{
  m_view->redraw();
}


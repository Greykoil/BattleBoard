//=============================================================================
//D The view model manager for interfacing the view skill page and the 
//  model list of skills
//
//-----------------------------------------------------------------------------
// includes from our libraries
#include "vwmSkillPage.h"
#include "vieSkillWidget.h"
#include "vwmSkill.h"
// system includes

//=============================================================================
vwmSkillPage::vwmSkillPage()
//
// Default constructort
//
//-----------------------------------------------------------------------------
  : m_creator(),
    m_skills()
{
}

//=============================================================================
void vwmSkillPage::initial_skill_list(
  std::vector<std::unique_ptr<vieSkillWidget>>& vector
)
//
//D Fill the passed in vector with the initial list of visable skills
//
//-----------------------------------------------------------------------------
{
  m_creator.create_skill_tree();

  for (int i = 0; i < m_creator.num_skills(); ++i) {
    m_skills.push_back(std::make_unique<vwmSkill>(m_creator.skill(i)));
  }

  for (std::unique_ptr<vwmSkill>& skill_vm: m_skills) {
    vector.push_back(skill_vm->make_widget());
  }
}

//=============================================================================
vwmSkillPage::~vwmSkillPage()
//
// Default destructor
//
//-----------------------------------------------------------------------------
{

}

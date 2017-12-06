//=============================================================================
//
//D The view model interface between the skill view and the skill model
//
//-----------------------------------------------------------------------------
// includes from our libraries
#include "vwmSkill.h"
#include "vieSkillWidget.h"
#include "modSkill.h"
#include "vwmSkillPage.h"
// system includes
#include <assert.h>

//=============================================================================
vwmSkill::vwmSkill(
  modSkill* skill_model,
  vwmSkillPage* parent
)
//
// Default Constructor
//
//-----------------------------------------------------------------------------
  : m_skill_model(skill_model),
    m_parent(parent)
{
  assert(skill_model != nullptr);
}

//=============================================================================
void vwmSkill::set_view_skill(vieSkillWidget* skill)
//
//D Set m_skill_view
//
//-----------------------------------------------------------------------------
{
  assert(skill != nullptr);
  m_skill_view = skill;
}

//=============================================================================
bool vwmSkill::is_visable()
//
//D Is the skill pickable
//
//-----------------------------------------------------------------------------
{
  return m_skill_model->is_pickable();
}

//=============================================================================
std::unique_ptr<vieSkillWidget> vwmSkill::make_widget()
//
//D Make the widget for the corresponding skill
//
//-----------------------------------------------------------------------------
{
  return std::make_unique<vieSkillWidget>(
    this,
    QString::fromStdString(m_skill_model->name()),
    m_skill_model->cost_per_rank(),
    m_skill_model->max_picks()
  );
}

//=============================================================================
bool vwmSkill::change_num_picks(int num_picks)
//
//D Change the number of picks of the skill and update the gui with the 
//  new cost for those picks. Caps picks at max picks the skill allows and 
//  return false if the skill does not change
//
//-----------------------------------------------------------------------------
{
  assert(num_picks >= 0);
  assert(m_skill_view != nullptr);
  
  // Check if too many ranks were picked
  if (num_picks > m_skill_model->max_picks()) {
    num_picks = m_skill_model->max_picks();
  }
  
  bool changed = m_skill_model->set_picks(num_picks);
  if (!changed) {
    return false;
  }
  
  int cost = m_skill_model->total_cost();

  m_skill_view->set_total_cost(cost);

  // We might need to update the available skills
  m_parent->update_displayed_skills();
  return true;
}

//=============================================================================
int vwmSkill::num_picks()
//
//-----------------------------------------------------------------------------
{
  return m_skill_model->num_picks();
}

//=============================================================================
int vwmSkill::total_cost()
//
//-----------------------------------------------------------------------------
{
  return m_skill_model->total_cost();
}

//=============================================================================
std::string vwmSkill::name()
//
//-----------------------------------------------------------------------------
{
  return m_skill_model->name();
}

//=============================================================================
//D Class for the default skill model. 
//
// A default skill has traits of name, picks, cost etx
//
//-----------------------------------------------------------------------------
// includes from our libraries
#include "modSkill.h"
#include "modSkillManager.h"
// system includes
#include <assert.h>

//=============================================================================
modSkill::modSkill(
  std::string a_name,
  int a_cost,
  int a_max_picks,
  bool a_status,
  std::vector<modSkill*> prerequisites
)
//
//D Constructor. Sets up members and adds this skill as a dependent to any
//  prerequisites
//
//-----------------------------------------------------------------------------
  : m_name(a_name),
    m_cost(a_cost),
    m_max_picks(a_max_picks),
    m_status(a_status),
    m_num_picks(0),
    m_prerequisite_skills(prerequisites),
    m_pickable(false)
{
  for (modSkill* skill : prerequisites) {
    skill->add_dependent_skill(this);
  }
  update_pickable_state();
}

//=============================================================================
int modSkill::num_picks() const
//
//D The ranks of the skill the character has
//
//-----------------------------------------------------------------------------
{
  return m_num_picks;
}

//=============================================================================
bool modSkill::is_pickable() const
//
//D Have all the prerequisites for this skill been taken?
//
//-----------------------------------------------------------------------------
{
  return m_pickable;
}

//=============================================================================
void modSkill::add_dependent_skill(modSkill* skill)
//
//D Add a skill that is dependent on this skill
//
//-----------------------------------------------------------------------------
{
  assert(skill != nullptr);
  m_dependent_skills.push_back(skill);
}

//=============================================================================
void modSkill::update_pickable_state()
//
//D Update the pickability of this skill based on the prerequisites having 
//  been met
//
//-----------------------------------------------------------------------------
{
  bool old = m_pickable;

  for (modSkill* skill : m_prerequisite_skills) {
    if (skill->num_picks() == 0) {
      m_pickable = false;
      return;
    }
  }
  
  // We have ranks in all prerequisite skills
  m_pickable = true;
}

//=============================================================================
std::string modSkill::name() const
//
//D Get the skill name
//
//-----------------------------------------------------------------------------
{
  return m_name;
}

//=============================================================================
int modSkill::cost_per_rank() const
//
//D Get the cost for the next rank of a skill
//
//-----------------------------------------------------------------------------
{
  return m_cost;
}

//=============================================================================
int modSkill::max_picks() const
//
//D Get the maximum number of allowed picks
//
//-----------------------------------------------------------------------------
{
  return m_max_picks;
}

//=============================================================================
bool modSkill::is_status() const
//
//D Does the skill cost status
//
//-----------------------------------------------------------------------------
{
  return false;
}

//=============================================================================
bool modSkill::set_picks(int num_picks)
//
//D Set the number of picks of the skill. 
//
//-----------------------------------------------------------------------------
{
  assert(num_picks <= m_max_picks);

  // Check for having to update the available skills
  int old = m_num_picks;

  m_num_picks = num_picks;

  // Check we have not got rid of a skill that is a prerequisite for skills we 
  // still have
  if (m_num_picks == 0) {
    for (modSkill* dependent : m_dependent_skills) {
      if (dependent->num_picks() > 0) {
        m_num_picks = old;
        return false;
      }
      // Update pickability of dependent skills 
      dependent->update_pickable_state();
    }
  }

  // We have taken the skill then open up any dependent skills
  if (m_num_picks > 0 && old == 0) {
    for (modSkill* dependent : m_dependent_skills) {
      dependent->update_pickable_state();
    }
  }

  return true;
}

//=============================================================================
int modSkill::total_cost() const
//
//D Return the total cost for the number of picks of this skill
//
//-----------------------------------------------------------------------------
{
  return m_num_picks * m_cost;
}

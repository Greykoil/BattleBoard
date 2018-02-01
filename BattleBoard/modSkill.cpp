//=============================================================================
//D Class for the default skill model. 
//
// A default skill has traits of name, picks, cost etc
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
  std::unique_ptr<modSkillCost> cost_manager,
  int a_max_picks,
  bool a_status,
  std::vector<modSkill*> prerequisites
)
//
//D Sets up members and adds this skill as a dependent to any
//  prerequisites
//
//-----------------------------------------------------------------------------
  : m_name(a_name),
    m_cost_manager(std::move(cost_manager)),
    m_max_picks(a_max_picks),
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
tinyxml2::XMLElement * modSkill::convert_to_xml(
  tinyxml2::XMLDocument* parent
) const
//
//D Convert the skill to an xml element
//
//-----------------------------------------------------------------------------
{
  tinyxml2::XMLElement* element = parent->NewElement("Skill");
  element->SetAttribute("Name", m_name.c_str());
  element->SetAttribute("Picks", m_num_picks);
  return element;
}

//=============================================================================
void modSkill::load_from_xml(tinyxml2::XMLElement * element)
//
//D Load the skill details from an xml element
//
//-----------------------------------------------------------------------------
{
  // All that we should need to do is set the number of picks
  element->QueryIntAttribute("Picks", &m_num_picks);
  set_picks(m_num_picks);

}

//=============================================================================
int modSkill::num_picks() const
//
//-----------------------------------------------------------------------------
{
  return m_num_picks;
}

//=============================================================================
bool modSkill::is_pickable() const
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
//-----------------------------------------------------------------------------
{
  return m_name;
}

//=============================================================================
int modSkill::cost_per_rank() const
//
//-----------------------------------------------------------------------------
{
  return m_cost_manager->cost_for_details();
}

//=============================================================================
int modSkill::max_picks() const
//
//-----------------------------------------------------------------------------
{
  return m_max_picks;
}

//=============================================================================
bool modSkill::set_picks(int num_picks)
//
//D Set the number of picks of the skill. 
//
//-----------------------------------------------------------------------------
{
  bool picks_correct = true;
  if (num_picks > m_max_picks) {
    picks_correct = false;
    m_num_picks = m_max_picks;
  }

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

  return picks_correct;
}

//=============================================================================
int modSkill::total_cost() const
//
//D Return the total cost for the number of picks of this skill
//
//-----------------------------------------------------------------------------
{
  return m_num_picks * cost_per_rank();
}

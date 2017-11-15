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

//=============================================================================
modSkill::modSkill(
  std::string a_name,
  int a_cost,
  int a_max_picks,
  bool a_status
)
//
//D Default constructor
//
//-----------------------------------------------------------------------------
  : m_name(a_name),
    m_cost(a_cost),
    m_max_picks(a_max_picks),
    m_status(a_status),
    m_num_picks(0)
{

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
void modSkill::set_picks(int num_picks)
//
//D Set the number of picks of the skill
//
//-----------------------------------------------------------------------------
{
  m_num_picks = num_picks;
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

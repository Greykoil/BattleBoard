//=============================================================================
//D Class for the default skill model. 
//
// A default skill has traits of name, picks, cost etx
//
//-----------------------------------------------------------------------------
// includes from our libraries
#include "SkillLinear.h"

// system includes

//=============================================================================
SkillLinear::SkillLinear(
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
    m_status(a_status)
{

}

//=============================================================================
void SkillLinear::add_prerequeset(std::string name)
//
//D Add a prerequired skill to the list of existing prerequisites
//
//-----------------------------------------------------------------------------
{
  m_prerequisits.push_back(name);
}

//=============================================================================
std::string SkillLinear::name() const
//
//D Get the skill name
//
//-----------------------------------------------------------------------------
{
  return m_name;
}

//=============================================================================
int SkillLinear::cost_per_rank() const
//
//D Get the cost for the next rank of a skill
//
//-----------------------------------------------------------------------------
{
  return m_cost;
}

//=============================================================================
int SkillLinear::max_picks() const
//
//D Get the maximum number of allowed picks
//
//-----------------------------------------------------------------------------
{
  return m_max_picks;
}

//=============================================================================
bool SkillLinear::is_status() const
//
//D Does the skill cost status
//
//-----------------------------------------------------------------------------
{
  return false;
}

//=============================================================================
SkillLinear::~SkillLinear()
//
//D Default Destructor
//
//-----------------------------------------------------------------------------
{

}


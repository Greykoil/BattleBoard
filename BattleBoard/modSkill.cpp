//=============================================================================
//D Class for the default skill model. 
//
// A default skill has traits of name, picks, cost etx
//
//-----------------------------------------------------------------------------
// includes from our libraries
#include "modSkill.h"

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
    m_status(a_status)
{

}

//=============================================================================
void modSkill::add_prerequeset(std::string name)
//
//D Add a prerequired skill to the list of existing prerequisites
//
//-----------------------------------------------------------------------------
{
  m_prerequisits.push_back(name);
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
modSkill::~modSkill()
//
//D Default Destructor
//
//-----------------------------------------------------------------------------
{

}


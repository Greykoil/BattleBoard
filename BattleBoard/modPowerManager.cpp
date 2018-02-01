//=============================================================================
//D Helper class to look after the players power and power related skills
//
//-----------------------------------------------------------------------------

// Class header include
#include "modPowerManager.h"

// includes from project
#include "modSkill.h"
// standard library includes
#include <assert.h>

//=============================================================================
modPowerManager::modPowerManager()
//
//-----------------------------------------------------------------------------
{

}

//=============================================================================
void modPowerManager::set_power_picks(modSkill * skill)
//
//-----------------------------------------------------------------------------
{
  assert(skill);
  m_power_picks = skill;
}

//=============================================================================
int modPowerManager::total_power() const
//
//-----------------------------------------------------------------------------
{
  return m_power_picks->num_picks() + 5;
}

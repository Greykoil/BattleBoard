//=============================================================================
//D Class to manage the characters ACs, including Dex, worn armour etc
//
//-----------------------------------------------------------------------------

// Class header include
#include "modArmourManager.h"
#include "modSkill.h"
// includes from project

// standard library includes
#include <memory>
#include <algorithm>
//=============================================================================
modArmourManager::modArmourManager()
//
//-----------------------------------------------------------------------------
{

}

//=============================================================================
int modArmourManager::pure_physical() const
//
//D 
//
//-----------------------------------------------------------------------------
{
  int total = 0;
  for (const std::unique_ptr<modArmourSource>& source : m_armour_sources) {
    total += source->get_physical();
  }
  for (modSkill* mastery : m_mastery_skills) {
    total += mastery->num_picks();
  }
  return total;
}

//=============================================================================
int modArmourManager::dex_physical() const
//
//D
//
//-----------------------------------------------------------------------------
{
  int non_dex = pure_physical() + m_armoured_dex->num_picks();
  return std::max(non_dex, m_unarmoured_dex->num_picks());
}

//=============================================================================
int modArmourManager::pure_power() const
//
//D
//
//-----------------------------------------------------------------------------
{
  int total = 0;
  for (const std::unique_ptr<modArmourSource>& source : m_armour_sources) {
    total += source->get_power();
  }
  return total;
}

//=============================================================================
int modArmourManager::dex_power() const
//
//D
//
//-----------------------------------------------------------------------------
{
  int non_dex = pure_power() + m_armoured_dex->num_picks();
  return std::max(non_dex, m_unarmoured_dex->num_picks());
}

//=============================================================================
int modArmourManager::pure_magic() const
//
//D
//
//-----------------------------------------------------------------------------
{
  int total = 0;
  for (const std::unique_ptr<modArmourSource>& source : m_armour_sources) {
    total += source->get_magic();
  }
  return total;
}

//=============================================================================
int modArmourManager::dex_magic() const
//
//D
//
//-----------------------------------------------------------------------------
{
  int non_dex = pure_magic () + m_armoured_dex->num_picks();
  return std::max(non_dex, m_unarmoured_dex->num_picks());
}

//=============================================================================
int modArmourManager::dex() const
//
//D In theory this could return the wrong number if the character has both 
//  armoured and unarmoured dex
//
//-----------------------------------------------------------------------------
{
  int base = std::max(m_armoured_dex->num_picks(), m_unarmoured_dex->num_picks());

  for (const std::unique_ptr<modArmourSource>& source : m_armour_sources) {
    base += source->get_dex();
  }
  return base;
}


//=============================================================================
int modArmourManager::evil() const
//
//-----------------------------------------------------------------------------
{
  int total = 0;
  for (const std::unique_ptr<modArmourSource>& source : m_armour_sources) {
    total += source->get_evil();
  }
  return total;
}

//=============================================================================
int modArmourManager::undead() const
//
//-----------------------------------------------------------------------------
{
  int total = 0;
  for (const std::unique_ptr<modArmourSource>& source : m_armour_sources) {
    total += source->get_evil();
  }
  return total;
}

//=============================================================================
void modArmourManager::add_mastery_skill(modSkill * skill)
//
//D
//
//-----------------------------------------------------------------------------
{
  m_mastery_skills.push_back(skill);
}

//=============================================================================
void modArmourManager::add_armoured_dex(modSkill* dex)
//
//-----------------------------------------------------------------------------
{
  m_armoured_dex = dex;
}

//=============================================================================
void modArmourManager::add_unarmoured_dex(modSkill* ua_dex)
//
//-----------------------------------------------------------------------------
{
  m_unarmoured_dex = ua_dex;
}

//=============================================================================
modArmourSource * modArmourManager::add_armour_source()
//
//D
//
//-----------------------------------------------------------------------------
{
  m_armour_sources.push_back(std::make_unique<modArmourSource>());
  return m_armour_sources[m_armour_sources.size() - 1].get();
}

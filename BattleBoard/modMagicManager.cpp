//=============================================================================
//D A helper class to manage the characters magic.
//
//-----------------------------------------------------------------------------

// Class header include
#include "modMagicManager.h"

// includes from project

// standard library includes
#include <assert.h>


//=============================================================================
modMagicManager::modMagicManager()
//
//-----------------------------------------------------------------------------
{

}

//=============================================================================
int modMagicManager::total_mana() const
//
//D
//
//-----------------------------------------------------------------------------
{
  return 0;
}

//=============================================================================
int modMagicManager::slots_of_level(int level) const
//
//D
//
//-----------------------------------------------------------------------------
{
  return 0;
}

//=============================================================================
void modMagicManager::set_slot_level(modSkill * skill, int level)
//
//-----------------------------------------------------------------------------
{
  // This is a hideous assert to make sure that the spell levels correspond to thier
  // possition in the vector. It is simply to save time accessing the levels
  assert(level = m_magic_level_skills.size() + 1);

  m_magic_level_skills.push_back(skill);
}

//=============================================================================
modSkill * modMagicManager::spell_level(int level)
//
//-----------------------------------------------------------------------------
{
  return m_magic_level_skills[level - 1];
}

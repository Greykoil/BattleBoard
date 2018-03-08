//=============================================================================
//D 
//
//-----------------------------------------------------------------------------

// Class header include
#include "modAbilityManager.h"

// includes from project

// standard library includes


//=============================================================================
modAbilityManager::modAbilityManager()
//
//-----------------------------------------------------------------------------
{

}

//=============================================================================
modAbility* modAbilityManager::add_new_ability()
//
//-----------------------------------------------------------------------------
{
  m_ability_list.push_back(std::make_unique<modAbility>());
  return m_ability_list[m_ability_list.size() - 1].get();
}

int modAbilityManager::num_abilities() const
{
  return m_ability_list.size();
}

//=============================================================================
modAbility * modAbilityManager::ability(int i)
//
//-----------------------------------------------------------------------------
{
  return m_ability_list[i].get();
}

//=============================================================================
//D 
//
//-----------------------------------------------------------------------------
#pragma once

// includes from our libraries
#include "modAbility.h"
// system includes
#include <memory>
#include <vector>
// class predeclarations to avoid header file inclusion
class modAbility;


//=============================================================================
class modAbilityManager
{
public:
  modAbilityManager();
  // Constructor

  modAbility* add_new_ability();
  // Add a new ability to the list
  // return ptr to it

  int num_abilities() const;

  modAbility* ability(int i);


  modAbilityManager(const modAbilityManager&) = delete;
  // Deleted copy constructor.

  modAbilityManager& operator=(const modAbilityManager&) = delete;
  // Deleted assignment operator.

  virtual ~modAbilityManager() = default;
  // Destructor

private:
  std::vector<std::unique_ptr<modAbility>> m_ability_list;


};


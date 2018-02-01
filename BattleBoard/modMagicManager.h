//=============================================================================
//D A helper class to manage the characters magic.
//
//-----------------------------------------------------------------------------
#pragma once

// includes from our libraries

// system includes
#include <vector>
// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs
class modSkill;

//=============================================================================
class modMagicManager
{
public:
  modMagicManager();
  // Constructor

  int total_mana() const;
  // Return the total mana that the character has taken.

  int slots_of_level(int level) const;
  // Return the number of slots available in a certain level

  void set_slot_level(modSkill* skill, int level);

  modSkill* spell_level(int level);

  modMagicManager(const modMagicManager&) = delete;
  // Deleted copy constructor.

  modMagicManager& operator=(const modMagicManager&) = delete;
  // Deleted assignment operator.

  virtual ~modMagicManager() = default;
  // Destructor

private:

  std::vector<modSkill*> m_magic_level_skills;



};


//=============================================================================
//D Class to manage the characters ACs, including Dex, worn armour etc
//
//-----------------------------------------------------------------------------
#pragma once

// includes from our libraries
#include "modArmourSource.h"
// system includes
#include <vector>
#include <memory>
// class predeclarations to avoid header file inclusion
class modSkill;

//=============================================================================
class modArmourManager
{
public:
  modArmourManager();
  // Constructor

  int pure_physical() const;
  int dex_physical() const;
  int pure_power() const;
  int dex_power() const;
  int pure_magic() const;
  int dex_magic() const;
  int dex() const;
  int evil() const;
  int undead() const;

  void add_mastery_skill(modSkill* skill);
  // Add a skill to the list of masteries. 

  void add_armoured_dex(modSkill* dex);

  void add_unarmoured_dex(modSkill* ua_dex);

  modArmourSource* add_armour_source();
  // Add a source of armour and return a ptr to it
  // This class maintains ownership of the armour source

  modArmourManager(const modArmourManager&) = delete;
  // Deleted copy constructor.

  modArmourManager& operator=(const modArmourManager&) = delete;
  // Deleted assignment operator.

  virtual ~modArmourManager() = default;
  // Destructor

private:
  
  std::vector<modSkill*> m_mastery_skills;

  modSkill* m_armoured_dex;

  modSkill* m_unarmoured_dex;

  std::vector<std::unique_ptr<modArmourSource>> m_armour_sources;
};


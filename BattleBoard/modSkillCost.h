//=============================================================================
//D Helper class to store and return the cost of skills for a given race/class
//
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries
#include "modCharacterDetailsEnum.h"
#include "modRaceCost.h"
// system includes
#include <vector>
#include <memory>
// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs
class modCharacterDetails;

//=============================================================================
class modSkillCost {
public:

  modSkillCost(
    std::unique_ptr<modRaceCost> human_costs,
    std::unique_ptr<modRaceCost> elf_costs,
    std::unique_ptr<modRaceCost> halforc_costs,
    modCharacterDetails* character_details
  );
  // Constructor
  
  int cost_for(CHARACTER_CLASS, CHARACTER_RACE);
  // Return the correct cost for a given character race and class

  int cost_for_details();
  // Return the correct cost for the current character details

  modSkillCost(const modSkillCost&) = delete;
  // Deleted copy constructor.

  modSkillCost& operator=(const modSkillCost&) = delete;
  // Deleted assignment operator.

  ~modSkillCost() = default;
  // Default Destructor

protected:

  // functions
  // variables

private:

  // friends
  // functions
  // variables
  std::unique_ptr<modRaceCost> m_human_costs;
  std::unique_ptr<modRaceCost> m_elf_costs;
  std::unique_ptr<modRaceCost> m_halforc_costs;

  modCharacterDetails* m_character_details;
};

//=============================================================================
//D Helper class to store and return the cost of skills for a given race/class
//
//-----------------------------------------------------------------------------
// Class Header include
#include "modSkillCost.h"
// Includes from our libraries
#include "modCharacterDetails.h"

// system includes
#include <assert.h>

//=============================================================================
modSkillCost::modSkillCost(
  std::unique_ptr<modRaceCost> human_costs,
  std::unique_ptr<modRaceCost> elf_costs,
  std::unique_ptr<modRaceCost> halforc_costs,
  modCharacterDetails* character_details
)
//
//
//-----------------------------------------------------------------------------
: m_human_costs(std::move(human_costs)),
  m_elf_costs(std::move(elf_costs)),
  m_halforc_costs(std::move(halforc_costs)),
  m_character_details(character_details)
{

}

//=============================================================================
int modSkillCost::cost_for(
  CHARACTER_CLASS character_class, 
  CHARACTER_RACE race
)
//
//-----------------------------------------------------------------------------
{
  switch (race)
  {
  case HUMAN:
    return m_human_costs->cost_for_class(character_class);
  case HALF_ORC:
    return m_halforc_costs->cost_for_class(character_class);
  case ELF:
    return m_elf_costs->cost_for_class(character_class);
  default:
    // Unknown enum
    assert(1 == 0);
    break;
  }
  return 0;
}

//=============================================================================
int modSkillCost::cost_for_details()
//
//D
//
//-----------------------------------------------------------------------------
{
  return cost_for(
    m_character_details->get_character_class(),
    m_character_details->get_character_race()
  );
}

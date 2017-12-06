//=============================================================================
//D Class for the current state of the character 
//
//  Manages skills, adventure record
//
// TO DO: Expand the class to include items, armour, hq abilities
//-----------------------------------------------------------------------------
// includes from our libraries
#include "modCharacter.h"
#include "modAdventureRecordManager.h"
#include "modSkillManager.h"

// system includes
#include <assert.h>

//=============================================================================
modCharacter::modCharacter(
  CHARACTER::RACE race,
  CHARACTER::CLASS char_class
)
//
// Default constructor
//
//-----------------------------------------------------------------------------
  : m_race(race),
    m_class(char_class),
    m_skill_manager(),
    m_adventure_record_manager()
{
  m_skill_manager.create_skill_tree();
}

//=============================================================================
int modCharacter::get_available_points() const
//
//D Get the number of points a character has available to spend
//
//-----------------------------------------------------------------------------
{
  return m_adventure_record_manager.get_total_points();
}

//=============================================================================
modSkillManager* modCharacter::get_skill_page_manager()
//
//D Return m_skill_manager
//
//-----------------------------------------------------------------------------
{
  return &m_skill_manager;
}

//=============================================================================
modAdventureRecordManager* modCharacter::get_adventure_record_manager()
//
//D Return m_adventure_record_manager
//
//-----------------------------------------------------------------------------
{
  return &m_adventure_record_manager;
}

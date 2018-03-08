//=============================================================================
//D 
//
//-----------------------------------------------------------------------------

// Class header include
#include "modAbility.h"

// includes from project

// standard library includes


//=============================================================================
modAbility::modAbility()
//
//-----------------------------------------------------------------------------
: m_name(""),
  m_uses(0),
  m_frequency(PER_SECTIONAL)
{

}

std::string modAbility::get_name() const
{
  return m_name;
}

void modAbility::set_name(std::string value)
{
  m_name = value;
}

ABILITY_FREQUENCY modAbility::get_frequency() const
{
  return m_frequency;
}

void modAbility::set_frequency(ABILITY_FREQUENCY value)
{
  m_frequency = value;
}

int modAbility::get_uses() const
{
  return m_uses;
}

void modAbility::set_uses(int value)
{
  m_uses = value;
}

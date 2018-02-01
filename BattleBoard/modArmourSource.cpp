//=============================================================================
//D A class to track any given source of armour the character has
//
//-----------------------------------------------------------------------------

// Class header include
#include "modArmourSource.h"

// includes from project

// standard library includes


//=============================================================================
modArmourSource::modArmourSource()
//
//-----------------------------------------------------------------------------
  : m_name(""),
    m_physical(0),
    m_power(0),
    m_magic(0),
    m_evil(0),
    m_undead(0),
    m_dexterity(0)
{

}

void modArmourSource::set_name(std::string name)
{
  m_name = name;
}

int modArmourSource::get_physical() const
{
  return m_physical;
}

void modArmourSource::set_physical(int value)
{
  m_physical = value;
}

int modArmourSource::get_power() const
{
  return m_power;
}

void modArmourSource::set_power(int value)
{
  m_power = value;
}

int modArmourSource::get_magic() const
{
  return m_magic;
}

void modArmourSource::set_magic(int value)
{
  m_magic = value;
}

int modArmourSource::get_evil() const
{
  return m_evil;
}

void modArmourSource::set_evil(int value)
{
  m_evil = value;
}

int modArmourSource::get_undead() const
{
  return m_undead;
}

void modArmourSource::set_undead(int value)
{
  m_undead = value;
}

int modArmourSource::get_dex() const
{
  return m_dexterity;
}

void modArmourSource::set_dex(int value)
{
  m_dexterity = value;
}

//=============================================================================
//D <One line description>
//
// <Full description.>
//
//-----------------------------------------------------------------------------
// includes from our libraries
#include "modAdventureRecord.h"

// system includes

//=============================================================================
modAdventureRecord::modAdventureRecord(
  ADVENTURERECORD::LENGTH length,
  ADVENTURERECORD::TYPE type
)
//
// Constructor
//
//-----------------------------------------------------------------------------
  : m_type(type),
    m_length(length)
{

}

//=============================================================================
void modAdventureRecord::set_type(ADVENTURERECORD::TYPE type)
//
//D
//
//-----------------------------------------------------------------------------
{
  m_type = type;
  update_points();
}

//=============================================================================
void modAdventureRecord::set_length(ADVENTURERECORD::LENGTH length)
//
//D
//
//-----------------------------------------------------------------------------
{
  m_length = length;
  update_points();
}

//=============================================================================
int modAdventureRecord::get_points() const
//
//D get m_points
//
//-----------------------------------------------------------------------------
{
  return m_points;
}

//=============================================================================
void modAdventureRecord::set_points(int points)
//
//D
//
//-----------------------------------------------------------------------------
{
  m_points = points;
}

//=============================================================================
void modAdventureRecord::update_points()
//
//D Update the points to default value
//
//-----------------------------------------------------------------------------
{
  // We don't have default values for unknown adventure type or length
  if (m_length == ADVENTURERECORD::LENGTH::OTHER ||
      m_type == ADVENTURERECORD::TYPE::UNKNOWN) {
    return;
  }

}

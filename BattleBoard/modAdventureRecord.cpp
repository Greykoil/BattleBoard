//=============================================================================
//D <One line description>
//
// <Full description.>
//
//-----------------------------------------------------------------------------
// includes from our libraries
#include "modAdventureRecord.h"
#include "vieAdventureRecordWidget.h"
// system includes
#include <assert.h>

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
void modAdventureRecord::set_view(vieAdventureRecordWidget * view)
//
//D Set m_view
//
//-----------------------------------------------------------------------------
{
  assert(view != nullptr);
  m_view = view;
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
  int multiplier = 1;
  switch (m_type)
  {
    case ADVENTURERECORD::UNKNOWN:
      // We can't make any guess at the number of points
      return;
    case ADVENTURERECORD::MONSTERED:
      multiplier = 1;
      break;
    case ADVENTURERECORD::REFFED:
      multiplier = 2;
      break;
    case ADVENTURERECORD::PLAYED:
      multiplier = 2;
      break;
    default:
      multiplier = 2;
      break;
  }

  int default_points;
  switch (m_length)
  {
  case ADVENTURERECORD::OTHER:
    // We can't guess at the number of points
    return;
  case ADVENTURERECORD::ADVENTURE_WEEKEND:
    default_points = 25;
    break;
  case ADVENTURERECORD::SPECIAL:
    default_points = 35;
    break;
  case ADVENTURERECORD::HEROQUEST:
    default_points = 50;
    break;
  default:
    default_points = 0;
    break;
  }

  int m_points = default_points * multiplier;
  assert(m_view != nullptr);
  m_view->set_points(m_points);
}

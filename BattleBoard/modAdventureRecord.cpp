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
  ADVENTURE_RECORD_LENGTH length,
  ADVENTURE_RECORD_TYPE type
)
//
//-----------------------------------------------------------------------------
  : m_type(type),
    m_length(length),
    m_points(0)
{

}

//=============================================================================
tinyxml2::XMLElement * modAdventureRecord::convert_to_xml(
  tinyxml2::XMLDocument * parent
) const 
//
//D Turn the adventure record into an xml element
//
//-----------------------------------------------------------------------------
{
  tinyxml2::XMLElement* element = parent->NewElement("Adventure");
  element->SetAttribute("Type", m_type);
  element->SetAttribute("Length", m_length);
  element->SetAttribute("Points", m_points);
  return element;
}

//=============================================================================
void modAdventureRecord::load_from_xml(tinyxml2::XMLElement * element)
//
//D Load the adventure details from the xml file
//
//-----------------------------------------------------------------------------
{
  int type;
  element->QueryIntAttribute("Type", &type);
  m_type = static_cast<ADVENTURE_RECORD_TYPE>(type);
  int length;
  element->QueryIntAttribute("Length", &length);
  m_length = static_cast<ADVENTURE_RECORD_LENGTH>(length);
  element->QueryIntAttribute("Points", &m_points);
}

//=============================================================================
void modAdventureRecord::set_view(vieAdventureRecordWidget* view)
//
//-----------------------------------------------------------------------------
{
  assert(view != nullptr);
  m_view = view;
}

//=============================================================================
void modAdventureRecord::set_type(ADVENTURE_RECORD_TYPE type)
//
//D set m_type and update the points to the correct points for this type
//
//-----------------------------------------------------------------------------
{
  m_type = type;
  update_points();
}

//=============================================================================
ADVENTURE_RECORD_TYPE modAdventureRecord::get_type() const
//
//-----------------------------------------------------------------------------
{
  return m_type;
}

//=============================================================================
ADVENTURE_RECORD_LENGTH modAdventureRecord::get_length() const
//
//-----------------------------------------------------------------------------
{
  return m_length;
}

//=============================================================================
void modAdventureRecord::set_length(ADVENTURE_RECORD_LENGTH length)
//
//D Set m_length and update the points to the correct points for the new length
//
//-----------------------------------------------------------------------------
{
  m_length = length;
  update_points();
}

//=============================================================================
int modAdventureRecord::get_points() const
//
//-----------------------------------------------------------------------------
{
  return m_points;
}

//=============================================================================
void modAdventureRecord::set_points(int points)
//
//-----------------------------------------------------------------------------
{
  m_points = points;
}

//=============================================================================
void modAdventureRecord::update_points()
//
//D Update the points to default value for the type length combo
//
//-----------------------------------------------------------------------------
{
  int multiplier = 1;
  switch (m_type)
  {
    case ADVENTURE_RECORD_TYPE::OTHER_TYPE:
      // We can't make any guess at the number of points
      return;
    case ADVENTURE_RECORD_TYPE::MONSTERED:
      multiplier = 1;
      break;
    case ADVENTURE_RECORD_TYPE::REFFED:
      multiplier = 2;
      break;
    case ADVENTURE_RECORD_TYPE::PLAYED:
      multiplier = 2;
      break;
    default:
      // Unknown type
      assert(1 == 0);
      break;
  }

  int default_points;
  switch (m_length)
  {
  case ADVENTURE_RECORD_LENGTH::OTHER_LENGTH:
    // We can't guess at the number of points
    return;
  case ADVENTURE_RECORD_LENGTH::ADVENTURE_WEEKEND:
    default_points = 25;
    break;
  case ADVENTURE_RECORD_LENGTH::SPECIAL:
    default_points = 35;
    break;
  case ADVENTURE_RECORD_LENGTH::HEROQUEST:
    default_points = 50;
    break;
  default:
    // Unknown type
    assert(1 == 0);
    default_points = 0;
    break;
  }

  int m_points = default_points * multiplier;
  assert(m_view != nullptr);
  m_view->set_points(m_points);
}

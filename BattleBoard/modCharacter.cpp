//=============================================================================
//D Class for the current state of the character 
//
//  Manages skills, adventure record
//
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
//-----------------------------------------------------------------------------
{
  return &m_skill_manager;
}

//=============================================================================
modAdventureRecordManager* modCharacter::get_adventure_record_manager()
//
//-----------------------------------------------------------------------------
{
  return &m_adventure_record_manager;
}

//=============================================================================
tinyxml2::XMLElement * modCharacter::convert_to_xml(
  tinyxml2::XMLDocument* parent
) const
//
//D Convert the state of the character into an xml node so that it can be 
//  saved.
//
//-----------------------------------------------------------------------------
{
  tinyxml2::XMLElement* root = parent->NewElement("Root");
  tinyxml2::XMLElement* character = parent->NewElement("Character");
  root->InsertEndChild(character);

  tinyxml2::XMLElement* skills = m_skill_manager.convert_to_xml(parent);
  tinyxml2::XMLElement* adventure_record = m_adventure_record_manager.convert_to_xml(parent);
  character->InsertFirstChild(skills);
  character->InsertEndChild(adventure_record);
  return character;
}

//=============================================================================
void modCharacter::load_from_xml(tinyxml2::XMLElement * element)
//
//D Load the state of the character from an xml node.
//
//-----------------------------------------------------------------------------
{
  tinyxml2::XMLElement* skill_list = element->FirstChildElement("Skills_List");
  m_skill_manager.load_from_xml(skill_list);
  tinyxml2::XMLElement* adventure_list = element->FirstChildElement("Adventure_List");
  m_adventure_record_manager.load_from_xml(adventure_list);
}

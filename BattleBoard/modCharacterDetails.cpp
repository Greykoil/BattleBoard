//=============================================================================
//D Class to track the high level character details like race and class
//
//-----------------------------------------------------------------------------
// Class Header include
#include "modCharacterDetails.h"
// Includes from our libraries

// system includes

//=============================================================================
modCharacterDetails::modCharacterDetails()
//
//-----------------------------------------------------------------------------
: m_character_class(WARRIOR),
  m_character_race(HUMAN),
  m_character_name(""),
  m_character_alignment(NEUTRAL),
  m_character_guild(OTHER)
{

}

//=============================================================================
void modCharacterDetails::set_character_alignment(CHARACTER_ALIGNMENT alignment)
//
//-----------------------------------------------------------------------------
{
  m_character_alignment = alignment;
}

//=============================================================================
void modCharacterDetails::set_character_guild(CHARACTER_GUILD guild)
//
//-----------------------------------------------------------------------------
{
  m_character_guild = guild;
}

//=============================================================================
void modCharacterDetails::set_character_name(std::string name)
//
//-----------------------------------------------------------------------------
{
  m_character_name = name;
}

//=============================================================================
void modCharacterDetails::set_character_race(CHARACTER_RACE race)
//
//-----------------------------------------------------------------------------
{
  m_character_race = race;
}

//=============================================================================
void modCharacterDetails::set_character_class(CHARACTER_CLASS character_class)
//
//-----------------------------------------------------------------------------
{
  m_character_class = character_class;
}

//=============================================================================
CHARACTER_CLASS modCharacterDetails::get_character_class() const
//
//-----------------------------------------------------------------------------
{
  return m_character_class;
}

//=============================================================================
CHARACTER_RACE modCharacterDetails::get_character_race() const
//
//-----------------------------------------------------------------------------
{
  return m_character_race;
}

//=============================================================================
tinyxml2::XMLElement * modCharacterDetails::convert_to_xml(tinyxml2::XMLDocument * parent) const
//
//D Load the character details into an xml node
//
//-----------------------------------------------------------------------------
{
  tinyxml2::XMLElement* element = parent->NewElement("CharacterDetails");
  element->SetAttribute("Name", m_character_name.c_str());
  element->SetAttribute("Race", m_character_race);
  element->SetAttribute("Class", m_character_class);
  return element;
}

//=============================================================================
void modCharacterDetails::load_from_xml(tinyxml2::XMLElement * element)
//
//D Load the character details from an xml node
//
//-----------------------------------------------------------------------------
{
  int character_class;
  element->QueryIntAttribute("Class", &character_class);
  m_character_class = static_cast<CHARACTER_CLASS>(character_class);
  int race;
  element->QueryIntAttribute("Length", &race);
  m_character_race = static_cast<CHARACTER_RACE>(race);
  const char* result = element->Attribute("Name");
  m_character_name = result;
}



//=============================================================================
//D Class to track the high level character details like race and class
//
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries
#include "modState.h"
#include "modCharacterDetailsEnum.h"
// system includes
#include <string>
// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs


//=============================================================================
class modCharacterDetails : public modState {
public:

  modCharacterDetails();
  // Constructor

  void set_character_alignment(CHARACTER_ALIGNMENT);
  // Set m_character alignment

  void set_character_guild(CHARACTER_GUILD);
  // Set m_character guild

  void set_character_name(std::string name);
  // Set m_character_name

  void set_character_race(CHARACTER_RACE);
  // Set m_character_race

  void set_character_class(CHARACTER_CLASS);
  // Set m_character_class

  CHARACTER_CLASS get_character_class() const;
  // Return m_character_class

  CHARACTER_RACE get_character_race() const;
  // Return m_character_race

  virtual tinyxml2::XMLElement* convert_to_xml(tinyxml2::XMLDocument* parent) const override;
  // Convert the state into an xml element

  virtual void load_from_xml(tinyxml2::XMLElement* element) override;
  // Load the state from an xml element

  modCharacterDetails(const modCharacterDetails&) = delete;
  // Deleted copy constructor.

  modCharacterDetails& operator=(const modCharacterDetails&) = delete;
  // Deleted assignment operator.

  ~modCharacterDetails() = default;
  // Default Destructor

protected:

  // functions
  // variables

private:

  // friends
  // functions
  // variables
  CHARACTER_RACE m_character_race;
  
  CHARACTER_CLASS m_character_class;

  CHARACTER_GUILD m_character_guild;

  CHARACTER_ALIGNMENT m_character_alignment;
  
  std::string m_character_name;
};

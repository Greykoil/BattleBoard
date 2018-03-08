//=============================================================================
//D Class for the current state of the character 
//
//  Manages skills, adventure record
//
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries
#include "modState.h"
#include "modSkillManager.h"
#include "modAdventureRecordManager.h"
#include "modCharacterDetails.h"
#include "modAbilityManager.h"
// system includes

// class predeclarations to avoid header file inclusion
class vwmCharacter;
class vwmAdventureRecordManager;

// types: classes, enums, typedefs

//=============================================================================
class modCharacter : public modState {
public:

  modCharacter();
  // Constructor

  int get_available_points() const;
  // Get the number of points the character has to spend

  modSkillManager* get_skill_page_manager();
  // Return m_skill_manager;

  modAdventureRecordManager* get_adventure_record_manager();
  // Return m_adventure_record_manger

  modCharacterDetails* get_character_details();
  // Return m_character_details

  modMagicManager* get_magic_manager();

  modPowerManager* get_power_manager();

  modArmourManager* get_armour_manager();

  modAbilityManager* get_ability_manager();

  void read_state(std::string file_name);
  // read the xml file and turn it into a character state

  void write_state(std::string file_name);
  // Write out the character state to the given file

  virtual tinyxml2::XMLElement* convert_to_xml(tinyxml2::XMLDocument* parent) const override;
  // Convert the state into an xml element

  virtual void load_from_xml(tinyxml2::XMLElement* element) override;
  // Load the state from an xml element

  modCharacter(const modCharacter&) = delete;
  // Deleted copy constructor.

  modCharacter& operator=(const modCharacter&) = delete;
  // Deleted assignment operator.

  ~modCharacter() = default;
  // Destructor

protected:

  // functions
  // variables

private:

  // friends
  // functions
  // variables
  modCharacterDetails m_character_details;

  modSkillManager m_skill_manager;

  modAdventureRecordManager m_adventure_record_manager;

  modArmourManager m_armour_manager;

  modAbilityManager m_ability_manager;
};

//=============================================================================
//D Class for the current state of the character 
//
//  Manages skills, adventure record
//
// TO DO: Expand the class to include items, armour, hq abilities
// 
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries
#include "modSkillManager.h"
#include "modAdventureRecordManager.h"
// system includes

// class predeclarations to avoid header file inclusion
class vwmCharacter;
class vwmAdventureRecordManager;
class vwmSkillPage;

// types: classes, enums, typedefs
namespace CHARACTER {
  enum RACE {
    HUMAN,
    HALF_ORC,
    ELF
  };
  enum CLASS {
    WARRIOR,
    MAGE,
    PRIEST,
    SCOUT
  };
};

//=============================================================================
class modCharacter {
public:

  modCharacter(
    CHARACTER::RACE race,
    CHARACTER::CLASS char_class
  );
  // Constructor

  int get_available_points() const;
  // Get the number of points the character has to spend

  modSkillManager* get_skill_page_manager();
  // Return m_skill_manager;

  modAdventureRecordManager* get_adventure_record_manager();
  // Return m_adventure_record_manger

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
  modSkillManager m_skill_manager;

  modAdventureRecordManager m_adventure_record_manager;

  CHARACTER::RACE m_race;

  CHARACTER::CLASS m_class;

};
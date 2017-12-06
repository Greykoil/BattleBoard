//=============================================================================
//D View model for the overall character
//
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries
#include "vwmSkillPage.h"
// system includes

// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs
class modCharacter;
class vieCharacterWindow;
class vieMainWindow;

//=============================================================================
class vwmCharacter {
public:

  vwmCharacter(
    modCharacter* model_character
  );
  // Constructor
  
  modCharacter* get_character_model() { return m_model_character; }

  void update();
  // Update the display of stuff

  void set_main_window(
    vieMainWindow* view
  );
  // set m_view

  void set_character_window(
    vieCharacterWindow* window
  );

  std::string points_text();
  // Return the text informaiton about character points

  std::string skills_text();
  // Return the text informaiton about character skills

  vwmSkillPage* get_skill_view_model();
  // Return m_skill_page_manager

//  vwmAdventureRecordManager* get_adventure_record_view_model();
  // Return m_adventure_record_manager

  vwmCharacter(const vwmCharacter&) = delete;
  // Deleted copy constructor.

  vwmCharacter& operator=(const vwmCharacter&) = delete;
  // Deleted assignment operator.

  ~vwmCharacter() = default;
  // Default Destructor

protected:

  // functions
  // variables

private:

  // friends
  // functions
  // variables
  modCharacter* m_model_character;

  vieMainWindow* m_main_window;

  vieCharacterWindow* m_view_character;

  // Some classes for this to manage the lifetime of
  vwmSkillPage m_skill_page_manager;
//  vwmAdventureRecordManager m_adventure_record_manager;

};

//=============================================================================
//D View model for the overall character
//
//-----------------------------------------------------------------------------
// Header class include 
#include "vwmCharacter.h"
#include "vieCharacterWindow.h"
#include "vieMainWindow.h"
#include "modCharacter.h"
#include "vwmSkill.h"
// Inlcludes frm this library

// system includes
#include <assert.h>
//=============================================================================
vwmCharacter::vwmCharacter(
  modCharacter* model_character
)
//
// Constructor
//
//-----------------------------------------------------------------------------
  : m_model_character(model_character),
    m_skill_page_manager(model_character->get_skill_page_manager(), this)
{
  assert(model_character != nullptr);
}

//=============================================================================
void vwmCharacter::update()
//
//D Update the display of character information
//
//-----------------------------------------------------------------------------
{
  m_view_character->update();
}

//=========================================================0====================
void vwmCharacter::set_main_window(vieMainWindow * view)
//
//D
//
//-----------------------------------------------------------------------------
{
  m_main_window = view;
}

//=============================================================================
void vwmCharacter::set_character_window(vieCharacterWindow* window)
//
//D
//
//-----------------------------------------------------------------------------
{
  m_view_character = window;
}

//=============================================================================
std::string vwmCharacter::points_text()
//
//D
//
//-----------------------------------------------------------------------------
{

  return std::string("The character has some points text");
}

//=============================================================================
std::string vwmCharacter::skills_text()
//
//D
//
//-----------------------------------------------------------------------------
{
  std::string output = "The character has the following skills \r\n";
  for (int i = 0; i < m_skill_page_manager.num_skills(); ++i) {
    vwmSkill* skill = m_skill_page_manager.skill(i);
    int ranks = skill->num_picks();
    std::string name = skill->name();
    std::string details = std::to_string(ranks);
    details += " ranks of " + name + "\r\n";
    output += details;
  }
  return output;
}

//=============================================================================
vwmSkillPage* vwmCharacter::get_skill_view_model()
//
//D return m_skill_page_manager
//
//-----------------------------------------------------------------------------
{
  return &m_skill_page_manager;
}

//=============================================================================
//D The window that tracks the character race, class and other misc details
//
//-----------------------------------------------------------------------------

// Class header include
#include "vieCharacterDetailsWindow.h"

// includes from project
#include "modCharacterDetails.h"
//includes from QT

//System includes
#include <assert.h>

//=============================================================================
vieCharacterDetailsWindow::vieCharacterDetailsWindow(
  modCharacterDetails* model,
  QWidget* parent
)
//
//
//-----------------------------------------------------------------------------
  : QDialog(parent),
    m_model(model)
{
  assert(model != nullptr);
  m_ui.setupUi(this);
}


//=============================================================================
void vieCharacterDetailsWindow::actionCharacterNameChanged(QString race)
//
//-----------------------------------------------------------------------------
{
  m_model->set_character_name(race.toStdString());
}

//=============================================================================
void vieCharacterDetailsWindow::actionCharacterRaceChanged(QString race)
//
//-----------------------------------------------------------------------------
{
  CHARACTER_RACE character_race = HUMAN;
  if (race == "Human") {
    character_race = HUMAN;
  } else if (race == "Elf") {
    character_race = ELF;
  } else if (race == "Half-Orc") {
    character_race = HALF_ORC;
  } else {
    // Somehow set to unknown race assert so we know something has gone wrong
    assert(1 ==0);
  }
  m_model->set_character_race(character_race);
}

//=============================================================================
void vieCharacterDetailsWindow::actionCharacterClassChanged(QString character_class)
//
//-----------------------------------------------------------------------------
{
  CHARACTER_CLASS model_class = ACOLYTE;
  if (character_class == "Acolyte") {
    model_class = ACOLYTE;
  } else if (character_class == "Mage") {
    model_class = MAGE;
  } else if (character_class == "Warrior") {
    model_class = WARRIOR;
  } else if (character_class == "Scout") {
    model_class = SCOUT;
  }
  m_model->set_character_class(model_class);
}

//=============================================================================
void vieCharacterDetailsWindow::actionCharacterAlignmentChanged(QString alignment)
//
//-----------------------------------------------------------------------------
{
  CHARACTER_ALIGNMENT character_alignment = NEUTRAL;
  if (alignment == "Good") {
    alignment = GOOD;
  } else if (alignment == "Neutral") {
    alignment = NEUTRAL;
  } else if (alignment == "Evil") {
    alignment = EVIL;
  } else {
    // Unknown alignment somehow
    assert(1 == 0);
  }
  m_model->set_character_alignment(character_alignment);
}

//=============================================================================
void vieCharacterDetailsWindow::actionCharacterGuildChanged(QString guild)
//
//-----------------------------------------------------------------------------
{
  CHARACTER_GUILD character_guild = EnumConverter::string_to_guild(guild.toStdString());
  m_model->set_character_guild(character_guild);
}

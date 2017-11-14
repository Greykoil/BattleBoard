//=============================================================================
//
//D The view model interface between the skill view and the skill model
//
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries

// system includes
#include <memory>
// class predeclarations to avoid header file inclusion
class modSkill;
class vieSkillWidget;
// types: classes, enums, typedefs

//=============================================================================
class vwmSkill {
public:

  vwmSkill(
    modSkill* skill_model
  );
  // Constructor

  std::unique_ptr<vieSkillWidget> make_widget();
  // Make the widget for the corresponding skill

  vwmSkill(const vwmSkill&) = delete;
  // Deleted copy constructor.

  vwmSkill& operator=(const vwmSkill&) = delete;
  // Deleted assignment operator.

  ~vwmSkill();
  // Destructor

protected:

  // functions
  // variables

private:

  // friends
  // functions
  // variables
  modSkill* m_skill_model;
  vieSkillWidget* m_skill_view;
};

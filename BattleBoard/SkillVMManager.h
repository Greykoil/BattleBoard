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
class SkillLinear;
class SkillWidget;
// types: classes, enums, typedefs

//=============================================================================
class SkillVMManager {
public:

  SkillVMManager(
    SkillLinear* skill_model
  );
  // Constructor

  std::unique_ptr<SkillWidget> make_widget();
  // Make the widget for the corresponding skill

  SkillVMManager(const SkillVMManager&) = delete;
  // Deleted copy constructor.

  SkillVMManager& operator=(const SkillVMManager&) = delete;
  // Deleted assignment operator.

  ~SkillVMManager();
  // Destructor

protected:

  // functions
  // variables

private:

  // friends
  // functions
  // variables
  SkillLinear* m_skill_model;
  SkillWidget* m_skill_view;
};

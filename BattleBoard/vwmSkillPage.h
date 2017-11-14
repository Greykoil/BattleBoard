//=============================================================================
//D The view model manager for interfacing the view skill page and the 
//  model list of skills
//
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries
#include "modSkillManager.h"
// system includes
#include <vector>
#include <memory>
// class predeclarations to avoid header file inclusion
class vwmSkill;
class vieSkillWidget;
// types: classes, enums, typedefs

//=============================================================================
class vwmSkillPage {
public:

  vwmSkillPage();
  // Constructor

  void initial_skill_list(std::vector<std::unique_ptr<vieSkillWidget>>& vector);
  // Construct the initial list of visable skill widgets

  vwmSkillPage(const vwmSkillPage&) = delete;
  // Deleted copy constructor.

  vwmSkillPage& operator=(const vwmSkillPage&) = delete;
  // Deleted assignment operator.

  ~vwmSkillPage();
  // Destructor

protected:

  // functions
  // variables

private:

  // friends
  // functions
  // variables
  
  //  ais::debug::<nnnn>
  // Move this to somewhere more sensible
  // ais::end::debug::<nnnn>
  modSkillManager m_creator;
  // The class resposible for reading the full skill list


  std::vector<std::unique_ptr<vwmSkill>> m_skills;
  // The list of individual View model managers for each skill
};

//=============================================================================
//D The view model manager for interfacing the view skill page and the 
//  model list of skills
//
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries
#include "SkillTreeCreator.h"
// system includes
#include <vector>
#include <memory>
// class predeclarations to avoid header file inclusion
class SkillVMManager;
class SkillWidget;
// types: classes, enums, typedefs

//=============================================================================
class SkillPageVMManager {
public:

  SkillPageVMManager();
  // Constructor

  void initial_skill_list(std::vector<std::unique_ptr<SkillWidget>>& vector);
  // Construct the initial list of visable skill widgets

  SkillPageVMManager(const SkillPageVMManager&) = delete;
  // Deleted copy constructor.

  SkillPageVMManager& operator=(const SkillPageVMManager&) = delete;
  // Deleted assignment operator.

  ~SkillPageVMManager();
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
  SkillTreeCreator m_creator;
  // The class resposible for reading the full skill list


  std::vector<std::unique_ptr<SkillVMManager>> m_skills;
  // The list of individual View model managers for each skill
};

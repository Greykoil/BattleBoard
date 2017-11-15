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
class modSkillManager;
class vwmCharacter;
class vieSkillWindow;
// types: classes, enums, typedefs

//=============================================================================
class vwmSkillPage {
public:

  vwmSkillPage(
    modSkillManager* model_skill_page,
    vwmCharacter* parent
  );
  // Constructor

  void full_skill_list(std::vector<std::unique_ptr<vieSkillWidget>>& vector);
  // Construct the initial list of visable skill widgets

  int num_skills();
  // The number of skills

  vwmSkill* skill(int n);
  // Get the n'th skill

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
  
  modSkillManager* m_model_skill_page;

  vieSkillWindow* m_view;

  std::vector<std::unique_ptr<vwmSkill>> m_skills;
  // The list of individual View model managers for each skill

  vwmCharacter* m_parent;
};

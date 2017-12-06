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
class vwmSkillPage;
// types: classes, enums, typedefs
#include <string>
//=============================================================================
class vwmSkill {
public:

  vwmSkill(
    modSkill* skill_model,
    vwmSkillPage* parent
  );
  // Constructor


  void set_view_skill(vieSkillWidget* skill);
  // Set m_view_skill

  bool is_visable();
  // Return true if the skill can be chosen by the user

  std::unique_ptr<vieSkillWidget> make_widget();
  // Make the widget for the corresponding skill

  bool change_num_picks(int num_picks);
  // The user has changed the number of picks of an available skill
  // Update everthing that needs it

  int num_picks();
  // Return m_num_picks

  int total_cost(); 
  // The total cost for the num picks of the skill

  std::string name();
  // Return m_name

  vwmSkill(const vwmSkill&) = delete;
  // Deleted copy constructor.

  vwmSkill& operator=(const vwmSkill&) = delete;
  // Deleted assignment operator.

  ~vwmSkill() = default;
  // Destructor

protected:

  // functions
  // variables

private:

  // friends
  // functions
  // variables
  modSkill* m_skill_model;
  // The model skill where all the logic happens

  vieSkillWidget* m_skill_view;
  // The view skill that is displayed to the user

  vwmSkillPage* m_parent;
};

//=============================================================================
//D Class for the default skill model. 
//
// A default skill has traits of name, picks, cost etc
//
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries
#include "modState.h"
#include "modSkillCost.h"
// system includes
#include <vector>
#include <memory>
// class predeclarations to avoid header file inclusion
class vwmSkill;
class modSkillManager;
class modCharacterDetails;
// types: classes, enums, typedefs

//=============================================================================
class modSkill : public modState {
public:

  modSkill(
    std::string name,
    std::unique_ptr<modSkillCost> cost_manager,
    int max_picks,
    bool status,
    std::vector<modSkill*> prerequisites // The list of skills needed before this skill can be taken
  );
  // Constructor

  virtual tinyxml2::XMLElement* convert_to_xml(
    tinyxml2::XMLDocument* parent
  ) const override;
  // Convert the state into an xml element

  virtual void load_from_xml(tinyxml2::XMLElement* element) override;
  // Load the state from an xml element

  std::string name() const;
  // Return m_name 

  int cost_per_rank() const;
  // Return m_cost_per_rank

  int max_picks() const;
  // Return m_max_picks

  bool set_picks(int num_picks);
  // Set m_num_picks
  // Return false if it breaks the dependency graph (and does not change picks)

  int total_cost() const;
  // Return the total cost for the number of picks

  int num_picks() const;
  // The m_num_picks

  bool is_pickable() const;
  // Return m_pickable (based on pre-requisites having been picked)

  modSkill(const modSkill&) = delete;
  // Deleted copy constructor.

  modSkill& operator=(const modSkill&) = delete;
  // Deleted assignment operator.

  ~modSkill() = default;
  // Destructor

protected:

  // functions
  void add_dependent_skill(modSkill* skill);
  // Add a skill that is dependant on this skill

  void update_pickable_state();
  // Check the pre_reqs and update the visability

  // variables

private:

  // friends
  // functions
  // variables
  std::string m_name;

  std::unique_ptr<modSkillCost> m_cost_manager;

  int m_max_picks;

  int m_num_picks;

  modSkillManager* m_parent;

  bool m_pickable;
  // A skill is pickable if we have ranks in all pre-requirements

  std::vector<modSkill*> m_prerequisite_skills;
  // The skills that are needed before the character can select this skill

  std::vector<modSkill*> m_dependent_skills;
  // The skills that this skill is a prerequisite for

};

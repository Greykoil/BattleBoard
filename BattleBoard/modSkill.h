//=============================================================================
//D Class for the default skill model. 
//
// A default skill has traits of name, picks, cost etx
//
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries
// system includes
#include <vector>
// class predeclarations to avoid header file inclusion
class vwmSkill;
class modSkillManager;

// types: classes, enums, typedefs

//=============================================================================
class modSkill {
public:

  modSkill(
    std::string name,
    int cost,
    int max_picks,
    bool status,
    std::vector<modSkill*> prerequisites // The list of skills needed before this skill can be taken
  );
  // Constructor

  std::string name() const;
  // Return the skill name

  int cost_per_rank() const;
  // Return the cost for each rank in the skill

  int max_picks() const;
  // Return the maximun number of times a skill can be taken

  bool is_status() const;
  // Return if a skill costs status
  
  bool set_picks(int num_picks);
  // Set m_num_picks
  // Return false if it breaks the dependency graph (and does not change picks)

  int total_cost() const;
  // Return the total cost for the number of picks

  int num_picks() const;
  // The number of ranks of skill the character has

  bool is_pickable() const;
  // Can the user pick the skill

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

  int m_cost;

  int m_max_picks;

  bool m_status;

  int m_num_picks;

  modSkillManager* m_parent;

  bool m_pickable;
  // A skill is pickable if we have ranks in all pre-requirements

  std::vector<modSkill*> m_prerequisite_skills;
  // The skills that are needed before the character can select this skill

  std::vector<modSkill*> m_dependent_skills;
  // The skills that this skill is a prerequisite for

};

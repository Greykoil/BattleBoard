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

// types: classes, enums, typedefs

//=============================================================================
class SkillLinear {
public:

  SkillLinear(
    std::string name,
    int cost,
    int max_picks,
    bool status
  );
  // Constructor

  void add_prerequeset(std::string name);
  // Add a pre-required skill

  std::string name() const;
  // Return the skill name

  int cost_per_rank() const;
  // Return the cost for each rank in the skill

  int max_picks() const;
  // Return the maximun number of times a skill can be taken

  bool is_status() const;
  // Return if a skill costs status

  SkillLinear(const SkillLinear&) = delete;
  // Deleted copy constructor.

  SkillLinear& operator=(const SkillLinear&) = delete;
  // Deleted assignment operator.

  ~SkillLinear();
  // Destructor

protected:

  // functions
  // variables

private:

  // friends
  // functions
  // variables
  std::string m_name;

  int m_cost;

  int m_max_picks;

  bool m_status;

  std::vector<std::string> m_prerequisits;
  // The names of any skills that are pre-requisites for this skill
};

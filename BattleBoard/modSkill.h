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
class vwmSkill;
class modSkillManager;

//=============================================================================
class modSkill {
public:

  modSkill(
    std::string name,
    int cost,
    int max_picks,
    bool status
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

  void set_picks(int num_picks);
  // Set m_num_picks

  int total_cost() const;
  // Return the total cost for the number of picks

  int num_picks() const;
  // The number of ranks of skill the character has

  modSkill(const modSkill&) = delete;
  // Deleted copy constructor.

  modSkill& operator=(const modSkill&) = delete;
  // Deleted assignment operator.

  ~modSkill() = default;
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

  int m_num_picks;

};

//=============================================================================
//D A class that takes skilltree.xml and turns it into a structure of 
//  classes for each skill
//
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries

#include "modSkill.h"
#include "modState.h"
#include "modMagicManager.h"
#include "modPowerManager.h"
// system includes
#include <vector>
#include <memory>

// class predeclarations to avoid header file inclusion
class modCharacterDetails;
class vieSkillWindow;
// types: classes, enums, typedefs

//=============================================================================
class modSkillManager : public modState {
public:

  modSkillManager(modCharacterDetails* character_details);
  // Constructor

  void set_view(vieSkillWindow* view_model);

  virtual tinyxml2::XMLElement* convert_to_xml(
    tinyxml2::XMLDocument* parent
  ) const override;
  // Convert the state into an xml element

  virtual void load_from_xml(tinyxml2::XMLElement* element) override;
  // Load the state from an xml element

  bool create_skill_tree();
  // Create the skill tree 

  int total_points_spent();
  // Get the total number of points for the chosen skills

  int num_skills() const;
  // Return the number of total skills

  modSkill* skill(int num);
  // return the n'th skill

  modCharacterDetails* get_character_details();
  // Get the current character details

  modMagicManager* get_magic_manager();

  modPowerManager* get_power_manager();

  int life();
  // Return the characters available life

  modSkillManager(const modSkillManager&) = delete;
  // Deleted copy constructor.

  modSkillManager& operator=(const modSkillManager&) = delete;
  // Deleted assignment operator.

  ~modSkillManager() = default;
  // Destructor

protected:

  // functions
  bool skill_from_xml(tinyxml2::XMLElement* node);
  // Create a skill from the xml node

  std::unique_ptr<modSkillCost> read_costs(tinyxml2::XMLElement* node);
  // Read the costs from the node

  std::unique_ptr<modRaceCost> cost_for_race(tinyxml2::XMLElement* node);
  // Get the costs associated with a given race

  void set_up_magic();
  // Set up the magic manager once the skill tree has been sorted.

  void set_up_power();
  // Set up the power manager once the skill tree has been sorted.

  modSkill* find_skill_by_name(std::string name);
  // Find the skill with the corresponding name

  // variables

private:

  // friends
  // functions
  // variables
  std::vector<std::unique_ptr<modSkill>> m_skill_tree;

  vieSkillWindow* m_view;

  modCharacterDetails* m_character_details;

  modMagicManager m_magic_manager;

  modPowerManager m_power_manager;
};

//=============================================================================
//D A class that takes skilltree.xml and turns it into a structure of 
//  classes for each skill
//
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries
#include "3rdPartyXml\tinyxml2.h"
// system includes
#include <vector>
#include <memory>

// class predeclarations to avoid header file inclusion
class modSkill;
class vwmSkillPage;
// types: classes, enums, typedefs

//=============================================================================
class modSkillManager {
public:

  modSkillManager();
  // Constructor

  bool create_skill_tree();
  // Create the skill tree 

  int num_skills() const;
  // Return the number of total skills

  modSkill* skill(int num);
  // return the n'th skill

  modSkillManager(const modSkillManager&) = delete;
  // Deleted copy constructor.

  modSkillManager& operator=(const modSkillManager&) = delete;
  // Deleted assignment operator.

  ~modSkillManager();
  // Destructor

protected:

  // functions
  bool skill_from_xml(tinyxml2::XMLElement* node);

  // variables

private:

  // friends
  // functions
  // variables
  std::vector<std::unique_ptr<modSkill>> m_skill_tree;

  vwmSkillPage* m_view_model;

};
